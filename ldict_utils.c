#include "head.h"

const float freq_english[] = { 8.167, 1.492, 2.782, 4.253, 12.702, 2.228, 2.015, 6.094, 6.966, 0.253, 1.772, 4.025, 2.406, 6.749, 7.507, 1.929, 0.095, 5.987, 6.327, 9.056, 2.758, 0.978, 2.360, 0.250, 1.974, 0.074 };
const float freq_french[] = { 7.636, 0.901, 3.260, 3.669, 14.715, 1.066, 0.866, 0.937, 7.529, 0.813, 0.074, 5.456, 2.968, 7.095, 5.796, 2.521, 1.362, 6.693, 7.948, 7.244, 6.311, 1.838, 0.049, 0.427, 0.708, 0.326 };
const float freq_german[] = { 6.516, 1.886, 2.732, 5.076, 16.396, 1.656, 3.009, 4.577, 6.550, 0.268, 1.417, 3.437, 2.534, 9.776, 2.594, 0.670, 0.018, 7.003, 7.270, 6.154, 4.166, 0.846, 1.921, 0.034, 0.039, 1.134 };
const float freq_spanish[] = { 11.525, 2.215, 4.019, 5.010, 12.181, 0.692, 1.768, 1.973, 6.247, 2.493, 0.026, 4.967, 3.157, 6.712, 8.683, 2.510, 0.877, 6.871, 7.977, 4.632, 3.927, 1.138, 0.027, 0.515, 1.433, 0.467 };

size_t fill_dict(char *c[], struct S_ldict* letter_dict)
{
  int index;
  int i;

  i = 0;
  index = 2;
  while (c[index] && (check_letter(c[index][0]) == 1))
  {
    letter_dict[i].letter = c[index][0];
    letter_dict[i].count = 0;
    letter_dict[i].frequency = 0;
    i++;
    index++;
  }
  return (index - 2);
}

void calc_freq(struct S_ldict* letter_dict, size_t texts, size_t dict_size)
{
  size_t j;

  j = 0;
  while (j < dict_size)
  {
    letter_dict[j].frequency = ((float) letter_dict[j].count / (float) texts);
    letter_dict[j].frequency *= 100;
    j++;
  }
}

void print_dict(struct S_ldict* letter_dict, size_t dict_size)
{
  size_t i;

  i = 0;
  while (i < dict_size)
  {
    write(1, &letter_dict[i].letter, 1);
    write(1, ":", 1);
    ft_putnbr(letter_dict[i].count);
    write(1, " (", 2);
    ft_putfloat(letter_dict[i].frequency);
    write(1, "%)", 2);
    write(1, "\n", 1);
    i++;
  }
}

float *compare_freq (struct S_ldict* letter_dict, size_t dict_size)
{
  size_t i;
  int index;
  float *delta_arr;

  i = 0;
  delta_arr = (float *) malloc(4 * sizeof(float));
  delta_arr = (float[4]){0.0f, 0.0f, 0.0f, 0.0f};
  while (i < dict_size)
  {
    index = (char) letter_dict[i].letter - 'a';
    delta_arr[0] += letter_dict[i].frequency - freq_english[index];
    delta_arr[1] += letter_dict[i].frequency - freq_french[index];
    delta_arr[2] += letter_dict[i].frequency - freq_german[index];
    delta_arr[3] += letter_dict[i].frequency - freq_spanish[index];
    __builtin_printf("dif EN %f - %f = %f\n", letter_dict[i].frequency, freq_english[index], delta_arr[0]);
    __builtin_printf("dif FR %f - %f = %f\n", letter_dict[i].frequency, freq_french[index], delta_arr[1]);
    __builtin_printf("dif GR %f - %f = %f\n", letter_dict[i].frequency, freq_german[index], delta_arr[2]);
    __builtin_printf("dif ES %f - %f = %f\n", letter_dict[i].frequency, freq_spanish[index], delta_arr[3]);
    i++;
  }
  return (delta_arr);
}

char *find_lang(float *delta_arr)
{
  char **lang;
  int const size = 4;
  int index;
  float tmp;
  char *result;

  lang = (char *[4]){ "FRENCH", "ENGLISH", "GERMAN", "SPANISH" };
  index = 0;
  while (index < size)
  {
    if (delta_arr[index] < 0)
      delta_arr[index] = -delta_arr[index];
    index++;
  }
  index = 0;
  tmp = 10000;
  while (index < size)
  {
    if (delta_arr[index] < tmp)
    {
      tmp = delta_arr[index];
      result = lang[index];
    }
    index++;
  }
  return (result);
}
