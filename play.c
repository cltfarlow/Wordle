#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "CheckWord.h"
#include "Definitions.h"
#include "Input.h"
#include "Output.h"

/*
  File: play.c
  Author: Emilina Salazar
  Debugged: Christopher Farlow, Max Klein
  Assignment: Wordle Project 11/22/2025
  Date: 11/22/2025
  References: notes, google
*/

/* function pre-declaration */
void play_easy(Game *g);
void play_medium(Game *g);
void play_hard(Game *g);
void play_loop(Game *g, int colors[]);

/* 
prints empty game board, then calls play look with game settings and color checking array
play easy function - normal wordle settings
  arguments:
  game *g - struct for game
          g.max_tries = max tires player gets = 5
          g.word_length = guess word length = 6
*/
void play_easy(Game *g)
{
  char line[64];
  int colors_FIVE[5];
  generate_rand_word(g->answer, g->smaller_word_list, SMALLER_FIVE_LETTER_LEN, FIVE);
  printf("\n[Play] Starting game with word length %d and %d max tries.\n",
         g->word_length, g->max_tries);
  
  printf("\n+---+---+---+---+---+\n");
  printf("|   |   |   |   |   |\n");
  printf("+---+---+---+---+---+\n");
  printf("|   |   |   |   |   |\n");
  printf("+---+---+---+---+---+\n");
  printf("|   |   |   |   |   |\n");
  printf("+---+---+---+---+---+\n");
  printf("|   |   |   |   |   |\n");
  printf("+---+---+---+---+---+\n");
  printf("|   |   |   |   |   |\n");
  printf("+---+---+---+---+---+\n");
  printf("|   |   |   |   |   |\n");
  printf("+---+---+---+---+---+\n");
  
  play_loop(g, colors_FIVE);
  
  printf("\nPress Enter to return to the main menu...");
  if (fgets(line, sizeof(line), stdin) == NULL)
  {
  }
}

/* 
prints empty game board, then calls play look with game settings and color checking array
play medium function - normal wordle settings
  8 letter words 6 tries
  arguments:
  game *g - struct for game
          g.max_tries = max tires player gets = 8
          g.word_length = guess word length = 6
*/
void play_medium(Game *g)
{
  char line[64];
  int colors_EIGHT[8];
  generate_rand_word(g->answer, g->word_list, EIGHT_LETTER_LEN, g->word_length);
  printf("\n[Play] Starting game with word length %d and %d max tries.\n",
         g->word_length, g->max_tries);
  printf("\n+---+---+---+---+---+---+---+---+\n");
  printf("|   |   |   |   |   |   |   |   |\n");
  printf("+---+---+---+---+---+---+---+---+\n");
  printf("|   |   |   |   |   |   |   |   |\n");
  printf("+---+---+---+---+---+---+---+---+\n");
  printf("|   |   |   |   |   |   |   |   |\n");
  printf("+---+---+---+---+---+---+---+---+\n");
  printf("|   |   |   |   |   |   |   |   |\n");
  printf("+---+---+---+---+---+---+---+---+\n");
  printf("|   |   |   |   |   |   |   |   |\n");
  printf("+---+---+---+---+---+---+---+---+\n");
  printf("|   |   |   |   |   |   |   |   |\n");
  printf("+---+---+---+---+---+---+---+---+\n");
  printf("|   |   |   |   |   |   |   |   |\n");
  printf("+---+---+---+---+---+---+---+---+\n");
  printf("|   |   |   |   |   |   |   |   |\n");
  printf("+---+---+---+---+---+---+---+---+\n");
  
  play_loop(g, colors_EIGHT);
   
  printf("\nPress Enter to return to the main menu...");
  if (fgets(line, sizeof(line), stdin) == NULL)
  {
  }
}
/* 
prints empty game board, then calls play look with game settings and color checking array
play hard function - normal wordle settings
  10 letter words 10 tries
  arguments:
  game *g - struct for game
          g.max_tries = max tires player gets = 10
          g.word_length = guess word length = 10
*/
void play_hard(Game *g)
{
  char line[64];
  int colors_TEN[10];
  generate_rand_word(g->answer, g->word_list, TEN_LETTER_LEN, g->word_length);
  printf("\n[Play] Starting game with word length %d and %d max tries.\n",
         g->word_length, g->max_tries);
  printf("\n+---+---+---+---+---+---+---+---+---+---+\n");
  printf("|   |   |   |   |   |   |   |   |   |   |\n");
  printf("+---+---+---+---+---+---+---+---+---+---+\n");
  printf("|   |   |   |   |   |   |   |   |   |   |\n");
  printf("+---+---+---+---+---+---+---+---+---+---+\n");
  printf("|   |   |   |   |   |   |   |   |   |   |\n");
  printf("+---+---+---+---+---+---+---+---+---+---+\n");
  printf("|   |   |   |   |   |   |   |   |   |   |\n");
  printf("+---+---+---+---+---+---+---+---+---+---+\n");
  printf("|   |   |   |   |   |   |   |   |   |   |\n");
  printf("+---+---+---+---+---+---+---+---+---+---+\n");
  printf("|   |   |   |   |   |   |   |   |   |   |\n");
  printf("+---+---+---+---+---+---+---+---+---+---+\n");
  printf("|   |   |   |   |   |   |   |   |   |   |\n");
  printf("+---+---+---+---+---+---+---+---+---+---+\n");
  printf("|   |   |   |   |   |   |   |   |   |   |\n");
  printf("+---+---+---+---+---+---+---+---+---+---+\n");
  printf("|   |   |   |   |   |   |   |   |   |   |\n");
  printf("+---+---+---+---+---+---+---+---+---+---+\n");
  printf("|   |   |   |   |   |   |   |   |   |   |\n");
  printf("+---+---+---+---+---+---+---+---+---+---+\n");
  
  play_loop(g, colors_TEN);
  
  printf("\nPress Enter to return to the main menu...");
  if (fgets(line, sizeof(line), stdin) == NULL)
  {
  }
}


/* 
play loop - takes in guess, loops through for all tries, prints guess to board
arguments:
game *g - struct for game
          g.max_tries = max tires player gets
          g.word_length = guess word length
int color - color array
            used to determine the background color for letters in the guess
            0 = gray = wrong letter
            1 = orange = right letter wrong spot
            2 = green = right letter right spot
*/
void play_loop(Game *g, int colors[])
{
  char guess[50];
  char board[10][50]; 
  int color_board[10][50];
  int attempt;
  int i, k;

  for (i = 0; i < g->max_tries; i++)
  {
    board[i][0] = '\0';
    for (k = 0; k < g->word_length; k++)
      {
        color_board[i][k] = -1;
      }
  } /*initilized board with empty guesses*/

  for (attempt = 0; attempt < g->max_tries; attempt++)
  {
    read_attempt(guess, g->word_length, g->word_list);
    if (guess[0] == '\0')
    {
      break; 
    } 
    
    
    
    strcpy(board[attempt], guess); 
    /*store guess*/
    {
      char empty[50];
      int k;
      
      for (k = 0; k < g->word_length; k++)
      {
        empty[k] = ' ';
      }
      empty[g->word_length] = '\0';
      check_letter(guess, color_board[attempt], g->answer, g->word_length); 
      print_sep(g->word_length); 
      for (i = 0; i < g->max_tries; i++)
      {
        if (board[i][0] != '\0')
        {
          print_guess_row(board[i], color_board[i], g->word_length);
        }
        else
        {
          print_guess_row(empty, color_board[i], g->word_length); 
        } /* print rows unused guesses*/
        print_sep(g->word_length);
      }
      if (strcmp(g->answer, guess) == 0)
      {
        printf("\ncongragulations you won!");
        return; 
      } /* if player guesses correct guess end game and tell them they won */
    }
  }
  if (strcmp(guess, g->answer) != 0)
  {
    printf("\nNo more tries left. You lost.");
    printf("\nThe answer was: %s.", g->answer);
  } /* if player runs out of guesses and got answer wrong tell them they lost */ 
}










