//
// Imman.cpp for  in /home/cao_y//sysunix/zappy-2015-2014s-haulot_a/client
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Wed Jun 13 11:42:37 2012 yuguo cao
// Last update Wed Jul  4 11:51:58 2012 yuguo cao
//

#include	"Imman.hh"

Imman::Imman()
{
}

Imman::~Imman()
{
}

void		Imman::loadImages()
{
  _images["sprite"].LoadFromFile("assets/sprite.png");

  _images["resources"].LoadFromFile("assets/resources.png");

  _images["back"].LoadFromFile("assets/back.png");

  _images["incant"].LoadFromFile("assets/incant.png");
}

sf::Image&	Imman::getImage(const std::string& name)
{
  if (_images.find(name) == _images.end())
    throw(new Errur(name + " : this image is not loaded."));
  return (_images[name]);
}
