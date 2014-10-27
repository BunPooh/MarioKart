/*
** random.c for  in /home/avazas_o/rendu/Rush2
** 
** Made by oleksandr avazashvili
** Login   <avazas_o@epitech.net>
** 
** Started on  Sat Oct 25 10:40:41 2014 oleksandr avazashvili
** Last update Sun Oct 26 18:43:33 2014 oleksandr avazashvili
*/

#include <ncurses/curses.h>
#include <time.h>
#include "../includes/rush.h"

void	aff(int x, int y)
{
  int	i;
  int	j;

  i = 0;
  while (i < y)
    {
      j = -1;
      while (++j < x)
	{
	  if (g_tab[i][j] >= 'B' && g_tab[i][j] <= 'K')
	    g_tab[i][j] += 1;
	  else if (g_tab[i][j] == 'L')
	    g_tab[i][j] = 'B';
	  mvprintw(i, j, "%c", g_tab[i][j]);
	}
      i++;
    }
}

int		my_random(int max)
{
  static int	i = 0;
  time_t	t;

  t = time(&t);
  i++;
  if (i == 100)
    i = 1;
  t = t / i;
  while (t > max)
    t = t % max;
  return (t);
}

void		random_road(int x, int rdm)
{
  static int	pos = 4;

  rdm = my_random(3);
  if (rdm == 1 && pos != 1)
    pos -= 1;
  else if (rdm == 2 && pos < x - 16)
    pos += 1;
  rdm = 1;
  while (rdm < x - 1)
    g_tab[1][rdm++] = ' ';
  g_tab[1][pos] = '%';
  g_tab[1][pos + 14] = '%';
  rdm = my_random(15);
  if (rdm == 0)   
    g_tab[1][pos + 7] = 'B';
  if (rdm == 2)
    {
      g_tab[1][pos + 2] = '%';
      g_tab[1][pos + 3] = '%';
    }
  if (rdm == 1)
    {
      g_tab[1][pos + 11] = '%';
      g_tab[1][pos + 12] = '%';
    }
}

int		score(int srt)
{
  time_t	now;

  time(&now);
  return (1 + (now - srt) * 0.2);
}
