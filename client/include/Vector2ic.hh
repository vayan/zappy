//
// Vector2ic.hh for  in /home/cao_y//sysunix/zappy-2015-2014s-haulot_a/client
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Thu Jun 28 11:14:36 2012 yuguo cao
// Last update Thu Jun 28 11:32:37 2012 yuguo cao
//

#ifndef		__VECTOR2IC__
# define	__VECTOR2IC__

#include	<SFML/Graphics.hpp>

class Vector2ic : public sf::Vector2i
{
public:
  Vector2ic();
  Vector2ic(int, int);
  ~Vector2ic();
};

bool	operator<(const Vector2ic&, const Vector2ic&);

#endif
