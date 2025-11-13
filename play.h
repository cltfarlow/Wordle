#ifndef PLAY_H
#define PLAY_H

typedef struct
{
  int word_length;
  int max_tries;
  char word_list[];
} Game;

void title();
void rules(Game *g);
void play_easy(Game *g);
void play_medium(Game *g);
void play_hard(Game *g);
void play_loop(Game *g);
void read_attempt(char *guess, Game *g);
void print_sep(Game *g);
void print_guess_row(char *guess, Game *g);
void uppercase(char *s);
int all_letters(char *s);
void clear_line();
int get_int_choice(char *prompt, int min_val, int max_val);

#endif