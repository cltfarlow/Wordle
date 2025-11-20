#ifndef PLAY_H

#include "Definitions.h"
#include "CheckWord.h"
#include "Input.h"

void play_easy(Game *g);
void play_medium(Game *g);
void play_hard(Game *g);
void play_loop(Game *g, int colors[]);
void uppercase(char *s);
int all_letters(char *s);
void clear_line();
int get_int_choice(char *prompt, int min_val, int max_val);

#endif