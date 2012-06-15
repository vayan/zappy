//
// ASprite.hh for  in /home/cao_y//sysunix/zappy-2015-2014s-haulot_a/client
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Wed Jun 13 20:17:42 2012 yuguo cao
// Last update Fri Jun 15 11:51:25 2012 yuguo cao
//

#ifndef		__ASPRITE__
# define	__ASPRITE__

#include	<SFML/Graphics.hpp>
#include	"LayerAnimation.hh"

enum ACTION
  {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    STAND,
    CAST,
    BROAD,
    DIE
  };

class ASprite
{
protected:
  sf::Image		_image;
  ACTION		_lastAction;
  LayerAnimation	_mUp;
  LayerAnimation	_mDown;
  LayerAnimation	_mLeft;
  LayerAnimation	_mRight;
  LayerAnimation	_mStand;
  LayerAnimation	_mCast;
  LayerAnimation	_mBroad;
  LayerAnimation	_mDie;

public:
  ASprite();
  virtual ~ASprite() {}

  ACTION		getLastAction() const;

  void			createAnim(const sf::Image&);
  virtual void		mUp() = 0;
  virtual void		mDown() = 0;
  virtual void		mLeft() = 0;
  virtual void		mRight() = 0;
  virtual void		mStand() = 0;
  virtual void		mCast() = 0;
  virtual void		mBroad() = 0;
  virtual void		mDie() = 0;
  LayerAnimation	anim(ACTION, ACTION last = UP);
  void			move(const float, const float);
  void			setPos(const int, const int);
};

#endif
