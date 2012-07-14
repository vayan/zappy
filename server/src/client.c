/*
** client.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/src
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Thu Jun  7 15:37:52 2012 yann vaillant
** Last update Sat Jul 14 12:09:16 2012 yann vaillant
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
#include		"option.h"
#include		"command_parser.h"

t_client		*get_graphic(t_client *_cl, int reset)
{
  static t_client	*cl = NULL;

  if (_cl != NULL)
    cl = _cl;
  if (reset == 1)
    cl = NULL;
  return (cl);
}

int			broadcast_to_one_client(char *msg, t_client *me)
{
  t_client		*tmp;
  char			*full_msg;

  if ((me == NULL && me->fd > 0) || strlen(msg) < 2)
    return (0);
  full_msg = xmalloc(MAX_INPUT * sizeof(char*));
  memset(full_msg, 0, MAX_INPUT);
  strcat(full_msg, msg);
  tmp = me;
  if ((xsend(tmp->fd, full_msg,
	     strlen(full_msg), MSG_DONTWAIT | MSG_NOSIGNAL)) == -1)
    remove_client(tmp);
  if (full_msg[strlen(full_msg) - 1] == '\n')
    full_msg[strlen(full_msg) -1] = 0;
  xprintf_cic("\033[1;%sm-->\tSend message to %d : '%s'\033[0;0;00m\n",
	      RED, me->id, full_msg);
  xfree(full_msg);
  return (0);
}

int			do_input_client(t_client *all_client)
{
  t_client		*tmp;
  t_option		*tab;

  if (all_client == NULL)
    return (0);
  tab = xmalloc (9 * sizeof(t_option));
  init_tab(tab);
  tmp = all_client;
  while (tmp)
    {
      if (tmp->buff_msg != NULL && tmp->is_graphic == 1)
	{
	  if (command_parser(tab, tmp->buff_msg->msg, tmp) == 0)
	    rm_top_msg_from_buffer(tmp);
	}
      else if (tmp->buff_msg != NULL && tmp->is_graphic == 0)
	{
	  if (parse_cmd_ia(tmp->buff_msg->msg, tmp) == 0)
	    rm_top_msg_from_buffer(tmp);
	}
      tmp = tmp->next;
    }
  return (0);
}
