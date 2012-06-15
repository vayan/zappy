//
// IA.hh for IA in /home/haulot_a//zappy-2015-2014s-haulot_a/IA
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Thu Jun 14 12:06:09 2012 alexandre haulotte
// Last update Fri Jun 15 10:22:57 2012 alexandre haulotte
//

#ifndef	__IA_HH__
#define	__IA_HH__


//----------------------------------------------//
//--------------- GenericBloc ------------------//
//----------------------------------------------//
int	Avance();
int	Droite();
int	Gauche();
int	Pond();
int	Eclosion();

//----------------------------------------------//
//--------------- SearchBloc -------------------//
//----------------------------------------------//
int	_NourritureSurCase();
int	LoopNourritureSurCase();
int	_LinemateSurCase();
int	LoopLinemateSurCase();
int	_DeraumereSurCase();
int	LoopDeraumereSurCase();
int	_SibureSurCase();
int	LoopSibureSurCase();
int	_MendianeSurCase();
int	LoopMendianeSurCase();
int	_PhirasSurCase();
int	LoopPhirasSurCase();
int	_ThystameSurCase();
int	LoopThystameSurCase();
int	_RessourceForLvlSurCase();
int	LoopRessourceForLvlSurCase();

//----------------------------------------------//
//----------------- TakeBloc -------------------//
//----------------------------------------------//

int	_RamassezNourriture();
int	LoopRamassezNourriture();
int	_RamassezLinemate();
int	_RamassezDeraumere();
int	_RamassezSibure();
int	_RamassezMendiane();
int	_RamassezPhiras();
int	_RamassezThystame();
int	_RamassezRessourceForLvl();
int	LoopRamassezRessource();

//----------------------------------------------//
//----------------- TestBloc -------------------//
//----------------------------------------------//

int	_AssezNourriture();
int	LoopAssezNourriture();
int	AssezRessourceForLevel();
int	_PlaceSurServeur();
int	LoopPlaceSurServeur();

//-----------------EndIAFunc--------------------//

typedef int (Player::*fct)();

std::map<int, std::map<int, int> > trTable;
std::map<int, fct > fctTable;
int	RWant;

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

enum  Retour
  {
    KO,
    OK,
    LOOP,
    ERR
  };

enum  cmd
  {
    AVANCE,
    FORK,
    LOOP_FUNC = 2500,
    LOOP_CONNECT = 2501,
    LOOP_PRENDRE_FOOD = 2502,
    LOOP_SEARCH_FOOD = 2503,
    LOOP_ASSEZ_FOOD = 2504
  };

#endif
