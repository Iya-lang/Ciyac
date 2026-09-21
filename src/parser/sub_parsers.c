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
#include <stdbool.h>
#include <stdlib.h>
#include "error/report.h"
#include "parser/ast.h"
#include "parser/parser.h"
#include "private.h"


static NODEType precedence(Parser* parser, TokenType type) {
  switch (type) {
    case TOKEN_MINUS:
    case TOKEN_PLUS:
      moveToken(parser);
      return NODE_ADD;
    case TOKEN_STAR:
    case TOKEN_DIVIDE:
      moveToken(parser);
      return NODE_DIVIDE;
    default:
      return NODE_NUMBER;
  }
}

static NODEType getOPType(Parser* parser, NODEType fallback) {
  switch (parser->previous.type) {
    case TOKEN_MINUS:
      return NODE_SUBTRACT;
    case TOKEN_STAR:
      return NODE_MULTIPLY;
    case TOKEN_NAME:
      return NODE_NAME;
    default:
      return fallback;
  }
}

int parseValue(Parser* parser) {
  int weight = precedence(parser, parser->current.type);
  
  if (weight != NODE_NUMBER) {
    Parser_reportError(parser, "-^", &parser->current, \
      "Expected value after '%.*s'.", \
      parser->previous.length, parser->previous.start);
    return -1;
  }

  NODEType type = getOPType(parser, NODE_NUMBER);

  #define asts parser->ast_pool.ast_list
  #define pool parser->ast_pool
  createNode(parser, type);

  if (type == NODE_NUMBER) {
    createNode(parser, NODE_NUMBER);
    char* endptr;
    asts[pool.count - 1].as.number = strtod(parser->current.start, &endptr);
  } else if (type == NODE_NAME) {
    asts[pool.count - 1].as.string.start = parser->current.start;
    asts[pool.count - 1].as.string.length = parser->current.length;
  }

  moveToken(parser);
  return pool.count - 1;
  #undef pool
  #undef asts
}

int parseExpr/*expression*/(Parser* parser, int min_weight, short op_count) {
  int left = parseValue(parser);
  int last_left = left;

  while (1) {
    Token current_op = parser->current;
    int weight = precedence(parser, parser->current.type);
    NODEType weight_type = getOPType(parser, weight);
    if (weight == NODE_NUMBER) break;
    if (weight < min_weight) {
      break;
    }

    int right = parseExpr(parser, min_weight + 1, op_count++);
    if (right == -1 && parser->had_error) break;
    left = createNode(parser, weight_type);
    parser->ast_pool.ast_list[left].left = last_left;
    parser->ast_pool.ast_list[left].right = right;
  }
  return left;
}

void parseSay(Parser* parser) {
  moveToken(parser);
  parseExpr(parser, 0, 0);

  if (parser->had_error) return;
  createNode(parser, NODE_SAY);
}