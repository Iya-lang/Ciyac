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
#include "lexer/lexer.h"
#include "lexer/token.h"
#include <string.h>
#include "utils/repl.h"
#include "utils/getline.h"
#include "misc/platform.h"

static void debugToken(Token* token) {
  printf("==== Token ====\n");
  printf("Type: %d\n", token->type); // Note: This will print 9 for everything except for +.
  printf("Lexeme: %.*s\n\n", token->length, token->start);
}

static void run(Token token) {
  debugToken(&token);
}

// See meaning on "utils/repl.h"
void REPL(char* argv[]) {
  printf("Ciya v0.0.2 interactive REPL\n");
  // Following GNU rights
  printf("Copyright (C) 2026  Johnryzon Z. Abejero, Nguyễn Phước Thành Lâm\n");
  printf("License GPLv2: GNU GPL version 2 <http://gnu.org/licenses/gpl.html>\n");
  printf("This is entirely free software: you are free to modify and redistribute it.\n");
  printf("There is NO WARRANTY, by the law of the GPL.\n\n");

  printf("Note: Type '.help' to view the current commands\n");
  while (1) {
    // An repl uses an "infinite" number of chars in input which means that NO LIMIT
    // to achieve this, I'll make a custom version of getline().
    printf(">>> "); // print the starting thing
    unsigned int count = 0;
    char* input = getLine(&count, stdin); // in here, we use a pointer to make it dynamically expandable
    input[count] = '\0'; // Manually put the null terminator
    Lexer lexer;
    if (strcmp(input, ".exit") == 0){
      printf("Exiting...\n");
      free(input);
      input = NULL;
      return;
    } else if (strcmp(input, ".linktosource") == 0){
      printf("link: https://github.com/johnryzon123/Ciya.git\n");

      #if defined(PLATFORM_LINUX)
      system("xdg-open https://github.com/johnryzon123/Ciya.git");
      #elif defined(PLATFORM_MACOS)
      system("open https://github.com/johnryzon123/Ciya.git");
      #elif defined(PLATFORM_WINDOWS)
      system("start https://github.com/johnryzon123/Ciya.git");
      #endif
      free(input);
      input = NULL;
    } else if (strcmp(input, ".freemem") == 0){
      free(input);
      input = NULL;
      printf("Memory free!\n");
    } else if (strcmp(input, ".websource") == 0){
      printf("link: https://github.com/Ciya-VM/Ciya-VM.github.io.git\n");

      #if defined(PLATFORM_LINUX)
      system("xdg-open https://github.com/Ciya-VM/Ciya-VM.github.io.git");
      #elif defined(PLATFORM_MACOS)
      system("open https://github.com/Ciya-VM/Ciya-VM.github.io.git");
      #elif defined(PLATFORM_WINDOWS)
      system("start https://github.com/Ciya-VM/Ciya-VM.github.io.git");
      #endif
      free(input);
      input = NULL;
    } else if (strcmp(input, ".help") == 0){
      printf("USAGE: %s <args (developing; not supported)>\n", argv[0]);
      printf("Commands: .help, .linktosource, .websource, .freemem, .exit\n");
      free(input);
      input = NULL;
    } else{
      lexer = initLexer(input);
      run(scanToken(&lexer));
    }
    free(input);
    input = NULL;
  }
}
