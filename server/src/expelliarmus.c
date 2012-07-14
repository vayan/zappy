/*
** expelliarmus.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/src
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Tue Jun 26 12:53:38 2012 yann vaillant
** Last update Sat Jul 14 12:30:14 2012 robin maitre
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
#include "command_fonc.h"

void		move_kicker(t_client *kicker, t_client *victim)
{
  t_setting	*setting;

  rm_pl(victim->x, victim->y, victim);
  setting = get_setting(NULL);
  correction_down(victim, kicker, setting);
  correction_up(victim, kicker, setting);
  correction_right(victim, kicker, setting);
  correction_left(victim, kicker, setting);
  add_pl(victim->x, victim->y, victim);
}

void		do_expelliarmus_broad(t_client *cl, t_pl_case   *tmp)
{
  char		*msg;
  char		*temp;

  msg = xmalloc(50 * sizeof(*msg));
  memset(msg, 0, 50);
  strcat(msg, "deplacement: ");
  temp = inttochar(get_direction(cl, tmp->client));
  strcat(msg, temp);
  strcat(msg, "\n");
  broadcast_to_one_client(msg, tmp->client);
  xfree(temp);
  xfree(msg);
}

int		do_expelliarmus(t_client *cl)
{
  t_map_case	***map;
  t_pl_case	*tmp;
  int		max;

  max = 0;
  map = get_map(NULL);
  tmp = (map[cl->x][cl->y])->client;
  if (tmp->next == NULL)
    return (-1);
  pex(NULL, cl);
  while (tmp && max >= 100)
    {
      if (tmp->client->id != cl->id)
        {
          do_expelliarmus_broad(cl, tmp);
          move_kicker(cl, tmp->client);
          max++;
        }
      tmp = tmp->next;
    }
  return (0);
}

int		expelliarmus(t_client *cl)
{
  t_setting	*setting;

  if (cl->stm->in_use != -1 && cl->stm->in_use != Kick)
    return (1);
  if (cl->stm->in_use == -1)
    {
      cl->stm->in_use = Kick;
      start_timer(cl->stm);
      return (1);
    }
  setting = get_setting(NULL);
  set_elapse_time(cl->stm);
  set_elapse_sec(cl->stm);
  if (cl->stm->in_use == Kick &&
      ((cl->stm->in_nsec) >= (7000000000/setting->delay)))
    {
      cl->stm->in_use = -1;
      if (do_expelliarmus(cl) == -1)
        broadcast_to_one_client("ko\n", cl);
      else
        broadcast_to_one_client("ok\n", cl);
      return (0);
    }
  return (1);
}
