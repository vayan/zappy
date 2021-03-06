//
// Imman.cpp for  in /home/cao_y//sysunix/zappy-2015-2014s-haulot_a/client
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Wed Jun 13 11:42:37 2012 yuguo cao
// Last update Sun Jul 15 00:38:37 2012 yuguo cao
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
  _images["fond"].LoadFromFile("assets/fond.png");

  _images["lvl1"].LoadFromFile("assets/lvl1.png");
  _images["lvl2"].LoadFromFile("assets/lvl2.png");
  _images["lvl3"].LoadFromFile("assets/lvl3.png");
  _images["lvl4"].LoadFromFile("assets/lvl4.png");
  _images["lvl5"].LoadFromFile("assets/lvl5.png");
  _images["lvl6"].LoadFromFile("assets/lvl6.png");
  _images["lvl7"].LoadFromFile("assets/lvl7.png");
  _images["lvl8"].LoadFromFile("assets/lvl8.png");

  _images["pvl1"].LoadFromFile("assets/portrait-lvl1.png");
  _images["pvl2"].LoadFromFile("assets/portrait-lvl2.png");
  _images["pvl3"].LoadFromFile("assets/portrait-lvl3.png");
  _images["pvl4"].LoadFromFile("assets/portrait-lvl4.png");
  _images["pvl5"].LoadFromFile("assets/portrait-lvl5.png");
  _images["pvl6"].LoadFromFile("assets/portrait-lvl6.png");
  _images["pvl7"].LoadFromFile("assets/portrait-lvl7.png");
  _images["pvl8"].LoadFromFile("assets/portrait-lvl8.png");

  _images["resources"].LoadFromFile("assets/resources.png");

  _images["level"].LoadFromFile("assets/level.png");

  _images["back"].LoadFromFile("assets/back.png");

  _images["incant"].LoadFromFile("assets/incant.png");

  _images["egg"].LoadFromFile("assets/egg.png");

  _images["info"].LoadFromFile("assets/cadre.png");

  _images["win"].LoadFromFile("assets/win.png");
}

const sf::Image&	Imman::getImage(const std::string& name)
{
  if (_images.find(name) == _images.end())
    throw(new Errur(name + " : this image is not loaded."));
  return (_images[name]);
}
