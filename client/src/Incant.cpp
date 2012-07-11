//
// Incant.cpp for  in /home/cao_y//sysunix/zappy-2015-2014s-haulot_a/client
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Thu Jun 14 11:21:28 2012 yuguo cao
// Last update Thu Jul  5 12:55:17 2012 yuguo cao
//

#include	"Incant.hh"

Incant::Incant()
{
}

Incant::~Incant()
{
}

void		Incant::mUp()
{
  sf::Sprite	*frame1 = new sf::Sprite;
  sf::Sprite	*frame2 = new sf::Sprite;
  sf::Sprite	*frame3 = new sf::Sprite;
  sf::Sprite	*frame4 = new sf::Sprite;

  frame1->SetImage(_image);
  frame2->SetImage(_image);
  frame3->SetImage(_image);
  frame4->SetImage(_image);

  frame1->SetSubRect(sf::IntRect(0, 0, 100, 84));
  frame2->SetSubRect(sf::IntRect(100, 0, 100 * 2, 84));
  frame3->SetSubRect(sf::IntRect(100 * 2, 0, 100 * 3, 84));
  frame4->SetSubRect(sf::IntRect(100 * 3, 0, 100 * 4, 84));

  _mUp.setDelay(0.1);
  _mUp.push_back(frame1);
  _mUp.push_back(frame2);
  _mUp.push_back(frame3);
  _mUp.push_back(frame4);
}

void		Incant::mDown()
{
}

void		Incant::mLeft()
{
}

void		Incant::mRight()
{
}

void		Incant::mStand()
{
}

void		Incant::mPond()
{
}

void		Incant::mTake()
{
}

void		Incant::mBroad()
{
}

void		Incant::mExpu()
{
}

void		Incant::mDie()
{
}
