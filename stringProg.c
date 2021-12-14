# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include "my_funcs.h"
# define TXT 1024
# define WORD 30

int main()
{
    char input_word[WORD];
    char input_text[TXT];
    int i;
    for (i = 0; i < WORD; i++)
    {
        if (input_word[i] ==' ' || input_word[i] =='\t'|| input_word[i] =='\n')
        {
            break;
        }
        scanf("%d", &input_word[i]);
    }
    while (++i < TXT)
    {
        if (input_text[i] == '~')
        {
            break;
        }
        scanf("%d",&input_text[i]);
    }
    
    printf("Gematria Sequences: " + gematria(input_word, input_text));
    printf("Atbash Sequences: " + atbash(input_word, input_text));
    printf("Anagram Sequences: " + anagram(input_word, input_text));

    return 1;
}