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

char *clean_see(char *msg)
{
  int i;
  int j;
  char  *msg_clean;

  msg_clean = xmalloc (100000 * sizeof(*msg_clean));
  memset(msg_clean, 0, 100000);
  i = 0;
  j = 0;
  while (msg[i])
  {
    if (i > 0 && msg[i - 1] == '{' && msg[i] == ' ')
      i++;
    if (msg[i] == ' ' && msg[i + 1] == ',')
      i++;
    if (msg[i] == ' ' && msg[i + 1] == ' ')
      i++;
    msg_clean[j] = msg[i];
    i++;
    j++; 
  }
  return (msg_clean);
}

void strcat_player(t_pl_case *tmp, char *msg)
{
  while (tmp)
  {
    strcat(msg," joueur ");
    tmp = tmp->next;
  }  
}

void  strcat_rsrc(Ressource *rsrc, char *msg)
{ 
  int i;
  int j;

  i = 0;
  while (rsrc[i])
  {
    j = 0;
    while (j < rsrc[i])
    {
      strcat(msg, " ");
      strcat(msg, Ressource_to_char(rsrc[i]));
      strcat(msg, " ");
      j++;
    }
    i++;
  }
}