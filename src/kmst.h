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

/**
 * Creates a new k-minimum spanning tree problem instance.
 * @param points a two dimensional point array.
 * @param k the size of the tree.
 * @param n the number of points in the graph.
 */
KMST* kmst_new(Point* points, int k, int n);

/**
 * Frees the memory used by the k-minimum spanning tree problem instance.
 * @param kmst the problem instance to be freed.
 */
void kmst_free(KMST* kmst);
