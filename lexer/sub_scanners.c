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
#include <ctype.h>
#include "private_lexer.h"

Token handleNumber(Lexer* lexer) {
  while (isdigit(peekChar(lexer))) {
    moveChar(lexer);
  }

  return setupToken(lexer, TOKEN_NUMBER);
}

Token handleName(Lexer* lexer) {
  char c;
  while (isalnum(c = peekChar(lexer)) || c == '_') {
    moveChar(lexer);
  }

  return setupToken(lexer, TOKEN_NAME);
}
