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

/**
 * Creates a new edge.
 * @param p the first point.
 * @param q the second point.
 * @param w the weight.
 */
Edge* edge_new(Point* p, Point* q, double w);

/**
 * Frees the memory used by the Edge.
 * @param edge the edge.
 */
void edge_free(Edge* edge);

/**
 * Compares two edges.
 * @param a the first edge.
 * @param b the first edge.
 * @return 0, if the first edge is greater than
 * the secons; 1, otherwise.
 */
int edge_compare(const void* a, const void* b);

/**
 * Returns an edge array.
 * @param n the number of edges.
 * @return the edge array.
 */
Edge* edge_array(int n);

/**
 * Returns the i-th position of the edge array.
 * @param edge the edge.
 * @param i the position.
 * @return the i-th element.
 */
Edge* edge_array_position(Edge* edge, int i);

/**
 * Sets the i-th position of the edge array.
 * @param edge the edge.
 * @param i the position.
 * @param e the new edge.
 */
void edge_set_array_position(Edge* edge, int i, Edge* e);

/**
 * Returns the first point.
 * @param the edge.
 * @return the first point.
 */
Point* edge_p(Edge* edge);

/**
 * Returns the second point.
 * @param the edge.
 * @return the second point.
 */
Point* edge_q(Edge* edge);

/**
 * Returns the weight.
 * @param the edge.
 * @return the weight.
 */
double edge_w(Edge* edge);

/**
 * Sets the first point.
 * @param edge the edge.
 * @param p the first point.
 */
void edge_set_p(Edge* edge, Point* p);

/**
 * Sets the second point.
 * @param edge the edge.
 * @param q the second point.
 */
void edge_set_q(Edge* edge, Point* q);

/**
 * Sets the weight.
 * @param edge the edge.
 * @param w the weight.
 */
void edge_set_w(Edge* edge, double w);

/**
 * Returns the first identifier.
 * @param edge the edge.
 * @return the first identifier.
 */
int edge_i(Edge* edge);

/**
 * Returns the second identifier.
 * @param edge the edge.
 * @return the second identifier.
 */
int edge_j(Edge* edge);

/**
 * Sets the first identifier.
 * @param edge the edge.
 * @param i the first indentifier.
 */
void edge_set_i(Edge* edge, int i);

/**
 * Sets the second identifier.
 * @param edge the edge.
 * @param j the second indentifier.
 */
void edge_set_j(Edge* edge, int j);

/**
 * Returns the size of an edge.
 * @return the size.
 */
size_t edge_size();

/**
 * Computes the evaluation of a an array of edges
 * @param edges the edges.
 * @param n the number of edges.
 * @return the evaluation.
 */
double eval_edge_array(Edge* edges, int n);

/**
 * Returns the string representation of an edge.
 * @param edge the edge.
 * @return the string representation.
 */
char* edge_to_string(Edge* edge);

/**
 * Copies the given edge.
 * @param edge the edge.
 * @return the copy.
 */
Edge* edge_copy(Edge* edge);
