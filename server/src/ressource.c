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

char  *Ressource_to_char(Ressource rsrc)
{
  char *ret;

  ret = xmalloc(15 * sizeof(*ret));
  memset(ret, 0, 15);
  if (rsrc == Nourriture)
    strcat(ret, "nourriture");
  if (rsrc == Linemate)
    strcat(ret, "linemate");
  if (rsrc == Deraumere)
    strcat(ret, "deraumere");
  if (rsrc == Sibur)
    strcat(ret, "sibur");
  if (rsrc == Mendiane)
    strcat(ret, "mendiane");
  if (rsrc == Phiras)
    strcat(ret, "phiras");
  if (rsrc == Thystame)
    strcat(ret, "thystame");
  return (ret);
}

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