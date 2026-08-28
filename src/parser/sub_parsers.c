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

#include "parser/parser.h"
#include "private.h"

void parseValue(Parser* parser) {
  #define TYPE parser->current.type
  if (TYPE != TOKEN_NUMBER && TYPE != TOKEN_NAME) {
    error(parser, "Expected a value");
    return;
  }

  if (parser->current.type == TOKEN_NUMBER) {
    createNode(parser, NODE_NUMBER);
  } else if (parser->current.type == TOKEN_NAME) {
    createNode(parser, NODE_NAME);
  }
  #undef TYPE
}

void parseExpr/*expression*/(Parser* parser) {
  while (1) {
    parseValue(parser);
    switch (parser->current.type) {
      case TOKEN_PLUS:
        moveToken(parser);
        createNode(parser, NODE_ADD);
        break;
      case TOKEN_MINUS:
        moveToken(parser);
        createNode(parser, NODE_SUBTRACT);
        break;
      case TOKEN_STAR:
        moveToken(parser);
        createNode(parser, NODE_MULTIPLY);
        break;
      case TOKEN_DIVIDE:
        moveToken(parser);
        createNode(parser, NODE_DIVIDE);
        break;
      default:
        return;
    }
  }
}

void parseSay(Parser* parser) {
  moveToken(parser);
  parseExpr(parser);
  createNode(parser, NODE_SAY);
}