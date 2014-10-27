/*
** my_str_func.c for battleship in /home/de-buy_i/rendu/Battleship
** 
** Made by Ismael De Buyst
** Login   <de-buy_i@epitech.net>
** 
** Started on  Tue Oct 21 08:39:30 2014 Ismael De Buyst
** Last update Sun Oct 26 14:14:49 2014 Ismael De Buyst
*/

#include <stdlib.h>
#include <unistd.h>
#include "../includes/rush.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
}

char	*my_strndup(char *str, int len)
{
  char	*dest;
  int	i;
  int	j;

  dest = NULL;
  i = 0;
  j = 0;
  if (my_strlen(str) < len)
    {
      if ((dest = malloc(sizeof(char) * my_strlen(str))) == NULL)
	return (NULL);
      dest = str;
      return (dest);
    }
  if ((dest = malloc(sizeof(char) * my_strlen(str))) == NULL)
    return (NULL);
  while (i < len)
    dest[j++] = str[i++];
  dest[j] = '\0';
  return (dest);
}

char    *my_strdup(char *str)
{
  char  *dest;

  dest = NULL;
  if ((dest = malloc(my_strlen(str))) == NULL)
    return (NULL);
  dest = str;
  return (dest);
}
