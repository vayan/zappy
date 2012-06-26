//
// Graph.hh for  in /home/cao_y//sysunix/zappy-2015-2014s-haulot_a/client
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Wed Jun  6 13:46:24 2012 yuguo cao
// Last update Wed Jun 20 14:54:18 2012 yuguo cao
//

#ifndef		__GRAPH__
# define	__GRAPH__

#include	<iostream>
#include	<SFML/Graphics.hpp>
#include	<cstdlib>
#include	"Imman.hh"
#include	"Errur.hh"
#include	"Character.hh"
#include	"Map.hh"

struct	Stone_t
{
  int	linemate;
  int	deraumere;
  int	sibur;
  int	mendiane;
  int	phiras;
  int	thystame;
  int	food;
};

class Graph
{
private:
  sf::RenderWindow		_app;
  const sf::Input&		_input;
  int				_scr_height;
  int				_scr_width;
  int				_scr_bpp;
  sf::View			_view;
  Imman				*_imman;
  Character		_char;
  Map				_map;

  std::map<int, ASprite*>	_sprites;
  std::map<int, int>		_movements;

public:
  Graph(const int, const int);
  ~Graph();

  void			run();
  void			initialize();
  void			update();
  sf::Vector2<int>&	relaMouse(const sf::Event& event);
  void			draw();

  void			updaCaseInfo(const int, const int, const Stone_t&);
  void			requCaseInfo(const int, const int, const Stone_t&);
  void			addPlayer(const int, const int, const ACTION, const int, const int);
  void			movePlayer(const int, const int, const ACTION, const int);
  void			requPlayerInfo(const int);
  void			expuPlayer(const int);
  void			broaPlayer(const int);
  void			incdPlayer(const int, const int);
  void			incfPlayer(const int, const int);
  void			pondPlayer(const int);
  void			dropPlayer(const int);
  void			takePlayer(const int);
  void			addEgg(const int, const int, const int, const int);
  void			eggHatched(const int);
};

#endif
