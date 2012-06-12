//
// Core.hh for Core in /home/haulot_a//zappy-2015-2014s-haulot_a/client/include
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Wed Jun  6 10:22:18 2012 alexandre haulotte
// Last update Tue Jun 12 10:30:36 2012 alexandre haulotte
//

#ifndef		__CORE_HH__
# define	__CORE_HH__

#include	<vector>
#include	<iostream>

#include	<sys/time.h>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<unistd.h>
#include	<netinet/in.h>
#include	<arpa/inet.h>
#include	<netdb.h>
//#include	"Graph.hh"
#include	"Errur.hh"

class	Core
{
  int			soc;
  //  Graph			*graph;
  std::string		teamName;
  std::string		macName;
  int			port;
  std::vector<int>	joueurs;

public:
  Core(int ac, char **av);
  ~Core();
  int		strToInt(char* str);
  std::string	intToStr(int i);
  void		beginParse(int ac, char **av);
  void		init();
  void		go();
};

#endif
