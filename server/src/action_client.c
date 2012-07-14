/*
** action_client.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/src
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Thu Jun  7 15:37:45 2012 yann vaillant
** Last update Sat Jul 14 11:43:48 2012 robin maitre
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
#include		"command_fonc.h"

void			remove_client_from_team(t_client *to_remove)
{
  if (to_remove->teams != NULL)
    {
      to_remove->teams->left++;
      to_remove->teams->nbr_pl--;
    }
}

int			remove_client_from_list(t_client *to_remove)
{
  t_client		*tmp;

  tmp = get_all_client(NULL, 0);
  while (tmp)
    {
      if (tmp->next != NULL)
        {
          if (tmp->next->fd == to_remove->fd)
            tmp->next = tmp->next->next;
        }
      tmp = tmp->next;
    }
  return (0);
}

int			remove_client(t_client *to_remove)
{
  t_client		*tmp;

  xprintf_ci("\033[1;%sm--Attemp to remove client %d\033[0;0;00m\n",
             COLOR_BLU, to_remove->id);
  if (to_remove->is_graphic == 1)
    get_graphic(NULL, 1);
  remove_client_from_team(to_remove);
  if (to_remove->teams != NULL)
    remove_client_on_map(to_remove);
  tmp = get_all_client(NULL, 0);
  xclose(to_remove->fd);
  if (tmp->fd == to_remove->fd && to_remove->next != NULL)
    {
      get_all_client(to_remove->next, 0);
      return (0);
    }
  if (tmp->fd == to_remove->fd)
    return (0);
  remove_client_from_list(to_remove);
  return (1);
}

void			remove_client_on_map(t_client *cl)
{
  rm_pl(cl->x, cl->y, cl);
  xprintf_ci("\033[1;%sm--Deleting client %d\033[0;0;00m\n",
	     COLOR_BLU, cl->id);
}
