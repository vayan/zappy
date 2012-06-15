//
// LayerAnimationation.cpp for  in /home/cao_y//sysunix/zappy-2015-2014s-haulot_a/client/src
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Thu Jun 14 14:55:48 2012 yuguo cao
// Last update Thu Jun 14 15:35:22 2012 yuguo cao
//

#include	"LayerAnimation.hh"

LayerAnimation::LayerAnimation(void)
{
}


unsigned int		LayerAnimation::getSize() const
{
  return size();
}

void			LayerAnimation::Render(sf::RenderTarget& Target) const
{
  Animation* th = const_cast<LayerAnimation*>(this);
  th->update();
  Target.Draw(*at(getActualFrame()));
}
