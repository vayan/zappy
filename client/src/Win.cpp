//
// Win.cpp for  in /home/cao_y//sysunix/zappy-2015-2014s-haulot_a/client
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Sat Jul 14 23:28:09 2012 yuguo cao
// Last update Sun Jul 15 00:27:08 2012 yuguo cao
//

#include	"Win.hh"

Win::Win(const sf::Image& i)
{
  _sprite.SetImage(i);
  _sprite.SetSubRect(sf::IntRect(0, 0, 400, 320));
  _string.SetColor(sf::Color(0, 0, 0));
}

Win::~Win()
{
}

void		Win::draw(sf::RenderWindow& app)
{
  app.Draw(_sprite);
  app.Draw(_string);
}

void		Win::setText(const std::string& s)
{
  _string.SetText(s);
}

void		Win::setPosition(const sf::Vector2f& v)
{
  std::cout << _string.GetRect().GetWidth() << std::endl;
  _sprite.SetPosition(v.x, v.y);
  _string.SetPosition(v.x + 200 - _string.GetRect().GetWidth() / 2, v.y + 100);
}

void		Win::setScale(const float x, const float y)
{
  _sprite.SetScale(x, y);
  _string.SetScale(x, y);
}
