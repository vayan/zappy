//
// Map.hh for  in /home/cao_y//sysunix/zappy-2015-2014s-haulot_a/client
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Fri Jun 15 12:08:55 2012 yuguo cao
// Last update Fri Jun 15 12:56:24 2012 yuguo cao
//

#ifndef		__MAP__
# define	__MAP__

#include	<SFML/Graphics.hpp>

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
  void			setWidth(const int);
  void			draw(const sf::RenderWindow&);
};

#endif
