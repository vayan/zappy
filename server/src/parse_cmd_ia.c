/*
** parse_cmd_ia.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/src
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Tue Jun 26 12:55:26 2012 yann vaillant
** Last update Sat Jul 14 11:30:31 2012 yann vaillant
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

int	parse_cmd_ia_classic(char *msg, t_client *cl)
{
  if (strcmp(msg, "avance") == 0)
    return (movefront(cl));
  else if (strcmp(msg, "droite") == 0)
    return (turn_right(cl));
  else if (strcmp(msg, "gauche") == 0)
    return (turn_left(cl));
  else if (strcmp(msg, "inventaire") == 0)
    return (inventory(cl));
  else if (strcmp(msg, "expulse") == 0)
    return (expelliarmus(cl));
  else if (strcmp(msg, "incantation") == 0)
    return (incant(cl, 1));
  else if (strcmp(msg, "fork") == 0)
    return (fork_cl(cl));
  else if (strcmp(msg, "connect_nbr") == 0)
    return (do_connect_nbr(cl));
  else if (strcmp(msg, "voir") == 0)
    return (want_see(cl));
  return (-3);
}

int	parse_cmd_ia_big(t_client *cl, char **tab, char *cmd)
{
  int	ret;

  if (cl->teams != NULL)
    {
      if ((ret = parse_cmd_ia_classic(tab[0], cl)) != -3)
	return (ret);
      else if (strcmp(tab[0], "prend") == 0 &&
	       tab[1] != 0 && parse_rsr(tab[1]) != -1)
	return (take_object(cl, parse_rsr(tab[1])));
      else if (strcmp(tab[0], "pose") == 0 &&
	       tab[1] != 0 && parse_rsr(tab[1]) != -1)
	return (drop_object(cl, parse_rsr(tab[1])));
      else if (strcmp(tab[0], "broadcast") == 0)
	return (broad_ia(cl, get_all_client(NULL, 0), parse_msg(cmd)));
    }
  return (0);
}

int		parse_cmd_ia(char *cmd, t_client *cl)
{
  static char	**tab = NULL;
  static char	*old = NULL;
  char		*tmp;

  if (old != NULL && strcmp(old, cmd) != 0)
    {
      xfree(old);
      xfree(tab[0]);
      xfree(tab);
      old = strdup(cmd);
      tmp = old;
      tab = my_str_to_wordtab(tmp, ' ');
    }
  if (old == NULL)
    {
      old = strdup(cmd);
      tmp = old;
      tab = my_str_to_wordtab(tmp, ' ');
    }
  if (tab == NULL)
    return (0);
  if (cl->teams == NULL && cl->is_graphic == 0)
    get_type_client(tab[0], cl);
  return (parse_cmd_ia_big(cl, tab, cmd));
}
