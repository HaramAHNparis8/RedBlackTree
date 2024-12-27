#include "util.h"
#include "arbre.h"

void AfficherLeMessage(void(*f)(void)) {
    
    time_t debut = time(NULL);
    time_t courant;
    
    while (1) {
        courant = time(NULL);

        
        if (courant - debut >= letempsdourant) {
            break;
        }
        (*f)();
	
        fflush(stdout);  

        usleep(clignotement); 
	
     
        printf("\r                                                \r ");
        fflush(stdout);

        usleep(clignotement);  
    }

    (*f)();
    fflush(stdout);
}


void afficherMessageEntrezLeval() {
    printf("Entrez la valeur que vous voulez ajouter");
}

int entrelavaleur() {
    
    element_int n;
    AfficherLeMessage(afficherMessageEntrezLeval);   
    printf("\n-> ");
    fflush(stdout);
    scanf("%d", &n);
  
    return n;
}
void EstimationGeneral(){

}
int EstRouge(couleur_t* couleur){

	return (*couleur == rouge) ? 1 : 0;
}
int EstNoir(couleur_t* couleur){

	return (*couleur == noir) ? 1 : 0;
}
