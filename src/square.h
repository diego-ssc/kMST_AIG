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
 * Returns the number of points contained in the square.
 * @param square the square.
 * @return the number of points.
 */
int square_n(Square* square);

/**
 * Sets the number of points contained in the square.
 * @param square the square.
 * @param n_points the number of points.
 */
void square_set_n_points(Square* square, int n_points);

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
int square_n_points(Square* square, Point** points, int n);

/**
 * Returns the points contained in the square.
 * @param square the square.
 * @param points the original set of points.
 * @param n the original number of points.
 * @return the points.
 */
Point** square_points(Square* square, Point** points, int n);

/**
 * Returns the side length of the square.
 * @param square the square.
 * @return the side length.
 */
double square_side(Square* square);

/**
 * Returns the sub-squares of the square.
 * @param square the square.
 * @param k the number of sub-squares.
 * @param points the original set of points.
 * @param n the original set of points quantity.
 * @return the square matrix.
 */
Square** square_cells(Square* square, int k,
                      Point** points, int n);

/**
 * Compares two squares.
 * @param s_1 the first square.
 * @param s_2 the second square.
 * @return an integer less, equal or greater than 0;
 * if s_1 is less, equal or greater than s_2.
 */
int square_compare(const void* s_1, const void* s_2);
