#include "head.h"

void  ft_putstr(char *str1, char *str2)
{
  int i;

  i = 0;
  while (str1[i])
    write(1, &str1[i++], 1);
  i = 0;
  while (str2[i])
    write(1, &str2[i++], 1);
}

int check_letter(char c)
{
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    return (1);
  else
    return (0);
}

void ft_putnbr(int nb)
{
  if (nb < 0)
    nb = -nb;
  if (nb > 10)
  {
    ft_putnbr(nb / 10);
    ft_putnbr(nb % 10);
  }
  else
  {
    nb = nb + '0';
    write(1, &nb, 1);
  }
}

void ft_putfloat(float f)
{
  int int_part;
  int decimal_part;
  int_part = (int) f;
  f = f - int_part;
  f *= 100;
  decimal_part = (int) f;
  ft_putnbr(int_part);
  write(1, ".", 1);
  ft_putnbr(decimal_part);
}
