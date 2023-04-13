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

/* The AIG structure. */
struct _AIG {
  /* The k-minimum spanning tree problem. */
  kMST* kmst;
  /* The first maximum angle value. */
  long double a_max;
  /* The second maximum angle value. */
  long double b_max;
  /* The epsilon parameter. */
  long epsilon;
  /* The delta parameter. */
  long delta;
  /* The adjacency matrix. */
  double** m;
};

/* Creates a new Algorithm of the Innovative Gunner Heuristic. */
AIG* aig_new(kMST* kmst, long double a_max, long double b_max,
             long epsilon, long delta) {
  /* Heap allocation. */
  AIG* aig = malloc(sizeof(struct _AIG));

  /* Value copy. */
  aig->ksmt    = kmst;
  aig->a_max   = a_max;
  aig->b_max   = b_max;
  aig->epsilon = epsilon;
  aig->delta   = delta;
}

/* Frees the memory used by the Algorithm of the Innovative Gunner. */
void aig_free(AIG* aig) {
  if (aig->ksmt)
    kmst_free(aig->ksmt);
  free(aig);
}
