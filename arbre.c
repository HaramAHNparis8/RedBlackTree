#include "util.h"
#include "arbre.h"

noeud_t* AllouerMallocNoeud_t(){

	noeud_t* noeud = (noeud_t *)malloc(sizeof(noeud_t));
	
	return noeud;
}

arbreRB_t* AllouerMallocArbreRB_t(){

	arbreRB_t* noeud = (arbreRB_t *)malloc(sizeof(arbreRB_t));
	
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
arbreRB_t* AllouerAbreRB(){

	arbreRB_t* arbre = AllouerMallocArbreRB_t();
	arbre -> nil = AllouerMallocNoeud_t();
	arbre -> racine = arbre -> nil;
	
	return arbre;

}


