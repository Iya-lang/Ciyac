/*
Ciya: a future programming language VM that is hoped to be a bigger leap than the successor, "CRy"
    Copyright (C) 2026  Johnryzon Z. Abejero, Nguyễn Phước Thành Lâm

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/
#ifndef INCLUDE_PARSER_AST_H
#define INCLUDE_PARSER_AST_H

typedef enum NODEType {
  NODE_ADD,
  NODE_SUBTRACT,
  NODE_MULTIPLY,
  NODE_DIVIDE,

  NODE_ASSIGN,

  NODE_NUMBER,
  NODE_NAME,

  NODE_SAY,
} NODEType;


typedef struct AST {
  NODEType type;
  union {
    struct {
      char* start; unsined int legth;
    } string;
    double number;
  } as;
} AST;

typedef struct ASTPool {
  AST* ast_list;
  unsigned int count;
  unsigned int capacity;
} ASTPool;

#endif

