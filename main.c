#include <stdio.h>
#include "util.h" 
#include "arbre.h"
#include "main.h"

void AfficherResultatNilEstBienAllouerOuPas(){
	arbreRN_t* arbre = AllouerAbreRN();
	printf("\n1 est bien allouer mais si c'est 0 non\n");
	printf("\nres :%d\n ",EstNoir(&(arbre -> nil -> couleur)));

	
}
void TestLaFonction(){
	AfficherResultatNilEstBienAllouerOuPas();

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
int main(void) {
    //TestLaFonction();
    AfficherLeMessage(LeMessageInsertionFonction);
    printf("\n");
    arbreRN_t* arbre = AllouerAbreRN();
    InsertionNoeudAbreRG(arbre, 10);
    InsertionNoeudAbreRG(arbre, 20); 
    InsertionNoeudAbreRG(arbre, 30);
    AfficherAbrePourTesterLaFonctionAllouerEstBienOupas(arbre -> racine, arbre -> nil, 0);   
    return 0;
}
