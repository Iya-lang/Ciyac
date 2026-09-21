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
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "misc/debug.h"
#include "parser/parser.h"
#include "lexer/lexer.h"
#include "utils/repl.h" 
#include "utils/getline.h"

static void run(Lexer* lexer) {
  Parser parser = initParser(lexer);
  parse(&parser);
  printAST(parser.ast_pool);
}

static void printREPLHead() {
  printf("Ciya v0.0.2 interactive REPL\n");
  // Following GNU rights
  printf("Copyright (C) 2026  Johnryzon Z. Abejero, Nguyễn Phước Thành Lâm\n");
  printf("Info: \n\
  > https://github.com/Iya-lang/Ciyac\n\
  > https://iya-lang.github.io\n\
  > https://github.com/Iya-lang/Ciya\n\n");

  printf("License GPLv2: GNU GPL version 2 <http://gnu.org/licenses/gpl.html>\n");
  printf("This is entirely free software: you are free to modify and redistribute it.\n");
  printf("There is NO WARRANTY, by the law of the GPL.\n\n");

  printf("Note: Type '.help' to view the current commands\n");
}

static void handleCommands(char* exec_name, char* input, Lexer* lexer) {
  if (*input == '.') {
    input += 1; // skip past the '.'
    if (strcmp(input, "exit") == 0){
      printf("Exiting...\n");
      free(input -= 1);
      input = NULL;
      exit(EXIT_SUCCESS);
    } else if (strcmp(input, "help") == 0){
      
      printf("USAGE: %s <file>\n", exec_name);
      printf("Commands: .help, .linktosource, .websource, .metasource, .freemem, .exit\n");
    }
  } else{
    initLexer(input, lexer);
    run(lexer);
  }
  input -= 1;
}

// See meaning on "utils/repl.h"
void REPL(char* argv[], Lexer* lexer) {
  printREPLHead();
  while (1) {
    printf(">>> "); // print the starting thing
    unsigned int count = 0;
    char* input = getLine(&count, stdin); // in here, we use a pointer to make it dynamically expandable
    input[count] = '\0'; // Manually put the null terminator
    handleCommands(argv[0], input, lexer);
    free(input);
    input = NULL;
  }
}