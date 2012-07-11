/*
** inventory.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/src
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Thu Jun 14 15:40:05 2012 yann vaillant
** Last update Tue Jul 10 11:24:59 2012 robin maitre
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
#include "client.h"

char	*inttochar(int i)
{
  char	*buff_int;

  buff_int = xmalloc(16 * sizeof(char*));
  sprintf(buff_int, "%d", i);
  return (buff_int);
}

void	send_invent(t_client *cl)
{
  char	*invent;
  char *tmp;

  invent = xmalloc(500 * sizeof(char*));
  memset(invent, 0, 500);

  strcat(invent, "{nourriture ");
  tmp = inttochar(cl->rsrc[Nourriture]);
  strcat(invent, tmp);
  xfree(tmp);

  strcat(invent, ",linemate ");
  tmp = inttochar(cl->rsrc[Linemate]);
  strcat(invent, tmp);
   xfree(tmp);


  strcat(invent, ",deraumere ");
  tmp = inttochar(cl->rsrc[Deraumere]);
  strcat(invent, tmp);
  xfree(tmp);

  strcat(invent, ",sibur ");
  tmp = inttochar(cl->rsrc[Sibur]);
  strcat(invent, tmp);
  xfree(tmp);

  strcat(invent, ",mendiane ");
  tmp = inttochar(cl->rsrc[Mendiane]);
  strcat(invent, tmp);
  xfree(tmp);

  strcat(invent, ",phiras ");
  tmp = inttochar(cl->rsrc[Phiras]);
  strcat(invent, tmp);
  xfree(tmp);

  strcat(invent, ",thystame ");
  tmp = inttochar(cl->rsrc[Thystame]);
  strcat(invent, tmp);
  xfree(tmp);

  strcat(invent, "}\n");
  broadcast_to_one_client(invent, cl);
  xfree(invent);
}

int		inventory(t_client *cl)
{
  t_setting	*setting;

  if (cl->stm->in_use != -1 && cl->stm->in_use != Inventaire)
    return (1);
  if (cl->stm->in_use == -1)
    {
      cl->stm->in_use = Inventaire;
      start_timer(cl->stm);
      return (1);
    }
  setting = get_setting(NULL);
  set_elapse_time(cl->stm);
  set_elapse_sec(cl->stm);
  if (cl->stm->in_use == Inventaire &&
      ((cl->stm->in_nsec) >= (1000000000/setting->delay)))
    {
      cl->stm->in_use = -1;
      send_invent(cl);
      return (0);
    }
  return (1);
}
