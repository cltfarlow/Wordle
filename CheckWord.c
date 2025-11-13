#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
File: CheckWord.c
Author: Christopher Farlow
Assignment: Wordle Project 11/22/2025
Date: 11/22/2025
References: ChatGPT, https://www.geeksforgeeks.org/c/get-a-substring-in-c/
*/

/*Five characters*/
#define FIVE 5
/*Amount of words in FiveLetterWords.txt*/
#define FIVE_LETTER_LEN 15933
/*Amount of words in SmallerFiveLetterWords.txt*/
#define SMALLER_FIVE_LETTER_LEN 2274
/*Eight characters*/
#define EIGHT 8
/*Amount of words in EightLetterWords.txt*/
#define EIGHT_LETTER_LEN 51628
/*Ten Characters*/
#define TEN 10
/*Amount of words in TenLetterWords.txt*/
#define TEN_LETTER_LEN 45873

#define FIVE_PATH "FiveLetterWords.txt"
#define SMALLER_FIVE_PATH "SmallerFiveLetterWords.txt"
#define EIGHT_PATH "EightLetterWords.txt"
#define TEN_PATH "TenLetterWords.txt"


int isValidWord(char bigA[], char guess[], int row, int col);
int initArray(char bigA[], int row, int col);
void generateRandWord(char word[], char bigA[], int row, int col);

/*
binary search algorithm
returns 1 if word is valid, 0 if not
Arguments:
@bigA: the array with every valid word
@guess: the word to see is valid
@row: amount of words in bigA
@col: amount of characters in words
*/
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

/*
Adds words from corresponding txt file to bigA based on @row and @col
Returns 1 if array initialization failed, 0 if it succeedes
Arguments:
@bigA: the array to store valid words
@row: amount of words in bigA
@col: amount of characters in words
*/
int initArray(char bigA[], int row, int col){
    FILE *filePointer;
    switch(col){
        case FIVE:
            if(row==SMALLER_FIVE_LETTER_LEN){
                filePointer = fopen(SMALLER_FIVE_PATH, "r");
            }else{
                filePointer = fopen(FIVE_PATH, "r");
            }
            break;
        case EIGHT:
            filePointer = fopen(EIGHT_PATH, "r");
            break;
        case TEN:
            filePointer = fopen(TEN_PATH, "r");
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

/*
Copies a random word from bigA into word
Arguments:
@word: the char array to store the generated word
@bigA: the array with every word to pull a word from
@row: amount of words in bigA
@col: amount of characters in words
Note: for 5 letter words, pass the smaller array as bigA, and use smaller_arr_len as row
*/
void generateRandWord(char word[], char bigA[], int row, int col){
    int i, index;
    index = rand()%row;
    strncpy(word, bigA+index*col, col);
}