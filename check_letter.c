
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


  int print_color2(int colors[], char guess[]){
  int i; 
  printf("\n----------------------------------------------");
  printf("\n");
  for(i = 0; i < FIVE; i++){
    switch (colors[i]){ 
    case 0: 
      printf(GREY_BG WHITE_TXT BOLD_TXT " %c " RESET, guess[i]); 
      break; 
    case 1: 
      printf(YELLOW_BG WHITE_TXT BOLD_TXT " %c " RESET, guess[i]); 
      break;
    case 2: 
      printf(GREEN_BG WHITE_TXT BOLD_TXT " %c " RESET, guess[i]); 
      break; 
    }
  }
  printf("\n");
}