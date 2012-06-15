//
// Layer.hh for  in /home/cao_y//sysunix/zappy-2015-2014s-haulot_a/client/include
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Thu Jun 14 14:29:27 2012 yuguo cao
// Last update Thu Jun 14 15:44:32 2012 yuguo cao
//

#ifndef		__LAYER__
#define		__LAYER__

#include	<vector>
#include	<SFML/Graphics.hpp>

typedef std::vector<sf::Drawable *>	FrameSet;
typedef FrameSet::const_iterator	itFrame;

class Layer : public sf::Drawable, public FrameSet
{
protected:
  virtual void Render(sf::RenderTarget& Target) const;

public:
  Layer(const sf::Vector2f& Position = sf::Vector2f(0, 0), const sf::Vector2f& Scale = sf::Vector2f(1, 1), float Rotation = 0.f, const sf::Color& Col = sf::Color(255, 255, 255, 255));
  virtual ~Layer();
};

#endif

