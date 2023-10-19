#ifndef HEAD_H
# define HEAD_H
#include <unistd.h>
#include <stdlib.h>

typedef struct S_ldict {
  char letter;
  int count;
  float frequency;
} T_ldict;

typedef struct S_freq_dict {
  float *french_dict;
} T_freq_dict;

int check_letter(char c);
size_t fill_dict(char *c[], struct S_ldict* letter_dict);
void ft_putnbr(int nb);
void ft_putstr(char *str1, char *str2);
void calc_freq(struct S_ldict* letter_dict, size_t texts, size_t dict_size);
void print_dict(struct S_ldict* letter_dict, size_t dict_size);
void ft_putfloat(float f);
void fill_freq_dict(struct S_freq_dict* ptr);
float *compare_freq (struct S_ldict* letter_dict, size_t dict_size);
char *find_lang(float *delta_arr);

#endif
