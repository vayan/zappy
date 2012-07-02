/*
** parse_cmd_ia.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/src
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Tue Jun 26 12:55:26 2012 yann vaillant
** Last update Mon Jul  2 12:05:18 2012 yann vaillant
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

int parse_cmd_ia_classic(char *msg, t_client *cl)
{
  if (strcmp(msg, "avance") == 0)
    return (MoveFront(cl));
  else if (strcmp(msg, "droite") == 0)
    return (turnRight(cl));
  else if (strcmp(msg, "gauche") == 0)
    return (turnLeft(cl));
  else if (strcmp(msg, "inventaire") == 0)
    return (Inventory(cl));
  else if (strcmp(msg, "expulse") == 0)
    return (expelliarmus(cl));
  else if (strcmp(msg, "incantation") == 0)
    return (incant(cl));
  else if (strcmp(msg, "fork") == 0)
    return (fork_cl(cl));
  else if (strcmp(msg, "connect_nbr") == 0)
    return (do_connect_nbr(cl));
  else if (strcmp(msg, "voir") == 0)
    return (Want_See(cl));
  return (-3);
}

int   parse_cmd_ia(char *cmd, t_client *cl)
{
  char **tab;
  int   ret;

  tab = my_str_to_wordtab(cmd, ' ');
  get_type_client(tab[0], cl);
  if (cl->teams != NULL)
    {
      ret = parse_cmd_ia_classic(tab[0], cl);
      if (ret != -3)
        return (ret);
      else if (strcmp(tab[0], "prend") == 0 && parse_rsr(tab[1]) != -1)
        return (Take_Object(cl, parse_rsr(tab[1])));
      else if (strcmp(tab[0], "pose") == 0 && parse_rsr(tab[1]) != -1)
        return (Drop_Object(cl, parse_rsr(tab[1])));
      else if (strcmp(tab[0], "broadcast") == 0)
        return (broad_ia(cl, get_all_client(NULL), parse_msg(cmd)));
    }
  return (0);
}
