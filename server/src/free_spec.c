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
#include "setting.h"
#include "map.h"
#include "client.h"

int  free_buff_msg(t_buffer_msg *buff_msg)
{
  t_buffer_msg *tmp;

  if (buff_msg == NULL)
    return (1);
  while (buff_msg)
  {
    tmp = buff_msg;
    if (buff_msg->msg != NULL)
      free(buff_msg->msg);
    buff_msg = buff_msg->next;
    if (tmp != NULL)
      free(tmp);
  }
  return (0);
}

int   free_client_map(t_pl_case *client)
{
 t_pl_case *tmp;

 if (client == NULL)
  return (0);
while (client)
{
  tmp = client;
  if (client->client != NULL)
    free(client->client);
  client = client->next;
  if (tmp != NULL)
    free (tmp);
}
free(client);
return (1);
}