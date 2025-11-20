#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "play.h"
/*
  File: Menu.c
  Author: Emilina Salazar
  Assignment: Wordle Project 11/22/2025
  Date: 11/22/2025
  References: notes, google
*/

void title();
void rules(Game *g);

int main()
{
  Game g;
  int difficulty = 1; /*default*/
  g.word_length = 5;
  g.max_tries = 6;
  int running = 1;
  title();
  initArray(g.smaller_word_list, SMALLER_FIVE_LETTER_LEN, FIVE);
  
  while (running)
  {
    int choice;
    printf("\n=========== MAIN  MENU ===========\n");
    printf(" 1) Play\n");
    printf(" 2) Rules\n");
    printf(" 3) Change difficulty\n");
    printf(" 4) Quit\n");
    printf("==================================\n");
    choice = get_int_choice("> ", 1, 4);

    if (choice == 1)
    {
      switch (difficulty)
      {
        case 1: 
        {
          g.word_length = FIVE; 
          g.max_tries = 6;
          if(initArray(g.word_list, FIVE_LETTER_LEN, FIVE)) return 1;
          play_easy(&g);
          break;
        } case 2:
        {
          g.word_length = 8; 
          g.max_tries = 6;
          if(initArray(g.word_list, EIGHT_LETTER_LEN, EIGHT)) return 1;
          play_medium(&g);
          break;
        } case 3:
        {
          g.word_length = 10; 
          g.max_tries = 6;
          if(initArray(g.word_list, TEN_LETTER_LEN, TEN)) return 1;
          play_hard(&g);
          break;
        }
      }
    }
    else if (choice == 2)
    {
      rules(&g);
    }
    else if (choice == 3)
    {
      difficulty = get_int_choice(
          "\nChoose difficulty:\n  1: Easy - 5 letter words with 6 tries\n  2: Medium - 8 letter word with 6 tires\n  3: Hard - 10 letter word with 6 tries\n> ",
          1, 3);
      printf("\nDifficulty set: word length = %d, max tries = %d\n",
             g.word_length, g.max_tries);
    }
    else
    {
      printf("\nGoodbye!\n");
      running = 0;
    }
  }
  return 0;
}

void title()
{
  printf("\n==================================");
  printf("\n              WORDLE              ");
  printf("\n==================================\n");
}

void rules(Game *g)
{
  char line[8];
  printf("\nHow to play Wordle by the Embry-Riddle Times:\n");
  printf(" 1. Type a guess and press Enter.\n");
  printf(" 2. Guess the hidden word in %d tries or fewer.\n", g->max_tries);
  printf(" 3. Each guess must be a valid English word that is %d letters long.\n", g->word_length);
  printf(" 4. Correct letters in the correct spot appear as GREEN.\n");
  printf(" 5. Correct letters in the wrong spot appear as ORANGE.\n");
  printf(" 6. Incorrect letters remain WHITE.\n");
  printf("\nPress Enter to return to the main menu...");
  if (fgets(line, sizeof(line), stdin) == NULL)
  {
  }
}