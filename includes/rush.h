/*
** rush.h for  in /home/avazas_o/rendu/Rush2
** 
** Made by oleksandr avazashvili
** Login   <avazas_o@epitech.net>
** 
** Started on  Sun Oct 26 11:03:41 2014 oleksandr avazashvili
** Last update Sun Oct 26 18:44:20 2014 oleksandr avazashvili
*/

#ifndef RUSH_H_
# define RUSH_H_

char	**g_tab;

void	start(int , int);
void	init(int, int);
void	init_road(int);
void	aff(int	, int);
void	start(int, int);
void    advance(int, int);
void	del_car(int, int);
void	random_road(int , int);
void	my_put_nbr(int);
void	my_putchar(char);
void	my_putstr(char *);
void	lets_turn(int, int);
int	my_printf(char *, ...);
int	my_strlen(char *);
int	my_getnbr(char *);
int	init_tab(int, int);
int	score(int);
int	my_random(int);
int	car_pos(int, int, int *);
char	*my_strdup(char *);
char	*my_strndup(char *, int);

#endif	/* RUSH_H_ */
