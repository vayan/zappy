//
// Map.hh for  in /home/cao_y//sysunix/zappy-2015-2014s-haulot_a/client
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Fri Jun 15 12:08:55 2012 yuguo cao
// Last update Wed Jun 20 11:16:19 2012 yuguo cao
//

#ifndef		__MAP__
# define	__MAP__

#include	<SFML/Graphics.hpp>
#include	<iostream>
#include	<cmath>

class Map
{
private:
  sf::Sprite		_tiles;
  int			_width;
  int			_height;

public:
  Map();
  Map(const sf::Image&, const int, const int);
  ~Map();

  void			setImage(const sf::Image&);
  void			setHeight(const int);
  int			getHeight() const;
  void			setWidth(const int);
  int			getWidth() const;
  void			draw(sf::RenderWindow&);
  sf::Vector2<int>	getMCase(const sf::Vector2<int>&);
};

#endif
