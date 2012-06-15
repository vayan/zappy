//
// IA.cpp for IA in /home/haulot_a//zappy-2015-2014s-haulot_a/IA
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Thu Jun 14 12:51:45 2012 alexandre haulotte
// Last update Thu Jun 14 17:12:15 2012 alexandre haulotte
//

#include	"Player.hh"

void	Player::initTab()
{
  trTable[1][OK] = 2;
  trTable[1][KO] = 1;
  trTable[2][OK] = 3;
  trTable[2][KO] = 2;
  trTable[LOOP_ASSEZ_FOOD][OK] = 1;
  trTable[LOOP_ASSEZ_FOOD][KO] = 4;
  trTable[3][KO] = 1;
  trTable[3][LOOP] = LOOP_ASSEZ_FOOD;
  trTable[LOOP_SEARCH_FOOD][OK] = 6;
  trTable[LOOP_SEARCH_FOOD][KO] = 5;
  trTable[4][KO] = 5;
  trTable[4][LOOP] = LOOP_SEARCH_FOOD;
  trTable[5][OK] = 4;
  trTable[5][KO] = 1;
  trTable[LOOP_PRENDRE_FOOD][OK] = 7;
  trTable[LOOP_PRENDRE_FOOD][KO] = 1;
  trTable[6][KO] = 5;
  trTable[6][LOOP] = LOOP_PRENDRE_FOOD;
  trTable[LOOP_CONNECT][OK] = 8;
  trTable[LOOP_CONNECT][KO] = 1;
  trTable[7][KO] = 1;
  trTable[7][LOOP] = LOOP_CONNECT;
  trTable[8][OK] = 1;
  trTable[8][KO] = 1;

  fctTable[1] = &Player::Pond;
  fctTable[2] = &Player::Avance;
  fctTable[3] = &Player::_AssezNourriture;
  fctTable[4] = &Player::_NourritureSurCase;
  fctTable[5] = &Player::Avance;
  fctTable[6] = &Player::RamassezNourriture;
  fctTable[7] = &Player::_PlaceSurServeur;
  fctTable[8] = &Player::Eclosion;
  fctTable[LOOP_CONNECT] = &Player::LoopPlaceSurServeur;
  fctTable[LOOP_SEARCH_FOOD] = &Player::LoopNourritureSurCase;
  fctTable[LOOP_PRENDRE_FOOD] = &Player::LoopRamassezNourriture;
  fctTable[LOOP_ASSEZ_FOOD] = &Player::LoopAssezNourriture;
  //fctTable[DROITE] = &Player::Droite;
}
