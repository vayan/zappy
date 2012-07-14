//
// Win.hh for  in /home/cao_y//sysunix/zappy-2015-2014s-haulot_a/client
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Sat Jul 14 23:25:21 2012 yuguo cao
// Last update Sun Jul 15 00:21:44 2012 yuguo cao
//

#ifndef		__WIN__
# define	__WIN__

#include	<string>
#include	<iostream>
#include	<SFML/Graphics.hpp>

class Win
{
private:
  sf::Sprite	_sprite;
  sf::String	_string;

public:
  Win(const sf::Image&);
  ~Win();

  void		draw(sf::RenderWindow&);
  void		setText(const std::string&);
  void		setPosition(const sf::Vector2f&);
  void		setScale(const float, const float);
};

#endif
