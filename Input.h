#ifndef INPUT_H

void check_letter(char guess[], int colors[], char answer[], int word_length);
int get_int_choice(char *prompt, int min_value, int max_value);
void uppercase(char *s);
void clear_line();
#endif