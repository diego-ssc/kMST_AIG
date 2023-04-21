/*
 * This file is part of TSP_SA.
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

struct _Input_parser {
  /* The file pointer. */
  FILE* fp;
  /* The point array. */
  Point** points;
  /* The number of points parsed. */
  int n;
};

/* Counts the number of points contained in thwe file. */
static int point_counter(Input_parser*);

/* Creates a new Input Parser. */
Input_parser* input_parser_new(char* fn) {
  /* Heap allocations. */
  Input_parser* parser = malloc(sizeof(struct _Input_parser));

  /* File opening. */
  parser->fp = fopen(fn, "r");

  /* Heap initialization. */
  parser->n = point_counter(parser);
  fclose(parser->fp);
  parser->fp = fopen(fn, "r");
  parser->points = point_array(parser->n);

  return parser;
}

/* Frees the memory used by the Input parser. */
void input_parser_free(Input_parser* parser) {
  if (parser->points)
    free_point_array(&parser->points, parser->n);
  fclose(parser->fp);
  free(parser);
}

/* Parses the file and returns the array of points. */
Point** parse(Input_parser* parser) {
  double x, y;
  int i = 0;
  while (EOF != fscanf(parser->fp, "%lf,%lf\n", &x, &y)) {
    *(parser->points + i) = point_new(x, y);
    ++i;
  }
  return parser->points;
}

/* Counts the number of points contained in thwe file. */
static int point_counter(Input_parser* parser) {
  int i = 0;
  while (EOF != fscanf(parser->fp, "%*f,%*f\n"))
    ++i;
  return i;
}
