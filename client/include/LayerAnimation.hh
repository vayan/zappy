//
// LayerAnimation.hh for  in /home/cao_y//sysunix/zappy-2015-2014s-haulot_a/client/include
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Thu Jun 14 14:55:56 2012 yuguo cao
// Last update Thu Jun 14 14:59:58 2012 yuguo cao
//

#ifndef		__LAYERANIMATION__
# define	__LAYERANIMATION__

#include	"Animation.hh"
#include	"Layer.hh"

class LayerAnimation : public Animation, public Layer
{
protected:
  virtual void		Render(sf::RenderTarget& Target) const;

public:
  LayerAnimation();

  virtual unsigned int	getSize() const;
};

#endif
