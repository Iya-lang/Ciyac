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
#include <stdlib.h>
#include "misc/debug.h"
#include "lexer/lexer.h"
#include "parser/parser.h"
#include "private.h"

Parser initParser(Lexer* lexer) {
  Parser parser;
  parser.lexer = lexer;
  parser.lexer->line_start = parser.lexer->start;
  parser.previous.type = TOKEN_NONE;
  parser.current.type = TOKEN_NONE;
  parser.next.type = TOKEN_NONE;

  parser.ast_pool.capacity = 15;
  parser.ast_pool.count = 0;
  parser.ast_pool.ast_list = malloc(sizeof(AST) * parser.ast_pool.capacity);
  return parser;
}

void parse(Parser* parser) {
  while (moveToken(parser).type != TOKEN_EOF) {
    if (parser->had_error) {
      parser->had_error = false; // reset the error flag for the next
      break; // This should be enough
    }
    
    switch (parser->current.type) {
      case TOKEN_NUMBER:
      case TOKEN_NAME:
        parseExpr(parser);
        break;
      case TOKEN_SAY:
        parseSay(parser);
        break;
      default:
        moveToken(parser);
        error(parser, "Unexpected token", &parser->previous);
        break;
    }
  }
}
