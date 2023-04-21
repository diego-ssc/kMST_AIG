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
 * Creates a new Circle
 * @param radius the radius.
 * @param center the middle point.
 */
Circle* circle_new(double radius, Point* center);

/**
 * Frees the memory used by the Circle.
 * @param circle.
 */
void circle_free(Circle* circle);

/**
 * Sets the radius of the circle.
 * @param circle the circle.
 * @param radius the new radius.
 */
void circle_set_radius(Circle* circle, double radius);

/**
 * Returns the radius of the circle.
 * @param circle the circle.
 * @return the radius.
 */
double circle_radius(Circle* circle);

/**
 * Tells whether the point is or not
 * inside the circle.
 * @param circle The circle.
 * @param point the point,
 * @return 1, if the point is located inside
 * the circle; 0, otherwise.
 */
int circle_in(Circle* circle, Point* point);

/**
 * Counts the points contained in the circle.
 * @param circle the circle.
 * @param points the original set of points.
 * @param n the original number of points.
 * @return the number of points.
 */
int circle_points(Circle* circle, Point** points, int n);

/**
 * Returns the circumscribing square of the circle.
 * @param circle circle the circle.
 * @return the circumscribing square.
 */
Square* circumscribing_square(Circle* circle);
