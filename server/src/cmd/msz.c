/*
** msz.c for zappy in /home/carlie_a//zappy-2015-2014s-haulot_a/server/src
** 
** Made by anatole carlier
** Login   <carlie_a@epitech.net>
** 
** Started on  Thu Jun  7 14:36:31 2012 anatole carlier
** Last update Thu Jun 14 14:16:03 2012 anatole carlier
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "xfunc.h"
#include "setting.h"
#include "command_fonc.h"

int		msz(char **tab)
{
  char		*str;

  str = xmalloc(sizeof(char) * 64);
  sprintf(str, "msz %s %s\n", tab[1], tab[2]);
  printf(str);
  return (0);
}
