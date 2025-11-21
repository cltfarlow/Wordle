#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "Definitions.h"
/*
  File: CheckWord.c
  Author: Christopher Farlow
  Assignment: Wordle Project 11/22/2025
  Date: 11/22/2025
  References: ChatGPT, https://www.geeksforgeeks.org/c/get-a-substring-in-c/
*/

int is_valid_word(char allowed_words[], char guess[], int row, int col);
int init_array(char array[], int row, int col);
void generate_rand_word(char word[], char possible_words[], int row, int col);
int all_letters(char *s);
void read_attempt(char *guess, int word_length, char word_list[]);

/*
binary search algorithm
returns 1 if word is valid, 0 if not
Arguments:
@allowed_words: the array with every valid word
@guess: the word to see is valid
@row: amount of words in bigA
@col: amount of characters in words
*/
int is_valid_word(char allowed_words[], char given_guess[], int row, int col){
    char guess[col+2];
    int left = 0, right = row, mid, cmp, i;
    char word[col];
    
    /*convert guess to lowercase*/
    strcpy(guess, given_guess);
    for(i = 0; i<col; i++){
        guess[i] = tolower(guess[i]);
    }

    while(left<=right){
        mid = left+(right-left)/2;
        strncpy(word, allowed_words+mid*col, col);
        cmp = strncmp(word, guess, col);
        if(cmp==0){
            return 1;
        }else if(cmp>0){
            right = mid-1;
        }else{
            left = mid+1;
        }
    }
    return 0;
}

/*
Adds words from corresponding txt file to bigA based on @row and @col
Returns 1 if array initialization failed, 0 if it succeedes
Arguments:
@array: the array to store valid words
@row: amount of words in bigA
@col: amount of characters in words
*/
int init_array(char array[], int row, int col){
    int i;
    FILE *file_pointer;
    /*clear array*/
    if(row!=SMALLER_FIVE_LETTER_LEN){
        for(i = 0; i<EIGHT_LETTER_LEN*TEN; i++){
            array[i] = '\0';
        }
    }
    switch(col){
        case FIVE:
            if(row==SMALLER_FIVE_LETTER_LEN){
                file_pointer = fopen(SMALLER_FIVE_PATH, "r");
            }else{
                file_pointer = fopen(FIVE_PATH, "r");
            }
            break;
        case EIGHT:
            file_pointer = fopen(EIGHT_PATH, "r");
            break;
        case TEN:
            file_pointer = fopen(TEN_PATH, "r");
            break;
    }
    if(file_pointer == NULL){
        printf("Error opening file");
        return 1;
    }
    char line[col+2];
    while(fgets(line, sizeof(line), file_pointer)!=NULL){
        strncat(array, line,col);
    }
    fclose(file_pointer);
    return 0;
}

void read_attempt(char *guess, int word_length, char word_list[])
{
  int length;
  int total_possible_words;

  switch(word_length){
    case FIVE:
      total_possible_words = FIVE_LETTER_LEN;
      break;
    case EIGHT:
      total_possible_words = EIGHT_LETTER_LEN;
      break;
    case TEN:
      total_possible_words = TEN_LETTER_LEN;
      break;
  }

  while (1)
  {
    printf("\nEnter a %d letter guess: ", word_length);

    if (fgets(guess, 50, stdin) == NULL)
    {
      guess[0] = '\0';
      return;
    }

    length = strcspn(guess, "\n");
    guess[length] = '\0';
    /*get rid of new line char */
    
    if ((int)strlen(guess) != word_length)
    {
      printf("\nInvalid input, please enter exactly %d letters.\n", word_length);
      continue;
    } /* guess length must match exactly*/

    if (!all_letters(guess))
    {
      printf("\nInvalid input, letters A-Z only (no numbers or symbols).\n");
      continue;
    } /* error check for special chars, spaces, numbers in guess */

    if(!is_valid_word(word_list, guess, total_possible_words, word_length)){
      printf("\nNot a valid word\n");
      continue;
    }/*Check if it's a valid word*/
    return;

  }
}

int all_letters(char *s)
{
  int i;
  for (i = 0; s[i] != '\0'; i++)
  {
    unsigned char ch = (unsigned char)s[i];
    if (!isalpha(ch)) return 0;  
  }/* reject digits/symbols/space  */
  return 1;
}
/*
Copies a random word from possible_words into word
Arguments:
@word: the char array to store the generated word
@bigA: the array with every word to pull a word from
@row: amount of words in possible_words
@col: amount of characters in words
Note: for 5 letter words, pass the smaller array as possible_words, and use smaller_arr_len as row
*/
void generate_rand_word(char word[], char possible_words[], int row, int col){
    int index;
    srand(time(0)*3000);
    index = rand()%row;
    strncpy(word, possible_words+index*col, col);
}