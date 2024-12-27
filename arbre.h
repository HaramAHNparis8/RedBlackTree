#ifndef ARBRE_H
#define ARBRE_H
#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "main.h"

typedef enum couleur{ 
	rouge, 
	noir 
} couleur_t;



typedef struct noeud {
  couleur_t couleur;
  int cle; // avant j'utilise element_int dans le fichier util.h mais il ne recherche pas - le probleme que je regle apres

  struct noeud * parent; 
  struct noeud * g; 
  struct noeud * d;

} noeud_t;

typedef struct arbreRN{
  
  noeud_t * racine;
  noeud_t * nil;

}arbreRN_t;

noeud_t* AllouerMallocNoeud_t();
arbreRN_t* AllouerMallocArbreRB_t();
noeud_t* AllouerMalloc();
noeud_t* AllouerNoeudNil();
arbreRN_t* AllouerAbreRN();
noeud_t* InitialisationArbreGN(arbreRN_t *t, int val);
void gauche_rotation(arbreRN_t *t, noeud_t* enbas);
void RechercheNoeudSential(arbreRN_t* t,noeud_t** actuelle, noeud_t** avant,int val);
void RechercheNoeudSentialRecusitif(arbreRN_t* t, noeud_t** actuelle, noeud_t** avant, int val);
noeud_t* InsertionNoeudAbreRG(arbreRN_t* t, int val);
#endif
