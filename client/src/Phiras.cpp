//
// Phiras.cpp for  in /home/cao_y//sysunix/zappy-2015-2014s-haulot_a/client
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Thu Jun 14 11:21:28 2012 yuguo cao
// Last update Wed Jun 27 16:11:58 2012 yuguo cao
//

#include	"Phiras.hh"

Phiras::Phiras()
{
}

Phiras::~Phiras()
{
}

void		Phiras::mUp()
{
}

void		Phiras::mDown()
{
}

void		Phiras::mLeft()
{
}

void		Phiras::mRight()
{
}

void		Phiras::mStand()
{
  sf::Sprite	*frame = new sf::Sprite;

  frame->SetImage(_image);

  frame->SetSubRect(sf::IntRect(80, 0, 96, 16));

  _mStand.setDelay(1);
  _mStand.push_back(frame);

}

void		Phiras::mCast()
{
}

void		Phiras::mPond()
{
}

void		Phiras::mTake()
{
}

void		Phiras::mBroad()
{
}

void		Phiras::mExpu()
{
}

void		Phiras::mDie()
{
}
