
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

void check_letter(const char guess[], int colors[], Game g) {
	int i; 
  int j;
  for (i = 0; i < g.word_length; i++){
    colors[i] = 0;
    switch(g.word_length){
      case 5: 
      int check_duplicates[FIVE] = {0};
      for (i = 0; i < g.word_length; i++){
		    if (guess[i] == g.answer[i]) {
		      colors[i] = 2;
          check_duplicates[i] = 1; 
          continue; 
		    }else if (guess[i] != g.answer[i]){
          for (j = 0; j < g.word_length; j++){
            if (guess[i] == g.answer[j] && check_duplicates[j] == 0){
              colors[i] = 1;
              check_duplicates[j] = 1; 
            } 
          }
        }
      }
      break; 
      case 8: 
        int check_duplicates[EIGHT] = {0};
      	for (i = 0; i < g.word_length; i++){
		      if (guess[i] == g.answer[i]) {
		        colors[i] = 2;
            check_duplicates[i] = 1; 
            continue; 
		      }else if (guess[i] != g.answer[i]){
            for (j = 0; j < g.word_length; j++){
              if (guess[i] == g.answer[j] && check_duplicates[j] == 0){
                colors[i] = 1;
                check_duplicates[j] = 1; 
              } 
            }
          }
        }
      break;
      case 10:
        int check_duplicates[TEN] = {0};
        for (i = 0; i < g.word_length; i++){
		      if (guess[i] == g.answer[i]) {
		        colors[i] = 2;
            check_duplicates[i] = 1; 
            continue; 
		      }else if (guess[i] != g.answer[i]){
            for (j = 0; j < g.word_length; j++){
              if (guess[i] == g.answer[j] && check_duplicates[j] == 0){
                colors[i] = 1;
                check_duplicates[j] = 1; 
              } 
            }
          }
        }
      break;
    }
  }
}

//TEXT



int print_color(int colors[], char guess[]){
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