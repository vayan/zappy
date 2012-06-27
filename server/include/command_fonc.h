/*
** command_fonc.h for  in /home/lyvet_r//tek2/syst-unix/zappy/zappy-2015-2014s-haulot_a/server
** 
** Made by randy lyvet
** Login   <lyvet_r@epitech.net>
** 
** Started on  Tue Jun 12 14:41:40 2012 randy lyvet
** Last update Tue Jun 26 10:25:24 2012 robin maitre
*/

#ifndef COMMAND_FONC_
# define COMMAND_FONC_

#include "setting.h"
#include "network.h"

int	msz(char **command, t_client *client);
int	bct(char **command, t_client *client);
int	mct(char **command, t_client *client);
int	tna(char **command, t_client *client);
int	pnw(char **command, t_client *client);
int	ppo(char **command, t_client *client);
int	plv(char **command, t_client *client);
int	pin(char **command, t_client *client);
int	pex(char **command, t_client *client);
int	pfk(char **command, t_client *client);
int	eht(int id, t_client *client);
int	ebo(int id, t_client *client);
int	sgt(char **command, t_client *client);
int	sst(char **command, t_client *client);
int	seg(char **command, t_client *client);
int	smg(char *mess, t_client *client);
int	suc(char **command, t_client *client);
int	sbp(char **command, t_client *client);
char	*map_contents(char *str, int x, int y);

#endif /* !COMMAND_FONC_ */
