//
// Nourriture.hh for  in /home/cao_y//sysunix/zappy-2015-2014s-haulot_a/client
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Thu Jun 14 11:14:42 2012 yuguo cao
// Last update Wed Jun 27 15:55:18 2012 yuguo cao
//

#ifndef		__NOURRITURE__
# define	__NOURRITURE__

#include	"ASprite.hh"

class Nourriture : public ASprite
{
public:
  Nourriture();
  ~Nourriture();

  virtual void		mUp();
  virtual void		mDown();
  virtual void		mLeft();
  virtual void		mRight();
  virtual void		mStand();
  virtual void		mCast();
  virtual void		mPond();
  virtual void		mTake();
  virtual void		mBroad();
  virtual void		mExpu();
  virtual void		mDie();
};

#endif
