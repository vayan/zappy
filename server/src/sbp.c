/*
** sbp.c for zappy in /home/carlie_a//zappy-2015-2014s-haulot_a/server/src
**
** Made by anatole carlier
** Login   <carlie_a@epitech.net>
**
** Started on  Tue Jun 12 11:18:39 2012 anatole carlier
** Last update Tue Jul 10 11:32:42 2012 alexandre haulotte
*/

#include <stdio.h>
#include <stdlib.h>

#include "xfunc.h"
#include "command_fonc.h"
#include "network.h"
#include "setting.h"

int		sbp(char **tab, t_client *client)
{
  t_client	*graphic;

  tab = tab;
  client = client;
  graphic = get_graphic(NULL, 0);
  if (graphic == NULL)
    return (0);
  broadcast_to_one_client("sbp\n", graphic);
  return (0);
}
