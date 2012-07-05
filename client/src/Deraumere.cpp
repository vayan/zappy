//
// Deraumere.cpp for  in /home/cao_y//sysunix/zappy-2015-2014s-haulot_a/client
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Thu Jun 14 11:21:28 2012 yuguo cao
// Last update Wed Jun 27 16:10:31 2012 yuguo cao
//

#include	"Deraumere.hh"

Deraumere::Deraumere()
{
}

Deraumere::~Deraumere()
{
}

void		Deraumere::mUp()
{
}

void		Deraumere::mDown()
{
}

void		Deraumere::mLeft()
{
}

void		Deraumere::mRight()
{
}

void		Deraumere::mStand()
{
  sf::Sprite	*frame = new sf::Sprite;

  frame->SetImage(_image);

  frame->SetSubRect(sf::IntRect(32, 0, 48, 16));

  _mStand.setDelay(1);
  _mStand.push_back(frame);

}

void		Deraumere::mCast()
{
}

void		Deraumere::mPond()
{
}

void		Deraumere::mTake()
{
}

void		Deraumere::mBroad()
{
}

void		Deraumere::mExpu()
{
}

void		Deraumere::mDie()
{
}
