//
// Player.hh for Player in /home/haulot_a//zappy-2015-2014s-haulot_a/client
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Wed Jun 13 10:36:21 2012 alexandre haulotte
// Last update Thu Jun 14 12:58:00 2012 alexandre haulotte
//

#ifndef	__PLAYER_HH__
#define	__PLAYER_HH__

#include	<vector>
#include	<map>
#include	<iostream>
#include	<string>
#include        <sys/time.h>
#include        <sys/types.h>
#include        <sys/socket.h>
#include        <unistd.h>
#include        <netinet/in.h>
#include        <arpa/inet.h>
#include        <netdb.h>
#include        <sstream>
#include        <stdlib.h>
#include	"Errur.hh"

class Player
{
protected:
  int							_x;
  int							_y;
  int							_width;
  int							_height;
  int							_dir;
  int							_lvl;
  int							_ressource[7];
  std::map< int, std::map< int, std::vector<int> > >	_map;
  int							_id;
  std::string						_teamName;

protected:
  int			_soc;
  int			_port;
  std::string		_addr;
  int			_nbCmd;
  std::vector<int>	_cmd;
  int			_compo;
  std::string		_lastRep;

  //--------------------------------------//
  //------------- Bloc IA ----------------//
  //--------------------------------------//
protected:
  int   Avance();
  //int tourne(Direction dir);
  int   Pond();
  int   RamassezNouriture();
  int	LoopRamassezNouriture();
  int	Eclosion();

  // ------------------------------------- //
  // ------------ Fct Noeud -------------- //
  // ------------------------------------- //
  int   _AssezNouriture();
  int	_NouritureSurCase();
  int	LoopNouritureSurCase();
  int	_PlaceSurServeur();
  int	LoopPlaceSurServeur();

public:
  Player(int port, std::string ip, std::string team, int compo = 0);
  Player(int compo = 0);
  ~Player();
  void		connexion();
  void		play();
  void		initCase(int x, int y);
  void		parse(int ac, char **av);
  int		strToInt(char* str);
  std::string	intToStr(int i);
  void    	initTab();
  //  std::string	charToStr(char*);

public:
  //-------------------------------------//
  //--------------- GETTER --------------//
  //-------------------------------------//
  int							getX() const;
  int							getY() const;
  int							getWidth() const;
  int							getHeight() const;
  int							getDir() const;
  int							getLvl() const;
  int							getRessource(int r) const;
  std::map< int, std::map< int, std::vector<int> > >	getMap() const;
  int							getId() const;

  //-------------------------------------//
  //--------------- SETTER --------------//
  //-------------------------------------//
  void	setX(int x);
  void	setY(int y);
  void	setDir(int dir);
  void	setLvl(int lvl);
  void	setRessource(int r, int nb);
  void	setMap(int x, int y, int p, int nb);

public:
  enum Direction
    {
      NORD = 1,
      EST = 2,
      SUD = 3,
      OUEST = 4
    };

  enum Ressources
    {
      FOOD,
      LINEMATE,
      DERAUMERE,
      SIBURE,
      MENDIANE,
      PHIRAS,
      THYSTAME
    };
  enum	Retour
    {
      KO,
      OK,
      LOOP,
      ERR
    };

  enum	cmd
    {
      AVANCE,
      DROITE,
      GAUCHE,
      VOIR,
      INVENTAIRE,
      PRENDRE_FOOD,
      PRENDRE_LINEMATE,
      PRENDRE_DERAUMERE,
      PRENDRE_SIBURE,
      PRENDRE_MENDIANE,
      PRENDRE_PHIRAS,
      PRENDRE_THYSTAME,
      POSE_FOOD,
      POSE_LINEMATE,
      POSE_DERAUMERE,
      POSE_SIBURE,
      POSE_MENDIANE,
      POSE_PHIRAS,
      POSE_THYSTAME,
      EXPULSE,
      BROADCAST,
      INCANTATION,
      FORK,
      CONNECT,
      ECLOSION,
      SEARCH_FOOD,
      ASSEZ_FOOD,
      LOOP_CONNECT,
      LOOP_PRENDRE_FOOD,
      LOOP_SEARCH_FOOD
    };

    #include	"IA.hh"
};

#endif
