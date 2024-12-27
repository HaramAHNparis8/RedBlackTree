#ifndef MAIN_H
#define MAIN_H
#include "util.h"

typedef struct noeud noeud_t;
typedef struct arbreRN arbreRN_t;
void AfficherResultatNilEstBienAllouerOuPas();
void TestLaFonction();
void AfficherAbrePourTesterLaFonctionAllouerEstBienOupas(noeud_t* noeud,arbreRN_t* nil, int niveau);
#endif
