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
#include "utils/getline.h"
#include "misc/return_vals.h"
#define STARTING_INPUT_SIZE 15

char* getDelim(unsigned int* count, FILE* stream, char delim) {
  int/*char*/ c; // This will store the current character in the input buffer
  char* input; // input string
  unsigned int capacity = STARTING_INPUT_SIZE;
  *count = 0;

  input = malloc(sizeof(char) * capacity);
  // It is a good habit to check if malloc returned NULL
  if (input == NULL) {
    exit(EXIT_FAILURE); // just exit
  }

  // get every character in the input stream until the end
  while ((c = getc(stream)) != delim && c != EOF) {
    if (count == NULL) {
      fprintf(stderr, "VM BUG: count is NULL; from getline\n");
      exit(BUG_ERROR);
    }
    // To make the dynamic input-er work, we resize capacity when the character count is over capacity
    if ((*count) >= capacity) {
      input = realloc(input, capacity *= 2);
    }

    // We then write the character into the input string
    input[(*count)++] = c;
  }
  return input; // return it
}

// getLine: This function will "infinitely" take input from the user
char* getLine(unsigned int* count, FILE* stream) {
  return getDelim(count, stream, '\n');
}
