//
// Core.hh for Core in /home/haulot_a//zappy-2015-2014s-haulot_a/client/include
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Wed Jun  6 10:22:18 2012 alexandre haulotte
// Last update Fri Jun 22 14:51:43 2012 yuguo cao
//

#ifndef		__CORE_HH__
# define	__CORE_HH__

#include	<vector>
#include	<iostream>
#include	<string>
#include	<sys/time.h>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<unistd.h>
#include	<netinet/in.h>
#include	<arpa/inet.h>
#include	<netdb.h>
#include	<sstream>
#include	<signal.h>
//#include	"Graph.hh"
#include	"Errur.hh"
#include	"Parser.hh"

class	Core
{
private:
  typedef void		(Core::*f)(const std::vector<int>);

  int			soc;
  //  Graph			*graph;
  Parser		*parser;
  std::string		teamName;
  std::string		macName;
  int			port;
  //std::vector<int>	joueurs;
  std::vector<f>	funcs;

  void			initTab();
  void			updaMapSize(const std::vector<int>);
  void			updaCaseInfo(const std::vector<int>);
  void			requCaseInfo(const std::vector<int>);
  void			addPlayer(const std::vector<int>);
  void			movePlayer(const std::vector<int>);
  void			requPlayerInfo(const std::vector<int>);
  void			expuPlayer(const std::vector<int>);
  void			broaPlayer(const std::vector<int>);
  void			incdPlayer(const std::vector<int>);
  void			incfPlayer(const std::vector<int>);
  void			pondPlayer(const std::vector<int>);
  void			dropPlayer(const std::vector<int>);
  void			takePlayer(const std::vector<int>);
  void			addEgg(const std::vector<int>);
  void			eggHatched(const std::vector<int>);

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
