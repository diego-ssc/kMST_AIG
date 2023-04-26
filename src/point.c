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

#include <stdlib.h>
#include <math.h>

/* The point structure. */
struct _Point {
  /* The x coordinate. */
  double x;
  /* The y coordinate. */
  double y;
  /* The string representation. */
  char* str;
};

/* Creates a new Point. */
Point* point_new(double x, double y) {
  /* Heap allocation. */
  Point* point = malloc(sizeof(struct _Point));
  point->str = malloc((sizeof(char)*4) +
                      (sizeof(double)*2) + 1);

  /* Value copy. */
  point->x = x;
  point->y = y;

  return point;
}

/* Frees the memory used by the Point. */
void point_free(Point* point) {
  if (point->str)
    free(point->str);
  free(point);
}

/* Sets the x coordinate of the point. */
void point_set_x(Point* point, double x) {
  point->x = x;
}

/* Sets the y coordinate of the point. */
void point_set_y(Point* point, double y) {
  point->y = y;
}

/* Returns the x coordinate of the point. */
double point_x(Point* point) {
  return point->x;
}

/* Returns the y coordinate of the point. */
double point_y(Point* point) {
  return point->y;
}

/* Creates a point array. */
Point** point_array(int n) {
  return calloc(1, n*sizeof(Point*));
}

/* Frees a point array. */
void free_point_array(Point*** points, int n) {
  int a = n;
  while (n--)
    if (*((*points) + a-(n+1)))
      point_free(*((*points) + a-(n+1)));
  free(*points);
}

/* Computes the distance between two points. */
double point_distance(Point* p_1, Point* p_2) {
  return sqrt(pow(fabs(p_1->x - p_2->x), 2) + pow(fabs(p_1->y - p_2->y), 2));
}

/* Computes the middle point between two points. */
Point* middle_point(Point* p_1, Point* p_2) {
  return point_new((point_x(p_1) + point_x(p_2))/2,
                   (point_y(p_1) + point_y(p_2))/2);
}

/* Copies the given point. */
Point* point_copy(Point* point) {
  /* Heap allocation. */
  Point* p = malloc(sizeof(struct _Point));
  p->str = malloc((sizeof(char)*4) +
                  (sizeof(double)*2) + 1);

  /* Value copy. */
  p->x = point->x;
  p->y = point->y;

  return p;
}

/* Returns the string representation of a point. */
char* point_to_string(Point* point) {
  char* str = point->str;
  sprintf(str, "(%.2f, %.2f)", point->x,
          point->y);
  return str;
}
