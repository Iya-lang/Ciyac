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
#include <stdio.h>
#include <stdlib.h>
#include "misc/debug.h"
#include "lexer/lexer.h"
#include "lexer/token.h"
#include "parser/parser.h"
#include "parser/ast.h"
#include "private.h"

Token moveToken(Parser* parser) {
  if (parser->current.type == TOKEN_NONE) {
    parser->current = scanToken(parser->lexer);
    parser->next = scanToken(parser->lexer);

    if (parser->lexer->token_debug == true)
      printToken(&parser->current);
    return parser->current; //Will exit for error works
  }

  parser->previous = parser->current;
  parser->current = parser->next;
  parser->next = scanToken(parser->lexer);
  if (parser->lexer->token_debug == true)
    printToken(&parser->current);
  return parser->current;
}

void error(Parser* parser, const char* message, Token* token) {
  parser->had_error = true; // for got line handling in parser
  fprintf(stderr, "[line %d] Error at '%.*s': %s\n", token->line, token->length, token->start, message);
  const char* line_end = token->start;
  while (*line_end != '\n' && *line_end != '\0') {
    line_end++;
  }
  int line_length = line_end - parser->lexer->line_start;
  printf("%4d| %.*s\n", token->line, line_length, parser->lexer->line_start);
  printf("    | ");
  for (unsigned int i = 1; i < token->column; i++) {
    printf(" ");
  }
  printf("^\n");
}

void resizeASTPool(Parser* parser) {
  parser->ast_pool.capacity *= 2;
  parser->ast_pool.ast_list = realloc(parser->ast_pool.ast_list, sizeof(AST) * parser->ast_pool.capacity);
  if (parser->ast_pool.ast_list == NULL)
    error(parser, "Failed to resize AST pool", &parser->previous);
}

void createNode(Parser* parser, NODEType type) {
  if (parser->ast_pool.count >= parser->ast_pool.capacity) {
    resizeASTPool(parser);
  }

  AST* node = &parser->ast_pool.ast_list[parser->ast_pool.count++];
  node->type = type;
}