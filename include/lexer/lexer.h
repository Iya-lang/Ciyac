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
#ifndef INCLUDE_LEXER_LEXER_H
#define INCLUDE_LEXER_LEXER_H
#include <stdbool.h>
#include "token.h"

// This will hold the lexer's important values that need to be passed around
typedef struct Lexer {
  char* line_start; // this will hold the starting string address of the current line
  char* start; // this will hold the starting string address of the current token
  char* current; // traces the current character to the end
  unsigned int line;
  unsigned int column;
  bool token_debug;
} Lexer;

// scanToken scans 1 token only, it groups a chunk of characters into easy spotting labeled structures
Token scanToken(Lexer* lexer); // it passes the lexer struct around to keep the same values
// This function initializes the lexer for use
void initLexer(char* src, Lexer* lexer);
#endif
