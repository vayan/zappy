/*
** action_client.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/src
** 
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
** 
** Started on  Thu Jun  7 15:37:45 2012 yann vaillant
** Last update Thu Jun  7 15:37:46 2012 yann vaillant
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

int   remove_client(t_client *to_remove)
{
  t_client  *tmp;

  printf("\033[1;%sm--Attemp to remove client %d\033[0;0;00m\n", COLOR_BLU, to_remove->id);
    xclose(to_remove->fd);
    remove_client_on_map(to_remove);
    tmp = get_all_client(NULL);
    if (tmp->fd == to_remove->fd)
    {
      tmp->fd = -1;
    //aff_map(); // debug
      return (0);
    }
    while (tmp)
    {
      if (tmp->next != NULL)
      {
        if (tmp->next->fd == to_remove->fd)
          tmp->next = tmp->next->next;
      }
      tmp = tmp->next;
    }
  //aff_map(); //debug
    return (1);
  }

  void      remove_client_on_map(t_client *cl)
  {
    rm_pl(cl->x, cl->y, cl);
    printf("\033[1;%sm--Deleting client %d\033[0;0;00m\n", COLOR_BLU, cl->id);
  }

  void      add_client_on_map(t_client *new)
  {
    t_setting *setting;

    setting = get_setting(NULL);
    new->x = random() % setting->width_map;
    new->y = random() % setting->height_map;
    printf("\033[1;%sm--Added new player %d on (%d, %d)\033[0;0;00m\n", 
      COLOR_BLU, new->id, new->x, new->y);
    add_pl(new->x, new->y, new);
  }

  t_client  *add_client(t_client *all_client, int fd)
  {
    t_client  *tmp;
    t_client  *new;
    t_setting *setting;

    char *buff_int;

    buff_int = xmalloc(50 * sizeof(char*));

    setting = get_setting(NULL);
    static int  id = 0;

    new = xmalloc(sizeof(t_client));
    tmp = all_client;
    new->fd = fd;
    new->id = id++;
    new->next = NULL;
    new->stm = xmalloc(sizeof(t_serv_time));
    new->stm->in_use = -1;
    new->rsrc = xmalloc(7 * sizeof(int));
    new->buff_msg = NULL;
    new->is_graphic = 0;
    memset(new->rsrc, 0, 7 * sizeof(int));
    add_client_on_map(new);
    broadcast_to_one_client("BIENVENUE\n", new);
    sprintf(buff_int, "%d\n", new->id);
    broadcast_to_one_client(buff_int, new);
    sprintf(buff_int, "%d %d\n", setting->width_map, setting->height_map);
    broadcast_to_one_client(buff_int, new);
    if (get_graphic(NULL) != NULL)
      pnw(NULL, get_graphic(NULL));
  //aff_map(); //debug
    if (tmp == NULL)
      return (new);
    while (tmp->next)
      tmp = tmp->next;
    tmp->next = new;
    return (NULL);
  }
