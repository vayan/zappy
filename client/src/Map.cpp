//
// Map.cpp for  in /home/cao_y//sysunix/zappy-2015-2014s-haulot_a/client
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Fri Jun 15 12:23:46 2012 yuguo cao
// Last update Tue Jul  3 15:19:59 2012 yuguo cao
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

int			Map::getHeight() const
{
  return (_height);
}

void			Map::setWidth(const int w)
{
  _width = w;
}

int			Map::getWidth() const
{
  return (_width);
}

void			Map::draw(sf::RenderWindow& app)
{
  int			x = 0;
  int			y = 0;

  while (y < _height)
    {
      x = 0;
      while (x < _width)
	{
	  _tiles.SetPosition(x * 64 + (y * 64), y * 32 - (x * 32));
	  app.Draw(_tiles);
	  x++;
	}
      y++;
    }
}

sf::Vector2<int>	Map::getMCase(const sf::Vector2<int>& me)
{
  float			dist = 0.0;
  float			dist_min = 1000.0;
  int			x = 0;
  int			y = 0;
  int			xcase = 0;
  int			ycase = 0;
  sf::Vector2<int>	rcase(0, 0);

  while (y < _height)
    {
      x = 0;
      while (x < _width)
	{
	  xcase = (x * 64 + (y * 64)) + 64;
	  ycase = (y * 32 - (x * 32)) + 32;
	  dist = sqrt(pow(ycase - me.y, 2) + pow((xcase - me.x) / 2, 2));
	  if (dist < dist_min)
	    {
	      dist_min = dist;
	      rcase.x = x;
	      rcase.y = y;
	    }
	  x++;
	}
      y++;
    }
  return (rcase);
}
