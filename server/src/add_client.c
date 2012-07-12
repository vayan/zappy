/*
** add_client.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/src
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Mon Jul  2 11:53:32 2012 yann vaillant
** Last update Mon Jul  9 12:33:53 2012 vailla_y
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <time.h>
#include <signal.h>
#include "network.h"
#include "xfunc.h"
#include "map.h"
#include "setting.h"
#include "command_fonc.h"

void		add_client_on_map(t_client *new)
{
  t_setting	*setting;

  setting = get_setting(NULL);
  if (new->x == -1 && new->y == -1)
  {
    new->x = random() % setting->width_map;
    new->y = random() % setting->height_map;
  }
  printf("\033[1;%sm--Added new player %d on (%d, %d)\033[0;0;00m\n",
   COLOR_BLU, new->id, new->x, new->y);
  add_pl(new->x, new->y, new);
}

void	init_val_new_client(t_client *new, int fd, int id)
{
  new->x = -1;
  new->y = -1;
  new->level = 1;
  new->fd = fd;
  new->id = id;
  new->next = NULL;
  new->teams = NULL;
  new->stm = xmalloc(sizeof(t_serv_time));
  new->stm->in_use = -1;
  new->death = xmalloc(sizeof(t_serv_time));
  new->death->in_use = 2;
  new->rsrc = xmalloc(7 * sizeof(int));
  new->buff_msg = NULL;
  new->is_graphic = 0;
  memset(new->rsrc, 0, 7 * sizeof(int));
  new->rsrc[Nourriture] = 10;
}

t_client	*add_client(t_client *all_client, int fd)
{
  t_client	*tmp;
  t_client	*new;
  static int	id = 0;

  if (id >= 1000000000)
    id = 0;
  new = xmalloc(sizeof(t_client));
  tmp = all_client;
  init_val_new_client(new, fd, id);
  id++;
  broadcast_to_one_client("BIENVENUE\n", new);
  if (tmp == NULL)
    return (new);
  while (tmp->next)
    tmp = tmp->next;
  tmp->next = new;
  return (NULL);
}
