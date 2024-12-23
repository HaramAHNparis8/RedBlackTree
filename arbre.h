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

typedef struct arbreRB{
  
  noeud_t * racine;
  noeud_t * nil;

}arbreRB_t;

#endif
