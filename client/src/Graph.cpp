//
// Graph.cpp for  in /home/cao_y//sysunix/zappy-2015-2014s-haulot_a/client
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Wed Jun  6 14:16:26 2012 yuguo cao
// Last update Thu Jul  5 11:45:47 2012 yuguo cao
//

#include	"Graph.hh"

Graph::Graph(const int width, const int height, const int m_width, const int m_height)
  : _app(sf::VideoMode(width, height, 32), "SFML Window"), _input(_app.GetInput())
{
  _imman = new Imman();
  _scr_height = height;
  _scr_width = width;
  _scr_bpp = 32;
  _server_time = 100;
  _map.setHeight(m_height);
  _map.setWidth(m_width);
}

Graph::~Graph()
{
}

void			Graph::run()
{
  //initialize();
  //while (_app.IsOpened())
  //{
      update();
      draw();
      //}
}

void			Graph::initialize()
{
  srand(time(NULL));
  _app.SetFramerateLimit(60);
  _imman->loadImages();

  _char.createAnim(_imman->getImage("sprite"));
  _char.setPosition(0, 0);

  _view.SetFromRect(sf::FloatRect(0, 0, _scr_width, _scr_height));
  _view.SetCenter(640, 0);

  _map.setImage(_imman->getImage("back"));
}

void			Graph::update()
{
  int			x;
  int			y;
  sf::Event		event;
  float			elapsedTime = _app.GetFrameTime();
  sf::Vector2<int>	ccase;

  while (_app.GetEvent(event))
    {
      if (((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::Escape))
	  || event.Type == sf::Event::Closed)
	_app.Close();

      if (event.Type == sf::Event::MouseWheelMoved)
	{
	  if (event.MouseWheel.Delta > 0)
	    _view.Zoom(1.1);
	  else if (event.MouseWheel.Delta < 0)
	    _view.Zoom(0.9);
	}
      if (event.Type == sf::Event::MouseButtonPressed)
	{
	  x = relaMouse(event).x;
	  y = relaMouse(event).y;
	  // if (event.MouseButton.Button == 0 && (x >= _char.getPosition().x && x <= _char.getPosition().x + 35 && y >= _char.getPosition().y && y <= _char.getPosition().y + 80))
	  //   {
	  //     std::cout << _char.getPosition().x << " " << _char.getPosition().y << std::endl;
	  //   }
	  //else
	  if (event.MouseButton.Button == 0)
	    {
	      for(std::map<int, ASprite*>::iterator it = _sprites.begin(); it != _sprites.end(); ++it)
		{
		  std::cout << x << " " << y << ":" << ((it->second)->getPosition()).x << " " << ((it->second)->getPosition()).y << std::endl;
		  if (x >= ((it->second)->getPosition()).x && x <= ((it->second)->getPosition()).x + 24 && y >= ((it->second)->getPosition()).y && y <= ((it->second)->getPosition()).y + 60)
		    {
		      std::cout << it->first << std::endl;
		      break;
		    }
		  std::cout << "clop" << std::endl;
		}
	    }
	  if (event.MouseButton.Button == 2)
	    {
	      ccase = _map.getMCase(relaMouse(event));
	    }
	}
    }
  // if (_view.GetCenter().x > 0 && _input.GetMouseX() < 200)
  //   _view.Move(-200 * elapsedTime, 0);
  // else if (_view.GetCenter().x < _map.getWidth() * 64 + (_map.getHeight() * 64) && _input.GetMouseX() > 1240)
  //   _view.Move(200 * elapsedTime, 0);
  // if (_view.GetCenter().y > (_map.getWidth() - 1) * -32 && _input.GetMouseY() < 100)
  //   _view.Move(0, -200 * elapsedTime);
  // else if (_view.GetCenter().y < (_map.getHeight() + 1) * 32 && _input.GetMouseY() > 800)
  //   _view.Move(0, 200 * elapsedTime);
}

sf::Vector2<int>&	Graph::relaMouse(const sf::Event& event)
{
  sf::Vector2<int>	*v2 = new sf::Vector2<int>();

  v2->x = _view.GetCenter().x + (int(_app.GetWidth()) / 2 - event.MouseButton.X) * -1;
  v2->y = _view.GetCenter().y + (int(_app.GetHeight()) / 2 - event.MouseButton.Y) * -1;
  return (*v2);
}

void			Graph::draw()
{
  float		elapsedTime = _app.GetFrameTime();

  _app.Clear(sf::Color(0, 0, 200));
  _map.draw(this->_app);
  // if (_app.GetInput().IsKeyDown(sf::Key::Left))
  //   {
  //     _char.move(-100 * elapsedTime, 50 * elapsedTime);
  //     _app.Draw(_char.anim(LEFT));
  //   }
  // else if (_app.GetInput().IsKeyDown(sf::Key::Right))
  //   {
  //     _char.move(100 * elapsedTime, -50 * elapsedTime);
  //     _app.Draw(_char.anim(RIGHT));
  //   }
  // else if (_app.GetInput().IsKeyDown(sf::Key::Up))
  //   {
  //     _char.move(-100 * elapsedTime, -50 * elapsedTime);
  //     _app.Draw(_char.anim(UP));
  //   }
  // else if (_app.GetInput().IsKeyDown(sf::Key::Down))
  //   {
  //     _char.move(100 * elapsedTime, 50 * elapsedTime);
  //     _app.Draw(_char.anim(DOWN));
  //   }
  // else
  //   _app.Draw(_char.anim(STAND));
  //_view.SetCenter(_char.getPosition());

  for(std::map<Vector2ic, std::vector<ASprite*> >::iterator imap = _s_map.begin(); imap != _s_map.end(); ++imap)
    {
      for(std::vector<ASprite*>::iterator imapvec = (imap->second).begin(); imapvec != (imap->second).end(); ++imapvec)
  	{
  	  _app.Draw((*imapvec)->anim(STAND));
  	}
    }

  for(std::map<Vector2ic, ASprite*>::iterator iot = _s_other.begin(); iot != _s_other.end(); ++iot)
    {
      _app.Draw((iot->second)->anim());
    }

  for(std::map<int, ASprite*>::iterator it = _sprites.begin(); it != _sprites.end(); ++it)
    {
      _app.Draw((it->second)->anim());
      if (_movements[it->first].z == 0)// && _movements[it->first].t > 0)
	{
	  //_movements[it->first].t = 0;
	  _sprites[it->first]->setLastAction(STAND);
	}
      if (_movements[it->first].z > 0 && _movements[it->first].t / _clock.GetElapsedTime() >= _movements[it->first].t / (_server_time * 10))
	{
	  _sprites[it->first]->move(_movements[it->first].x, _movements[it->first].y);
	  _movements[it->first].z--;
	  _clock.Reset();
	}
    }
  _app.SetView(_view);
  _app.Display();
}

void			Graph::updaCaseInfo(const int x, const int y, const Stone_t& res)
{
  Vector2ic		v(x, y);

  _s_map[v].clear();
  if (res.linemate)
    {
      Linemate *n = new Linemate;
      n->createAnim(_imman->getImage("resources"));
      n->setPosition(x * 64 + (y * 64), y * 32 - (x * 32) + 16);
      n->setLastAction(NO);
      n->setScale((log(res.linemate) + 4) / 5);
      _s_map[v].push_back(n);
    }
  if (res.deraumere)
    {
      Deraumere *n = new Deraumere;
      n->createAnim(_imman->getImage("resources"));
      n->setPosition(x * 64 + (y * 64) + 16, y * 32 - (x * 32) + 16);
      n->setLastAction(NO);
      n->setScale((log(res.deraumere) + 4) / 5);
      _s_map[v].push_back(n);
    }
  if (res.sibur)
    {
      Sibur *n = new Sibur;
      n->createAnim(_imman->getImage("resources"));
      n->setPosition(x * 64 + (y * 64) + 32, y * 32 - (x * 32) + 16);
      n->setLastAction(NO);
      n->setScale((log(res.sibur) + 4) / 5);
      _s_map[v].push_back(n);
    }
  if (res.mendiane)
    {
      Mendiane *n = new Mendiane;
      n->createAnim(_imman->getImage("resources"));
      n->setPosition(x * 64 + (y * 64) + 48, y * 32 - (x * 32) + 16);
      n->setLastAction(NO);
      n->setScale((log(res.mendiane) + 4) / 5);
      _s_map[v].push_back(n);
    }
  if (res.phiras)
    {
      Phiras *n = new Phiras;
      n->createAnim(_imman->getImage("resources"));
      n->setPosition(x * 64 + (y * 64) + 64, y * 32 - (x * 32) + 16);
      n->setLastAction(NO);
      n->setScale((log(res.phiras) + 4) / 5);
      _s_map[v].push_back(n);
    }
  if (res.thystame)
    {
      Thystame *n = new Thystame;
      n->createAnim(_imman->getImage("resources"));
      n->setPosition(x * 64 + (y * 64) + 80, y * 32 - (x * 32) + 16);
      n->setLastAction(NO);
      n->setScale((log(res.thystame) + 4) / 5);
      _s_map[v].push_back(n);
    }
  if (res.food)
    {
      Nourriture *n = new Nourriture;
      n->createAnim(_imman->getImage("resources"));
      n->setPosition(x * 64 + (y * 64) + 112, y * 32 - (x * 32) + 16);
      n->setLastAction(NO);
      n->setScale(((log(res.food) + 4) / 5) * 2);
      _s_map[v].push_back(n);
    }
}

void			Graph::requCaseInfo(const int x, const int y, const Stone_t& res)
{
  (void) x;
  (void) y;
  (void) res;
}

void			Graph::addPlayer(const int n, const int x, const int y, const ACTION orientation, const int lvl, const std::string& t)
{
  Character		*newchar = new Character();

  newchar->createAnim(_imman->getImage("sprite"));
  newchar->setPosition(x * 64 + (y * 64), y * 32 - (x * 32));
  newchar->setOrientation(orientation);
  newchar->setLastAction(STAND);
  _sprites[n] = newchar;
  _teams[n] = t;
}

void			Graph::movePlayer(const int n, const int x, const int y, const ACTION orientation)
{
  int			x_src;
  int			y_src;
  int			x_dest;
  int			y_dest;

  if (_movements[n].z > 0)
    {
      //std::cout << "Retard" << std::endl;
      _sprites[n]->move(_movements[n].x * _movements[n].z, _movements[n].y * _movements[n].z);
    }

  _sprites[n]->setOrientation(orientation);
  _sprites[n]->setLastAction(orientation);
  x_src = _sprites[n]->getPosition().x;
  y_src = _sprites[n]->getPosition().y;
  x_dest = x * 64 + y * 64;
  y_dest = y * 32 - x * 32;
  _movements[n].x = (x_dest - x_src) / 10;
  _movements[n].y = (y_dest - y_src) / 10;
  _movements[n].z = 10;
  _movements[n].t = 7;
}

void			Graph::lvlPlayer(const int n, const int lvl)
{
  _invent[n]->l = lvl;
}

void			Graph::inventPlayer(const int n, Stone_t *res)
{
  int			lvl;

  lvl = res->l;
  _invent[n] = res;
  _invent[n]->l = lvl;
}

void			Graph::requPlayerInfo(const int n)
{
  (void) n;
}

void			Graph::expuPlayer(const int n)
{
  if (_movements[n].z > 0)
    {
      //std::cout << "Retard" << std::endl;
      _sprites[n]->move(_movements[n].x * _movements[n].z, _movements[n].y * _movements[n].z);
    }
  _sprites[n]->setLastAction(EXPU);
  _movements[n].x = 0;
  _movements[n].y = 0;
  _movements[n].z = 10;
  _movements[n].t = 7;
}

void			Graph::broaPlayer(const int n)
{
  if (_movements[n].z > 0)
    {
      //std::cout << "Retard" << std::endl;
      _sprites[n]->move(_movements[n].x * _movements[n].z, _movements[n].y * _movements[n].z);
    }
  _sprites[n]->setLastAction(BROAD);
  _movements[n].x = 0;
  _movements[n].y = 0;
  _movements[n].z = 10;
  _movements[n].t = 7;
}

void			Graph::incdPlayer(const int x, const int y)
{
  Incant		*newinc = new Incant();

  newinc->createAnim(_imman->getImage("incant"));
  newinc->setPosition(x * 64 + (y * 64), y * 32 - (x * 32));
  newinc->setLastAction(UP);
  newinc->setOrientation(UP);
  _s_other[Vector2ic(x, y)] = newinc;
}

void			Graph::incfPlayer(const int x, const int y)
{
  _s_other.erase(Vector2ic(x, y));
}

void			Graph::pondPlayer(const int n)
{
  if (_movements[n].z > 0)
    {
      std::cout << "Retard" << std::endl;
      _sprites[n]->move(_movements[n].x * _movements[n].z, _movements[n].y * _movements[n].z);
    }
  _sprites[n]->setLastAction(POND);
  _movements[n].x = 0;
  _movements[n].y = 0;
  _movements[n].z = 10;
  _movements[n].t = 42;
}

void			Graph::dropPlayer(const int n)
{
  takePlayer(n);
}

void			Graph::takePlayer(const int n)
{
  if (_movements[n].z > 0)
    {
      std::cout << "Retard" << std::endl;
      _sprites[n]->move(_movements[n].x * _movements[n].z, _movements[n].y * _movements[n].z);
    }
  _sprites[n]->setLastAction(TAKE);
  _movements[n].x = 0;
  _movements[n].y = 0;
  _movements[n].z = 10;
  _movements[n].t = 7;
}

void			Graph::addEgg(const int x, const int y, const int n, const int t)
{
  // Egg			*newegg = new Egg();

  // newegg->createAnim(_imman->getImage("mage_charset1"));
  // newegg->setPosition(x * 64 + (y * 64), y * 32 - (x * 32));
  // newegg->setLastAction(orientation);
  // _sprites[n] = newegg;
  (void) x;
  (void) y;
  (void) n;
  (void) t;
}

void			Graph::diePlayer(const int n)
{
  _sprites.erase(n);
}

void			Graph::eggHatched(const int n)
{
  //_sprites.erase(n);
}

void			Graph::timeServer(const int t)
{
  _server_time = t;
}
