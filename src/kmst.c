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

/* The kMST structure. */
struct _kMST {
  /* The solution. */
  Tree* tree;
  /* The size of the tree. */
  int k;
  /* The number of points. */
  int n;
  /* The graph points. */
  Point** points;
  /* The adjacency matrix. */
  double** m;
  /* RNG buffer. */
  struct drand48_data *buffer;
};

/* Selects the initial solution. */
static Point** initial_solution(kMST*, int);

/* Creates a new k-minimum spanning tree problem instance. */
kMST* kmst_new(Point** points, int k, int n, long int seedval) {
  /* Heap allocation. */
  kMST* kmst = malloc(sizeof(struct _kMST));

  /* Value copy. */
  kmst->points = points;
  kmst->k      = k;
  kmst->n      = n;

  /* RNG. */
  kmst->buffer = malloc(sizeof(struct drand48_data));
  srand48_r(seedval, kmst->buffer);
  Point** initial = initial_solution(kmst, k);
  kmst->tree = tree_new(initial, k);
  free(initial);

  return kmst;
}

/* Frees the memory used by the k-minimum spanning tree problem instance. */
void kmst_free(kMST* kmst) {
  if (kmst->tree)
    tree_free(kmst->tree);
  if (kmst->buffer)
    free(kmst->buffer);
  free(kmst);
}


/* Returns the tree of the problem. */
Tree* kmst_tree(kMST* kmst) {
  return kmst->tree;
}

/* Returns the points of the problem. */
Point** kmst_points(kMST* kmst) {
  return kmst->points;
}

/* Returns the total number of points. */
int kmst_point_n(kMST* kmst) {
  return kmst->n;
}

/* Returns the k value. */
int kmst_k(kMST* kmst) {
  return kmst->k;
}

/* Returns the RNG buffer of the problem. */
struct drand48_data* kmst_buffer(kMST* kmst) {
  return kmst->buffer;
}

/* Selects the initial solution. */
static Point** initial_solution(kMST* kmst, int k) {
  int i;
  long int* result = calloc(1, sizeof(long int));
  Point** points = point_array(k);
  for (i = 0; i < k; ++i) {
    lrand48_r(kmst->buffer, result);
    *(points + i) = *(kmst->points + (*result % k));
  }
  free(result);
  return points;
}
