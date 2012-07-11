//
// ASprite.hh for  in /home/cao_y//sysunix/zappy-2015-2014s-haulot_a/client
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Wed Jun 13 20:17:42 2012 yuguo cao
// Last update Wed Jul 11 15:33:54 2012 yuguo cao
//

#ifndef		__ASPRITE__
# define	__ASPRITE__

#include	<SFML/Graphics.hpp>
#include	"LayerAnimation.hh"

enum ACTION
  {
    NO,
    UP,
    DOWN,
    LEFT,
    RIGHT,
    STAND,
    POND,
    TAKE,
    BROAD,
    EXPU,
    DIE
  };

class ASprite
{
protected:
  sf::Image		_image;
  ACTION		_orientation;
  ACTION		_lastAction;
  LayerAnimation	_mUp;
  LayerAnimation	_mDown;
  LayerAnimation	_mLeft;
  LayerAnimation	_mRight;
  LayerAnimation	_mStand;
  LayerAnimation	_mPond;
  LayerAnimation	_mTake;
  LayerAnimation	_mBroad;
  LayerAnimation	_mExpu;
  LayerAnimation	_mDie;
  int			_x_margin;
  int			_y_margin;

public:
  ASprite();
  virtual ~ASprite() {}

  void			createAnim(const sf::Image&);
  virtual void		mUp() = 0;
  virtual void		mDown() = 0;
  virtual void		mLeft() = 0;
  virtual void		mRight() = 0;
  virtual void		mStand() = 0;
  virtual void		mPond() = 0;
  virtual void		mTake() = 0;
  virtual void		mBroad() = 0;
  virtual void		mExpu() = 0;
  virtual void		mDie() = 0;

  LayerAnimation	anim(const ACTION a = NO);
  void			move(const float, const float);
  void			setLastAction(const ACTION);
  ACTION		getLastAction() const;
  void			setOrientation(const ACTION);
  ACTION		getOrientation() const;
  void			setPosition(const int, const int);
  void			setScale(const float);
  void			setColor(unsigned int, unsigned int, unsigned int, unsigned int);
  const sf::Vector2f&	getPosition() const;
};

#endif
