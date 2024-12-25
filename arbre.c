#include "util.h"
#include "arbre.h"
#include "main.h"

noeud_t* AllouerMallocNoeud_t(){

	noeud_t* noeud = (noeud_t *)malloc(sizeof(noeud_t));
	
	return noeud;
}

arbreRN_t* AllouerMallocArbreRN_t(){

	arbreRN_t* noeud = (arbreRN_t *)malloc(sizeof(arbreRN_t));
	
	return noeud;
}

noeud_t* AllouerNoeudNil(){

	noeud_t* nil = AllouerMallocNoeud_t();
	if(nil == NULL){
		
		free(nil);
		return NULL;
	}

	nil -> couleur = noir;
	nil -> cle = 0;
	nil -> parent = NULL;
	nil -> g = NULL;
	nil -> d = NULL;
	
	return nil;
	

} 
arbreRN_t* AllouerAbreRN(){

	arbreRN_t* noeud = AllouerMallocArbreRN_t();
	noeud -> nil = AllouerNoeudNil();
	noeud -> racine = noeud -> nil;
	
	return noeud;

}

noeud_t* InitialisationArbreGN(arbreRN_t *t, int cle){
	
	noeud_t* noeud = AllouerMallocNoeud_t();
	if(noeud == NULL){
		
		return NULL;
	}
	
	noeud -> couleur  = rouge;
	noeud -> cle = cle;
	noeud -> parent = t -> nil;
	noeud -> g = t -> nil;
	noeud -> d = t -> nil;

	return noeud;
	
		
}

noeud_t* InsertionNoeudAbreRG(arbreRN_t* t, int cle){
	noeud_t* noeud = InitialisationArbreGN(t,cle);
	if(t -> racine == t -> nill){
		
		t -> racine = noeud;
		t -> racine -> couleur = noir;
		
		return noeud;

	}
}
