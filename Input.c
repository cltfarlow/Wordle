
#include <stdio.h>
#include <string.h> 
#include <ctype.h>
#include <stdlib.h>
#include "Definitions.h"

/* 

  File: Output.c
  Author: Max Klein, Emilina Salazar
  Debugged: Max Klein
  Assignment: Wordle Project 11/22/2025
  Date: 11/22/2025
  References: notes, google

*/
void clear_line();
void check_letter(char guess[], int colors[], char answer[], int word_length);
int get_int_choice(char *prompt, int min_value, int max_value);
void uppercase(char *s);

/*
Clears the input line to avoid reading the wrong inputs
Arguments: none
Returns: none
Clears the newline character to avoid skipping user inputs in the scanf function
*/
void clear_line()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
  {
  }
}

/*
Loops through guess and answer to check for correct letters and if they are in the correct position
Arguments:
@guess: the user's guessed word
@colors: array to store color codes for each letter in guess
@answer: the correct word to be guessed
@word_length: length of the word being guessed

color codes: 
0 - letter not in word
1 - letter in word but wrong position
2 - letter in word and in correct position

Returns: none
Modifies color array which is passed to another function later to print colored output
*/
void check_letter(char guess[], int colors[], char answer[], int word_length) {
    
    int i; 
    int j;
    for (i = 0; i < word_length; i++){
    colors[i] = 0;
    }
    switch(word_length){
        case 5: {
            /*Initializes the check duplicates array to keep track of letters already matched*/
            int check_duplicates_FIVE[FIVE] = {0};
            /* First pass: check for correct letters in correct positions, updates color and duplicates arrays */
            for (i = 0; i < word_length; i++){
                if (guess[i] == answer[i]) {
                    colors[i] = 2;
                    check_duplicates_FIVE[i] = 1; 
                }
            }
            /* Second pass: check for correct letter in incorrect positions
             updates color and duplicates arrays accordingly, if */
            for (i = 0; i < word_length; i++){
                for (j = 0; j < word_length; j++){
                    if (guess[i] != answer[i]){
                        for (j = 0; j < word_length; j++){
                            if ((guess[i] == answer[j]) && (check_duplicates_FIVE[j] == 0)){
                                colors[i] = 1;
                                check_duplicates_FIVE[j] = 1; 
                            } 
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
                }

            }
            for (i = 0; i < word_length; i++){
                for (j = 0; j < word_length; j++){
                    if (guess[i] != answer[i]){
                        for (j = 0; j < word_length; j++){
                            if ((guess[i] == answer[j]) && (check_duplicates_EIGHT[j] == 0)){
                                colors[i] = 1;
                                check_duplicates_EIGHT[j] = 1; 
                            } 
                        }
                    }
                } 
            }
            break;
      }
        case 10:{
            int check_duplicates_FIVE[FIVE] = {0};
            for (i = 0; i < word_length; i++){
                if (guess[i] == answer[i]) {
                    colors[i] = 2;
                    check_duplicates_FIVE[i] = 1; 
                }
            }
            for (i = 0; i < word_length; i++){
                for (j = 0; j < word_length; j++){
                    if (guess[i] != answer[i]){
                        for (j = 0; j < word_length; j++){
                            if ((guess[i] == answer[j]) && (check_duplicates_FIVE[j] == 0)){
                                colors[i] = 1;
                                check_duplicates_FIVE[j] = 1; 
                            } 
                        }
                    }
                } 
            }
            break;
        }
    }
}

/* 
Converts string to uppercase, used for standardizing strings throughout the various functions
Arguments:
@s: pointer to the string to be converted to uppercase
Returns: none
*/
void uppercase(char *s)
{
  size_t i;
  if (s == NULL) return;
  for (i = 0; s[i] != '\0'; ++i)
  {
    /* cast to unsigned char to avoid UB for negative chars */
    s[i] = (char)toupper((unsigned char)s[i]);
  }
}




/*
Acquires an integer input from the user within a specified range corresponding to menu choices
Arguments:
@prompt: pointer to the message displayed to the user when asking for input`
@min_value: the minimum acceptable integer value
@max_value: the maximum acceptable integer value
Returns: the validated integer input from the user
*/
int get_int_choice(char *prompt, int min_value, int max_value)
{
  int value;
  int scan;
  
  printf("%s", prompt);
  scan = scanf("%d", &value);
  /* Loop until valid input is received*/
  while (scan != 1 || value < min_value || value > max_value)
  {
    printf("\nInvalid input. Enter a number between %d and %d: ", min_value, max_value);
    /* clear the input line to avoid infinite loop on invalid input*/
    clear_line();
    scan = scanf("%d", &value);
  }
  /* clear the input line to avoid affecting subsequent inputs*/
  clear_line();
  return value;
}