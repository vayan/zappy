//
// Core.hh for Core in /home/haulot_a//zappy-2015-2014s-haulot_a/client/include
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Wed Jun  6 10:22:18 2012 alexandre haulotte
// Last update Sat Jul 14 22:16:58 2012 yuguo cao
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
#include	"Graph.hh"
#include	"Errur.hh"
#include	"Parser.hh"

class Graph;

class	Core
{
private:
  typedef void		(Core::*fct)(const std::vector<std::string>&);

  int			soc;
  Graph			*graph;
  Parser		*parser;
  std::string		macName;
  int			port;
  //std::vector<int>	joueurs;
  std::vector<fct>	funcs;
  Parser		p;

  void			initTab();
  void			createMap(const std::vector<std::string>&);
  void			updaCaseInfo(const std::vector<std::string>&);
  void			requCaseInfo(const std::vector<std::string>&);
  void			addPlayer(const std::vector<std::string>&);
  void			movePlayer(const std::vector<std::string>&);
  void			lvlPlayer(const std::vector<std::string>&);
  void			inventPlayer(const std::vector<std::string>&);
  void			requPlayerInfo(const std::vector<std::string>&);
  void			expuPlayer(const std::vector<std::string>&);
  void			broaPlayer(const std::vector<std::string>&);
  void			incdPlayer(const std::vector<std::string>&);
  void			incfPlayer(const std::vector<std::string>&);
  void			pondPlayer(const std::vector<std::string>&);
  void			dropPlayer(const std::vector<std::string>&);
  void			takePlayer(const std::vector<std::string>&);
  void			addEgg(const std::vector<std::string>&);
  void			eggHatched(const std::vector<std::string>&);
  void			diePlayer(const std::vector<std::string>&);
  void			timeServer(const std::vector<std::string>&);
  void			victory(const std::vector<std::string>&);
  void			rien(const std::vector<std::string>&);

public:
  Core(int ac, char **av);
  ~Core();

  int				sti(std::string str);
  std::string			its(int i);
  const std::vector<int>	vstvi(const std::vector<std::string>);
  void				beginParse(int ac, char **av);
  int				protocole() const;
  void				init();
  void				go();

  void				askLevel(const int);
  void				askInvent(const int);
};

#endif
