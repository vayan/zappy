//
// Player.hh for Player in /home/haulot_a//zappy-2015-2014s-haulot_a/client
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Wed Jun 13 10:36:21 2012 alexandre haulotte
// Last update Wed Jun 20 12:38:17 2012 alexandre haulotte
//

#ifndef	__PLAYER_HH__
#define	__PLAYER_HH__

#include	<vector>
#include	<map>
#include	<iostream>
#include	<string>
#include        <sys/time.h>
#include        <sys/types.h>
#include        <sys/socket.h>
#include        <unistd.h>
#include        <netinet/in.h>
#include        <arpa/inet.h>
#include        <netdb.h>
#include        <sstream>
#include        <stdlib.h>
#include	"Errur.hh"

class Player
{
protected:
  int							_x;
  int							_y;
  int							_width;
  int							_height;
  int							_dir;
  int							_lvl;
  int							_ressource[7];
  std::map< int, std::map< int, std::vector<int> > >	_map;
  int							_id;
  std::string						_teamName;
  int 							_lvlTab[7][7];

protected:
  int				_soc;
  int				_port;
  std::string			_addr;
  std::vector<std::string>	_msg;
  int				_compo;
  std::string			_lastRep;
  int				_cState;

public:
  Player(int port, std::string ip, std::string team, int compo = 0);
  Player(int compo = 0);
  ~Player();
  void		connexion();
  void		play();
  void		recInfo();
  void		parse(int ac, char **av);
  int		strToInt(char* str);
  int		xrecv();
  int		xsend(int soc, const void* msg, int size, int flag);
  std::string	intToStr(int i);
  void    	initTab();
  //  std::string	charToStr(char*);

public:
  //-------------------------------------//
  //--------------- GETTER --------------//
  //-------------------------------------//
  int							getX() const;
  int							getY() const;
  int							getWidth() const;
  int							getHeight() const;
  int							getDir() const;
  int							getLvl() const;
  int							getRessource(int r) const;
  std::map< int, std::map< int, std::vector<int> > >	getMap() const;
  int							getId() const;

  //-------------------------------------//
  //--------------- SETTER --------------//
  //-------------------------------------//
  void	setX(int x);
  void	setY(int y);
  void	setDir(int dir);
  void	setLvl(int lvl);
  void	setRessource(int r, int nb);
  void	initCase(int x, int y);
  void	setMap(int x, int y, int p, int nb);

#include	"IA.hh"

};

#endif
