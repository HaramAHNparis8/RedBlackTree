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

void RechercheNoeudSential(arbreRN_t* t,noeud_t** actuelle, noeud_t** avant,int val){

	//on descend jusqu'a trouver les noeud sential
	while(*actuelle != t -> nil){
		
		*avant = *actuelle;
		if(val < (*actuelle) -> cle){
			
			*actuelle = (*actuelle) -> g;

		}
		else{

			*actuelle = (*actuelle) -> d; 
		}
	}
		

}

void RechercheNoeudSentialRecusitif(arbreRN_t* t, noeud_t** actuelle, noeud_t** avant, int val) {
    
    if (*actuelle == t->nil) {
        return;
    }

    *avant = *actuelle; 

    
    if (val < (*actuelle)->cle) {
        RechercheNoeudSentialRecusitif(t, &((*actuelle)->g), avant, val);
    } 
    else {
        RechercheNoeudSentialRecusitif(t, &((*actuelle)->d), avant, val);
    }
}

noeud_t* InsertionNoeudAbreRG(arbreRN_t* t, int val){
	noeud_t* noeud = InitialisationArbreGN(t,val);
	//si l'arbre est vide on ajoute et apres retourner les noeuds
	
	if(t -> racine == t -> nil){
		
		t -> racine = noeud;
		t -> racine -> couleur = noir;
		
		return noeud;

	}
	
// la premier propostion

	noeud_t* actuelle = t -> racine; // quand on ajoute les noeuds c'est noeud compare avec le noeud nouveau
	noeud_t* avant = t -> nil; // ce noeud devient parent noeud
	
	RechercheNoeudSential(t, &actuelle, &avant, val);
//s'il y aurait bcp de data, ca cause l'erreur donc j'use la premiere propostion

// la deuxieme propostion

	//RechercheNoeudSentialRecursif(t, &actuelle, &avant, val);

	noeud -> parent = avant;
	if(val < avant -> cle){

		avant -> g = noeud;

	}
	else{
		avant -> d = noeud;
	}

	return noeud;

}

void gauche_rotation(arbreRN_t *t, noeud_t* enbas){
    // le noeud nommé enhaut va en haut, et noeud va en bas
    noeud_t* enhaut = enbas->d;
    enbas->d = enhaut->g;

    if (enhaut->g != t->nil) {
        enhaut->g->parent = enbas;
    }

    enhaut->parent = enbas->parent;

    // si noeud enbas est la racine, alors enhaut devient la racine
    if (enbas->parent == t->nil) {
        t->racine = enhaut;
    } else {
        if (enbas == enbas->parent->g) {
            enbas->parent->g = enhaut;
        } else {
            enbas->parent->d = enhaut;
        }
    }

    enhaut->g = enbas;
    enbas->parent = enhaut;
}


void RNInsertReparer(arbreRN_t* t, noeud_t* noeud){
	while(1){

		if(noeud != t -> racine && noeud -> parent -> couleur == rouge){
				break;
			}

		if(noeud -> parent == noeud -> parent -> parent -> g){
				
				noeud_t* tonton  = noeud -> parent -> parent -> d;
			if(tonton != NULL && tonton -> couleur == rouge){
			noeud -> parent -> couleur = noir;
			tonton -> parent -> parent -> couleur = rouge;

			noeud = noeud -> parent -> parent;

				
				}
			else{


				}

			}


		}
}

	
