/*
** new_client_is_ia.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/src
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Mon Jul  2 11:55:35 2012 yann vaillant
** Last update Mon Jul  2 11:55:39 2012 yann vaillant
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
#include "option.h"
#include "client.h"
#include "map.h"
#include "setting.h"
#include "my_strtowordtab.h"
#include "command_fonc.h"

int   client_team_init(t_client *cl, char *cmd, t_team *tm)
{
  cl->teams = check_team(cmd);
  cl->death->in_use = -1;
  cl->teams->nbr_pl++;
  tm->left--;
  if (cl->teams->nbr_pl >= tm->max)
  {
    if (cl->teams->egg != NULL)
    {
      cl->y = cl->teams->egg->y;
      cl->x = cl->teams->egg->x; 
      ebo(cl->teams->egg->id, cl);
      cl->teams->egg = cl->teams->egg->next;
    }
  }
  return (0);
}

void  send_message_start_client(t_client *cl)
{
  char *buff_int;
  t_setting *setting;

  buff_int = xmalloc(50 * sizeof(char*));
  setting = get_setting(NULL);
  sprintf(buff_int, "%d\n", cl->id);
  broadcast_to_one_client(buff_int, cl);
  sprintf(buff_int, "%d %d\n", setting->width_map, setting->height_map);
  broadcast_to_one_client(buff_int, cl);
  free(buff_int);
}

int   get_type_client(char *cmd, t_client *cl)
{
  t_team *tm;

  if (strcmp (cmd, "GRAPHIC") == 0)
  {
    cl->is_graphic = 1;
    get_graphic(cl, 0);
    first_data_graphic(cl);
    return (0);
  }
  else if (cl->teams == NULL && (tm = check_team(cmd)) != NULL)
  {
    check_place_left_in_team(cl, cmd, tm);
    client_team_init(cl, cmd, tm);
    add_client_on_map(cl);
    send_message_start_client(cl);
    pnw(NULL, cl);
    return (0);
  }
  remove_client(cl);
  return (1);
}
