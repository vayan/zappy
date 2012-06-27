/*
** init_tab.c for  in /home/lyvet_r//tek2/syst-unix/zappy/zappy-2015-2014s-haulot_a/server
** 
** Made by randy lyvet
** Login   <lyvet_r@epitech.net>
** 
** Started on  Thu Jun 14 12:30:26 2012 randy lyvet
** Last update Thu Jun 14 12:30:28 2012 randy lyvet
*/

#include  <string.h>
#include	"option.h"
#include	"command_fonc.h"

void		init_tab2(t_option *tab)
{
  tab[0].option = "msz";
  tab[0].op_func = msz;
  tab[1].option = "bct";
  tab[1].op_func = bct;
  tab[2].option = "mct";
  tab[2].op_func = mct;
  tab[3].option = "tna";
  tab[3].op_func = tna;
  tab[4].option = "ppo";
  tab[4].op_func = ppo;
  tab[5].option = "plv";
  tab[5].op_func = plv;
  tab[6].option = "pin";
  tab[6].op_func = pin;
}

void		init_tab3(t_option *tab)
{
  tab[7].option = "sgt";
  tab[7].op_func = sgt;
  tab[8].option = "sst";
  tab[8].op_func = sst;
}

void		init_tab(t_option *tab)
{
  memset(tab, 0, TAB_SIZE);
  init_tab2(tab);
  init_tab3(tab);
}
