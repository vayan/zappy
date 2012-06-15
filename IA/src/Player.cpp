//
// Player.cpp for player in /home/haulot_a//zappy-2015-2014s-haulot_a/client/src
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Wed Jun 13 11:21:10 2012 alexandre haulotte
// Last update Thu Jun 14 18:51:26 2012 alexandre haulotte
//

#include	"Player.hh"

void  Player::connexion()
{
  struct protoent       *pe;
  struct sockaddr_in    sin;
  int                   ret = 0;

  pe = getprotobyname("TCP");
  if ((_soc = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    throw(new Errur("Connection Fail"));
  sin.sin_family = AF_INET;
  sin.sin_addr.s_addr = inet_addr(&_addr[0]);
  if (static_cast<int>(sin.sin_addr.s_addr) == -1)
    throw(new Errur("Connection Fail"));
  sin.sin_port = htons(_port);
  ret = connect(_soc, (const struct sockaddr*)&sin, sizeof(sin));
  if (ret == -1)
    throw(new Errur("Connection Fail"));
}

void  Player::play()
{
  fd_set		readfds;
  struct timeval	tv;
  int                   ret;
  char                  buff[8096 + 1];
  int			fctRet = 0;

  connexion();
  ret = recv(_soc, buff, 8096, 0);
  initTab();
  tv.tv_sec = 0;
  tv.tv_usec = 20;
  send(_soc, &_teamName[0], 40, 0);
  send(_soc, "\n", 1, 0);

  // Player Id
  ret = recv(_soc, buff, 8096, 0);
  buff[ret] = 0;
  _id = strToInt(buff);
  std::cout << "Mon Id est : " << _id;

  // Map X Y
  ret = recv(_soc, buff, 8096, 0);
  buff[ret] = 0;
  std::cout << "Taille Map : " << buff << std::endl;

  FD_ZERO(&readfds);
  FD_SET(0, &readfds);
  FD_SET(_soc, &readfds);
  while (select(_soc + 1, &readfds, NULL, NULL, &tv) != -1)
    {
      if (FD_ISSET(_soc, &readfds))
	{
	  ret = recv(_soc, buff, 8096, 0);
	  buff[ret] = 0;
	  std::cout << buff << std::endl;
	  _lastRep = buff;
	  if (std::string(buff).find("mort") != std::string::npos)
	    exit(0);
	  if (fctRet == LOOP && *(_cmd.begin()) > LOOP_FUNC)
	    {
	      fctRet = (this->*fctTable[_cState])();
	      std::cout << _cState << " " << fctRet << std::endl;
	      _cState = trTable[_cState][fctRet];
	      std::cout << _cState << std::endl;
	    }
	  if (_nbCmd > 0)
	    {
	      _nbCmd--;
	      _cmd.erase(_cmd.begin());
	    }
	}
      if (_nbCmd < 5)
	{
	  if (fctRet != LOOP)
	    {
	      fctRet = (this->*fctTable[_cState])();
	      _cState = trTable[_cState][fctRet];
	    }
	}
      FD_ZERO(&readfds);
      FD_SET(0, &readfds);
      FD_SET(_soc, &readfds);
    }
}

Player::Player(int compo)
  :_x(0), _y(0), _width(0), _height(0), _dir(0), _lvl(0), _id(0),
   _port(0), _addr(""), _nbCmd(0), _compo(0), _lastRep(""), _cState(1)
{
  _teamName = "";
  _ressource[FOOD] = 10;
  _ressource[LINEMATE] = 0;
  _ressource[DERAUMERE] = 0;
  _ressource[SIBURE] = 0;
  _ressource[MENDIANE] = 0;
  _ressource[PHIRAS] = 0;
  _ressource[THYSTAME] = 0;
  _lvlTab = {{1, 1, 0, 0, 0, 0, 0},
	    {2, 1, 1, 1, 0, 0, 0},
	    {2, 2, 0, 1, 0, 2, 0},
	    {4, 1, 1, 2, 0, 1, 0},
	    {4, 1, 2, 1, 3, 0, 0},
	    {6, 1, 2, 3, 0, 1, 0},
	    {6, 2, 2, 2, 2, 2, 1}};
}

Player::Player(int port, std::string ip, std::string team, int compo)
  :_x(0), _y(0), _width(0), _height(0), _dir(0), _lvl(0), _id(0),
   _port(port), _addr(ip), _nbCmd(0), _compo(0), _lastRep(""), _cState(1)
{
  _teamName = team;
  _ressource[FOOD] = 10;
  _ressource[LINEMATE] = 0;
  _ressource[DERAUMERE] = 0;
  _ressource[SIBURE] = 0;
  _ressource[MENDIANE] = 0;
  _ressource[PHIRAS] = 0;
  _ressource[THYSTAME] = 0;
  _lvlTab = {{1, 1, 0, 0, 0, 0, 0},
	    {2, 1, 1, 1, 0, 0, 0},
	    {2, 2, 0, 1, 0, 2, 0},
	    {4, 1, 1, 2, 0, 1, 0},
	    {4, 1, 2, 1, 3, 0, 0},
	    {6, 1, 2, 3, 0, 1, 0},
	    {6, 2, 2, 2, 2, 2, 1}};
}

void	Player::initCase(int x, int y)
{
  for (int i = 0; i < 9; i++)
    (_map[x][y])[i] = 0;
}

void    Player::parse(int ac, char **av)
{
  struct hostent *h;
  std::string ip_address;
  in_addr *addss;

  if (ac < 5)
    throw(new Errur("Usage : ./client -n nom_equipe -p port [-h nom machine]"));
  if (ac == 5)
    _addr = "127.0.0.1";
  else if (ac != 7)
    throw(new Errur("Usage : ./client -n nom_equipe -p port [-h nom machine]"));
  for (int i = 1; i < ac; i++)
    {
      if (i % 2 == 1 && av[i][0] != '-')
	throw(new Errur("Usage : ./client -n nom_equipe -p port [-h nom machine]"));
      else if (i % 2 == 1 && av[i][0] == '-' && av[i][2] == '\0')
	{
	  switch (av[i][1])
	    {
	    case 'n':
	      _teamName = &av[i + 1][0];
	      break;
	    case 'p':
	      _port = strToInt(&av[i + 1][0]);
	      break;
	    case 'h':
	      h = gethostbyname(&av[i + 1][0]);
	      addss = (in_addr*)h->h_addr;
	      ip_address = inet_ntoa(*addss);
	      _addr = ip_address;
	      break;
	    default:
	      throw(new Errur("Usage : ./client -n nom_equipe -p port [-h nom machine]"));
	      break;
	    }
	  i++;
	}
      else
        throw(new Errur("Usage : ./client -n nom_equipe -p port [-h nom machine]"));
    }
  if (_teamName == "" || _port == 0 || _addr == "")
    throw(new Errur("Usage : ./client -n nom_equipe -p port [-h nom machine]"));
  else
    {
      std::cout << "Team Name is : " << _teamName << std::endl;
      std::cout << "Port is : " << _port << std::endl;
      std::cout << "Host Name is : " << _addr << std::endl;
    }
}

//-------------------------------------//
//--------------- GETTER --------------//
//-------------------------------------//
int	Player::getX() const
{ return (_x); }

int	Player::getY() const
{ return (_y); }

int	Player::getWidth() const
{ return (_width); }

int	Player::getHeight() const
{ return (_height); }

int	Player::getDir() const
{ return (_dir); }

int	Player::getLvl() const
{ return (_lvl); }

int	Player::getRessource(int r) const
{ return (_ressource[r]); }

std::map< int, std::map< int, std::vector<int> > >	Player::getMap() const
{ return (_map); }

int	Player::getId() const
{ return (_id); }

//-------------------------------------//
//--------------- SETTER --------------//
//-------------------------------------//
void  Player::setX(int x)
{ _x = x; }

void  Player::setY(int y)
{ _y = y; }

void  Player::setDir(int dir)
{ _dir = dir; }

void  Player::setLvl(int lvl)
{ _lvl = lvl; }

void  Player::setRessource(int r, int nb)
{ _ressource[r] += nb; }

void  Player::setMap(int x, int y, int p, int nb)
{
  if (_map[x][y].empty())
    initCase(x, y);
  (_map[x][y])[p] += nb;
}


int     Player::strToInt(char* str)
{
  std::istringstream    buffer(str);
  int                   nbr;

  buffer >> nbr;
  return (nbr);
}

std::string   Player::intToStr(int i)
{
  std::ostringstream oss;

  oss << i;
  return (oss.str());
}

 // std::string	Player::charToStr(char *buff)
 // {
 //   stringstream	ss;
 //   string 	s;
 //   ss << buff;
 //   ss >> s;
 //   return (s);
 // }

Player::~Player() {}
