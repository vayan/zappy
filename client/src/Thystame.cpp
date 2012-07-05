//
// Thystame.cpp for  in /home/cao_y//sysunix/zappy-2015-2014s-haulot_a/client
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Thu Jun 14 11:21:28 2012 yuguo cao
// Last update Wed Jun 27 16:12:33 2012 yuguo cao
//

#include	"Thystame.hh"

Thystame::Thystame()
{
}

Thystame::~Thystame()
{
}

void		Thystame::mUp()
{
}

void		Thystame::mDown()
{
}

void		Thystame::mLeft()
{
}

void		Thystame::mRight()
{
}

void		Thystame::mStand()
{
  sf::Sprite	*frame = new sf::Sprite;

  frame->SetImage(_image);

  frame->SetSubRect(sf::IntRect(96, 0, 112, 16));

  _mStand.setDelay(1);
  _mStand.push_back(frame);

}

void		Thystame::mCast()
{
}

void		Thystame::mPond()
{
}

void		Thystame::mTake()
{
}

void		Thystame::mBroad()
{
}

void		Thystame::mExpu()
{
}

void		Thystame::mDie()
{
}
