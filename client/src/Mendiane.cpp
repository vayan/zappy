//
// Mendiane.cpp for  in /home/cao_y//sysunix/zappy-2015-2014s-haulot_a/client
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Thu Jun 14 11:21:28 2012 yuguo cao
// Last update Wed Jun 27 16:11:42 2012 yuguo cao
//

#include	"Mendiane.hh"

Mendiane::Mendiane()
{
}

Mendiane::~Mendiane()
{
}

void		Mendiane::mUp()
{
}

void		Mendiane::mDown()
{
}

void		Mendiane::mLeft()
{
}

void		Mendiane::mRight()
{
}

void		Mendiane::mStand()
{
  sf::Sprite	*frame = new sf::Sprite;

  frame->SetImage(_image);

  frame->SetSubRect(sf::IntRect(64, 0, 80, 16));

  _mStand.setDelay(1);
  _mStand.push_back(frame);

}

void		Mendiane::mCast()
{
}

void		Mendiane::mPond()
{
}

void		Mendiane::mTake()
{
}

void		Mendiane::mBroad()
{
}

void		Mendiane::mExpu()
{
}

void		Mendiane::mDie()
{
}
