#ifndef ARBRE_H
#define ARBRE_H
#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "main.h"

typedef int element_val;

typedef enum couleur{ 
	rouge, 
	noir 
} couleur_t;



typedef struct noeud {
  couleur_t couleur;
  element_val cle; // avant j'utilise element_int dans le fichier util.h mais il ne recherche pas - le probleme que je regle apres

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
void droit_rotation(arbreRN_t *t, noeud_t* enbas);
void RNInsertReparer(arbreRN_t* t, noeud_t* noeud);
void echange(arbreRN_t* t, noeud_t* a, noeud_t* b);
arbreRN_t* ReparerArbreRN(int taille,element_val* tab);
element_val* TableauPourRepare(int taille);
noeud_t* RechercherNoeud(arbreRN_t* t,element_val val);
void ReparerFrereRougeCase1(arbreRN_t* t, noeud_t* a, noeud_t* b);
void ReparerFrereRougeCase2ET3(arbreRN_t* t, noeud_t* frere, noeud_t** v);
void ReparerFrereRougeCase4(arbreRN_t* t, noeud_t* frere, noeud_t* v);
void ReparerFrereRougeCase6(noeud_t* frere, noeud_t** v);
void ReparerFrereRougeCase7(arbreRN_t* t, noeud_t* frere);
void ReparerFrereRougeCase8(arbreRN_t* t, noeud_t* frere, noeud_t** v);
void ArbreSupprimer(arbreRN_t* t, noeud_t* v);
void SupprimerReparer(arbreRN_t *t, noeud_t * v);
#endif
