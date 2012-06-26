//
// Core.cpp for Core in /home/haulot_a//zappy-2015-2014s-haulot_a/client/src
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Wed Jun  6 13:59:33 2012 alexandre haulotte
// Last update Tue Jun 26 12:08:49 2012 yuguo cao
//

#include	"Core.hh"

Core::Core(int ac, char **av)
  :soc(0), teamName(""), macName(""), port(0)
{
  beginParse(ac, av);

  
}

Core::~Core()
{

}

void			Core::go()
{
  int			ret;
  char			buff[8096 + 1];
  char			cmd[128];
  fd_set		readfds;
  struct timeval	tv;
  int			i , j, save = 0;
  Parser		p;
  std::vector<int>	vec;

  init();
  ret = 1;
  tv.tv_sec = 0;
  tv.tv_usec = 2000;
  send(soc, "GRAPHIC\n", 8, 0);
  FD_ZERO(&readfds);
  FD_SET(0, &readfds);
  FD_SET(soc, &readfds);
  while (select(soc + 1, &readfds, NULL, NULL, &tv) != -1)
    {
      i = 0;
      if (FD_ISSET(soc, &readfds))
	{
	  ret = recv(soc, buff, 8096, 0);
	  if (ret == -1)
	    throw (new Errur("Receive Fail"));
	  buff[ret] = '\0';
	  while (i < ret)
	    {
	      j = save;
	      while (j < 128 && buff[i] && buff[i] != '\n')
	  	{
	  	  cmd[j] = buff[i];
	  	  i++;
	  	  j++;
	  	}
	      cmd[j] = '\0';
	      if (buff[i] == '\n')
		{
		  vec = p.parse(cmd);
		  std::cout << "Commande = " << cmd << std::endl;
		  for(std::vector<int>::iterator i = vec.begin(); i != vec.end();++i)
		    std::cout << *i << std::endl;
		}
	      i++;
	      save = 0;
	    }
	  if (buff[ret - 1] != '\n')
	    save = j;
	}
      FD_ZERO(&readfds);
      FD_SET(0, &readfds);
      FD_SET(soc, &readfds);
    }
}

void			Core::init()
{
  struct protoent	*pe;
  struct sockaddr_in	sin;
  int			ret = 0;

  pe = getprotobyname("TCP");
  if ((soc = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    throw(new Errur("Connection Fail"));
  sin.sin_family = AF_INET;
  sin.sin_addr.s_addr = inet_addr(&macName[0]);
  if (static_cast<int>(sin.sin_addr.s_addr) == -1)
    throw(new Errur("Connection Fail"));
  sin.sin_port = htons(port);
  ret = connect(soc, (const struct sockaddr*)&sin, sizeof(sin));
  if (ret == -1)
    throw(new Errur("Connection Fail"));
}

void	Core::beginParse(int ac, char **av)
{
  struct hostent *h;
  std::string ip_address;
  in_addr *addss;

  if (ac < 5)
    throw(new Errur("Usage : ./client -n nom_equipe -p port [-h nom machine]"));
  if (ac == 5)
    macName = "127.0.0.1";
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
	      teamName = &av[i + 1][0];
	      break;
	    case 'p':
	      port = strToInt(&av[i + 1][0]);
	      break;
	    case 'h':
	      h = gethostbyname(&av[i + 1][0]);
	      addss = (in_addr*)h->h_addr;
	      ip_address = inet_ntoa(*addss);
	      macName = ip_address;
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
  if (teamName == "" || port == 0 || macName == "")
    throw(new Errur("Usage : ./client -n nom_equipe -p port [-h nom machine]"));
  else
    {
      std::cout << "Team Name is : " << teamName << std::endl;
      std::cout << "Port is : " << port << std::endl;
      std::cout << "Host Name is : " << macName << std::endl;
    }
}

int	Core::strToInt(char* str)
{
  std::istringstream 	buffer(str);
  int 			nbr;

  buffer >> nbr;
  return (nbr);
}

std::string   Core::intToStr(int i)
{
  std::ostringstream oss;

  oss << i;
  return (oss.str());
}

void			Core::initTab()
{
  funcs.push_back(&Core::updaMapSize); //msz
  funcs.push_back(&Core::updaCaseInfo); //bct
  funcs.push_back(&Core::rien); //tna
  funcs.push_back(&Core::addPlayer); //pnw
  funcs.push_back(&Core::movePlayer); //ppo
  funcs.push_back(&Core::rien); //plv
  funcs.push_back(&Core::rien); //pin
  funcs.push_back(&Core::rien); //pex
  funcs.push_back(&Core::broaPlayer); //pbc
  funcs.push_back(&Core::incdPlayer); //pic
  funcs.push_back(&Core::incfPlayer); //pie
  funcs.push_back(&Core::pondPlayer); //pfk
  funcs.push_back(&Core::rien); //ebo
  funcs.push_back(&Core::rien); //edi
  funcs.push_back(&Core::rien); //sgt
  funcs.push_back(&Core::rien); //seg
  funcs.push_back(&Core::rien); //smg
  funcs.push_back(&Core::rien); //suc
  funcs.push_back(&Core::rien); //sbp
}

void			Core::updaMapSize(const std::vector<int> v)
{
  Stone_t		stone;

  stone.linemate = v[3];
  stone.deraumere = v[4];
  stone.sibur = v[5];
  stone.mendiane = v[6];
  stone.phiras = v[7];
  stone.thystame = v[8];
  stone.food = v[9];
  graph->updaCaseInfo(v[1], v[2], stone);
}

void			Core::updaCaseInfo(const std::vector<int> v)
{
  Stone_t		stone;

  stone.linemate = v[3];
  stone.deraumere = v[4];
  stone.sibur = v[5];
  stone.mendiane = v[6];
  stone.phiras = v[7];
  stone.thystame = v[8];
  stone.food = v[9];
  graph->updaCaseInfo(v[1], v[2], stone);
}

void			Core::requCaseInfo(const std::vector<int> v)
{
  (void) v;  
}

void			Core::addPlayer(const std::vector<int> v)
{
  ACTION		a;

  switch(v[3])
    {
    case (1):
      a = UP;
      break;
    case (2):
      a = RIGHT;
      break;
    case (3):
      a = DOWN;
      break;
    case (4):
      a = LEFT;
      break;
    default:
      a = UP;
    }
  graph->addPlayer(v[1], v[2], a, v[4], v[5]);
}

void			Core::movePlayer(const std::vector<int> v)
{
  ACTION		a;

  switch(v[3])
    {
    case (1):
      a = UP;
      break;
    case (2):
      a = RIGHT;
      break;
    case (3):
      a = DOWN;
      break;
    case (4):
      a = LEFT;
      break;
    default:
      a = UP;
    }
  graph->movePlayer(v[1], v[2], a, v[4]);
}

void			Core::requPlayerInfo(const std::vector<int> v)
{
  (void) v;
}

void			Core::expuPlayer(const std::vector<int> v)
{
  graph->expuPlayer(v[1]);
}

void			Core::broaPlayer(const std::vector<int> v)
{
  graph->broaPlayer(v[1]);
}

void			Core::incdPlayer(const std::vector<int> v)
{
  graph->incdPlayer(v[1], v[2]);
}

void			Core::incfPlayer(const std::vector<int> v)
{
  graph->incfPlayer(v[1], v[2]);
}

void			Core::pondPlayer(const std::vector<int> v)
{
  graph->pondPlayer(v[1]);
}

void			Core::dropPlayer(const std::vector<int> v)
{
  graph->dropPlayer(v[1]);
}

void			Core::takePlayer(const std::vector<int> v)
{
  graph->takePlayer(v[1]);
}

void			Core::addEgg(const std::vector<int> v)
{
  graph->addEgg(v[1], v[2], v[3], v[4]);
}

void			Core::eggHatched(const std::vector<int> v)
{
  graph->eggHatched(v[1]);
}

void			Core::rien(const std::vector<int> v)
{
  (void) v;
}
