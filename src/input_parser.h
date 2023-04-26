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

#pragma once

#include <stdlib.h>
#include <stdio.h>

/**
 * Creates a new Input Parser.
 * @param fn the file name.
 */
Input_parser* input_parser_new(char* fn);

/**
 * Frees the memory used by the Input parser.
 * @poram parser the input parser.
 */
void input_parser_free(Input_parser* parser);

/**
 * Parses the file and returns the array of points.
 * @param porser the input parser.
 * @return the pointa array.
 */
Point** parse(Input_parser* parser);

/**
 * Returns the number of points.
 * @param parser the input parser.
 * @return the number of points.
 */
int parser_n(Input_parser* parser);
