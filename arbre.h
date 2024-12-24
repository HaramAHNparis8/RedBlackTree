#ifndef ARBRE_H
#define ARBRE_H
#include <stdio.h>
#include <stdlib.h>
#include "util.h"

typedef enum { rouge, noir } couleur_t;

typedef struct noeud {
  couleur_t couleur;
  element_int cle;
  struct noeud * parent; 
  struct noeud * g; 
  struct noeud * d;
} noeud_t;

typedef struct arbreRN{
  
  noeud_t * racine;
  noeud_t * nil;

}arbreRN_t;
noeud_t* AllouerMallocNoeud_t();
arbreRB_t* AllouerMallocArbreRB_t();
noeud_t* AllouerMalloc();
noeud_t* AllouerNoeudNil();
arbreRB_t* AllouerAbreRB();
int EstRouge(couleur_t* couleur);
#endif
