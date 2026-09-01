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
#include "parser/ast.h"
#include "lexer/token.h"
#include "misc/debug.h"

void printAST(ASTPool pool) {
  for (int i=0; i!=pool.count; i++) {
    printf("====%d NODE====\n", i);
    printf("Type: %d\n", pool.ast_list[i].type);
    printf("Left Index: %d\n", pool.ast_list[i].left);
    printf("Right Index: %d\n", pool.ast_list[i].right);
    printf("Number: %g\n", pool.ast_list[i].as.number);
    printf("String/Name: %.*s\n", pool.ast_list[i].as.string.length, pool.ast_list[i].as.string.start);
    printf("\n");
  }

  printf("====%d NODE ====\n", pool.count);
  printf("Type: %d\n", pool.ast_list[pool.count].type);
  printf("Left Index: %d\n", pool.ast_list[pool.count].left);
  printf("Right Index: %d\n", pool.ast_list[pool.count].right);
  printf("Number: %g\n", pool.ast_list[pool.count].as.number);
  printf("String/Name: %.*s\n", pool.ast_list[pool.count].as.string.length, pool.ast_list[pool.count].as.string.start);
  printf("\n");

}
void printToken(Token* token) {
  printf("==== Token ====\n");
  printf("Type: %d\n", token->type); // Note: This will print the token's type in digits
  printf("Lexeme: %.*s\n\n", token->length, token->start);
}