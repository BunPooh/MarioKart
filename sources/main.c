/*
** main.c for  in /home/avazas_o/rendu/Rush2
** 
** Made by oleksandr avazashvili
** Login   <avazas_o@epitech.net>
** 
** Started on  Sat Oct 25 9:48:55 2014 oleksandr avazashvili
** Last update Sun Oct 26 18:07:18 2014 oleksandr avazashvili
*/

#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "../includes/rush.h"

void	init(int x, int y)
{
  int	i;
  int	j;

  i = 0;
  while (i < x)
    {
      g_tab[0][i] = '#';
      g_tab[y - 1][i++] = '#';
    }
  i = 0;
  while (i < y)
    {
      g_tab[i][0] = '#';
      g_tab[i++][x - 1] = '#';
    }
  i = 1;
  while (i < y - 1)
    {
      j = 1;
      while (j < x - 1)
	g_tab[i][j++] = ' ';
      i++;
    }
}

void	init_road(int y)
{
  int	i;

  i = 1;
  while (i < y - 1)
    {
      g_tab[i][4] = '%';
      g_tab[i][18] = '%';
      i++;
    }
}

int	init_tab(int x, int y)
{
  int	i;

  i = 0;
  if ((g_tab = malloc(sizeof(char *) * (y + 1))) == NULL)
    return (-1);
  g_tab[y] = NULL;
  while (i < x)
    {
      if ((g_tab[i] = malloc(x + 1)) == NULL)
	return (-1);
      g_tab[i][x] = '\0';
      i++;
    }
  return (0);
}

int	main(int ac, char **av)
{
  int	x;
  int	y;

  if (ac < 3)
    {
      write(1, "Enter screen size please\n", 25);
      return (-1);
    }
  x = my_getnbr(av[1]);
  y = my_getnbr(av[2]);
  if (x < 26 || x > 52 || y < 14 || y > 28)
    {
      my_putstr("Minimal width, height is 26,14 and max 52,28\n");
      return (-1);
    }
  if (init_tab(x, y) == -1)
    my_putstr("Failed\n");
  init(x, y);
  init_road(y);
  start(x, y);
  return (0);
}
