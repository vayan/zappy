//
// Imman.hh for  in /home/cao_y//sysunix/zappy-2015-2014s-haulot_a/client
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Wed Jun 13 11:42:51 2012 yuguo cao
// Last update Tue Jul 10 15:40:05 2012 yuguo cao
//

#ifndef		__IMMAN__
# define	__IMMAN__

#include	<SFML/Graphics.hpp>
#include	<map>
#include	<string>
#include	<iostream>
#include	"Errur.hh"

class Imman
{
private:
  std::map<std::string, sf::Image>	_images;

public:
  Imman();
  ~Imman();

  void			loadImages();
  const sf::Image&	getImage(const std::string&);
};

#endif
