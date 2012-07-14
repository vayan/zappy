/*
** mct.c for zappy in /home/carlie_a//zappy-2015-2014s-haulot_a/server/src
**
** Made by anatole carlier
** Login   <carlie_a@epitech.net>
**
** Started on  Thu Jun  7 15:27:10 2012 anatole carlier
** Last update Sat Jul 14 13:03:22 2012 robin maitre
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#include	"xfunc.h"
#include	"network.h"
#include	"setting.h"
#include	"command_fonc.h"
#include	"map.h"

int		mct(char **tab, t_client *client)
{
  t_setting	*settings;
  char		*str;
  int		x;
  int		y;

  settings = get_setting(NULL);
  x = -1;
  tab = tab;
  while (++x < settings->width_map)
    {
      y = 0;
      while (y < settings->height_map)
        {
          str = xmalloc(sizeof(char) * 1024);
          str = map_contents(str, x, y);
          broadcast_to_one_client(str, client);
          y++;
          xfree(str);
        }
    }
  return (0);
}

char		*map_contents(char *str, int x, int y)
{
  t_map_case	***c_case;

  c_case = get_map(NULL);
  sprintf(str, "bct %i %i %i %i %i %i %i %i %i\n", x, y,
          (c_case[x][y])->rsrc[Nourriture],
          (c_case[x][y])->rsrc[Linemate],
          (c_case[x][y])->rsrc[Deraumere], (c_case[x][y])->rsrc[Sibur],
          (c_case[x][y])->rsrc[Mendiane], (c_case[x][y])->rsrc[Phiras],
          (c_case[x][y])->rsrc[Thystame]);
  return (str);
}
