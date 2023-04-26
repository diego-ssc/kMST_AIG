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

/* The Circle structure. */
struct _Circle {
  /* The radius. */
  double radius;
  /* The middle point. */
  Point* m_point;
  /* The number of points inside of the circle. */
  int points;
};

/* Creates a new Circle */
Circle* circle_new(double radius, Point* center) {
  /* Heap allocation. */
  Circle* circle  = malloc(sizeof(struct _Circle));
  circle->m_point = point_copy(center);

  /* Value copy. */
  circle->radius = radius;

  return circle;
}

/* Frees the memory used by the Circle. */
void circle_free(Circle* circle) {
  if (circle->m_point)
    point_free(circle->m_point);
  free(circle);
}

/* Sets the radius of the circle. */
void circle_set_radius(Circle* circle, double radius) {
  circle->radius = radius;
}

/* Sets the number of points contained
   within the circle. */
void circle_set_n(Circle* circle, int points) {
  circle->points = points;
}

/* Returns the radius of the circle. */
double circle_radius(Circle* circle) {
  return circle->radius;
}

/* Returns the number of points contained
   within the circle. */
int circle_n(Circle* circle) {
  return circle->points;
}

/* Tells whether the points is or not
 * inside the circle. */
int circle_in(Circle* circle, Point* point) {
  return point_distance(circle->m_point, point)
    <= circle->radius;
}

/* Counts the points contained in the circle. */
int circle_n_points(Circle* circle, Point** points, int n) {
  int i, c = 0;
  for (i = 0; i <  n; ++i)
    if (circle_in(circle, *(points + i)))
      c++;
  return c;
}

/* Returns the points that are inside of the circle. */
Point** circle_points(Circle* circle, Point** points, int n) {
  int i, j = 0;
  Point** p = calloc(1,sizeof(Point*)*circle->points);
  for (i = 0; i <  n; ++i)
    if (circle_in(circle, *(points + i))) {
      *(p + j) = point_copy(*(points + i));
      j++;
    }

  return p;
}
