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

/* The square structure. */
struct _Square {
  /* The first corner. */
  Point* p_1;
  /* The second corner. */
  Point* p_2;
};

/* Creates a new Square. */
Square* square_new(Point* p_1, Point* p_2) {
  /* Heap allocation. */
  Square* square = malloc(sizeof(struct _Square));
  square->p_1 = point_copy(p_1);
  square->p_2 = point_copy(p_2);

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
int square_points(Square* square, Point** points, int n) {
  int c = 0, i;
  for (i = 0; i < n; i++)
    if (square_in(square, *(points+i)))
      c++;
  return c;
}
