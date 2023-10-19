#include "head.h"

int main(int ac, char *av[])
{
  if (!av[1] || !av[2])
    exit(84);
  
  float *delta_arr;
  size_t texts;
  size_t dict_size;
  size_t j;
  struct S_ldict *letter_dict;

  delta_arr = (float *) malloc(5 * sizeof(float));
  delta_arr = (float[4]){0.0f, 0.0f, 0.0f, 0.0f};
  letter_dict = (struct S_ldict*) malloc((ac - 2) * sizeof(struct S_ldict));
  dict_size = fill_dict(av, letter_dict);
  texts = 0;
  
  while (av[1] && av[1][texts])
  {
    j = 0;
    while (j < dict_size)
      if (letter_dict[j++].letter == av[1][texts])
      {
        letter_dict[j].count++;
        break;
      }
    texts++;
  }

  calc_freq(letter_dict, texts, dict_size);
  print_dict(letter_dict, dict_size);
  compare_freq(letter_dict, dict_size, delta_arr);
  ft_putstr("==> ", find_lang(delta_arr));
  return(EXIT_SUCCESS);
}
