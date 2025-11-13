#ifndef FUNCTIONS_H   // include guard start
#define FUNCTIONS_H


typedef struct
{
  int word_length;
  int max_tries;
} Game;
void check_letter(const char guess[], const char answer[], int colors[]);

void print_color(int colors[], char guess[]); 

int isValidWord(char bigA[], char guess[], int row, int col);
int initArray(char bigA[], int row, int col);
void generateRandWord(char word[], char bigA[], int row, int col);

#define FIVE 5
#define FIVE_LETTER_LEN 15933
#define SMALLER_FIVE_LETTER_LEN 2274
#define EIGHT 8
#define EIGHT_LETTER_LEN 51628
#define TEN 10
#define TEN_LETTER_LEN 45873

#endif 
