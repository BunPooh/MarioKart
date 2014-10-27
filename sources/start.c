/*
** start.c for  in /home/avazas_o/rendu/Rush2
** 
** Made by oleksandr avazashvili
** Login   <avazas_o@epitech.net>
** 
** Started on  Sat Oct 25 10:05:52 2014 oleksandr avazashvili
** Last update Sun Oct 26 18:09:27 2014 oleksandr avazashvili
*/

#include <time.h>
#include <unistd.h>
#include <ncurses/curses.h>
#include "../includes/rush.h"

int		car_pos(int y, int nb, int *bonus)
{
  static int	pos = 12;

  pos += nb;
  if (g_tab[y - 2][pos] == '%' || g_tab[y - 3][pos] == '%' ||
      g_tab[y - 2][pos + 1] == '%' || g_tab[y - 3][pos + 1] == '%' ||
      g_tab[y - 2][pos + 2] == '%' || g_tab[y - 3][pos + 2] == '%')
    return (-1);
  if ((g_tab[y - 2][pos] >= 'B' && g_tab[y - 2][pos] <= 'L') ||
      (g_tab[y - 3][pos] >= 'B' && g_tab[y - 3][pos] <= 'L') ||
      (g_tab[y - 2][pos + 1] >= 'B' && g_tab[y - 2][pos + 1] <= 'L') ||
      (g_tab[y - 3][pos + 1] >= 'B' && g_tab[y - 3][pos + 1] <= 'L') ||
      (g_tab[y - 2][pos + 2] >= 'B' && g_tab[y - 2][pos + 2] <= 'L') ||
      (g_tab[y - 3][pos + 2] >= 'B' && g_tab[y - 3][pos + 2] <= 'L'))
    *bonus += 20;
  g_tab[y - 2][pos] = 'o';
  g_tab[y - 3][pos] = 'o';
  g_tab[y - 2][pos + 1] = 'M';
  g_tab[y - 3][pos + 1] = 'A';
  g_tab[y - 2][pos + 2] = 'o';
  g_tab[y - 3][pos + 2] = 'o';
  return (0);
}

void		del_car(int x, int y)
{
  int		i;
  int		j;

  i = 0;
  while (i < y)
    {
      j = 0;
      while (j < x)
	{
	  if (g_tab[i][j] == 'o' || g_tab[i][j] == 'M' || g_tab[i][j] == 'A')
	    g_tab[i][j] = ' ';
	  j++;
	}
      i++;
    }
}

void		advance(int x, int y)
{
  int	i;
  int	j;

  i = y - 2;
  while (i > 1)
    {
      j = 1;
      while (j < x - 1)
	{
	  g_tab[i][j] = g_tab[i - 1][j];
	  j++;
	}
      i--;
    }
}

void		start(int x, int y)
{
  WINDOW	*disp;

  disp = initscr();
  if (cbreak() == ERR || noecho() == ERR
      || keypad(disp, TRUE) == ERR || nodelay(disp ,TRUE) == ERR)
    {
      my_putstr("ICI A CHANGER\n");
      return ;
    }
  curs_set(false);
  lets_turn(x, y);
}
