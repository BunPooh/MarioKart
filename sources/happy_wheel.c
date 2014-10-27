/*
** happy_wheel.c for MarioKart in /home/de-buy_i/rendu/ReRush1/sources
** 
** Made by Ismael De Buyst
** Login   <de-buy_i@epitech.net>
** 
** Started on  Sun Oct 26 15:20:40 2014 Ismael De Buyst
** Last update Mon Oct 27 10:18:53 2014 Ismael De Buyst
*/

#include <unistd.h>
#include <ncurses/curses.h>
#include <time.h>
#include "../includes/rush.h"

void		lets_turn(int x, int y)
{
  time_t	srt;
  int		c;
  int		bonus;

   bonus = 0;
  time(&srt);
  while (1)
    {
      advance(x, y);
      random_road(x, 0);
      del_car(x, y);
      c = getch();
      if (c == 260)
	car_pos(y, -1, &bonus);
      else if (c == 261)
	car_pos(y, 1, &bonus);
      if (car_pos(y, 0, &bonus) == -1)
        {
          endwin();
          return ;
        }
      aff(x, y);
      usleep(50000);
      mvprintw(y + 1, 0,"score : %d\n", bonus + score(srt));
    }
}
