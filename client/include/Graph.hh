//
// Graph.hh for  in /home/cao_y//sysunix/zappy-2015-2014s-haulot_a/client
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Wed Jun  6 13:46:24 2012 yuguo cao
// Last update Fri Jun 15 12:53:00 2012 yuguo cao
//

#ifndef		__GRAPH__
# define	__GRAPH__

#include	<iostream>
#include	<SFML/Graphics.hpp>
#include	"Imman.hh"
#include	"Errur.hh"
#include	"Character.hh"
#include	"Map.hh"

class Graph
{
private:
  sf::RenderWindow	_app;
  sf::Clock		_clock;
  const sf::Input&	_input;
  int			_scr_height;
  int			_scr_width;
  int			_scr_bpp;
  sf::Sprite		_sprite;

  Imman			*_imman;
  Character		_char;
  Map			_map;

public:
  Graph(const int, const int);
  ~Graph();

  void		run();
  void		initialize();
  void		update();
  void		draw();
};

#endif
