/*
** suc.c for zappy in /home/carlie_a//zappy-2015-2014s-haulot_a/server/src
** 
** Made by anatole carlier
** Login   <carlie_a@epitech.net>
** 
** Started on  Tue Jun 12 11:18:04 2012 anatole carlier
** Last update Fri Jun 15 15:36:05 2012 randy lyvet
*/

#include 	<stdio.h>

#include	"network.h"

int	suc(char **tab, t_client *client)
{
  tab = tab;

  broadcast_to_one_client("suc\n", client);
  return (0);
}
