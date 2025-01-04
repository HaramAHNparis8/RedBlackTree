#include <stdio.h>
#include "util.h" 
#include "arbre.h"
#include "main.h"
#include <wchar.h>
#include <locale.h>

void AfficherResultatNilEstBienAllouerOuPas(){
	arbreRN_t* arbre = AllouerAbreRN();
	printf("\n1 est bien allouer mais si c'est 0 non\n");
	printf("\nres :%d\n ",EstNoir(&(arbre -> nil -> couleur)));

	
}
void AfficherAbrePourTesterLaFonctionAllouerEstBienOupas(noeud_t* noeud, arbreRN_t* nil, int niveau){

	int i;
	if((arbreRN_t *)noeud == nil){
		
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
	setlocale(LC_ALL, ""); // UTF-8 set local
	wchar_t smile_emoji[] = L"\U0001F60A";
	wprintf(L"%ls Noeud insere avec succes  %ls", smile_emoji, smile_emoji); // liste caractere %ls affiche

}

void LeMessageRotationGauche(){
	printf("Effectuer une rotation gauche sur la racine");
}
void LeMessageRotationGaucheRes(){
	printf("Effectuer une rotation gauche sur la racine le res");
}

void LeMessageRNArbreRes() {
    setlocale(LC_ALL, ""); // UTF-8 set local

    wchar_t smile_emoji[] = L"\U0001F60A";
    wprintf(L"%ls l'abrRN  %ls", smile_emoji, smile_emoji); // liste caractere %ls affiche 
}

void LeMessageDesole(){
     setlocale(LC_ALL, ""); 

     wchar_t smile_emoji[] = L"\U0001F60A";
     wprintf(L"%ls on ne peut pas supprimer desole! Parce que l'on ne peut pas trouver les noeuds! Est-ce que vous pourriez verifier les noeuds que vous voulez supprimer svp??  %ls", smile_emoji, smile_emoji); 

}

void LeMessageDesoleDeux(){
     setlocale(LC_ALL, ""); 

     wchar_t smile_emoji[] = L"\U0001F60A";
     wprintf(L"%ls AH........ le noeud n'est pas encore supprime desole %ls", smile_emoji, smile_emoji); 

}


void LeMessageContent(){
     setlocale(LC_ALL, ""); 

     wchar_t smile_emoji[] = L"\U0001F60A";
     wprintf(L"%ls Tada!!!! on a supprime! %ls", smile_emoji, smile_emoji); 

}

void TestLaFonction(){
	
	//AfficherResultatNilEstBienAllouerOuPas();
	//AfficherLeMessage(LeMessageInsertionFonction);
    	printf("\n");
    	arbreRN_t* arbre = AllouerAbreRN();
    	InsertionNoeudAbreRG(arbre, 40);
    	InsertionNoeudAbreRG(arbre, 30); 
    	InsertionNoeudAbreRG(arbre, 20);
    	InsertionNoeudAbreRG(arbre, 15);
	InsertionNoeudAbreRG(arbre, 50);
	InsertionNoeudAbreRG(arbre, 5);
	//AfficherLeMessage(LeMessageRNArbreRes);
	//printf("\n");	
	//AfficherAbrePourTesterLaFonctionAllouerEstBienOupas(arbre -> racine, arbre -> nil, 0);
	//noeud_t* noeud_a_supprimer = RechercherNoeud(arbre,40);
	//if (noeud_a_supprimer != arbre->nil) {
        //	ArbreSupprimer(arbre, noeud_a_supprimer);
	//}
	//printf("\n");
	//AfficherAbrePourTesterLaFonctionAllouerEstBienOupas(arbre -> racine, arbre -> nil, 0);
	
	//printf("\n");
	//AfficherLeMessage(LeMessageRotationGauche);
	//gauche_rotation(arbre, arbre->racine);
	//printf("\n");  
	//AfficherLeMessage(LeMessageRotationGaucheRes);
	//printf("\n");
	//AfficherAbrePourTesterLaFonctionAllouerEstBienOupas(arbre -> racine, arbre -> nil, 0);
	//droit_rotation(arbre, arbre -> racine);
	//printf("\n rotation gauche\n");
	//AfficherAbrePourTesterLaFonctionAllouerEstBienOupas(arbre -> racine, arbre -> nil, 0);
	 //element_val tab[] = {10, 20, 30, 50};
	 //int taille = sizeof(tab) / sizeof(tab[0]);
	 //arbreRN_t* ArbreReparer = ReparerArbreRN(taille, tab);
	//printf("\n les lst apres avoir reparer\n"); 
	//AfficherAbrePourTesterLaFonctionAllouerEstBienOupas(ArbreReparer -> racine, ArbreReparer -> nil, 0);
	
	/*element_val* tab = TableauPourRepare(taille);
	SauvegarderVal(arbre->racine, arbre -> nil,tab, indice, taille,40);
	for(i = 0; i < taille; ++i){
		
		printf("%d ", tab[i]);

	}
	*/
}

int main(void) {
    //TestLaFonction();
    char choix = '\0';
    int n = 0;
    arbreRN_t* arbre = AllouerAbreRN();
    //je vais creer la logique pour si l'utilisateur entre Y, on ajoute le noeud sinon le programme est fini. demain. je veux dormir un peu...
    
    while(1){
	        printf("\nEntrez votre choix (Y: Ajouter, D: Supprimer, N: Quitter): ");
    		scanf(" %c", &choix);

		if(choix == 'N'){

			break;
		}

		else if(choix == 'Y'){
			n = entrelavaleur();
			InsertionNoeudAbreRG(arbre, n);
			AfficherAbrePourTesterLaFonctionAllouerEstBienOupas(arbre -> racine,(arbreRN_t*)arbre -> nil, 0);
			printf("\n");
			n = 0;
			AfficherLeMessage(LeMessageInsertionFonction);
			printf("\n");

				
			
		}
		
		else if(choix == 'D'){
			n = entrelavaleur();
			noeud_t* noeud_a_supprimer = RechercherNoeud(arbre,n);
			if (noeud_a_supprimer == NULL || noeud_a_supprimer == arbre->nil) {
					AfficherLeMessage(LeMessageDesole);
					printf("\n");

			}
			else if(noeud_a_supprimer->couleur == noir){
					AfficherLeMessage(LeMessageDesoleDeux);
					printf("\n");					
			}
				
			else{
				ArbreSupprimer(arbre, noeud_a_supprimer);
				AfficherAbrePourTesterLaFonctionAllouerEstBienOupas(arbre -> racine,(arbreRN_t*)arbre -> nil, 0);
				printf("\n");
				AfficherLeMessage(LeMessageContent);
				printf("\n");
			}
		
                        
			n = 0;
		}
		else if(choix == 'P'){

                                AfficherLeMessageOeuf();

                        }
		
	}

    return 0;
} 
