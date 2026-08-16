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
#include <ctype.h>
#include "private_lexer.h"

static void skipSpaces(Lexer* lexer) {
  while (1) {
    switch (peekChar(lexer)) {
    case '#':
      while (1) {
        char c;
        if ((c = peekChar(lexer)) == '\n' | c == '\0') break;
        moveChar(lexer);
      }
      break;
    case ' ':
    case '\r': // Very uncommon in linux
    case '\t': // Tab character
    case '\n': // Newline character
      moveChar(lexer);
      break;
    default:
      return; // exit if it is un-skipable
    }
  }
}

Token scanToken(Lexer* lexer) {
  skipSpaces(lexer);
  lexer->start = lexer->current;
  char c = peekChar(lexer);

  if (c == '\0') return setupToken(lexer, TOKEN_EOF);
  moveChar(lexer);

  switch (c) {
  case '+':
    return setupToken(lexer, TOKEN_PLUS);
  case '-':
    return setupToken(lexer, TOKEN_MINUS);
  case '*':
    return setupToken(lexer, TOKEN_STAR);
  case '/':
    return setupToken(lexer, TOKEN_DIVIDE);
  case '=':
    return setupToken(lexer, TOKEN_EQUALS);
  case ':':
    return setupToken(lexer, TOKEN_EQUALS);
  default:
    if (isdigit(peekChar(lexer))) {
      return handleNumber(lexer);
    } else if (isalpha(peekChar(lexer))) {
      return handleName(lexer);
    }

    return setupToken(lexer, TOKEN_EOF/*replaced by TOKEN_ERROR later on*/);
  }
}

Lexer initLexer(char* src) {
  Lexer lexer;
  lexer.current = src;
  lexer.start = src;
  return lexer;
}
