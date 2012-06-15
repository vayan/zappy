//
// Layer.cpp for  in /home/cao_y//sysunix/zappy-2015-2014s-haulot_a/client/src
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Thu Jun 14 14:28:52 2012 yuguo cao
// Last update Thu Jun 14 15:44:39 2012 yuguo cao
//

#include	"Layer.hh"
#include	<iostream>

Layer::Layer(const sf::Vector2f& Position, const sf::Vector2f& Scale, float Rotation, const sf::Color& Col)
  : Drawable(Position,Scale,Rotation,Col)
{
}

Layer::~Layer()
{
}

void		Layer::Render(sf::RenderTarget& Target) const
{
  for( itFrame i = begin() ;i!=end();i++)
    Target.Draw(*(*i));
}

