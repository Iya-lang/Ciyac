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
#include <stdio.h>
#include <stdarg.h>
#include "lexer/token.h"
#include "parser/parser.h"
#include "error/report.h"

void Parser_reportError(Parser *parser, char* caret_symbol, Token* token, char *message__format, ...) {

  fprintf(stderr, "[line %d: col %d] Error: ", token->line, token->column);
  va_list args;

  va_start(args, message__format);
  vprintf(message__format, args);
  va_end(args);

  printf("\n%4d | %s\n", token->line, parser->lexer->line_start);
  printf("     |");
  for (int i=0; i<token->column; i++) {
    printf(" ");
  }
  printf("%s", caret_symbol);
  for (int i=1; i<token->length; i++) printf("~");
  printf("\n");

  parser->had_error = true;
  fprintf(stderr, "\nWARNING: all ast nodes are erased!\n");
  free(parser->ast_pool.ast_list);
  // Make sure no other instances accesses the asts even if it's not there
  parser->ast_pool.count = 0;
}