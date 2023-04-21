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

#define EPSILON 0.00016

/* The square structure. */
struct _Square {
  /* The first corner. */
  Point* p_1;
  /* The second corner. */
  Point* p_2;
  /* The number of points contained in it. */
  int n_points;
};

/* Creates a new Square. */
Square* square_new(Point* p_1, Point* p_2) {
  /* Heap allocation. */
  Square* square = malloc(sizeof(struct _Square));
  square->p_1 = point_x(p_1) < point_x(p_2)
    ? point_copy(p_1) : point_copy(p_2);
  square->p_2 = point_x(p_2) > point_x(p_1)
    ? point_copy(p_2) : point_copy(p_1);

  if (point_y(p_1) < point_y(p_2)) {
    Point* p = point_new(point_x(square->p_1), point_y(square->p_2));
    Point* q = point_new(point_x(square->p_2), point_y(square->p_1));
    point_free(square->p_1);
    point_free(square->p_2);
    square->p_1 = p;
    square->p_2 = q;
  }
  return square;
}

/* Frees the memory used by the Square. */
void square_free(Square* square) {
  if (square->p_1)
    point_free(square->p_1);
  if (square->p_2)
    point_free(square->p_2);
  free(square);
}

/* Returns the number of points contained in the square. */
int square_n(Square* square) {
  return square->n_points;
}

/* Sets the number of points contained in the square. */
void square_set_n_points(Square* square, int n_points) {
  square->n_points = n_points;
}

/* Tells whether the point is or not  inside the square. */
int square_in(Square* square, Point* point) {
  double h_max = point_x(square->p_1) > point_x(square->p_2) ?
    point_x(square->p_1) : point_x(square->p_2);
  double h_min = point_x(square->p_2) < point_x(square->p_1) ?
    point_x(square->p_2) : point_x(square->p_1);
  double v_max = point_y(square->p_1) > point_y(square->p_2) ?
    point_y(square->p_1) : point_y(square->p_2);
  double v_min = point_y(square->p_2) < point_y(square->p_1) ?
    point_y(square->p_2) : point_y(square->p_1);

  return (h_min <= point_x(point)) && (h_max >= point_x(point))
    && (v_min <= point_y(point)) && (v_max >= point_y(point));
}

/* Counts the points contained in the circle. */
int square_n_points(Square* square, Point** points, int n) {
  int c = 0, i;
  for (i = 0; i < n; i++)
    if (square_in(square, *(points+i)))
      ++c;
  return c;
}

/* Returns the points contained in the square. */
Point** square_points(Square* square, Point** points, int n) {
  int i;
  /* The attribute n_points had to be previously assigned. */
  Point** p = calloc(1, sizeof(Point*)*square->n_points);
  for (i = 0; i < n; i++)
    if (square_in(square, *(points+i)))
      *(p + i) = *(points+i);

  return p;
}

/* Returns the side length of the square. */
double square_side(Square* square) {
  return fabs(point_x(square->p_1) - point_x(square->p_2));
}

/* Returns the sub-squares of the square. */
Square** square_cells(Square* square, int k, Point** points, int m) {
  int n = floor(abs(point_x(square->p_1) - point_x(square->p_2)));
  Square** a = calloc(1, sizeof(Square*)*n*n);
  int i, size = n;
  Point *p = point_new(0., 0.), *q = point_new(0., 0.);
  double x = point_x(square->p_1), y = point_x(square->p_1);
  Square* s;

  for (i = 0; i < size; ++i) {
    point_set_x(p, x);
    x += (size/sqrt((double)k));
    point_set_x(q, x);
    s = square_new(p, q);
    s->n_points = square_n_points(s, points, m);
    *(a+i) = s;

    if ((x - size) < EPSILON) {
      x = 0., y -= (size/sqrt((double)k));
      point_set_y(p, y);
      point_set_y(q, y);
    }
  }

  point_free(p);
  point_free(q);
  return a;
}

/* Compares two squares. */
int square_compare(const void* s_1, const void* s_2) {
  return ((Square*)s_1)->n_points - ((Square*)s_2)->n_points;
}
