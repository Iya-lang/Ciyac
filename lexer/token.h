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

// Header guards
#ifndef INCLUDE_LEXER_TOKEN_H
#define INCLUDE_LEXER_TOKEN_H
#include "tokentype.h"

// this looks enough
// This struct will hold the token information
typedef struct Token {
  //wait, let's sort it in deccending form to save memory
  // start of the token
  char* start; // a pointer=8 bytes
  // this variable holds the length of the token(useful in debugging/error reporting)
  unsigned int length; // int is usually 4 bytes
  // acts as a label in the token
  TokenType type; // an enum is just the same as int in runtime
} Token; // A token is a temporary part of a programming language
         // that contains nessesary information about the source code
// ok bye now! i'm sleeping

#endif
