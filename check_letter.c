
#include <stdio.h>
#include <string.h> 
#include "colors.h"
#include "functions.h"

#define FIVE 5

void check_letter(const char guess[], const char answer[], int colors[]) {
	int i; 
  int j;
  for (i = 0; i < FIVE; i++)
    colors[i] = 0;
  int check_duplicates[FIVE] = {0};
	for (i = 0; i < FIVE; i++){
		if (guess[i] == answer[i]) {
		  colors[i] = 2;
      check_duplicates[i] = 1; 
      continue; 
		}else if (guess[i] != answer[i]){
      for (j = 0; j < FIVE; j++){
        if (guess[i] == answer[j] && check_duplicates[j] == 0){
          colors[i] = 1;
          check_duplicates[j] = 1; 
        } 
      }
    }
  }
}


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


int main() {

	int colors[FIVE];
	char guess[6];
	char answer[6]; 
	strcpy(guess, "APPLE");
	strcpy(answer, "APPLE");
	check_letter(guess, answer, colors);
	print_color(colors, guess); 
  return 0;

}