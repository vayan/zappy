//
// PlayerCreator.hh for PlCreator in /home/haulot_a//zappy-2015-2014s-haulot_a/client
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Tue Jun 12 10:42:26 2012 alexandre haulotte
// Last update Fri Jun 22 11:39:51 2012 alexandre haulotte
//

#ifndef	__PLAYERCREATOR_HH__
#define	__PLAYERCREATOR_HH__

#include	<string>
#include	<vector>

class PlayerCreator
{
public:
  PlayerCreator();
  ~PlayerCreator();
  int	create(std::string& ip, int port, std::string& teamName, int id);
};

#endif
