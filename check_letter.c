
#include <stdio.h>
#include <string.h> 
#include "colors.h"
#include "play.h"
#include "CheckWord.h"


/* 

  File: check_letter.c
  Author: Max Klein
  Assignment: Wordle Project 11/22/2025
  Date: 11/22/2025
  References: notes, google

*/

void check_letter(char guess[], int colors[], char answer[], int word_length) {
	int i; 
  int j;
  for (i = 0; i < word_length; i++){
    colors[i] = 0;
  }
    switch(word_length){
      case 5: {
      int check_duplicates_FIVE[FIVE] = {0};
      for (i = 0; i < word_length; i++){
		    if (guess[i] == answer[i]) {
		      colors[i] = 2;
          check_duplicates_FIVE[i] = 1; 
          continue; 
		    }else if (guess[i] != answer[i]){
          for (j = 0; j < word_length; j++){
            if (guess[i] == answer[j] && check_duplicates_FIVE[j] == 0){
              colors[i] = 1;
              check_duplicates_FIVE[j] = 1; 
            } 
          }
        }
      }
      break; 
      }
      case 8: {
        int check_duplicates_EIGHT[EIGHT] = {0};
      	for (i = 0; i < word_length; i++){
		      if (guess[i] == answer[i]) {
		        colors[i] = 2;
            check_duplicates_EIGHT[i] = 1; 
            continue; 
		      }else if (guess[i] != answer[i]){
            for (j = 0; j < word_length; j++){
              if (guess[i] == answer[j] && check_duplicates_EIGHT[j] == 0){
                colors[i] = 1;
                check_duplicates_EIGHT[j] = 1; 
              } 
            }
          }
        }
      break;
      }
      case 10:{
        int check_duplicates_TEN[TEN] = {0};
        for (i = 0; i < word_length; i++){
		      if (guess[i] == answer[i]) {
		        colors[i] = 2;
            check_duplicates_TEN[i] = 1; 
            continue; 
		      }else if (guess[i] != answer[i]){
            for (j = 0; j < word_length; j++){
              if (guess[i] == answer[j] && check_duplicates_TEN[j] == 0){
                colors[i] = 1;
                check_duplicates_TEN[j] = 1; 
              } 
            }
          }
        }
      break;
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
    /*get rid of new line char */
    
    if ((int)strlen(guess) != g->word_length)
    {
      printf("\nInvalid input, please enter exactly %d letters.\n", g->word_length);
      continue;
    } /* guess length must match exactly*/

    if (!all_letters(guess))
    {
      printf("\nInvalid input, letters A-Z only (no numbers or symbols).\n");
      continue;
    } /* error check for special chars, spaces, numbers in guess */

    if(!isValidWord(g->word_list, guess, totalPossibleWords, g->word_length)){
      printf("\nNot a valid word\n");
      continue;
    }/*Check if it's a valid word*/

    return;

  }
}
