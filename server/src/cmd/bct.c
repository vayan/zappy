/*
** bct.c for zappy in /home/carlie_a//zappy-2015-2014s-haulot_a/server/src
** 
** Made by anatole carlier
** Login   <carlie_a@epitech.net>
** 
** Started on  Thu Jun  7 14:54:41 2012 anatole carlier
** Last update Thu Jun 14 14:38:33 2012 anatole carlier
*/

#include <stdio.h>
#include <xfunc.h>

int	bct(char **tab)
{
  char	*str;

  str = xmalloc(sizeof(char) * 1024);
  sprintf(str, "bct %s %s %s %s %s %s %s %s %s\n", tab[1], tab[2], tab[3], 
	  tab[4], tab[5], tab[6], tab[7], tab[8], tab[9]);
  return (0);
}
