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
#ifndef SRC_LEXER_PRIVATE_LEXER_H
#define SRC_LEXER_PRIVATE_LEXER_H
#include "lexer/token.h"
#include "lexer/lexer.h"

// We put private and non-global lexer functions and objects here
char peekChar(Lexer* lexer); // This function returns the current character
char moveChar(Lexer* lexer); // Moves to the next character

// Sets up the token for use in the parser
Token setupToken(Lexer* lexer, TokenType type);

// These functions will handle token making for literals like numbers
Token handleNumber(Lexer* lexer);
Token handleName(Lexer* lexer);

#endif
