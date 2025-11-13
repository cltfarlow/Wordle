#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "functions.h"

/*
  File: win.c
  Author: Emilina Salazar
  Assignment: Wordle Project 11/22/2025
  Date: 11/22/2025
  References: notes, google
*/

int main(char *ans, char *guess)
{
  int win = 0;
  if (strcmp(ans, guess) == 0)
  {
    printf("\ncongragulations you won!");
    win = 1;
    return win;
  }
  else 
  {
    return win;
  }
}