# include <stdio.h>
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
    input_word[i] = '\0'; // end for the string
    for (i = 0; i < TXT; i++)
    {
        scanf("%c", &currChar);
        if (currChar == '~') // text rule
        {
            break;
        }
        input_text[i] = currChar;
    }
    input_text[i] = '\0'; // end for the string
    char *word_ptr = input_word; // pointer for the word
    char *txt_ptr = input_text; // pointer for the text
    printf("Gematria Sequences: ");
    gematria(word_ptr, txt_ptr);
    printf("\n");
    printf("Atbash Sequences: ");
    atbash(word_ptr, txt_ptr);
    printf("\n");
    printf("Anagram Sequences: ");
    anagram(word_ptr, txt_ptr);
    //printf("\n");
    return 0;
}