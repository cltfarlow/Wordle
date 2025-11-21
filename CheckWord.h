#ifndef CHECKWORD_H

int is_valid_word(char allowed_words[], char guess[], int row, int col);
int init_array(char array[], int row, int col);
void generate_rand_word(char word[], char possible_words[], int row, int col);
void read_attempt(char *guess, int word_length, char word_list[]);
int all_letters(char *s);
#endif