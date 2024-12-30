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

void droit_rotation(arbreRN_t *t, noeud_t* enbas){
    // le noeud nomme enhaut va en haut, et noeud va en bas
    noeud_t* enhaut = enbas->g;
    enbas->g = enhaut->d;

    if (enhaut->d != t->nil) {
        enhaut->d->parent = enbas;
    }

    enhaut->parent = enbas->parent;

    // si noeud enbas est la racine, alors enhaut devient la racine
    if (enbas->parent == t->nil) {
        t->racine = enhaut;
    } else {
        if (enbas == enbas->parent->d) {
            enbas->parent->d = enhaut;
        } 
	else {
            enbas->parent->g = enhaut;
        }
    }

    enhaut->d = enbas;
    enbas->parent = enhaut;
}

void RNInsertReparer(arbreRN_t* t, noeud_t* noeud) {
    // Tant que le noeud n'est pas la racine et que son parent est rouge
    while (noeud != t->racine && noeud->parent->couleur == rouge) {
        // Le parent du noeud est le fils gauche du grand-parent
        if (noeud->parent == noeud->parent->parent->g) {
            noeud_t* tonton = noeud->parent->parent->d;

            // Case 1: Parent et oncle sont rouges
            if (tonton != NULL && tonton->couleur == rouge) {
                noeud->parent->couleur = noir;
                tonton->couleur = noir;
                noeud->parent->parent->couleur = rouge;
                noeud = noeud->parent->parent; // Remonter au grand-parent
            } 
	    else {
                // Case 2: Oncle est noir et le noeud est un fils droit
                if (noeud == noeud->parent->d) {
                    noeud = noeud->parent;
                    gauche_rotation(t, noeud);
                }
                // Case 3: Oncle est noir et le noeud est un fils gauche
                noeud->parent->couleur = noir;
                noeud->parent->parent->couleur = rouge;
                droit_rotation(t, noeud->parent->parent);
            }
        } 
	else { 
	    // Le parent du noeud est le fils droit du grand-parent
            noeud_t* tonton = noeud->parent->parent->g;

            // Case 4: Parent et oncle sont rouges
            if (tonton != NULL && tonton->couleur == rouge) {
                noeud->parent->couleur = noir;
                tonton->couleur = noir;
                noeud->parent->parent->couleur = rouge;
                noeud = noeud->parent->parent; // Remonter au grand-parent
            } 
	    else {
                // Case 5: Oncle est noir et le noeud est un fils gauche
                if (noeud == noeud->parent->g) {
                    noeud = noeud->parent;
                    droit_rotation(t, noeud);
                }
                // Case 6: Oncle est noir et le noeud est un fils droit
                noeud->parent->couleur = noir;
                noeud->parent->parent->couleur = rouge;
                gauche_rotation(t, noeud->parent->parent);
            }
        }
    }

    //pour  assurer que la racine est toujours noire
    t->racine->couleur = noir;
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

	//RechercheNoeudSentialRecusitif(t, &actuelle, &avant, val);

	noeud -> parent = avant;
	if(val < avant -> cle){

		avant -> g = noeud;

	}
	else{
		avant -> d = noeud;
	}
	RNInsertReparer(t, noeud);	
	return noeud;

}

void echange(arbreRN_t* t, noeud_t* a, noeud_t* b){

	if(a -> parent == t -> nil){

		t -> racine = b;

	}
	else if(a == a -> parent -> g){
		
		a -> parent -> g = b;

	}
	else{
		a -> parent -> g = b;
	}
	if(b != t -> nil){

		b -> parent = a -> parent;

	}


}

noeud_t* min(arbreRN_t* t, noeud_t* min){

	  while(min -> g != t -> nil){

		min = min -> g;

	}

	return min;
}


void ReparerFrereRougeCase1(arbreRN_t* t, noeud_t* a, noeud_t* b) {
    if (b -> couleur == rouge) { 
        b -> couleur = noir; 
        a -> parent -> couleur = rouge; 
        gauche_rotation(t, a -> parent);
        b = a ->parent -> d;
    }
}

void ReparerFrereRougeCase2ET3(arbreRN_t* t, noeud_t* frere, noeud_t** v) {
   
    if (frere -> g -> couleur == noir && frere -> d -> couleur == noir) {
        frere->couleur = rouge; 
        *v = (*v) -> parent; 
    } 
    else {
       
        if (frere ->d -> couleur == noir) {
            frere -> g ->couleur = noir; 
            frere -> couleur = rouge;
            droit_rotation(t, frere); 
            frere = (*v) -> parent -> d; 
        }
    }
}

void ReparerFrereRougeCase4(arbreRN_t* t, noeud_t* frere, noeud_t* v){
	
            frere -> couleur = v -> parent -> couleur;
            v -> parent -> couleur = noir; 
            frere -> d -> couleur = noir; 
            gauche_rotation(t, v -> parent);
            v = t -> racine; 

}
void ReparerFrereRougeCase6(noeud_t* frere, noeud_t** v) {
    if (frere -> g -> couleur == noir && frere -> d -> couleur == noir) {
        frere->couleur = rouge; 
        *v = (*v) -> parent; 
    }
}

void ReparerFrereRougeCase7(arbreRN_t* t, noeud_t* frere) {
    if (frere -> d -> couleur == noir) {
        frere -> g -> couleur = noir; 
        frere -> couleur = rouge; 
        droit_rotation(t, frere); 
    }
}

void ReparerFrereRougeCase8(arbreRN_t* t, noeud_t* frere, noeud_t** v) {
    frere -> couleur = (*v) -> parent -> couleur; 
    (*v) -> parent -> couleur = noir; 
    frere -> g -> couleur = noir; 
    gauche_rotation(t, (*v) -> parent); 
    *v = t -> racine; 
}


void SupprimerReparer(arbreRN_t *t, noeud_t *v){
	
	//le noeud v ne doit pas etre toujours la racinemais la couleur de noeud doit etre noir dans le boucle while
	while(1){

		if(v != t -> racine && v -> couleur == noir){
			break;
		}
		noeud_t* frere = (v == v -> parent -> g) ? v -> parent -> d : v -> parent -> g;

		ReparerFrereRougeCase1(t, v, frere);//case1
		ReparerFrereRougeCase2ET3(t, frere, &v);//case 2 et 3
		ReparerFrereRougeCase4(t,frere,v);//case 4
		ReparerFrereRougeCase6(frere, &v);
		ReparerFrereRougeCase7(t, frere);
		ReparerFrereRougeCase8(t, frere, &v);

	}
	v -> couleur = noir;
}

noeud_t* RechercherNoeud(arbreRN_t* t,element_val val){
	noeud_t* courant = t -> racine;
	while(courant != t -> nil && courant -> cle != val){
		if(val < courant -> cle){

			courant = courant -> g;

		}
		else{

			courant = courant -> d;
		}	


	}

	return courant;
}

void ArbreSupprimer(arbreRN_t* t, noeud_t* v) {
    noeud_t* supprimer = v; // Le noeud à supprimer
    couleur_t CouleurOriginal = supprimer -> couleur; // La couleur d'origine du noeud à supprimer
    noeud_t* base;

    if (v -> g == t -> nil) {
        // Remplacer v par son fils droit
        base = v -> d;
        echange(t, v, v -> d);
    } 
    else if (v -> d == t -> nil) {
        // Remplacer v par son fils gauche
        base = v -> g;
        echange(t, v, v -> g);
    } 
    else {
        // Trouver le successeur
        supprimer = min(t, v -> d);
        CouleurOriginal = supprimer -> couleur;
        base = supprimer -> d;

        if (supprimer != v -> d) {
            // Remplacer le successeur par son sous-arbre droit
            echange(t, supprimer, supprimer->d);
            supprimer -> d = v -> d;
            supprimer -> d -> parent = supprimer;
        } 
	else {
            base -> parent = supprimer;
        }

        echange(t, v, supprimer);
        supprimer -> g = v -> g;
        supprimer -> g -> parent = supprimer;
        supprimer -> couleur = v -> couleur;
    }

    // Liberer la memoire du noeud supprime
    free(v);

    // Si un noeud noir est supprime, reequilibrer l'arbre
    if (CouleurOriginal == noir) {
        SupprimerReparer(t, base);
    }
}


