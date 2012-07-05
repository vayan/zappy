//
// Sibur.cpp for  in /home/cao_y//sysunix/zappy-2015-2014s-haulot_a/client
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Thu Jun 14 11:21:28 2012 yuguo cao
// Last update Wed Jun 27 16:11:01 2012 yuguo cao
//

#include	"Sibur.hh"

Sibur::Sibur()
{
}

Sibur::~Sibur()
{
}

void		Sibur::mUp()
{
}

void		Sibur::mDown()
{
}

void		Sibur::mLeft()
{
}

void		Sibur::mRight()
{
}

void		Sibur::mStand()
{
  sf::Sprite	*frame = new sf::Sprite;

  frame->SetImage(_image);

  frame->SetSubRect(sf::IntRect(48, 0, 64, 16));

  _mStand.setDelay(1);
  _mStand.push_back(frame);

}

void		Sibur::mCast()
{
}

void		Sibur::mPond()
{
}

void		Sibur::mTake()
{
}

void		Sibur::mBroad()
{
}

void		Sibur::mExpu()
{
}

void		Sibur::mDie()
{
}
