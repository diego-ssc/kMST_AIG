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

#pragma once

#include <stdlib.h>
#include <math.h>

/**
 * Creates a new Algorithm of the Innovative Gunner Heuristic.
 * @param ksmt the kMST instance.
 * @param a_max the first maximum angle.
 * @param b_max the first maximum angle.
 * @param epsilon the epsilon parameter.
 * @param diameter the variable to optimize.
 */
AIG* aig_new(kMST* kmst, long double a_max, long double b_max,
             long epsilon, long diameter);

/**
 * Frees the memory used by the Algorithm of the Innovative Gunner.
 * @param aig the heuristic to be freed.
 */
void aig_free(AIG* aig);

/**
 * Computes the circle.
 * @param aig the heuristic.
 * @return the initial circle.
 */
Circle* aig_circle(AIG* aig);

/**
 * Begins the execution of the heuristic.
 * @param aig the heuristic.
 */
void aig(AIG* aig);

/**
 * Creates the point array of the problem instance.
 * @param aig the heuristic.
 * @return the point array.
 */
Point** aig_array(AIG* aig);
