# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>
# define TXT 1024
# define WORD 30

int calc_gim(char *word)
{
    int i;
    int gim_val = 0;
    for (i = 0; i < WORD; i++)
    {
        if (strcmp(word, "/0") == 0) // end of the word
        {
            break;
        }
        if (islower(*word))
        {
            gim_val += *word-96;
        }
        else if (isupper(*word))
        {
            gim_val += tolower(*word)-96;
        }
        word++;
    }
    return gim_val;
}

int gematria(char *word, char *text)
{
    int word_val = calc_gim(word);
    return 1;
}

int atbash(char *word, char *text)
{

    return 1;
}

int anagram(char *word, char *text)
{

    return 1;
}