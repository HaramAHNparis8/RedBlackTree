#include <stdio.h>
#include "util.h" 
#include "arbre.h"
#include "main.h"

void AfficherResultatNilEstBienAllouerOuPas(){
	arbreRN_t* arbre = AllouerAbreRN();
	printf("\n1 est bien allouer mais si c'est 0 non\n");
	printf("\nres :%d\n ",EstNoir(&(arbre -> nil -> couleur)));

	
}
void AfficherAbrePourTesterLaFonctionAllouerEstBienOupas(noeud_t* noeud, arbreRN_t* nil, int niveau){

	int i;
	if(noeud == nil){
		
		return;
	}
	AfficherAbrePourTesterLaFonctionAllouerEstBienOupas(noeud -> d, nil, niveau + 1);
	for(i = 0; i < niveau; i++){
		
		printf("   ");

	}
	printf("%d [%s] \n", noeud->cle, noeud->couleur == rouge ? "Rouge" : "Noir");
	AfficherAbrePourTesterLaFonctionAllouerEstBienOupas(noeud -> g, nil, niveau + 1);
	


}

void LeMessageInsertionFonction(){
	printf("Insertion des noeuds dans l'abre");
}

void LeMessageRotationGauche(){
	printf("Effectuer une rotation gauche sur la racine");
}
void LeMessageRotationGaucheRes(){
	printf("Effectuer une rotation gauche sur la racine le res");
}

void LeMessageRNArbreRes(){
	printf("l'arbre RN est construit");
}




void TestLaFonction(){
	//AfficherResultatNilEstBienAllouerOuPas();
	//AfficherLeMessage(LeMessageInsertionFonction);
    	printf("\n");
    	arbreRN_t* arbre = AllouerAbreRN();
    	InsertionNoeudAbreRG(arbre, 40);
    	InsertionNoeudAbreRG(arbre, 30); 
    	InsertionNoeudAbreRG(arbre, 20);
    	InsertionNoeudAbreRG(arbre, 10);
	InsertionNoeudAbreRG(arbre, 50);
	InsertionNoeudAbreRG(arbre, 5);
	AfficherLeMessage(LeMessageRNArbreRes);
	printf("\n");
	AfficherAbrePourTesterLaFonctionAllouerEstBienOupas(arbre -> racine, arbre -> nil, 0);
	//printf("\n");
	//AfficherLeMessage(LeMessageRotationGauche);
	//gauche_rotation(arbre, arbre->racine);
	printf("\n");  
	//AfficherLeMessage(LeMessageRotationGaucheRes);
	printf("\n");
	//AfficherAbrePourTesterLaFonctionAllouerEstBienOupas(arbre -> racine, arbre -> nil, 0);
	//droit_rotation(arbre, arbre -> racine);
	//printf("\n rotation gauche\n");
	//AfficherAbrePourTesterLaFonctionAllouerEstBienOupas(arbre -> racine, arbre -> nil, 0);

}

int main(void) {
    //TestLaFonction();
    char choix = '\0';

    arbreRN_t* arbre = AllouerAbreRN();
    //je vais creer le logique pour si l'utilisateur entre Y, on ajoute le noeud sinon le programme est fini. demain. je veux dormir un peu...
    while(1){

		if(choix == 'N'){

			break;
		}

		else{

		}
	}
     
    return 0;
}
