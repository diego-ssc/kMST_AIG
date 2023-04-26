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

#include <string.h>

/* The Edge structure. */
struct _Edge {
  /* The first point. */
  Point* p;
  /* The second point. */
  Point* q;
  /* The point identifiers. */
  int i, j;
  /* The weight. */
  double w;
  /* The string representation. */
  char* str;
};

/* Creates a new edge. */
Edge* edge_new(Point* p, Point* q, double w) {
  /* Heap allocation. */
  Edge* edge = malloc(sizeof(struct _Edge));

  /* Heap initialization. */
  edge->p   = point_copy(p);
  edge->q   = point_copy(q);
  edge->str = malloc(((sizeof(char)*4) +
                     (sizeof(double)*2) + 1)*2 +
                     sizeof(char)*8 +
                     sizeof(double) + 1);

  /* Value copy. */
  edge->w = w;

  return edge;
}

/* Frees the memory used by the Edge. */
void edge_free(Edge* edge) {
  if (edge->p)
    point_free(edge->p);
  if (edge->q)
    point_free(edge->q);
  if (edge->str)
    free(edge->str);
  free(edge);
}

/* Compares two edges. */
int edge_compare(const void* a, const void* b) {
  return ((Edge*)a)->w - ((Edge*)b)->w > 0;
}

/* Returns an edge array. */
Edge* edge_array(int n) {
  return calloc(1, sizeof(struct _Edge)*n);
}

/* Returns the i-th position of the edge array. */
Edge* edge_array_position(Edge* edge, int i){
  return edge+i;
}

/* Sets the i-th position of the edge array. */
void edge_set_array_position(Edge* edge, int i, Edge* e) {
  *(edge+i) = *e;
}

/* Returns the first point. */
Point* edge_p(Edge* edge) {
  return edge->p;
}

/* Returns the second point. */
Point* edge_q(Edge* edge) {
  return edge->q;
}

/* Returns the weight. */
double edge_w(Edge* edge) {
  return edge->w;
}

/* Returns the first identifier. */
int edge_i(Edge* edge) {
  return edge->i;
}

/* Returns the second identifier. */
int edge_j(Edge* edge) {
  return edge->j;
}

/* Sets the first identifier. */
void edge_set_i(Edge* edge, int i) {
  edge->i = i;
}

/* Sets the second identifier. */
void edge_set_j(Edge* edge, int j) {
  edge->j = j;
}

/* Sets the first point. */
void edge_set_p(Edge* edge, Point* p) {
  edge->p = p;
}

/* Sets the second point. */
void edge_set_q(Edge* edge, Point* q) {
  edge->q = q;
}

/* Sets the weight. */
void edge_set_w(Edge* edge, double w) {
  edge->w = w;
}

/* Returns the size of an edge. */
size_t edge_size() {
  return sizeof(struct _Edge);
}

/* Computes the evaluation of a an array of edges */
double eval_edge_array(Edge* edges, int n) {
  double eval = 0;
  for (int i = 0; i < n; i++)
    eval += edge_w(edges + i);
  return eval;
}

/* Returns the string representation of an edge. */
char* edge_to_string(Edge* edge) {
  sprintf(edge->str, "(%s, %s) :: %.2f",
          point_to_string(edge->p),
          point_to_string(edge->q),
          edge->w);
    return edge->str;
}

/* Copies the given edge. */
Edge* edge_copy(Edge* edge) {
  /* Heap allocation. */
  Edge* e = malloc(sizeof(struct _Edge));

  /* Heap initialization. */
  e->p = point_copy(edge->p);
  e->q = point_copy(edge->q);

  /* Value copy. */
  e->w = edge->w;

  return e;
}
