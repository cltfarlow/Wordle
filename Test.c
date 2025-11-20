

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TEN 10
#define EIGHT 8
#define FIVE 5

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
                }
                printf("%d", check_duplicates_FIVE[i]);

            }
            for (i = 0; i < word_length; i++){
                for (j = 0; j < word_length; j++){
                    if (guess[i] != answer[i]){
                        for (j = 0; j < word_length; j++){
                            if ((guess[i] == answer[j]) && (check_duplicates_FIVE[j] == 0)){
                                printf("%d", check_duplicates_FIVE[i]);
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
                printf("%d", check_duplicates_EIGHT[i]);

            }
            for (i = 0; i < word_length; i++){
                for (j = 0; j < word_length; j++){
                    if (guess[i] != answer[i]){
                        for (j = 0; j < word_length; j++){
                            if ((guess[i] == answer[j]) && (check_duplicates_EIGHT[j] == 0)){
                                printf("%d", check_duplicates_EIGHT[i]);
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
                printf("%d", check_duplicates_FIVE[i]);

            }
            for (i = 0; i < word_length; i++){
                for (j = 0; j < word_length; j++){
                    if (guess[i] != answer[i]){
                        for (j = 0; j < word_length; j++){
                            if ((guess[i] == answer[j]) && (check_duplicates_FIVE[j] == 0)){
                                printf("%d", check_duplicates_FIVE[i]);
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

int main(){
    char guess[50];
    char buffer[50]; 
    printf("Guess\n");
    scanf("%s",guess); 
    int color[5];
    char answer[50];
    strcpy(answer, "aisle");

    check_letter(guess, color, answer, 5);
    for(int i = 0; i < 5; i++){
        printf("%d ", color[i]);
    }
}
