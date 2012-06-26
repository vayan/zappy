//
// Imman.cpp for  in /home/cao_y//sysunix/zappy-2015-2014s-haulot_a/client
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Wed Jun 13 11:42:37 2012 yuguo cao
// Last update Fri Jun 15 14:06:18 2012 yuguo cao
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
  _images["mage_charset1"].LoadFromFile("assets/mage_charset1.bmp");
  _images["mage_charset1"].CreateMaskFromColor(sf::Color(0, 0, 255));

  _images["back"].LoadFromFile("assets/back.bmp");
  _images["back"].CreateMaskFromColor(sf::Color(0, 0, 255));
}

sf::Image&	Imman::getImage(const std::string& name)
{
  return (_images[name]);
}
