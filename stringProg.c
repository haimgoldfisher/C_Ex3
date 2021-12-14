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
    scanf("%10[0-9a-zA-Z ]", &input); // scan the whole input into this string
    char *input_ptr = input; // pointer to the first char of the string
    char input_word[WORD]; // the word
    char input_text[TXT]; // the text
    int i;
    for (i = 0; i < WORD; i++)
    {
        if (strcmp(input_ptr, "/0")) // end of the first word
        {
            break; // finish to fill the word
        }
        input_word[i] = *input_ptr; // add the curr char to word
        input_ptr++;
    }
    i = 0;
    for (i = 0; i < TXT; i++)
    {
        if (strcmp(input_ptr, "~") == 0) // '~' is the end of the text
        {
            break; // finish to fill the text
        }
        input_text[i] = *input_ptr; // add the curr char to text
        input_ptr++;
    }
    
    puts(input_word);
    puts(input_text);
    
    // char *word_ptr = input_word;
    // char *txt_ptr = input_text;
    // printf("Gematria Sequences: ");
    // gematria(word_ptr, txt_ptr);
    // printf("Atbash Sequences: ");
    // atbash(word_ptr, txt_ptr);
    // printf("Anagram Sequences: ");
    // anagram(word_ptr, txt_ptr);

    return 1;
}