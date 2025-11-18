#ifndef DEFINITIONS_H

#define RESET "\033[0m"

#define GREEN_BG "\033[48;2;83;141;78m"
#define YELLOW_BG "\033[48;2;181;159;59m"
#define GREY_BG "\033[48;2;;58;58;58m"

#define WHITE_TXT "\033[97m"
#define BOLD_TXT "\033[1m"

/*Five characters*/
#define FIVE 5
/*Amount of words in FiveLetterWords.txt*/
#define FIVE_LETTER_LEN 15933
/*Amount of words in SmallerFiveLetterWords.txt*/
#define SMALLER_FIVE_LETTER_LEN 2274
/*Eight characters*/
#define EIGHT 8
/*Amount of words in EightLetterWords.txt*/
#define EIGHT_LETTER_LEN 51628
/*Ten Characters*/
#define TEN 10
/*Amount of words in TenLetterWords.txt*/
#define TEN_LETTER_LEN 45873

#define FIVE_PATH "FiveLetterWords.txt"
#define SMALLER_FIVE_PATH "SmallerFiveLetterWords.txt"
#define EIGHT_PATH "EightLetterWords.txt"
#define TEN_PATH "TenLetterWords.txt"

typedef struct
{
  int word_length;
  int max_tries;
  char answer[TEN+1];
  char word_list[EIGHT_LETTER_LEN*TEN];
} Game;

#endif
