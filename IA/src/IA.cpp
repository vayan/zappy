//
// IA.cpp for IA in /home/haulot_a//zappy-2015-2014s-haulot_a/IA
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Thu Jun 14 12:51:45 2012 alexandre haulotte
// Last update Wed Jun 20 12:54:07 2012 alexandre haulotte
//

#include	"Player.hh"

void	Player::initTab()
{
  // ------------------ Lapin Mania ----------------//
  // trTable[1][OK] = 2;
  // trTable[2][OK] = 3;
  // trTable[3][OK] = 7;
  // trTable[3][KO] = 4;
  // trTable[4][OK] = 6;
  // trTable[4][KO] = 5;
  // trTable[5][OK] = 4;
  // trTable[6][OK] = 7;
  // trTable[6][KO] = 5;
  // trTable[7][OK] = 8;
  // trTable[7][KO] = 9;
  // trTable[8][OK] = 9;
  // trTable[9][OK] = 2;

  // fctTable[1] = &Player::Pond;
  // fctTable[2] = &Player::Avance;
  // fctTable[3] = &Player::AssezNourriture;
  // fctTable[4] = &Player::NourritureSurCase;
  // fctTable[5] = &Player::Avance;
  // fctTable[6] = &Player::RamassezNourriture;
  // fctTable[7] = &Player::PlaceSurServeur;
  // fctTable[8] = &Player::Eclosion;
  // fctTable[9] = &Player::CallRenfort;

  // ------------------ Avance Ramasse... ------------------//
  trTable[1][OK] = 2;
  trTable[1][KO] = 6;
  trTable[6][OK] = 3;
  trTable[2][OK] = 1;
  trTable[3][OK] = 4;
  trTable[3][KO] = 5;
  trTable[4][OK] = 2;
  trTable[4][KO] = 5;
  trTable[5][OK] = 3;


  fctTable[1] = &Player::AssezNourriture;
  fctTable[2] = &Player::Avance;
  fctTable[3] = &Player::NourritureSurCase;
  fctTable[4] = &Player::RamassezNourriture;
  fctTable[5] = &Player::Avance;
  fctTable[6] = &Player::CallRenfort;

  // ------------------ Monte d'un Level ----------------//
  // trTable[1][OK] = 2;
  // trTable[2][OK] = 6;
  // trTable[2][KO] = 3;
  // trTable[2][ALREADY] = 8;
  // trTable[3][OK] = 17;
  // trTable[4][OK] = 5;
  // trTable[4][KO] = 2;
  // trTable[5][OK] = 2;
  // trTable[6][OK] = 7;
  // trTable[6][KO] = 3;
  // trTable[7][OK] = 8;
  // trTable[7][KO] = 3;
  // trTable[8][OK] = 9;
  // trTable[9][OK] = 10;
  // trTable[9][KO] = 12;
  // trTable[10][OK] = 11;
  // trTable[10][KO] = 2;
  // trTable[11][OK] = 2;
  // trTable[11][KO] = 6;
  // trTable[12][OK] = 13;
  // trTable[12][KO] = 14;
  // trTable[13][OK] = 8;
  // trTable[13][KO] = 8;
  // trTable[14][OK] = 15;
  // trTable[15][OK] = 16;
  // trTable[15][KO] = 9;
  // trTable[16][OK] = 9;
  // trTable[17][OK] = 2;

  // fctTable[1] = &Player::Pond;
  // fctTable[2] = &Player::RessourceForLvlSurCase;
  // fctTable[3] = &Player::Avance;
  // fctTable[4] = &Player::PlaceSurServeur;
  // fctTable[5] = &Player::Eclosion;
  // fctTable[6] = &Player::RamassezRessourceForLvl;;
  // fctTable[7] = &Player::AssezRessourceForLevel;
  // fctTable[8] = &Player::VideCase;
  // fctTable[9] = &Player::AssezPlayerForLvl;
  // fctTable[10] = &Player::PoserRessourceForLvl;
  // fctTable[11] = &Player::Incantation;
  // fctTable[12] = &Player::RecvRenfort;
  // fctTable[13] = &Player::GoToMsgRenfort;
  // fctTable[14] = &Player::CallRenfort;
  // fctTable[15] = &Player::PlaceSurServeur;
  // fctTable[16] = &Player::Eclosion;
  // fctTable[17] = &Player::VideCase;
  rDir = 0;
}
