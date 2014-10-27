/*
** main.c for main in /home/de-buy_i/PSU_2018_my_printf
** 
** Made by de buyst ismael
** Login   <de-buy_i@epitech.net>
** 
** Started on  Tue Nov 12 13:47:40 2013 de buyst ismael
** Last update Sun Oct 26 16:07:17 2014 Ismael De Buyst
*/

#include <stdarg.h>
#include "../includes/rush.h"

int		my_printf(char *str, ...)
{
  va_list	bj;
  int		i;

  i = -1;
  va_start(bj, str);
  while (str[++i])
    if (str[i] == '%')
      {
	if (str[i + 1] == 'd' || str[i + 1] == 'i')
	  my_put_nbr(va_arg(bj, int));
	else if (str[i + 1] == 's')
	  my_putstr(va_arg(bj, char *));
	else if (str[i + 1] == 'c')
	  my_putchar(va_arg(bj, int));
	else
	  my_putchar(str[i]);
	i = i + 1;
      }
    else
      my_putchar(str[i]);
  va_end(bj);
  return (0);
}
