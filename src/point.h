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
 * Creates a new Point.
 * @param x the x coordinate.
 * @param y the y coordinate.
 */
Point* point_new(double x, double y);

/**
 * Frees the memory used by the Point.
 * @param point the point.
 */
void point_free(Point* point);

/**
 * Sets the x coordinate of the point.
 * @param point the point.
 * @param x the x coordinate.
 */
void point_set_x(Point* point, double x);

/**
 * Sets the y coordinate of the point.
 * @param point the point.
 * @param y the y coordinate.
 */
void point_set_y(Point* point, double y);

/**
 * Returns the x coordinate of the point.
 * @param point the point.
 * @return the x coordinate.
 */
double point_x(Point* point);

/**
 * Returns the y coordinate of the point.
 * @param point the point.
 * @return the y coordinate.
 */
double point_y(Point* point);

/**
 * Creates a point array.
 * @param n the array size.
 * @return the point array.
 */
Point** point_array(int n);

/**
 * Frees a point array.
 * @param points the point array.
 * @param n the number of elements of the array.
 */
void free_point_array(Point*** points, int n);

/**
 * Computes the distance between two points.
 * @param p1 the first point.
 * @param p2 the second point.
 */
double point_distance(Point* p1, Point* p2);

/**
 * Computes the middle point between two points.
 * @param p_1 the first point.
 * @param p_2 the second point.
 * @return the middle point.
 */
Point* middle_point(Point* p_1, Point* p_2);

/**
 * Copies the given point.
 * @param point the point.
 * @return the copied point.
 */
Point* point_copy(Point* point);
