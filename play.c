#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "CheckWord.h"
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

void title();
void rules(Game *g);
void play_easy(Game *g);
void play_medium(Game *g);
void play_hard(Game *g);
void play_loop(Game *g);
void read_attempt(char *guess, Game *g);
void print_sep(Game *g);
void print_guess_row(char *guess, int colors[], Game *g);
void print_color(int colors[], char guess[], Game *g);
void uppercase(char *s);
int all_letters(char *s);
void clear_line();
int  get_int_choice(char *prompt, int min_val, int max_val);

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

void play_easy(Game *g)
{
  char line[64];
  int row = g->word_length;
  int col = g->max_tries;
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
  
  play_loop(g);
  
  printf("\nPress Enter to return to the main menu...");
  if (fgets(line, sizeof(line), stdin) == NULL)
  {
  }
}


void play_medium(Game *g)
{
  char line[64];
  int row = g->word_length;
  int col = g->max_tries;
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
  
  play_loop(g);
   
  printf("\nPress Enter to return to the main menu...");
  if (fgets(line, sizeof(line), stdin) == NULL)
  {
  }
}

void play_hard(Game *g)
{
  char line[64];
  int row = g->word_length;
  int col = g->max_tries;
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
  
  play_loop(g);
  
  printf("\nPress Enter to return to the main menu...");
  if (fgets(line, sizeof(line), stdin) == NULL)
  {
  }
}

void play_loop(Game *g)
{
  char guess[50];
  char board[10][50]; 
  int color_board[10][50];
  int colors
  int attempt;
  int i, k;

  
  for (i = 0; i < g->max_tries; i++)
  {
    board[i][0] = '\0';
    for (k = 0; k < g->word_length; k++)
      {
        color_board[i][k] = -1;
      }
  } //initilized board with empty guesses

  for (attempt = 0; attempt < g->max_tries; attempt++)
  {
    read_attempt(guess, g);
    if (guess[0] == '\0')
    {
      break; 
    } 
    
    


    strcpy(board[attempt], guess); 
    //store guess
    {
      char empty[50];
      int k;

      for (k = 0; k < g->word_length; k++)
      {
        empty[k] = ' ';
      }
      empty[g->word_length] = '\0';

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
        } // print empty rows
        print_sep(g);
      }
    }
  }
}


void read_attempt(char *guess, Game *g)
{
  int length;
  int totalPossibleWords;

  switch(g->word_length){
    case FIVE:
      totalPossibleWords = FIVE_LETTER_LEN;
      break;
    case EIGHT:
      totalPossibleWords = EIGHT_LETTER_LEN;
      break;
    case TEN:
      totalPossibleWords = TEN_LETTER_LEN;
      break;
  }

  while (1)
  {
    printf("\nEnter a %d letter guess: ", g->word_length);

    if (fgets(guess, 50, stdin) == NULL)
    {
      guess[0] = '\0';
      return;
    }

    length = strcspn(guess, "\n");
    guess[length] = '\0';
    //get rid of new line char 
    
    if ((int)strlen(guess) != g->word_length)
    {
      printf("\nInvalid input, please enter exactly %d letters.\n", g->word_length);
      continue;
    } // guess length must match exactly

    if (!all_letters(guess))
    {
      printf("\nInvalid input, letters A-Z only (no numbers or symbols).\n");
      continue;
    } // error check for special chars, spaces, numbers in guess 

    if(!isValidWord(g->word_list, guess, totalPossibleWords, g->word_length)){
      printf("\nNot a valid word\n");
      continue;
    }//Check if it's a valid word

    uppercase(guess);
    return;
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
      /* fall back to no color if colors[i] is something else */
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


void uppercase(char *s)
{
  size_t i;
  if (s == NULL) return;
  for (i = 0; s[i] != '\0'; ++i)
  {
    // cast to unsigned char to avoid UB for negative chars
    s[i] = (char)toupper((unsigned char)s[i]);
  }
}

int all_letters(char *s)
{
  int i;
  for (i = 0; s[i] != '\0'; i++)
  {
    unsigned char ch = (unsigned char)s[i];
    if (!isalpha(ch)) return 0;  
  }// reject digits/symbols/space 
  return 1;
}

void clear_line()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
  {
  }
}

int get_int_choice(char *prompt, int min_value, int max_value)
{
  int value;
  int scan;
  
  printf("%s", prompt);
  scan = scanf("%d", &value);

  while (scan != 1 || value < min_value || value > max_value)
  {
    printf("\nInvalid input. Enter a number between %d and %d: ", min_value, max_value);
    clear_line();
    scan = scanf("%d", &value);
  }

  clear_line();
  return value;
}


