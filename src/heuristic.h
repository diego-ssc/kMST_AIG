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

/**
 * The Point opaque structure.
 */
typedef struct _Point Point;

/**
 * The Input Parser opaque structure.
 */
typedef struct _Input_parser Input_parser;

/**
 * The AIG opaque structure.
 */
typedef struct _AIG AIG;

/**
 * The kMST opaque structure.
 */
typedef struct _kMST kMST;

/**
 * The Tree opaque structure.
 */
typedef struct _Tree Tree;

/**
 * The Circle opaque structure.
 */
typedef struct _Circle Circle;

/**
 * The Edge opaque structure.
 */
typedef struct _Edge Edge;

#include "edge.h"
#include "point.h"
#include "input_parser.h"
#include "tree.h"
#include "kmst.h"
#include "aig.h"
#include "circle.h"
