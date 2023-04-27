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

#define MAX_ITERATIONS 2
#define A_MAX 0.2
#define B_MAX 0.2

/* The AIG structure. */
struct _AIG {
  /* The k-minimum spanning tree problem. */
  kMST* kmst;
  /* The first maximum angle value. */
  double a_max;
  /* The second maximum angle value. */
  double b_max;
  /* The epsilon parameter. */
  int epsilon;
  /* The variable to optimize. */
  double diameter;
  /* The maximum number of iterations. */
  int max_iterations;
};

/* Returns the function according to the given correction angle. */
static double heuristic_function(double);

/* Creates a new Algorithm of the Innovative Gunner Heuristic. */
AIG* aig_new(kMST* kmst, double a_max, double b_max,
             int epsilon, int max_iterations) {
  /* Heap allocation. */
  AIG* aig = malloc(sizeof(struct _AIG));

  /* Value copy. */
  aig->kmst           = kmst;
  aig->a_max          = a_max ? a_max : A_MAX;
  aig->b_max          = b_max ? b_max : B_MAX;
  aig->max_iterations = max_iterations ? max_iterations : MAX_ITERATIONS;
  aig->epsilon  = epsilon;

  return aig;
}

/* Frees the memory used by the Algorithm of the Innovative Gunner. */
void aig_free(AIG* aig) {
  if (aig->kmst)
    kmst_free(aig->kmst);
  free(aig);
}

/* Computes the circle. */
Circle* aig_circle(AIG* aig, int i, int j) {
  Point** points = kmst_points(aig->kmst);

  Point* p_1 = *(points + i);
  Point* p_2 = *(points + j);
  Point* m   = middle_point(p_1, p_2);
  Circle* c = circle_new((point_distance(p_1, p_2)/2)*sqrt(3), m);
  point_free(m);

  return c;
}

/* Returns the function according to the given correction angle. */
static double heuristic_function(double a) {
  if (a > 0)
    return acos(a);
  else
    return cos(a);
}

/* Begins the execution of the heuristic. */
void aig_heuristic(AIG* aig) {
  /* The circle. */
  Circle* c = 0;

  /* The point counter. */
  int n;

  /* The indexes. */
  int i, j;

  /* The generated tree. */
  Tree* tree = 0, *best = 0;

  /* The problem instance data. */
  Point** points = kmst_points(aig->kmst);
  int p_n = kmst_point_n(aig->kmst);
  int k = kmst_k(aig->kmst);

  /* The points contained within the circle. */
  Point** c_points;

  Edge* span_1 = 0;
  double new_eval;
  double old_eval = 100000;
  int max = aig->max_iterations;

  for (i = 0; i < kmst_point_n(aig->kmst); ++i) {
    for (j = i+1; j < kmst_point_n(aig->kmst); ++j) {
      /* Computing the generated circle. */
      c = aig_circle(aig, i, j);

      /* Setting the new attributes. */
      circle_set_radius(c, circle_radius(c)*sqrt(3));

      /* Computing the number of points. */
      n = circle_n_points(c, points, p_n);

      circle_set_n(c, n);

      if (n < k) {
        circle_free(c);
        continue;
      }

      max = aig->max_iterations;
      while ((circle_n(c) >= k) && max--) {
        c_points = circle_points(c, points, p_n);

        tree = tree_new(c_points, k);

        span_1 = kruskal(tree);
        new_eval = eval_edge_array(span_1, k - 1);
        if (new_eval < old_eval) {
          old_eval = new_eval;
          if (best)
            tree_free(best);
          best = tree_copy(tree);
        }
        if (tree)
          tree_free(tree);

        free_point_array(&c_points, circle_n(c));
        circle_set_radius(c, circle_radius(c)*
                          heuristic_function(aig->a_max)*
                          heuristic_function(aig->b_max));
        n = circle_n_points(c, points, p_n);
        circle_set_n(c, n);
        free(span_1);
      }

      circle_free(c);
    }
  }

  kmst_set_tree(aig->kmst, best);
}
