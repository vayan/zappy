/*
** init_tab.c for  in /home/lyvet_r//tek2/syst-unix/zappy/zappy-2015-2014s-haulot_a/server
** 
** Made by randy lyvet
** Login   <lyvet_r@epitech.net>
** 
** Started on  Thu Jun 14 12:30:26 2012 randy lyvet
** Last update Thu Jun 14 12:30:28 2012 randy lyvet
*/

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
  tab[4].option = "pnw";
  tab[4].op_func = pnw;
  tab[5].option = "ppo";
  tab[5].op_func = ppo;
  tab[6].option = "plv";
  tab[6].op_func = plv;
  tab[7].option = "pin";
  tab[7].op_func = pin;
  tab[8].option = "pex";
  tab[8].op_func = pex;
  tab[9].option = "pbc";
  tab[9].op_func = pbc;
  tab[10].option = "pic";
  tab[10].op_func = pic;
  tab[11].option = "pie";
  tab[11].op_func = pie;
}

void		init_tab3(t_option *tab)
{
  tab[12].option = "pfk";
  tab[12].op_func = pfk;
  tab[13].option = "pdr";
  tab[13].op_func = pdr;
  tab[14].option = "pgt";
  tab[14].op_func = pgt;
  tab[15].option = "pdi";
  tab[15].op_func = pdi;
  tab[16].option = "enw";
  tab[16].op_func = enw;
  tab[17].option = "eht";
  tab[17].op_func = eht;
  tab[18].option = "ebo";
  tab[18].op_func = ebo;
  tab[19].option = "edi";
  tab[19].op_func = edi;
  tab[20].option = "sgt";
  tab[20].op_func = sgt;
  tab[21].option = "sst";
  tab[21].op_func = sst;
  tab[22].option = "seg";
  tab[22].op_func = seg;
  tab[23].option = "smg";
  tab[23].op_func = smg;
}

void		init_tab4(t_option *tab)
{
  tab[24].option = "suc";
  tab[24].op_func = suc;
  tab[25].option = "sbp";
  tab[25].op_func = sbp;
}

void		init_tab(t_option *tab)
{
  init_tab2(tab);
  init_tab3(tab);
  init_tab4(tab);
}
