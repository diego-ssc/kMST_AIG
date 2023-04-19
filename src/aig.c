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

#define A_MAX 30
#define B_MAX 30
#define EPSILON 100000

/* The AIG structure. */
struct _AIG {
  /* The k-minimum spanning tree problem. */
  kMST* kmst;
  /* The first maximum angle value. */
  long double a_max;
  /* The second maximum angle value. */
  long double b_max;
  /* The epsilon parameter. */
  long double epsilon;
  /* The variable to optimize. */
  long double diameter;
  /* The adjacency matrix. */
  double** m;
};

/* Creates a new Algorithm of the Innovative Gunner Heuristic. */
AIG* aig_new(kMST* kmst, long double a_max, long double b_max,
             long epsilon, long diameter) {
  /* Heap allocation. */
  AIG* aig = malloc(sizeof(struct _AIG));

  /* Value copy. */
  aig->kmst     = kmst;
  aig->a_max    = a_max;
  aig->b_max    = b_max;
  aig->epsilon  = epsilon;
  aig->diameter = diameter;

  return aig;
}

/* Frees the memory used by the Algorithm of the Innovative Gunner. */
void aig_free(AIG* aig) {
  if (aig->kmst)
    kmst_free(aig->kmst);
  free(aig);
}

/* Computes the circle. */
Circle* aig_circle(AIG* aig) {
  long int i = 0, j = 0;
  Point** points = kmst_points(aig->kmst);
  while (i == j) { //For each pair of points?
    lrand48_r(kmst_buffer(aig->kmst), &i);
    lrand48_r(kmst_buffer(aig->kmst), &j);
  }

  Point* p_1 = *(points + i);
  Point* p_2 = *(points + j);
  Point* m   = middle_point(p_1, p_2);
  Circle* c = circle_new((point_distance(p_1, p_2)/2)*sqrt(3), m);
  free(m);

  return c;
}

/* Begins the execution of the heuristic. */
void aig(AIG* aig) {
  Circle* c = 0;
  int n = 0;
  long double r_1, r_2;

  do {
    if (c)
      free(c);
    c = aig_circle(aig);
    /* circle_set_radius(c, circle_radius(c)*acos(a_max)*acos(b_max)); */
    n = circle_points(c, kmst_points(aig->kmst),
                      kmst_point_n(aig->kmst));
    /* drand48_r(kmst_buffer(aig->kmst), &r_1); */
    /* drand48_r(kmst_buffer(aig->kmst), &r_2); */
    /* a_max *= r_1; */
    /* b_max *= r_2; */
  } while (n < kmst_k(aig->kmst));
  
  circle_free(c);
}
