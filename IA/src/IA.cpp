//
// IA.cpp for IA in /home/haulot_a//zappy-2015-2014s-haulot_a/IA
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Thu Jun 14 12:51:45 2012 alexandre haulotte
// Last update Thu Jun 14 12:58:51 2012 alexandre haulotte
//

#include	"Player.hh"

void	Player::initTab()
{
  trTable[FORK][OK] = AVANCE;
  trTable[FORK][KO] = FORK;
  trTable[AVANCE][OK] = ASSEZ_FOOD;
  trTable[AVANCE][KO] = AVANCE;
  trTable[ASSEZ_FOOD][OK] = FORK;
  trTable[ASSEZ_FOOD][KO] = SEARCH_FOOD;
  trTable[SEARCH_FOOD][OK] = PRENDRE_FOOD;
  trTable[SEARCH_FOOD][KO] = AVANCE;
  trTable[SEARCH_FOOD][LOOP] = LOOP_SEARCH_FOOD;
  trTable[PRENDRE_FOOD][OK] = CONNECT;
  trTable[PRENDRE_FOOD][KO] = AVANCE;
  trTable[PRENDRE_FOOD][LOOP] = LOOP_PRENDRE_FOOD;
  trTable[CONNECT][OK] = ECLOSION;
  trTable[CONNECT][KO] = AVANCE;
  trTable[CONNECT][LOOP] = LOOP_CONNECT;
  trTable[ECLOSION][OK] = AVANCE;
  trTable[ECLOSION][KO] = AVANCE;

  fctTable[FORK] = &Player::Pond;
  fctTable[AVANCE] = &Player::Avance;
  fctTable[ASSEZ_FOOD] = &Player::_AssezNouriture;
  fctTable[SEARCH_FOOD] = &Player::_NouritureSurCase;
  fctTable[PRENDRE_FOOD] = &Player::RamassezNouriture;
  fctTable[CONNECT] = &Player::_PlaceSurServeur;
  fctTable[ECLOSION] = &Player::Eclosion;
  fctTable[LOOP_CONNECT] = &Player::LoopPlaceSurServeur;
  fctTable[LOOP_SEARCH_FOOD] = &Player::LoopNouritureSurCase;
  fctTable[LOOP_PRENDRE_FOOD] = &Player::LoopRamassezNouriture;
}
