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

int   do_connect_nbr(t_client *cl)
{
  char *buff_int;

  buff_int = xmalloc(50 * sizeof(char*));
  sprintf(buff_int, "%d\n", cl->teams->left);
  broadcast_to_one_client(buff_int, cl);
  return (0);
}