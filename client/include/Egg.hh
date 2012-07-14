//
// Egg.hh for  in /home/cao_y//sysunix/zappy-2015-2014s-haulot_a/client
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Thu Jun 14 11:14:42 2012 yuguo cao
// Last update Sat Jul 14 23:10:04 2012 yuguo cao
//

#ifndef		__EGG__
# define	__EGG__

#include	"ASprite.hh"

class Egg : public ASprite
{
public:
  Egg();
  ~Egg();

  void			genMargins();
  virtual void		mUp();
  virtual void		mDown();
  virtual void		mLeft();
  virtual void		mRight();
  virtual void		mStand();
  virtual void		mPond();
  virtual void		mTake();
  virtual void		mBroad();
  virtual void		mExpu();
  virtual void		mDie();
};

#endif
