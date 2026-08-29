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
// This header will hold the token types enumeration
#ifndef INCLUDE_LEXER_TOKEN_TYPE_H
#define INCLUDE_LEXER_TOKEN_TYPE_H

typedef enum TokenType {
  // What token types do you want?
  // i'll start with these
  // Operators
  TOKEN_PLUS, // +
  TOKEN_MINUS, // -
  TOKEN_STAR, // *
  TOKEN_DIVIDE, // /

  TOKEN_EQUALS, // =
  TOKEN_COLON, // :

  // Literals
  TOKEN_NUMBER, // like 123
  TOKEN_NAME/*or identifier*/,

  // keywords
  TOKEN_SAY,

  // Misc/others
  TOKEN_EOF // End of file
} TokenType;

#endif
