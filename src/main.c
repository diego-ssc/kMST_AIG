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
#include <math.h>
#include <string.h>

#include "heuristic.h"

/* Prints the execution intructions of the program. */
static void usage() {
  fprintf(stderr, "Usage:\n\t./kMST_AIG"
          " -f [input file] [options]\n\n");
  fprintf(stderr, "Options:\n"
          "\t-k\n\t\tthe size of minimum spanning tree\n");
  exit(1);
}

/* Parses the arguments passed to the program. */
void parse_arguments(int argc, char** argv) {
  if (argc < 3)
    usage();
  int k = 0, f = 0;
  char c, n[100];
  while (--argc > 0)
    if ((*++argv)[0] == '-')
      while ((c = *++argv[0]))
        switch (c) {
        case 'k':
          k = argc - 1 ? atof(*(argv + 1)) : k;
          break;
        case 'f':
          if (argc - 1)
            strcpy(n, *(argv + 1));
          f++;
          break;
        default:
          fprintf(stderr, "kMST: illegal option %c\n", c);
          argc = 0;
          break;
        }

  if (!k)
    k = 10;
  if (!f)
    usage();
  Input_parser* parser = input_parser_new(n);
  kMST* kmst = kmst_new(parse(parser), k, parser_n(parser), 584);
  AIG* aig = aig_new(kmst, 0.2, 0.2, 100000);
  aig_heuristic(aig);

  Edge* span = kruskal(kmst_tree(kmst));
  double w = 0;
  printf("Span size: %d\n", tree_span_size(kmst_tree(kmst)));
  for (int i = 0; i < tree_span_size(kmst_tree(kmst)); ++i) {
    w += edge_w(edge_array_position(span, i));
    printf("(%s, %s) :: %f\n",
           point_to_string(edge_p(edge_array_position(span, i))),
           point_to_string(edge_q(edge_array_position(span, i))),
           edge_w(edge_array_position(span, i)));
  }
  printf("Cost: %f\n", w);

  free(span);

  aig_free(aig);
  input_parser_free(parser);
}

/* Executes the main thread of the program. */
int main(int argc, char** argv) {
  parse_arguments(argc, argv);
  return 0;
}
