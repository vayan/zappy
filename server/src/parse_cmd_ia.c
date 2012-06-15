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
#include "my_strtowordtab.h"

Ressource parse_rsr(char *rsrc)
{
  if (strcmp(rsrc, "nourriture") == 0)
    return (Nourriture);
  if (strcmp(rsrc, "linemate") == 0)
    return (Linemate);
  if (strcmp(rsrc, "deraumere") == 0)
    return (Deraumere);
  if (strcmp(rsrc, "sibur") == 0)
    return (Sibur);
  if (strcmp(rsrc, "mendiane") == 0)
    return (Mendiane);
  if (strcmp(rsrc, "phiras") == 0)
    return (Phiras);
  if (strcmp(rsrc, "thystame") == 0)
    return (Thystame);
  return (-1);
}

int   parse_cmd_ia(char *cmd, t_client *cl)
{
  char **tab;

  tab = my_str_to_wordtab(cmd, ' ');
  if (strcmp (tab[0], "GRAPHIC") == 0)
  {
    cl->is_graphic = 1;
    return (0);
  }
  else if (strcmp(tab[0], "avance") == 0)
    return (MoveFront(cl));
  else if (strcmp(tab[0], "droite") == 0)
    return (turnRight(cl));
  else if (strcmp(tab[0], "gauche") == 0)
    return (turnLeft(cl));
  else if (strcmp(tab[0], "inventaire") == 0)
    return (Inventory(cl));
  else if (strcmp(tab[0], "prend") == 0)
    return(Take_Object(cl, parse_rsr(tab[1])));
  else if (strcmp(tab[0], "pose") == 0)
    return(Drop_Object(cl, parse_rsr(tab[1])));
  else if (strcmp(tab[0], "expulse") == 0)
  {

  }
  else if (strcmp(tab[0], "broadcast") == 0)
  {

  }
  else if (strcmp(tab[0], "incantation") == 0)
  {

  }
  else if (strcmp(tab[0], "fork") == 0)
  {

  }
  else if (strcmp(tab[0], "connect_nbr") == 0)
  {

  }
  else if (strcmp(tab[0], "voir") == 0) 
  {

  }
  return (0);
}