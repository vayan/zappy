#ifndef _CLIENT_H
#define _CLIENT_H

typedef void (*sighandler_t)(int);

typedef struct      s_client {
  int       fd;
  int       id;
  struct  s_client  *next;
}    t_client;


t_client    *get_all_client(t_client *_all_client);


#endif