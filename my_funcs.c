# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include "my_funcs.h"
# include <ctype.h>

// inner funcs declaration:
int gim_char(char);
int calc_gim(char *);
// end of inner funcs declaration


// Func A: Gematria
int gematria(char *word, char *text)
{
    int word_val = calc_gim(word);
    int first_print = true; // for printing '~' between each two strings
    int str_len = strlen(text);
    for (int i = 0; i < str_len; i++)
    {
        char curr_char = text[i];
        if (gim_char(curr_char) != 0) // ignore chars which are not in the scale {a-z | A-Z}
        {
            int curr_gim_sum, j;
            curr_gim_sum = word_val;
            for (j = i; j < str_len; j++)
            {
                curr_gim_sum -= gim_char(text[j]);
                if (curr_gim_sum <= 0)
                {
                    break;
                }
            }
            if (curr_gim_sum == 0)
            {
                if (first_print == false)
                {
                    printf("~");
                }
                for (int k = i; k < j+1; k++)
                {
                    printf("%c", text[k]);
                }
                first_print = false;
            }
        }
    }
    return 1;
}

int gim_char(char ch) // inner func: return the gematria of a single char
{
    int gim_value = 0;
    if (islower(ch))
    {
        gim_value += ch-96;
    }
    else if (isupper(ch))
    {
        gim_value += tolower(ch)-96;
    }
    return gim_value;
}

int calc_gim(char *str_ptr) // inner func: return the gematria of the word
{
    int i;
    int gim_val = 0;
    int str_len = strlen(str_ptr);
    for (i = 0; i < str_len; i++)
    {
        gim_val += gim_char(str_ptr[i]);
    }
    return gim_val;
}
// **************************************************

// Func B: Atbash
int atbash(char *word, char *text)
{

    return 1;
}
// **************************************************

// Func C: Anagram
int anagram(char *word, char *text)
{

    return 1;
}
