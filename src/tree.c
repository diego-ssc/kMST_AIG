/*
 * This file is part of kMST_AIG.
 *
 * Copyright © 2023 Diego Sebastián Sánchez Correa
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <https://www.gnu.org/licenses/>.
 */

#include "heuristic.h"

/* The tree structure. */
struct _Tree {
  /* The points. */
  Point** points;
  /* Tree size. */
  int k;
  /* The span size. */
  int n;
  /* The array used by the Kruskal algorithm. */
  int* belongs;
};

/* Copies the given points into the tree structure. */
static void copy_points(Tree*, Point**);

/* Auxiliary function for the union-find algorithm. */
static int find(int*, int);

/* Auxiliary function for the union-find algorithm. */
static void k_union(int*, int, int, int);

/* Creates a new Tree. */
Tree* tree_new(Point** points, int k) {
  /* Heap allocation. */
  Tree* tree = malloc(sizeof(struct _Tree));
  tree->points = point_array(k);

  /* Value copy. */
  tree->k = k;

  /* Value initialization. */
  copy_points(tree, points);
  tree->belongs = calloc(1, sizeof(int)*k);
  for (int i = 0; i < k; i++)
    *(tree->belongs+i) = i;

  return tree;
}

/* Frees the memory used by the tree. */
void tree_free(Tree* tree) {
  if (tree->points)
    free_point_array(&tree->points, tree->k);
  if(tree->belongs)
    free(tree->belongs);
  free(tree);
}

/* Copies the given points into the tree structure. */
static void copy_points(Tree* tree, Point** points) {
  int i;
  for (i = 0; i < tree->k; ++i)
    *(tree->points + i) = point_copy(*(points + i));
}

/* Auxiliary function for the union-find algorithm. */
static int find(int* b, int n) {
  return *(b+n);
}

/* Auxiliary function for the union-find algorithm. */
static void k_union(int* b, int c1, int c2, int n) {
  int i;
  for (i = 0; i < n; i++)
    if (*(b+i) == c2)
      *(b+i) = c1;
}

/* Computes the Kruskal algorithm. */
Edge* kruskal(Tree* tree) {
  int i, j, cluster_1, cluster_2;
  int n = tree->k;
  int t = n*(n-1)/2;
  Edge *edges = edge_array(t), *span = edge_array(t);
  int c_1 = 0, c_2 = 0;

  for (i = 0; i < n; i++)
    for (j = i+1; j < n; j++) {
      edge_set_q(edge_array_position(edges, c_1), *(tree->points + j));
      edge_set_p(edge_array_position(edges, c_1), *(tree->points + i));
      edge_set_w(edge_array_position(edges, c_1), point_distance(*(tree->points + i),
                                                                 *(tree->points + j)));
      edge_set_i(edge_array_position(edges, c_1), i);
      edge_set_j(edge_array_position(edges, c_1), j);
      ++c_1;
    }

  qsort(edges, t, edge_size(), edge_compare);

  for (i = 0; i < c_1; i++) {
    cluster_1 = find(tree->belongs, edge_i(edge_array_position(edges, i)));
    cluster_2 = find(tree->belongs, edge_j(edge_array_position(edges, i)));
    if (cluster_1 != cluster_2) {
      edge_set_array_position(span, c_2,
                              edge_array_position(edges, i));
      ++c_2;
      k_union(tree->belongs, cluster_1, cluster_2, n);
    }
  }

  tree->n = c_2;
  free(edges);
  return span;
}

/* Returns the size of the span. */
int tree_span_size(Tree* tree) {
  return tree->n;
}

/* Returns a copy of the tree. */
Tree* tree_copy(Tree* tree) {
  /* Heap allocation. */
  Tree* t = malloc(sizeof(struct _Tree));
  t->points = point_array(tree->k);

  /* Value copy. */
  t->k = tree->k;

  /* Value initialization. */
  copy_points(t, tree->points);
  t->belongs = calloc(1, sizeof(int)*tree->k);
  for (int i = 0; i < tree->k; i++)
    *(t->belongs+i) = i;

  return t;
}
