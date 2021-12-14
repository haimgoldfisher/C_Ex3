# include <stdio.h>
# include <string.h>
# include <stdbool.h>
# include <stdlib.h>
# include "my_funcs.h"
# define TXT 1024
# define WORD 30

int main()
{
    char input[WORD+TXT];
    scanf("%s", input); // scan the whole input into this string
    char *input_ptr = input; // pointer to the first char of the string
    char input_word[WORD]; // the word
    char input_text[TXT]; // the text
    int i;
    for (i = 0; i < WORD; i++)
    {
        if (strcmp(input_ptr, "/0") == 0) // end of the first word
        {
            break; // finish to fill the word
        }
        input_word[i] = ++*input_ptr; // add the curr char to word
    }
    i = 0;
    for (i = 0; i < TXT; i++)
    {
        if (strcmp(input_ptr, "~") == 0) // '~' is the end of the text
        {
            break; // finish to fill the text
        }
        input_text[i] = ++*input_ptr; // add the curr char to text
    }
    printf("%s", input_text);
    printf("%s", input_word);
    
    // printf("Gematria Sequences: " + gematria(input_word, input_text));
    // printf("Atbash Sequences: " + atbash(input_word, input_text));
    // printf("Anagram Sequences: " + anagram(input_word, input_text));

    return 1;
}