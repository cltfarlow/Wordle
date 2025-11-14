#ifndef PLAY_H
#define PLAY_H

#define FIVE 5
#define FIVE_LETTER_LEN 15933
#define SMALLER_FIVE_LETTER_LEN 2274
#define EIGHT 8
#define EIGHT_LETTER_LEN 51628
#define TEN 10
#define TEN_LETTER_LEN 45873

typedef struct
{
  int word_length;
  int max_tries;
  char word_list[EIGHT_LETTER_LEN*TEN];
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