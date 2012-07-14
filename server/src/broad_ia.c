/*
** broad_ia.c for zappy in /home/carlie_a//zappy-2015-2014s-haulot_a/server/src
**
** Made by anatole carlier
** Login   <carlie_a@epitech.net>
**
** Started on  Wed Jun 20 11:13:20 2012 anatole carlier
** Last update Sat Jul 14 12:14:42 2012 robin maitre
*/

#include		<sys/types.h>
#include		<sys/socket.h>
#include		<netinet/in.h>
#include		<arpa/inet.h>
#include		<sys/time.h>
#include		<unistd.h>
#include		<stdio.h>
#include		<string.h>
#include		<stdlib.h>
#include		<sys/types.h>
#include		<sys/ipc.h>
#include		<time.h>
#include		<signal.h>

#include		"network.h"
#include		"xfunc.h"
#include		"map.h"
#include		"setting.h"
#include		"client.h"
#include		"command_fonc.h"

int			broad_ia(t_client *cl, t_client *all_client, char *msg)
{
  t_setting		*setting;

  if (cl->stm->in_use != -1 && cl->stm->in_use != Say)
    return (1);
  if (cl->stm->in_use == -1)
    {
      cl->stm->in_use = Say;
      start_timer(cl->stm);
      return (1);
    }
  setting = get_setting(NULL);
  set_elapse_time(cl->stm);
  set_elapse_sec(cl->stm);
  if (cl->stm->in_use == Say &&
      ((cl->stm->in_nsec) >= (7000000000/setting->delay)))
    {
      cl->stm->in_use = -1;
      do_say(cl, all_client, msg);
      return (0);
    }
  return (1);
}

int			do_say(t_client *me, t_client *all_client, char *msg)
{
  t_client		*tmp;
  char			*str;

  tmp = all_client;
  while (tmp)
    {
      if (tmp != me && tmp->teams != NULL)
        {
          str = xmalloc(sizeof(char) * (strlen(msg) + 11 + 13));
          sprintf(str, "message %i,%s\n", get_direction(me, tmp), msg);
          broadcast_to_one_client(str, tmp);
          xfree(str);
        }
      tmp = tmp->next;
    }
  pbc(msg, me);
  broadcast_to_one_client("ok\n", me);
  return (0);
}

char			*parse_msg(char *msg)
{
  int			i;

  i = 0;
  while (msg[i] != '\0' && msg[i] != ' ')
    msg++;
  if (msg[i] != '\0')
    msg++;
  return (msg);
}
