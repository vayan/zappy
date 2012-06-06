#ifndef _CLIENT_H
#define _CLIENT_H

typedef struct      s_client {
  int       fd;
  int       id;
  int       level;
  char      *team;
  struct  s_client  *next;
}    t_client;


t_client    *get_all_client(t_client *_all_client);


#endif