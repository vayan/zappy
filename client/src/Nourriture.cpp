//
// Nourriture.cpp for  in /home/cao_y//sysunix/zappy-2015-2014s-haulot_a/client
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Thu Jun 14 11:21:28 2012 yuguo cao
// Last update Thu Jun 28 12:01:36 2012 yuguo cao
//

#include	"Nourriture.hh"

Nourriture::Nourriture()
{
}

Nourriture::~Nourriture()
{
}

void		Nourriture::mUp()
{
}

void		Nourriture::mDown()
{
}

void		Nourriture::mLeft()
{
}

void		Nourriture::mRight()
{
}

void		Nourriture::mStand()
{
  sf::Sprite	*frame = new sf::Sprite;

  frame->SetImage(_image);

  frame->SetSubRect(sf::IntRect(0, 0, 16, 16));

  _mStand.setDelay(1);
  _mStand.push_back(frame);
}

void		Nourriture::mCast()
{
}

void		Nourriture::mPond()
{
}

void		Nourriture::mTake()
{
}

void		Nourriture::mBroad()
{
}

void		Nourriture::mExpu()
{
}

void		Nourriture::mDie()
{
}
