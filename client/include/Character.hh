//
// Character.hh for  in /home/cao_y//sysunix/zappy-2015-2014s-haulot_a/client
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Thu Jun 14 11:14:42 2012 yuguo cao
// Last update Thu Jun 14 18:24:11 2012 yuguo cao
//

#ifndef		__CHARACTER__
# define	__CHARACTER__

#include	"ASprite.hh"

class Character : public ASprite
{
public:
  Character();
  ~Character();

  virtual void		mUp();
  virtual void		mDown();
  virtual void		mLeft();
  virtual void		mRight();
  virtual void		mStand();
  virtual void		mCast();
  virtual void		mBroad();
  virtual void		mDie();
};

#endif
