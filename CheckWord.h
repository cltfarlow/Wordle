#ifndef CHECKWORD_H

int isValidWord(char bigA[], char guess[], int row, int col);
int initArray(char bigA[], int row, int col);
void generateRandWord(char word[], char bigA[], int row, int col);
void read_attempt(char *guess, int word_length, char word_list[]);
int all_letters(char *s);
#endif