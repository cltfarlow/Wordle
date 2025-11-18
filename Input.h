#ifndef INPUT_H

void check_letter(char guess[], int colors[], char answer[], int word_length);
void read_attempt(char *guess, int word_length, char word_list[]);
int get_int_choice(char *prompt, int min_value, int max_value);
int all_letters(char *s);
void uppercase(char *s);
#endif