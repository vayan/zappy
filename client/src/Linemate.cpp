//
// Linemate.cpp for  in /home/cao_y//sysunix/zappy-2015-2014s-haulot_a/client
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Thu Jun 14 11:21:28 2012 yuguo cao
// Last update Wed Jun 27 16:01:18 2012 yuguo cao
//

#include	"Linemate.hh"

Linemate::Linemate()
{
}

Linemate::~Linemate()
{
}

void		Linemate::mUp()
{
}

void		Linemate::mDown()
{
}

void		Linemate::mLeft()
{
}

void		Linemate::mRight()
{
}

void		Linemate::mStand()
{
  sf::Sprite	*frame = new sf::Sprite;

  frame->SetImage(_image);

  frame->SetSubRect(sf::IntRect(16, 0, 32, 16));

  _mStand.setDelay(1);
  _mStand.push_back(frame);

}

void		Linemate::mCast()
{
}

void		Linemate::mPond()
{
}

void		Linemate::mTake()
{
}

void		Linemate::mBroad()
{
}

void		Linemate::mExpu()
{
}

void		Linemate::mDie()
{
}
