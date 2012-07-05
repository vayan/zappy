//
// Vector2ic.cpp for  in /home/cao_y//sysunix/zappy-2015-2014s-haulot_a/client
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Thu Jun 28 11:17:51 2012 yuguo cao
// Last update Thu Jun 28 11:34:54 2012 yuguo cao
//

#include "Vector2ic.hh"

Vector2ic::Vector2ic()
{
}

Vector2ic::Vector2ic(int x, int y)
  : sf::Vector2i(x, y)
{
}

Vector2ic::~Vector2ic()
{
}

bool  operator<(const Vector2ic& a, const Vector2ic& b)
{
  return ((a.x < b.x) || ((a.x == b.x) && (a.y < b.y)));
}
