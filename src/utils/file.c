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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser/parser.h"
#include "lexer/lexer.h"
#include "misc/return_vals.h"
#include "utils/file.h"
#include "utils/getline.h"

static FILE* readFile(char* filename) {
  if (strcmp(filename, "--version") == 0) {
    printf("Ciyac v0.2.0-1\n");
    exit(0);
  }
  FILE* file = fopen(filename, "rb");
  if (file == NULL) {
    fprintf(stderr, "MISSING: file '%s' in directory\n", filename);
    exit(IO_ERROR);
  }
  return file;
}

void runFile(char* filename) {
  FILE* file = readFile(filename);
  unsigned int count;
  Lexer lexer = initLexer(getDelim(&count, file, '\0'));
  lexer.start[count] = '\0'; // Null-terminate the string
  fclose(file);
  Parser parser = initParser(&lexer);
  parse(&parser);
}

