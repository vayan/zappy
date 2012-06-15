//
// Map.cpp for  in /home/cao_y//sysunix/zappy-2015-2014s-haulot_a/client
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Fri Jun 15 12:23:46 2012 yuguo cao
// Last update Fri Jun 15 13:06:31 2012 yuguo cao
//

#include	"Map.hh"

Map::Map()
{
}

Map::Map(const sf::Image& i, const int height, const int width)
{
  _tiles.SetImage(i);
  _height = height;
  _width = width;
}

Map::~Map()
{
}

void			Map::setImage(const sf::Image& i)
{
  _tiles.SetImage(i);
}

void			Map::setHeight(const int h)
{
  _height = h;
}

void			Map::setWidth(const int w)
{
  _width = w;
}

void			Map::draw(const sf::RenderWindow& app)
{
  int			x = 0;
  int			y = 0;

  while (y < height)
    {
      while (x < width)
	{

	}
    }
  (void) app;
}
