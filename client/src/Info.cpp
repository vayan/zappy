//
// Info.cpp for  in /home/cao_y//sysunix/zappy-2015-2014s-haulot_a/client
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Wed Jul 11 16:49:59 2012 yuguo cao
// Last update Thu Jul 12 13:34:51 2012 yuguo cao
//

#include	"Info.hh"

Info::Info(Imman *i)
{
  _lvl = 1;
  _font.LoadFromFile("assets/monofonto.ttf", 24);
  _s_back.SetImage(i->getImage("info"));
  _s_back.SetSubRect(sf::IntRect(0, 0, 400, 200));
  _s_stone.lvl.SetImage(i->getImage("resources"));
  _s_stone.food.SetImage(i->getImage("resources"));
  _s_stone.linemate.SetImage(i->getImage("resources"));
  _s_stone.deraumere.SetImage(i->getImage("resources"));
  _s_stone.sibur.SetImage(i->getImage("resources"));
  _s_stone.mendiane.SetImage(i->getImage("resources"));
  _s_stone.phiras.SetImage(i->getImage("resources"));
  _s_stone.thystame.SetImage(i->getImage("resources"));
  _s_portrait.l1.SetImage(i->getImage("pvl1"));
  _s_portrait.l2.SetImage(i->getImage("pvl2"));
  _s_portrait.l3.SetImage(i->getImage("pvl3"));
}

Info::~Info()
{
}

void			Info::draw(sf::RenderWindow& app, const struct Stone_t& res)
{
  _lvl = res.l;
  setTextsIcons(app, res);
  _s_back.SetPosition(absolutePosition(app, sf::Vector2i(0, 700)));
  app.Draw(_s_back);
  drawText(app);
}

void			Info::setTextsIcons(sf::RenderWindow& app, const struct Stone_t& res)
{
  _strings.lvl.SetText(its(res.l));
  _strings.food.SetText(its(res.food));
  _strings.linemate.SetText(its(res.linemate));
  _strings.deraumere.SetText(its(res.deraumere));
  _strings.sibur.SetText(its(res.sibur));
  _strings.mendiane.SetText(its(res.mendiane));
  _strings.phiras.SetText(its(res.phiras));
  _strings.thystame.SetText(its(res.thystame));

  _strings.lvl.SetPosition(absolutePosition(app, sf::Vector2i(50, 710)));
  _strings.food.SetPosition(absolutePosition(app, sf::Vector2i(50, 755)));
  _strings.linemate.SetPosition(absolutePosition(app, sf::Vector2i(50, 800)));
  _strings.deraumere.SetPosition(absolutePosition(app, sf::Vector2i(50, 845)));
  _strings.sibur.SetPosition(absolutePosition(app, sf::Vector2i(130, 710)));
  _strings.mendiane.SetPosition(absolutePosition(app, sf::Vector2i(130, 755)));
  _strings.phiras.SetPosition(absolutePosition(app, sf::Vector2i(130, 800)));
  _strings.thystame.SetPosition(absolutePosition(app, sf::Vector2i(130, 845)));

  _s_stone.lvl.SetSubRect(sf::IntRect(0, 0, 16, 16));
  _s_stone.food.SetSubRect(sf::IntRect(0, 0, 16, 16));
  _s_stone.linemate.SetSubRect(sf::IntRect(16, 0, 32, 16));
  _s_stone.deraumere.SetSubRect(sf::IntRect(32, 0, 48, 16));
  _s_stone.sibur.SetSubRect(sf::IntRect(48, 0, 64, 16));
  _s_stone.mendiane.SetSubRect(sf::IntRect(64, 0, 80, 16));
  _s_stone.phiras.SetSubRect(sf::IntRect(80, 0, 96, 16));
  _s_stone.thystame.SetSubRect(sf::IntRect(96, 0, 112, 16));

  _s_stone.lvl.SetScale(2, 2);
  _s_stone.food.SetScale(2, 2);
  _s_stone.linemate.SetScale(2, 2);
  _s_stone.deraumere.SetScale(2, 2);
  _s_stone.sibur.SetScale(2, 2);
  _s_stone.mendiane.SetScale(2, 2);
  _s_stone.phiras.SetScale(2, 2);
  _s_stone.thystame.SetScale(2, 2);

  _s_stone.lvl.SetPosition(absolutePosition(app, sf::Vector2i(18, 710)));
  _s_stone.food.SetPosition(absolutePosition(app, sf::Vector2i(18, 755)));
  _s_stone.linemate.SetPosition(absolutePosition(app, sf::Vector2i(18, 800)));
  _s_stone.deraumere.SetPosition(absolutePosition(app, sf::Vector2i(18, 845)));
  _s_stone.sibur.SetPosition(absolutePosition(app, sf::Vector2i(98, 710)));
  _s_stone.mendiane.SetPosition(absolutePosition(app, sf::Vector2i(98, 755)));
  _s_stone.phiras.SetPosition(absolutePosition(app, sf::Vector2i(98, 800)));
  _s_stone.thystame.SetPosition(absolutePosition(app, sf::Vector2i(98, 845)));

  _s_portrait.l1.SetSubRect(sf::IntRect(0, 0, 250, 250));
  _s_portrait.l2.SetSubRect(sf::IntRect(0, 0, 250, 250));
  _s_portrait.l3.SetSubRect(sf::IntRect(0, 0, 250, 250));

  _s_portrait.l1.SetPosition(absolutePosition(app, sf::Vector2i(150, 650)));
  _s_portrait.l2.SetPosition(absolutePosition(app, sf::Vector2i(150, 650)));
  _s_portrait.l3.SetPosition(absolutePosition(app, sf::Vector2i(150, 650)));
}

void			Info::drawText(sf::RenderWindow& app)
{
  app.Draw(_strings.lvl);
  app.Draw(_strings.food);
  app.Draw(_strings.linemate);
  app.Draw(_strings.deraumere);
  app.Draw(_strings.sibur);
  app.Draw(_strings.mendiane);
  app.Draw(_strings.phiras);
  app.Draw(_strings.thystame);

  app.Draw(_s_stone.lvl);
  app.Draw(_s_stone.food);
  app.Draw(_s_stone.linemate);
  app.Draw(_s_stone.deraumere);
  app.Draw(_s_stone.sibur);
  app.Draw(_s_stone.mendiane);
  app.Draw(_s_stone.phiras);
  app.Draw(_s_stone.thystame);

  switch (_lvl)
    {
    case (1):
      app.Draw(_s_portrait.l1);
	break;
    case (2):
      app.Draw(_s_portrait.l2);
	break;
    case (3):
      app.Draw(_s_portrait.l3);
      break;
    }
}

std::string		Info::its(const int i)
{
  std::ostringstream	oss;

  oss << i;
  return (oss.str());
}

sf::Vector2f&		Info::absolutePosition(const sf::RenderWindow& app, const sf::Vector2i& v)
{
  sf::Vector2f		*vi = new sf::Vector2f;

  vi->x = app.GetView().GetCenter().x + (int(app.GetWidth()) / 2 - v.x) * -1;
  vi->y = app.GetView().GetCenter().y + (int(app.GetHeight()) / 2 - v.y) * -1;
  return (*vi);
}