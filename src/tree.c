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

#include <stdlib.h>

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

typedef struct {
  int u, v, w;
} Edge;

static int eequal(const void* a, const void* b) {
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

void kruskal(double** m, int n) {
  int i, j, cno1, cno2;
  int t = n*(n-1)/2, a = n;
  Edge l[t], span[t];
  int b[n];
  for (i = 1; i < n; i++)
    for (j = 0; j < i; j++) {
      (l+n-a)->u = i;
      (l+n-a)->v = j;
      (l+n-a)->w = *(*(m+i)+j);
      --a;
    }
  qsort(l, t, sizeof(Edge), eequal);
  
  for (i = 0; i < n; i++)
    *(b+i) = i;

  a = n;
  for (i = 0; i < t; i++) {
    cno1 = find(b, (l+i)->u);
    cno2 = find(b, (l+i)->v);
    if (cno1 != cno2) {
      *(span+n-a) = *(l+i);
      k_union(b, cno1, cno2, n);
      --a;
    }
  } 
} 
