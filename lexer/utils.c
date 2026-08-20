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

#include "private_lexer.h"

// chars:
// Returns the current character; used as an "alias"
char peekChar(Lexer* lexer) {
  return *(lexer->current);
} // peekChar

// The function of this is to move to the next character
char moveChar(Lexer* lexer) {
  // Tip: ++ doesn't just add 1, it adds 1 then returns the previous unchanged value
  return *(lexer->current++);
} // moveChar

// tokens:
// The `setupToken` function sets a token with information
Token setupToken(Lexer* lexer, TokenType type) {
  Token token; // Be careful not to change `Token* token`
  token.start = lexer->start;
  // To calculate the length of the token, we subtract current and start
  // * Don't ever flip the 2 variable placements, it would cause in negative values.
  token.length = (unsigned int)(lexer->current - lexer->start);
  token.type = type;

  // Synchronize start to the current character for the next token.
  lexer->start = lexer->current; // we don't want infinite loop bugs
  return token;
}
