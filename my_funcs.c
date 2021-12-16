# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <ctype.h>

// inner funcs declaration:
int gim_char(char);
int calc_gim(char *);
int len(char *);
char atbash_char(char);
int calc_atbash(char *, char *);
// end of inner funcs declaration


// Func A: Gematria
int gematria(char *word, char *text)
{
    int word_val = calc_gim(word);
    int first_print = true; // for printing '~' between each two strings
    int text_len = strlen(text);
    for (int i = 0; i < text_len; i++)
    {
        char curr_char = text[i];
        if (gim_char(curr_char) != 0) // ignore chars which are not in the scale {a-z | A-Z}
        {
            int curr_gim_sum, j;
            curr_gim_sum = word_val;
            for (j = i; j < text_len; j++)
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
    int word_len = len(word);
    int text_len = len(text);
    char atbash_word[word_len];
    char *atb_ptr = atbash_word;
    calc_atbash(word, atb_ptr);
    int first_print = true; // for printing '~' between each two strings
    char first_atb = *atb_ptr;
    char last_atb = *(atb_ptr+word_len-1);
    int i;
    for (i = 0; i < text_len; i++) {
        char curr_char = text[i];
        if (gim_char(curr_char) != 0)
        {
            if (curr_char == first_atb) // ignore chars which are not in the scale {a-z | A-Z}
            {
                int j, k;
                int flag = true;
                for (j = i, k = 0; k < word_len; j++, k++)
                {
                    if (text[j] != atb_ptr[k])
                    {
                        flag = false;
                        break;
                    }
                    if (text[j] == '\0' && atb_ptr[k] != '\0')
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag == false)
                {
                    continue;
                }
                if (first_print == false)
                {
                    printf("~");
                }
                for (k = i; k < j; k++)
                {
                    printf("%c", text[k]);
                }
                first_print = false;
            }
            else if (curr_char == last_atb)
            {
                int j, k;
                int flag = true;
                for (j = i, k = word_len-1; k >= 0; j++, k--)
                {
                    if (text[j] != atb_ptr[k])
                    {
                        flag = false;
                        break;
                    }
                    if (text[j] == '\0' && k >= 0)
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag == false)
                {
                    continue;
                }
                if (first_print == false)
                {
                    printf("~");
                }
                for (k = i; k < j; k++)
                {
                    printf("%c", text[k]);
                }
                first_print = false;
            }
        }
    }
    return 1;
}

int len (char *pointer)
{
    int i = 0;
    while (pointer[i] != '\0')
    {
        i++;
    }
    return i;
}

char atbash_char(char ch)
{
    char res;
    if (isupper(ch)) // between A(65) to Z(90)
    {
        res = 90 - (ch % 65);
    }
    else if (islower(ch))
    {
       res = 122 - (ch % 97); // between a(97) to z(122)
    }
    return res;
}

int calc_atbash(char *str_ptr, char *atbash_res)
{
    int i = 0;
    while (str_ptr[i] != '\0')
    {
        atbash_res[i] = atbash_char(str_ptr[i]); // char in word -> atbash char in res
        i++;
    }
    atbash_res[i] = '\0';
    return 1;
}

// **************************************************

// Func C: Anagram
int anagram(char *word, char *text)
{

    return 1;
}
