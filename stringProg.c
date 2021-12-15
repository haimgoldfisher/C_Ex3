# include <stdio.h>
# include <string.h>
# include <stdbool.h>
# include <stdlib.h>
# include "my_funcs.h"
# define TXT 1024
# define WORD 30


int main()
{
    char input_word[WORD], input_text[TXT]; // string for word and text
    int i; // index
    char currChar; // for the input loops
    for (i = 0; i < WORD; i++)
    {
        scanf("%c", &currChar);
        if (currChar == ' ' || currChar == '\n' || currChar == '\t') // word rule
        {
            break;
        }
        input_word[i] = currChar;
    }
    for (i = 0; i < TXT; i++)
    {
        scanf("%c", &currChar);
        if (currChar == '~') // text rule
        {
            break;
        }
        input_text[i] = currChar;
    }

     char *word_ptr = input_word;
     char *txt_ptr = input_text;
     printf("%s", "Gematria Sequences: ");
     gematria(word_ptr, txt_ptr);
     printf("%s", "Atbash Sequences: ");
     atbash(word_ptr, txt_ptr);
     printf("%s", "Anagram Sequences: ");
     anagram(word_ptr, txt_ptr);

    return 1;
}