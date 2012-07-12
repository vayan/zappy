//
// Info.hh for  in /home/cao_y//sysunix/zappy-2015-2014s-haulot_a/client
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Wed Jul 11 16:50:16 2012 yuguo cao
// Last update Thu Jul 12 15:33:08 2012 yuguo cao
//

#ifndef		__INFO__
# define	__INFO__

#include	<string>
#include	<sstream>
#include	<iostream>
#include	<SFML/Graphics.hpp>
#include	"Imman.hh"
#include	"Graph.hh"

struct		InfoString_t
{
  sf::String	lvl;
  sf::String	food;
  sf::String	linemate;
  sf::String	deraumere;
  sf::String	sibur;
  sf::String	mendiane;
  sf::String	phiras;
  sf::String	thystame;
};

struct		InfoIcon_t
{
  sf::Sprite	lvl;
  sf::Sprite	food;
  sf::Sprite	linemate;
  sf::Sprite	deraumere;
  sf::Sprite	sibur;
  sf::Sprite	mendiane;
  sf::Sprite	phiras;
  sf::Sprite	thystame;
};

struct		InfoPort_t
{
  sf::Sprite	l1;
  sf::Sprite	l2;
  sf::Sprite	l3;
  sf::Sprite	l4;
  sf::Sprite	l5;
  sf::Sprite	l6;
  sf::Sprite	l7;
};

  class Graph;

class Info
{
private:
  int			_lvl;
  sf::Font		_font;
  sf::Sprite		_s_back;
  InfoPort_t		_s_portrait;
  InfoIcon_t		_s_stone;
  InfoString_t		_strings;

public:
  Info(Imman*);
  ~Info();

  void		draw(sf::RenderWindow&, const struct Stone_t&);

  std::string	its(const int);
  sf::Vector2f&	absolutePosition(const sf::RenderWindow&, const sf::Vector2i&);
  void		setTextsIcons(sf::RenderWindow&, const struct Stone_t&, const float);
  void		drawText(sf::RenderWindow&);
};

#endif
