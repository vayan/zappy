/*
** client.h for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/include
** 
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
** 
** Started on  Thu Jun  7 15:38:47 2012 yann vaillant
** Last update Thu Jun  7 15:38:48 2012 yann vaillant
*/

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
