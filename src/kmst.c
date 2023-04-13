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
struct _KMST {
  /* The solution. */
  Tree* tree;
  /* The size of the tree. */
  int k;
  /* The graph points. */
  Point* points;
  /* The adjacency matrix. */
  double** m;
};

/* Creates a new k-minimum spanning tree problem instance. */
KMST* kmst_new(Point* points, int k, int n) {
  /* Heap allocation. */
  KMST* kmst = malloc(sizeof(struct _KMST));
  kmst->tree = tree_new();//////

  /* Value copy. */
  kmst->points = points;
  kmst->k      = k;
  kmst->m      = m;
}

/* Frees the memory used by the k-minimum spanning tree problem instance. */
void kmst_free(KMST* kmst) {
  if (kmst->tree)
    tree_free(kmst->tree);
  free(kmst);
}
