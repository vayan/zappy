//
// Character.cpp for  in /home/cao_y//sysunix/zappy-2015-2014s-haulot_a/client
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Thu Jun 14 11:21:28 2012 yuguo cao
// Last update Wed Jul  4 11:44:32 2012 yuguo cao
//

#include	"Character.hh"

Character::Character()
{
}

Character::~Character()
{
}

void		Character::mUp()
{
  sf::Sprite	*frame1 = new sf::Sprite;
  sf::Sprite	*frame2 = new sf::Sprite;
  sf::Sprite	*frame3 = new sf::Sprite;
  sf::Sprite	*frame4 = new sf::Sprite;

  frame1->SetImage(_image);
  frame2->SetImage(_image);
  frame3->SetImage(_image);
  frame4->SetImage(_image);

  frame1->SetSubRect(sf::IntRect(24, 0, 24 * 2, 60));
  frame2->SetSubRect(sf::IntRect(24 * 3, 0, 24 * 4, 60));
  frame3->SetSubRect(sf::IntRect(24 * 5, 0, 24 * 6, 60));
  frame4->SetSubRect(sf::IntRect(24 * 7, 0, 24 * 8, 60));

  _mUp.setDelay(0.2);
  _mUp.push_back(frame1);
  _mUp.push_back(frame3);
  _mUp.push_back(frame2);
  _mUp.push_back(frame4);
}

void		Character::mDown()
{
  sf::Sprite	*frame1 = new sf::Sprite;
  sf::Sprite	*frame2 = new sf::Sprite;
  sf::Sprite	*frame3 = new sf::Sprite;
  sf::Sprite	*frame4 = new sf::Sprite;

  frame1->SetImage(_image);
  frame2->SetImage(_image);
  frame3->SetImage(_image);
  frame4->SetImage(_image);

  frame1->SetSubRect(sf::IntRect(24 * 17, 0, 24 * 18, 60));
  frame2->SetSubRect(sf::IntRect(24 * 19, 0, 24 * 20, 60));
  frame3->SetSubRect(sf::IntRect(24 * 21, 0, 24 * 22, 60));
  frame4->SetSubRect(sf::IntRect(24 * 23, 0, 24 * 24, 60));

  _mDown.setDelay(0.2);
  _mDown.push_back(frame1);
  _mDown.push_back(frame2);
  _mDown.push_back(frame3);
  _mDown.push_back(frame4);
}

void		Character::mLeft()
{
  sf::Sprite	*frame1 = new sf::Sprite;
  sf::Sprite	*frame2 = new sf::Sprite;
  sf::Sprite	*frame3 = new sf::Sprite;
  sf::Sprite	*frame4 = new sf::Sprite;

  frame1->SetImage(_image);
  frame2->SetImage(_image);
  frame3->SetImage(_image);
  frame4->SetImage(_image);

  frame1->SetSubRect(sf::IntRect(24 * 25, 0, 24 * 26, 60));
  frame2->SetSubRect(sf::IntRect(24 * 27, 0, 24 * 28, 60));
  frame3->SetSubRect(sf::IntRect(24 * 29, 0, 24 * 30, 60));
  frame4->SetSubRect(sf::IntRect(24 * 31, 0, 24 * 32, 60));

  _mLeft.setDelay(0.2);
  _mLeft.push_back(frame1);
  _mLeft.push_back(frame2);
  _mLeft.push_back(frame3);
  _mLeft.push_back(frame4);
}

void		Character::mRight()
{
  sf::Sprite	*frame1 = new sf::Sprite;
  sf::Sprite	*frame2 = new sf::Sprite;
  sf::Sprite	*frame3 = new sf::Sprite;
  sf::Sprite	*frame4 = new sf::Sprite;

  frame1->SetImage(_image);
  frame2->SetImage(_image);
  frame3->SetImage(_image);
  frame4->SetImage(_image);

  frame1->SetSubRect(sf::IntRect(24 * 9, 0, 24 * 10, 60));
  frame2->SetSubRect(sf::IntRect(24 * 11, 0, 24 * 12, 60));
  frame3->SetSubRect(sf::IntRect(24 * 13, 0, 24 * 14, 60));
  frame4->SetSubRect(sf::IntRect(24 * 15, 0, 24 * 16, 60));

  _mRight.setDelay(0.2);
  _mRight.push_back(frame1);
  _mRight.push_back(frame2);
  _mRight.push_back(frame3);
  _mRight.push_back(frame4);
}

void		Character::mStand()
{
  sf::Sprite	*frame1 = new sf::Sprite;
  sf::Sprite	*frame2 = new sf::Sprite;
  sf::Sprite	*frame3 = new sf::Sprite;
  sf::Sprite	*frame4 = new sf::Sprite;

  frame1->SetImage(_image);
  frame2->SetImage(_image);
  frame3->SetImage(_image);
  frame4->SetImage(_image);

  frame1->SetSubRect(sf::IntRect(24, 0, 24 * 2, 60));
  frame2->SetSubRect(sf::IntRect(24 * 9, 0, 24 * 10, 60));
  frame3->SetSubRect(sf::IntRect(24 * 17, 0, 24 * 18, 60));
  frame4->SetSubRect(sf::IntRect(24 * 25, 0, 24 * 26, 60));

  _mStand.pause();
  _mStand.push_back(frame1);
  _mStand.push_back(frame3);
  _mStand.push_back(frame4);
  _mStand.push_back(frame2);
}

void		Character::mPond()
{
  sf::Sprite	*frame1 = new sf::Sprite;
  // sf::Sprite	*frame2 = new sf::Sprite;
  // sf::Sprite	*frame3 = new sf::Sprite;
  // sf::Sprite	*frame4 = new sf::Sprite;

  frame1->SetImage(_image);
  // frame2->SetImage(_image);
  // frame3->SetImage(_image);
  // frame4->SetImage(_image);

  frame1->SetSubRect(sf::IntRect(24 * 49, 0, 24 * 50, 60));
  // frame2->SetSubRect(sf::IntRect(24 * 49, 0, 24 * 50, 60));
  // frame3->SetSubRect(sf::IntRect(24 * 49, 0, 24 * 50, 60));
  // frame4->SetSubRect(sf::IntRect(24 * 49, 0, 24 * 50, 60));

  _mPond.pause();
  _mPond.push_back(frame1);
  _mPond.push_back(frame1);
  _mPond.push_back(frame1);
  _mPond.push_back(frame1);
}

void		Character::mTake()
{
  sf::Sprite	*frame1 = new sf::Sprite;
  sf::Sprite	*frame2 = new sf::Sprite;
  sf::Sprite	*frame3 = new sf::Sprite;
  sf::Sprite	*frame4 = new sf::Sprite;

  frame1->SetImage(_image);
  frame2->SetImage(_image);
  frame3->SetImage(_image);
  frame4->SetImage(_image);

  frame1->SetSubRect(sf::IntRect(24 * 33, 0, 24 * 34, 60));
  frame2->SetSubRect(sf::IntRect(24 * 35, 0, 24 * 36, 60));
  frame3->SetSubRect(sf::IntRect(24 * 37, 0, 24 * 38, 60));
  frame4->SetSubRect(sf::IntRect(24 * 39, 0, 24 * 40, 60));

  _mTake.pause();
  _mTake.push_back(frame3);
  _mTake.push_back(frame2);
  _mTake.push_back(frame1);
  _mTake.push_back(frame4);
}

void		Character::mBroad()
{
  sf::Sprite	*frame1 = new sf::Sprite;
  // sf::Sprite	*frame2 = new sf::Sprite;
  // sf::Sprite	*frame3 = new sf::Sprite;
  // sf::Sprite	*frame4 = new sf::Sprite;

  frame1->SetImage(_image);
  // frame2->SetImage(_image);
  // frame3->SetImage(_image);
  // frame4->SetImage(_image);

  frame1->SetSubRect(sf::IntRect(24 * 51, 0, 24 * 52, 60));
  // frame2->SetSubRect(sf::IntRect(24 * 49, 0, 24 * 50, 60));
  // frame3->SetSubRect(sf::IntRect(24 * 49, 0, 24 * 50, 60));
  // frame4->SetSubRect(sf::IntRect(24 * 49, 0, 24 * 50, 60));

  _mBroad.pause();
  _mBroad.push_back(frame1);
  _mBroad.push_back(frame1);
  _mBroad.push_back(frame1);
  _mBroad.push_back(frame1);

}

void		Character::mExpu()
{
  sf::Sprite	*frame1 = new sf::Sprite;
  sf::Sprite	*frame2 = new sf::Sprite;
  sf::Sprite	*frame3 = new sf::Sprite;
  sf::Sprite	*frame4 = new sf::Sprite;

  frame1->SetImage(_image);
  frame2->SetImage(_image);
  frame3->SetImage(_image);
  frame4->SetImage(_image);

  frame1->SetSubRect(sf::IntRect(24 * 41, 0, 24 * 42, 60));
  frame2->SetSubRect(sf::IntRect(24 * 43, 0, 24 * 44, 60));
  frame3->SetSubRect(sf::IntRect(24 * 45, 0, 24 * 46, 60));
  frame4->SetSubRect(sf::IntRect(24 * 47, 0, 24 * 48, 60));

  _mExpu.pause();
  _mExpu.push_back(frame3);
  _mExpu.push_back(frame2);
  _mExpu.push_back(frame1);
  _mExpu.push_back(frame4);
}

void		Character::mDie()
{
}
