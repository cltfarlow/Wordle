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
int isValidWord(char bigA[], char givenGuess[], int row, int col){
    char guess[col+2];
    int left = 0, right = row, mid, cmp, i;
    char word[col];
    
    /*convert guess to lowercase*/
    strcpy(guess, givenGuess);
    for(i = 0; i<col; i++){
        guess[i] = tolower(guess[i]);
    }

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
    int i;
    FILE *filePointer;
    /*clear bigA*/
    if(row!=SMALLER_FIVE_LETTER_LEN){
        for(i = 0; i<EIGHT_LETTER_LEN*TEN; i++){
            bigA[i] = '\0';
        }
    }
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
    int index;
    srand(time(0)*3000);
    index = rand()%row;
    strncpy(word, bigA+index*col, col);
}