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
#include <string.h>
#include <stdlib.h>
#include <stdio.h> //For printf()
#include "lexer/lexer.h"
#include "misc/return_vals.h"
#include "utils/repl.h"
#include "utils/file.h"

bool checkFlags(char* argv[], Lexer* lexer) {
  // argc is already handled in main
  char* arg = argv[1];
  bool isFlag = true;
  if (arg[0] == '-' && arg[0] == '-') {
    if (strcmp(arg, "--debug-tokens") == 0) {
      lexer->token_debug = true; 
    } else {
      isFlag = false;
    }
  } else
    isFlag = false;

  return isFlag;
}

// since you have custom return values then I'm making them, should we write the return in the docs
int main(int argc, char* argv[]) {
  Lexer lexer;
  lexer.token_debug = false;

  if (argc > 2) {
    fprintf(stderr, "USAGE: %s <command>\n", argv[0]);
    return IO_ERROR;
  } else if (argc == 2) {
    if (!checkFlags(argv, &lexer)) {
      runFile(argv[1], &lexer);
      return EXIT_SUCCESS;
    }
  }

  REPL(argv, &lexer);
  return EXIT_SUCCESS;
}
