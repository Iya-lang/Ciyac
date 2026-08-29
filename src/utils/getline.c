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
#define STARTING_INPUT_SIZE 15

// getLine: This function will "infinitely" take input from the user
/*
 It needs all of these mentioned:
 * The input variable: The function will dynamically increase this string's size
 * A current character variable: This tracks the current character in the input buffer
 * Capacity: The total size of the string, will increase if count reaches the string's size
 * Count: By the name, it will count how many characters has already been processed

 The function works like this:
  1) It firstly allocates a specific size in the heap
  2) Check if there are no more space in ram
  3) Loop through all characters in the input stream:
    1. Double the size of the string when the character count exeeds the string's size
    2. Save the character into the string and add 1 to the count
  4) Add a null terminator at the end of the string
  5) Return the string.
*/
char* getLine() {
  int/*char*/ c; // This will store the current character in the input buffer
  char* input; // input string
  unsigned int capacity = STARTING_INPUT_SIZE;
  unsigned int count = 0;

  input = malloc(sizeof(char) * capacity);
  // It is a good habit to check if malloc returned NULL
  if (input == NULL) {
    exit(EXIT_FAILURE); // just exit
  }

  // get every character in the input stream until the end
  while ((c = getchar()) != '\n' && c != EOF) {
    // To make the dynamic input-er work, we resize capacity when the character count is over capacity
    if (count >= capacity) {
      input = realloc(input, capacity *= 2);
    }

    // We then write the character into the input string
    input[count++] = c;
  }
  input[count] = '\0'; // we must always put a null terminator at the end of each string
  return input; // return it
  
}
