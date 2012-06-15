//
// IA.hh for IA in /home/haulot_a//zappy-2015-2014s-haulot_a/IA
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Thu Jun 14 12:06:09 2012 alexandre haulotte
// Last update Fri Jun 15 09:46:58 2012 alexandre haulotte
//

#ifndef	__IA_HH__
#define	__IA_HH__


//----------------------------------------------//
//--------------- GenericBloc ------------------//
//----------------------------------------------//
int   Avance();
int   Droite();
int   Gauche();
int   Pond();
int   Eclosion();

//----------------------------------------------//
//--------------- SearchBloc -------------------//
//----------------------------------------------//
int   _NourritureSurCase();
int   LoopNourritureSurCase();
int   _LinemateSurCase();
int   LoopLinemateSurCase();
int   _DeraumereSurCase();
int   LoopDeraumereSurCase();
int   _SibureSurCase();
int   LoopSibureSurCase();
int   _MendianeSurCase();
int   LoopMendianeSurCase();
int   _PhirasSurCase();
int   LoopPhirasSurCase();
int   _ThystameSurCase();
int   LoopThystameSurCase();

//----------------------------------------------//
//----------------- TakeBloc -------------------//
//----------------------------------------------//

int   RamassezNourriture();
int   LoopRamassezNourriture();

//----------------------------------------------//
//----------------- TestBloc -------------------//
//----------------------------------------------//

int   _AssezNourriture();
int   LoopAssezNourriture();
int   _AssezRessourceForLevel();
int   _PlaceSurServeur();
int   LoopPlaceSurServeur();

//-----------------EndIAFunc--------------------//

typedef int (Player::*fct)();

std::map<int, std::map<int, int> > trTable;
std::map<int, fct > fctTable;

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
    M_LINE,
    M_DERA,
    M_SIB,
    M_MEND,
    M_PHI,
    M_THY,
    ERR
  };

enum  cmd
  {
    AVANCE,
    // DROITE,
    // GAUCHE,
    // VOIR,
    // INVENTAIRE,
    // PRENDRE_FOOD,
    // PRENDRE_LINEMATE,
    // PRENDRE_DERAUMERE,
    // PRENDRE_SIBURE,
    // PRENDRE_MENDIANE,
    // PRENDRE_PHIRAS,
    // PRENDRE_THYSTAME,
    // POSE_FOOD,
    // POSE_LINEMATE,
    // POSE_DERAUMERE,
    // POSE_SIBURE,
    // POSE_MENDIANE,
    // POSE_PHIRAS,
    // POSE_THYSTAME,
    // EXPULSE,
    // BROADCAST,
    // INCANTATION,
    FORK,
    // CONNECT,
    // ECLOSION,
    // SEARCH_FOOD,
    // ASSEZ_FOOD,
    // TOURNE_DROITE,
    LOOP_FUNC = 2500,
    LOOP_CONNECT = 2501,
    LOOP_PRENDRE_FOOD = 2502,
    LOOP_SEARCH_FOOD = 2503,
    LOOP_ASSEZ_FOOD = 2504
  };

#endif
