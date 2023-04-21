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
  /* The adjacency matrix. */
  double** m;
};

/* Copies the given points into the tree structure. */
static void copy_points(Tree*, Point**);

/* static void create_adj_matrix(); */

/* Creates a new Tree. */
Tree* tree_new(Point** points, int k) {
  /* Heap allocation. */
  Tree* tree = malloc(sizeof(struct _Tree));
  tree->points = point_array(k);

  /* Value copy. */
  tree->k = k;

  /* Value initialization. */
  copy_points(tree, points);

  return tree;
}

/* Frees the memory used by the tree. */
void tree_free(Tree* tree) {
  free(tree);
}

/* Copies the given points into the tree structure. */
static void copy_points(Tree* tree, Point** points) {
  int i;
  for (i = 0; i < tree->k; ++i)
    *(tree->points + i) = point_copy(*(points + i));
}

Point_Kruskal* point_kruskal_new(Point* point, int id) {
  Point_Kruskal* p_k = malloc(sizeof(Point_Kruskal));
  p_k->point = point;
  p_k->id = id;
  return p_k;
}

/* point_kruskal_free(Point_Kruskal* p_k) { */
/*   if () */
/* } */

static int edge_compare(const void* a, const void* b) {
  return ((Edge*)a)->w - ((Edge*)b)->w < 0;
}

int find(int* b, int n) {
  return *(b+n);
}

void k_union(int* b, int c1, int c2, int n) {
  int i;
  for (i = 0; i < n; i++)
    if (*(b+i) == c2)
      *(b+i) = c1;
}

Edge* kruskal(Point** points, int n) {
  int i, j, cluster_1, cluster_2;
  int t = n*(n-1)/2, a = n;
  Edge *edges = calloc(1, sizeof(Edge)*t), *span = calloc(1, sizeof(Edge)*t);
  int* belongs = calloc(1, sizeof(int)*t);

  for (i = 0; i < n; i++)
    for (j = i+1; j < n; j++) {
      (edges+n-a)->p = point_kruskal_new(*(points+i), n-a);
      (edges+n-a)->q = point_kruskal_new(*(points+j), n-a);
      (edges+n-a)->w = point_distance((edges+n-a)->p->point,
                                       (edges+n-a)->q->point);
      --a;
    }
  
  qsort(edges, t, sizeof(Edge), edge_compare);

  for (i = 0; i < t; i++)
    *(belongs+i) = i;
 
  a = n;
  int l = 0;
  for (i = 0; i < t; i++) {
    cluster_1 = find(belongs, (edges+i)->p->id);
    cluster_2 = find(belongs, (edges+i)->q->id);
    if (cluster_1 != cluster_2) {
      *(span+n-a) = *(edges+i);
      l++;
      k_union(belongs, cluster_1, cluster_2, n);
      --a;
    }
  }
  printf("Span size: %d\n", l);
  return span;
}
