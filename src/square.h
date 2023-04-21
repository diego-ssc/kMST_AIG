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
 * Creates a new Square.
 * @param p_1 the first corner.
 * @param p_2 the second corner.
 */
Square* square_new(Point* p_1, Point* p_2);

/**
 * Frees the memory used by the Square.
 * @param square the square,
 */
void square_free(Square* square);

/**
 * Tells whether the point is or not
 * inside the square.
 * @param square the square.
 * @param point the point.
 * @return 1, if the point is located inside
 * the square; 0, otherwise.
 */
int square_in(Square* square, Point* point);

/**
 * Counts the points contained in the circle.
 * @param square the square.
 * @param points the original set of points.
 * @param n the original number of points.
 * @return the number of points.
 */
int square_points(Square* square, Point** points, int n);
