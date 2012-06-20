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

void  rm_top_msg_from_buffer(t_client *cl)
{
  t_buffer_msg *tmp;

  tmp = cl->buff_msg;
  if (cl->buff_msg->next != NULL)
    cl->buff_msg = cl->buff_msg->next;
  else
    cl->buff_msg = NULL;
  free(tmp->msg);
  free(tmp);
}

int    add_msg_to_buffer(t_client *cl, char *msg)
{
  int i;
  t_buffer_msg *tmp;

  tmp = cl->buff_msg;
  if (msg[strlen(msg) - 1] == '\n')
    msg[strlen(msg) - 1] = '\0';    
  i = 0;
  if (tmp == NULL)
  {
    cl->buff_msg = xmalloc(sizeof(t_buffer_msg));
    cl->buff_msg->msg = strdup(msg);
    cl->buff_msg->next = NULL; 
    return (1);
  }
  while (tmp->next)
  {
    tmp = tmp->next;
    i++;
  }
  if (i < 9)
  {
    tmp->next = xmalloc(sizeof(t_buffer_msg));
    tmp->next->msg = strdup(msg);
    tmp->next->next = NULL;
  }
  return (0);
}