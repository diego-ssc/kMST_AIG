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

#pragma once

#include <stdlib.h>

/* The Point wrapper structure. */
typedef struct {
  /* The point. */
  Point* point;
  /* The identifier. */
  int id;
} Point_Kruskal;

/* The Edge structure. */
typedef struct {
  /* The first point. */
  Point_Kruskal *p;
  /* The second point. */
  Point_Kruskal *q;
  /* The weight. */
  double w;
} Edge;

/**
 * Creates a new Tree.
 * @param points the points.
 * @param k the size.
 */
Tree* tree_new(Point** points, int k);

/**
 * Frees the memory used by the tree.
 * @param tree the tree.
 */
void tree_free(Tree* tree);

Edge* kruskal(Point** points, int n);
