//
// IA.hh for IA in /home/haulot_a//zappy-2015-2014s-haulot_a/IA
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Thu Jun 14 12:06:09 2012 alexandre haulotte
// Last update Thu Jun 14 12:59:22 2012 alexandre haulotte
//

#ifndef	__IA_HH__
#define	__IA_HH__

#include	<map>

typedef int (Player::*fct)(void);

std::map<int, std::map<int, int> > trTable;
std::map<int, fct > fctTable;

#endif
