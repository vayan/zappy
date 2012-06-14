//
// Core.cpp for Core in /home/haulot_a//zappy-2015-2014s-haulot_a/client/src
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Wed Jun  6 13:59:33 2012 alexandre haulotte
// Last update Wed Jun 13 12:45:35 2012 alexandre haulotte
//

#include 	<sstream>
#include	<signal.h>
#include	"Core.hh"
#include	"Parser.hh"
#include	"PlayerCreator.hh"

void			Core::go()
{
  int			ret;
  char			buff[8096 + 1];
  char			cmd[128];
  fd_set		readfds;
  struct timeval	tv;
  int			i , j, save = 0;
  Parser		p;
  PlayerCreator		plCreat;
  std::vector<int>	vec;

  init();
  ret = 1;
  tv.tv_sec = 0;
  tv.tv_usec = 2000;
  send(soc, "GRAPHIC\n", 8, 0);
  send(soc, "tna lola\n", 9, 0);
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
		  vec = p.parseThat(cmd);
		  if (!vec.empty())
		    {
		      joueurs.push_back(plCreat.create(vec, macName, port));
		    }
		  std::cout << "Commande = " << cmd << std::endl;
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

Core::Core(int ac, char **av)
  :soc(0), teamName(""), macName(""), port(0)
{
  beginParse(ac, av);
}

Core::~Core()
{
  std::vector<int>::iterator it;
  for (it = joueurs.begin(); it != joueurs.end(); it++)
    {
      kill((*it), SIGKILL);
    }
}
