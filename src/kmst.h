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

/**
 * Creates a new k-minimum spanning tree problem instance.
 * @param points a two dimensional point array.
 * @param k the size of the tree.
 * @param n the number of points in the graph.
 * @param seedval the seed.
 */
kMST* kmst_new(Point** points, int k, int n, long int seedval);

/**
 * Frees the memory used by the k-minimum spanning tree problem instance.
 * @param kmst the problem instance to be freed.
 */
void kmst_free(kMST* kmst);

/**
 * Returns the tree of the problem.
 * @param kmst the problem instance.
 * @return the tree.
 */
Tree* kmst_tree(kMST* kmst);

/**
 * Returns the points of the problem.
 * @param kmst the problem instance.
 * @return the point array.
 */
Point** kmst_points(kMST* kmst);

/**
 * Returns the total number of points.
 * @param kmst the problem instance.
 * @return the total number of points.
 */
int kmst_point_n(kMST* kmst);

/**
 * Returns the k value.
 * @param kmst the problem instance.
 * @return the k value.
 */
int kmst_k(kMST* kmst);

/**
 * Returns the RNG buffer of the problem.
 * @param kmst the problem instance.
 * @return the buffer.
 */
struct drand48_data* kmst_buffer(kMST* kmst);
