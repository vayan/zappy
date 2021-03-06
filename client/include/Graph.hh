//
// Graph.hh for  in /home/cao_y//sysunix/zappy-2015-2014s-haulot_a/client
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Wed Jun  6 13:46:24 2012 yuguo cao
// Last update Sat Jul 14 23:47:40 2012 yuguo cao
//

#ifndef		__GRAPH__
# define	__GRAPH__

#include	<iostream>
#include	<SFML/Graphics.hpp>
#include	<cstdlib>
#include	<ctime>

#include	"Core.hh"
#include	"Imman.hh"
#include	"Errur.hh"
#include	"Character.hh"
#include	"Map.hh"
#include	"Vector2ic.hh"
#include	"Vector4i.hh"
#include	"Info.hh"
#include	"Win.hh"

#include	"Nourriture.hh"
#include	"Linemate.hh"
#include	"Deraumere.hh"
#include	"Sibur.hh"
#include	"Mendiane.hh"
#include	"Phiras.hh"
#include	"Thystame.hh"
#include	"Incant.hh"
#include	"Egg.hh"

struct	Stone_t
{
  int	linemate;
  int	deraumere;
  int	sibur;
  int	mendiane;
  int	phiras;
  int	thystame;
  int	food;
  int	l;
};

// struct		Movement_t
// {
//   ACTION	action;
//   int		a_remain;
// };

class Core;
class Info;

class Graph
{
private:
  Core				*_core;
  sf::RenderWindow		_app;
  sf::Clock			_clock;
  sf::Sprite			_background;
  const sf::Input&		_input;
  sf::Vector2i			_lastCoor;
  sf::Vector2i			_newCoor;
  float				_xratio;
  float				_yratio;
  int				_click;
  int				_soc;
  int				_scr_height;
  int				_scr_width;
  int				_scr_bpp;
  int				_server_time;
  int				_follow;
  sf::View			_view;
  Imman				*_imman;
  Character			_char;
  Map				_map;
  Info				*_info;
  Win				*_winscreen;
  std::string			_win;

  std::map<int, ASprite*>			_sprites;
  std::map<int, ASprite*>			_eggs;
  std::map<int, Vector4i>			_movements;
  std::map<int, Stone_t*>			_invent;
  std::map<Vector2ic, std::vector<ASprite*> >	_s_map;
  //std::map<Vector2ic, std::map<std::string, ASprite*> >	_s_map;
  std::map<Vector2ic, ASprite*>			_s_other;
  std::map<int, std::string>			_teams;

public:
  Graph(Core *, const int, const int, const int, const int, const int);
  ~Graph();

  void			run();
  void			initialize();
  void			update();
  sf::Vector2<int>&	relaMouse(const sf::Event& event);
  sf::Vector2f&		absolutePosition(const sf::Vector2i&);
  void			draw();

  void			updaCaseInfo(const int, const int, const Stone_t&);
  void			requCaseInfo(const int, const int, const Stone_t&);
  void			addPlayer(const int, const int, const int, const ACTION, const int, const std::string&);
  void			movePlayer(const int, const int, const int, const ACTION);
  void			lvlPlayer(const int, const int);
  void			inventPlayer(const int, const Stone_t&);
  void			requPlayerInfo(const int);
  void			expuPlayer(const int);
  void			broaPlayer(const int);
  void			incdPlayer(const int, const int);
  void			incfPlayer(const int, const int);
  void			pondPlayer(const int);
  void			dropPlayer(const int);
  void			takePlayer(const int);
  void			addEgg(const int, const int, const int, const int);
  void			diePlayer(const int);
  void			eggHatched(const int);
  void			timeServer(const int);
  void			victory(const std::string&);
  void			askLevel(const int);
  void			askInvent(const int);
  int			testPlayer(const int, const int x = 0, const int y = 0, const ACTION = UP);
};

#endif
