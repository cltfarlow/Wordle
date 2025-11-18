#ifndef OUTPUT_H
#define OUTPUT_H

void print_sep(int word_length);
void print_guess_row(char *guess, int colors[], int word_length);
void print_color(int colors[], char guess[], int word_length);
void clear_line();

#endif