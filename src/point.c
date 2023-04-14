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

#include <math.h>

/* The point structure. */
struct _Point {
  /* The x coordinate. */
  int x;
  /* The y coordinate. */
  int y;
};

/* Creates a new Point. */
Point* point_new(int x, int y) {
  /* Heap allocation. */
  Point* point = malloc(sizeof(struct _Point));
  /* Value copy. */
  point->x = x;
  point->y = y;
}

/* Frees the memory used by the Point. */
void point_free(Point* point) {
  free(point);
}

/* Returns the x coordinate of the point. */
int point_x(Point* point) {
  return point->x;
}

/* Returns the y coordinate of the point. */
int point_y(Point* point) {
  return point->y;
}

/* Creates a point array. */
Point* point_array(int n) {
  Point* points = calloc(1, sizeof(struct _Point)*n);
}

/* Computes the distance between two points. */
long double point_distance(Point* p1, Point* p2) {
  return sqrt(pow(fabs(p1->x - p2->x), 2) + pow(fabs(p1->y - p2->y), 2));
}
