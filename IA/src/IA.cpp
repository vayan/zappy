//
// IA.cpp for IA in /home/haulot_a//zappy-2015-2014s-haulot_a/IA
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Thu Jun 14 12:51:45 2012 alexandre haulotte
// Last update Fri Jun 15 20:47:04 2012 alexandre haulotte
//

#include	"Player.hh"

void	Player::initTab()
{
  // ------------------ Lapin Mania ----------------//
  trTable[1][OK] = 2;
  trTable[2][OK] = 3;
  trTable[3][OK] = 7;
  trTable[3][KO] = 4;
  trTable[4][OK] = 6;
  trTable[4][KO] = 5;
  trTable[5][OK] = 4;
  trTable[6][OK] = 7;
  trTable[6][KO] = 5;
  trTable[7][OK] = 8;
  trTable[7][KO] = 1;
  trTable[8][OK] = 1;
  //trTable[9][OK] = 2;

  fctTable[1] = &Player::Pond;
  fctTable[2] = &Player::Avance;
  fctTable[3] = &Player::AssezNourriture;
  fctTable[4] = &Player::NourritureSurCase;
  fctTable[5] = &Player::Avance;
  fctTable[6] = &Player::RamassezNourriture;
  fctTable[7] = &Player::PlaceSurServeur;
  fctTable[8] = &Player::Eclosion;
  //  fctTable[9] = &Player::CallRenfort;

  // ------------------ Avance Ramasse... ------------------//
  // trTable[1][OK] = 2;
  // trTable[1][KO] = 6;
  // trTable[6][OK] = 3;
  // trTable[2][OK] = 1;
  // trTable[3][OK] = 4;
  // trTable[3][KO] = 5;
  // trTable[4][OK] = 2;
  // trTable[4][KO] = 5;
  // trTable[5][OK] = 3;


  // fctTable[1] = &Player::AssezNourriture;
  // fctTable[2] = &Player::Avance;
  // fctTable[3] = &Player::NourritureSurCase;
  // fctTable[4] = &Player::RamassezNourriture;
  // fctTable[5] = &Player::Avance;
  // fctTable[6] = &Player::CallRenfort;

  // ------------------ Monte d'un Level ----------------//
  // trTable[1][ALREADY] = 5;
  // trTable[1][OK] = 2;
  // trTable[1][KO] = 3;
  // trTable[2][OK] = 4;
  // trTable[2][KO] = 3;
  // trTable[3][OK] = 1;
  // trTable[4][OK] = 5;
  // trTable[4][KO] = 6;
  // trTable[5][OK] = 6;
  // trTable[5][KO] = 6;
  // trTable[6][OK] = 3;
  // trTable[6][KO] = 7;
  // trTable[7][OK] = 9;
  // trTable[7][KO] = 8;
  // trTable[8][OK] = 7;
  // trTable[9][OK] = 4;
  // trTable[9][KO] = 8;

  // fctTable[1] = &Player::RessourceForLvlSurCase;
  // fctTable[2] = &Player::RamassezRessourceForLvl;
  // fctTable[3] = &Player::Avance;
  // fctTable[4] = &Player::AssezRessourceForLevel;
  // fctTable[5] = &Player::Incantation;
  // fctTable[6] = &Player::AssezNourriture;
  // fctTable[7] = &Player::NourritureSurCase;
  // fctTable[8] = &Player::Avance;
  // fctTable[9] = &Player::RamassezNourriture;
}
