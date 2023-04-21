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

#include <stdio.h>
#include <stdlib.h>

#include "heuristic.h"

/* Prints the execution intructions of the program. */
static void usage() {
  fprintf(stderr, "Usage:\n\t./kMST_AIG [aig-parameters]"
          " [input file] [options]\n\n");
  exit(1);
}

/* Executes the main thread of the program. */
int main(int argc, char** argv) {
  if (argc == 1)
    usage();
  Input_parser* parser = input_parser_new(*(argv+1));
  Point** points = parse(parser);
  Edge* edges = kruskal(points, 149);
  /* for (int i = 0; i < ) */
  return 0;
}
