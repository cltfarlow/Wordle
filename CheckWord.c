#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
/*
Author: Christopher Farlow
References: ChatGPT, https://www.geeksforgeeks.org/c/get-a-substring-in-c/
*/
#define FIVE 5
#define FIVE_LETTER_LEN 15933
#define SMALLER_FIVE_LETTER_LEN 2274
#define EIGHT 8
#define EIGHT_LETTER_LEN 51628
#define TEN 10
#define TEN_LETTER_LEN 45873

int isValidWord(char bigA[], char guess[], int row, int col);
int initArray(char bigA[], int row, int col);
void generateRandWord(char word[], char bigA[], int row, int col);

/*binary search algorithm
returns 1 if word is valid, 0 if not*/
int isValidWord(char bigA[], char guess[], int row, int col){
    int left = 0, right = row, mid, cmp;
    char word[col];
    while(left<=right){
        mid = left+(right-left)/2;
        strncpy(word, bigA+mid*col, col);
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

/*Returns 1 if array initialization failed, 0 if it suceedes*/
int initArray(char bigA[], int row, int col){
    FILE *filePointer;
    switch(col){
        case FIVE:
            if(row==SMALLER_FIVE_LETTER_LEN){
                filePointer = fopen("SmallerFiveLetterWords.txt", "r");
            }else{
                filePointer = fopen("FiveLetterWords.txt", "r");
            }
            break;
        case EIGHT:
            filePointer = fopen("EightLetterWords.txt", "r");
            break;
        case TEN:
            filePointer = fopen("TenLetterWords.txt", "r");
            break;
    }
    if(filePointer == NULL){
        printf("Error opening file");
        return 1;
    }
    char line[col+2];
    while(fgets(line, sizeof(line), filePointer)!=NULL){
        strncat(bigA, line,col);
    }
    fclose(filePointer);
    return 0;
}

/*Note: for 5 letter words, pass the smaller array as bigA, and use smaller_arr_len as row*/
void generateRandWord(char word[], char bigA[], int row, int col){
    int i, index;
    index = rand()%row;
    strncpy(word, bigA+index*col, col);
}