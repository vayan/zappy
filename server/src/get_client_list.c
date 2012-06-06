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

t_client    *get_all_client(t_client *_all_client)
{
  static t_client *client = NULL;

  if (_all_client != NULL)
    client = _all_client;
  return (client);
}