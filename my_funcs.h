# ifndef MY_FUNCS_H
# define MY_FUNCS_H
# define TXT 1024
# define WORD 30

/* Prints the sub-strings from the text with the same "Gematria" value as the word
 * (there is '~' between every 2 of these) */
int gematria(char*, char*);

/* Prints the sub-strings from the text which are identical to the "Atbash" form
 * of the word (there is '~' between every 2 of these) */
int atbash(char*, char*);

/* Prints the sub-strings that are identical in their letters to all the letters of
 * the word, not necessarily in the same order between every 2 of these) */
int anagram(char*, char*);

# endif
