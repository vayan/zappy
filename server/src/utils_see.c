/*
** utils_see.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/src
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Mon Jul  2 11:56:17 2012 yann vaillant
** Last update Mon Jul  2 11:56:21 2012 yann vaillant
*/

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

void set_y_see(t_client *cl, int *y, int lvl, int i)
{
  if (cl->dir == Down)
    *y = cl->y + lvl;
  if (cl->dir == Up)
    *y = cl->y - lvl;
  if (cl->dir == Right)
    *y = (cl->y - lvl) + i;
  if (cl->dir == Left)
    *y = (cl->y + lvl) - i;

}
void  set_x_see(t_client *cl, int *x, int lvl, int i)
{
  if (cl->dir == Down)
    *x = (cl->x + lvl) - i;
  if (cl->dir == Up)
    *x = (cl->x - lvl) + i;
  if (cl->dir == Right)
    *x = cl->x + lvl;
  if (cl->dir == Left)
    *x = cl->x - lvl;
}
