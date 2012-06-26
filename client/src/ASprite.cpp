//
// ASprite.cpp for  in /home/cao_y//sysunix/zappy-2015-2014s-haulot_a/client
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Thu Jun 14 11:09:55 2012 yuguo cao
// Last update Wed Jun 20 15:41:49 2012 yuguo cao
//

#include	"ASprite.hh"

ASprite::ASprite()
{
  _lastAction = UP;
}

ACTION		ASprite::getLastAction() const
{
  return (_lastAction);
}

void		ASprite::createAnim(const sf::Image& i)
{
  _image = i;
  mUp();
  mDown();
  mLeft();
  mRight();
  mStand();
  mCast();
  mBroad();
  mCast();
}

LayerAnimation	ASprite::anim(ACTION a)
{
  if (a == NO)
    a = _lastAction;
  switch (a)
    {
    case (UP):
      _orientation = UP;
      _lastAction = UP;
      return (_mUp);
      break;
    case (DOWN):
      _orientation = DOWN;
      _lastAction = DOWN;
      return (_mDown);
      break;
    case (LEFT):
      _orientation = LEFT;
      _lastAction = LEFT;
      return (_mLeft);
      break;
    case (RIGHT):
      _orientation = RIGHT;
      _lastAction = RIGHT;
      return (_mRight);
      break;
    case (STAND):
      _lastAction = STAND;
      switch (_orientation)
	{
	case (UP):
	  _mStand.setFrame(0);
	  break;
	case (DOWN):
	  _mStand.setFrame(1);
	  break;
	case (LEFT):
	  _mStand.setFrame(2);
	  break;
	case (RIGHT):
	  _mStand.setFrame(3);
	  break;
	default:
	  _mStand.setFrame(0);
	}
      return (_mStand);
      break;
    case (CAST):
      _lastAction = CAST;
      switch (_orientation)
	{
	case (UP):
	  _mCast.setFrame(0);
	  break;
	case (DOWN):
	  _mCast.setFrame(1);
	  break;
	case (LEFT):
	  _mCast.setFrame(2);
	  break;
	case (RIGHT):
	  _mCast.setFrame(3);
	  break;
	default:
	  _mCast.setFrame(0);
	}
      return (_mCast);
      break;
    case (BROAD):
      _lastAction = BROAD;
      switch (_orientation)
	{
	case (UP):
	  _mBroad.setFrame(0);
	  break;
	case (DOWN):
	  _mBroad.setFrame(1);
	  break;
	case (LEFT):
	  _mBroad.setFrame(2);
	  break;
	case (RIGHT):
	  _mBroad.setFrame(3);
	  break;
	default:
	  _mBroad.setFrame(0);
	}
      return (_mBroad);
      break;
    case (DIE):
      _lastAction = DIE;
      switch (_orientation)
	{
	case (UP):
	  _mDie.setFrame(0);
	  break;
	case (DOWN):
	  _mDie.setFrame(1);
	  break;
	case (LEFT):
	  _mDie.setFrame(2);
	  break;
	case (RIGHT):
	  _mDie.setFrame(3);
	  break;
	default:
	  _mDie.setFrame(0);
	}
      return (_mDie);
      break;
    default:
      return (_mStand);
    }
}


// LayerAnimation	ASprite::anim(ACTION a, ACTION last)
// {
//   switch (a)
//     {
//     case (UP):
//       _lastAction = UP;
//       return (_mUp);
//       break;
//     case (DOWN):
//       _lastAction = DOWN;
//       return (_mDown);
//       break;
//     case (LEFT):
//       _lastAction = LEFT;
//       return (_mLeft);
//       break;
//     case (RIGHT):
//       _lastAction = RIGHT;
//       return (_mRight);
//       break;
//     case (STAND):
//       switch (last)
// 	{
// 	case (UP):
// 	  _mStand.setFrame(0);
// 	  break;
// 	case (DOWN):
// 	  _mStand.setFrame(1);
// 	  break;
// 	case (LEFT):
// 	  _mStand.setFrame(2);
// 	  break;
// 	case (RIGHT):
// 	  _mStand.setFrame(3);
// 	  break;
// 	default:
// 	  _mStand.setFrame(0);
// 	}
//       return (_mStand);
//       break;
//     case (CAST):
//       switch (last)
// 	{
// 	case (UP):
// 	  _mCast.setFrame(0);
// 	  break;
// 	case (DOWN):
// 	  _mCast.setFrame(1);
// 	  break;
// 	case (LEFT):
// 	  _mCast.setFrame(2);
// 	  break;
// 	case (RIGHT):
// 	  _mCast.setFrame(3);
// 	  break;
// 	default:
// 	  _mCast.setFrame(0);
// 	}
//       return (_mCast);
//       break;
//     case (BROAD):
//       switch (last)
// 	{
// 	case (UP):
// 	  _mBroad.setFrame(0);
// 	  break;
// 	case (DOWN):
// 	  _mBroad.setFrame(1);
// 	  break;
// 	case (LEFT):
// 	  _mBroad.setFrame(2);
// 	  break;
// 	case (RIGHT):
// 	  _mBroad.setFrame(3);
// 	  break;
// 	default:
// 	  _mBroad.setFrame(0);
// 	}
//       return (_mBroad);
//       break;
//     case (DIE):
//       switch (last)
// 	{
// 	case (UP):
// 	  _mDie.setFrame(0);
// 	  break;
// 	case (DOWN):
// 	  _mDie.setFrame(1);
// 	  break;
// 	case (LEFT):
// 	  _mDie.setFrame(2);
// 	  break;
// 	case (RIGHT):
// 	  _mDie.setFrame(3);
// 	  break;
// 	default:
// 	  _mDie.setFrame(0);
// 	}
//       return (_mDie);
//       break;
//     default:
//       return (_mStand);
//     }
// }

void		ASprite::move(const float x, const float y)
{
  _mUp.Move(x, y);
  _mDown.Move(x, y);
  _mLeft.Move(x, y);
  _mRight.Move(x, y);
  _mStand.Move(x, y);
  _mCast.Move(x, y);
  _mBroad.Move(x, y);
  _mDie.Move(x, y);
}

void		ASprite::setLastAction(const ACTION a)
{
  _lastAction = a;
}

void		ASprite::setPosition(const int x, const int y)
{
  _mUp.SetPosition(x, y);
  _mDown.SetPosition(x, y);
  _mLeft.SetPosition(x, y);
  _mRight.SetPosition(x, y);
  _mStand.SetPosition(x, y);
  _mCast.SetPosition(x, y);
  _mBroad.SetPosition(x, y);
  _mDie.SetPosition(x, y);
}

const sf::Vector2f&	ASprite::getPosition()
{
  return (_mStand.GetPosition());
}
