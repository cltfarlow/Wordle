#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "CheckWord.h"
#include "colors.h"
#include "Input.h"

/*
  File: Menu.c
  Author: Emilina Salazar
  Assignment: Wordle Project 11/22/2025
  Date: 11/22/2025
  References: notes, google
*/

typedef struct
{
  int word_length;
  int max_tries;
  char answer[TEN+1];
  char word_list[EIGHT_LETTER_LEN*TEN];
} Game;

void play_easy(Game *g);
void play_medium(Game *g);
void play_hard(Game *g);
void play_loop(Game *g, int colors[]);
void print_sep(Game *g);
void print_guess_row(char *guess, int colors[], Game *g);
void print_color(int colors[], char guess[], Game *g);
void uppercase(char *s);
int all_letters(char *s);
void clear_line();
int  get_int_choice(char *prompt, int min_val, int max_val);

void play_easy(Game *g)
{
  char line[64];
  int colors_FIVE[5];
  int row = g->word_length;
  int col = g->max_tries;
  char tempArr[SMALLER_FIVE_LETTER_LEN*FIVE];
  initArray(tempArr, SMALLER_FIVE_LETTER_LEN, FIVE);
  generateRandWord(g->answer, tempArr, SMALLER_FIVE_LETTER_LEN, FIVE);
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
  
  play_loop(g, colors_FIVE);
  
  printf("\nPress Enter to return to the main menu...");
  if (fgets(line, sizeof(line), stdin) == NULL)
  {
  }
}


void play_medium(Game *g)
{
  char line[64];
  int colors_EIGHT[8];
  int row = g->word_length;
  int col = g->max_tries;
  generateRandWord(g->answer, g->word_list, EIGHT_LETTER_LEN, g->word_length);
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
  
  play_loop(g, colors_EIGHT);
   
  printf("\nPress Enter to return to the main menu...");
  if (fgets(line, sizeof(line), stdin) == NULL)
  {
  }
}

void play_hard(Game *g)
{
  char line[64];
  int colors_TEN[10];
  int row = g->word_length;
  int col = g->max_tries;
  generateRandWord(g->answer, g->word_list, TEN_LETTER_LEN, g->word_length);
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
  
  play_loop(g, colors_TEN);
  
  printf("\nPress Enter to return to the main menu...");
  if (fgets(line, sizeof(line), stdin) == NULL)
  {
  }
}

void play_loop(Game *g, int colors[])
{
  char guess[50];
  char board[10][50]; 
  int color_board[10][50];
  int attempt;
  int i, k;

  printf("Answer in play: %s\n", g->answer); /*debug*/
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
      print_sep(g);
      for (i = 0; i < g->max_tries; i++)
      {
        if (board[i][0] != '\0')
        {
          print_guess_row(board[i], color_board[i], g);
        }
        else
        {
          print_guess_row(empty, color_board[i], g); 
        } /* print empty rows*/
        print_sep(g);
      }
      if (strcmp(g->answer, guess) == 0)
      {
        printf("\ncongragulations you won!");
        return; 
      }
  }
}
}



void print_sep(Game *g)
{
  int i;
  int n = g->word_length;

  putchar('\n');
  for (i = 0; i < n; i++)
  {
    printf("+---");
  }
  printf("+\n");
}

void print_guess_row(char *guess, int colors[], Game *g)
{
  int i;
  int n = g->word_length;

  printf("|");
  for (i = 0; i < n; i++)
  {
    char ch;

    if (guess[i] != '\0')
    {
      ch = guess[i];
    }
    else
    {
      ch = ' ';
    }

    ch = (char)toupper((unsigned char)ch);
    /*print_color2(colors, guess);*/
    switch (colors[i])
    {
    case 0:
      printf(GREY_BG WHITE_TXT BOLD_TXT " %c " RESET, ch);
      break;
    case 1:
      printf(YELLOW_BG WHITE_TXT BOLD_TXT " %c " RESET, ch);
      break;
    case 2:
      printf(GREEN_BG WHITE_TXT BOLD_TXT " %c " RESET, ch);
      break;
    default:
      /*fall back to no color if colors[i] is something else*/
      printf(" %c ", ch);
      break;
    }

    printf("|");
  }
  printf("\n");
}

void print_color(int colors[], char guess[], Game *g)
{
  print_sep(g);
  print_guess_row(guess, colors, g);
}






void clear_line()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
  {
  }
}




