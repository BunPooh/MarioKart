/*
** my_nbr_func.c for battleship in /home/de-buy_i/rendu/Battleship
** 
** Made by Ismael De Buyst
** Login   <de-buy_i@epitech.net>
** 
** Started on  Tue Oct 21 08:39:15 2014 Ismael De Buyst
** Last update Sun Oct 26 14:08:55 2014 Ismael De Buyst
*/

#include "../includes/rush.h"

void	my_put_nbr(int nb)
{
  int	div;

  div = 1;
  if (nb == 0)
    my_putchar('0');
  while (div <= nb)
    div = div * 10;
  div = div / 10;
  while (div > 0)
    {
      my_putchar((nb / div) + 48);
      nb = nb % div;
      div = div / 10;
    }
}

int	my_getnbr(char *nb)
{
  int	nbr;
  int	sng;
  int	i;

  i = 0;
  sng = 1;
  nbr = 0;
  while (nb[i] == '-' || nb[i] == '+')
    {
      if (nb[i] == '-')
	sng = sng * -1;
      i++;
    }
  while (nb[i] >= '0' && nb[i] <= '9')
    {
      nbr = (nbr + (nb[i] - 48));
      i++;
      nbr = nbr * 10;
    }
  if (sng < 0)
    return (-(nbr / 10));    
  return (nbr / 10);
}
