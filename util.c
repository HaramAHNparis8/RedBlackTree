#include <stdio.h>
#include <unistd.h>  // sleep(), usleep()
#include <time.h>    // time()

#define clignotement 200000 
#define letempsdourant 2  

typedef int element_int;


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
	
     
        printf("\r                                                \r");
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
    printf("\n->  ");
    fflush(stdout);
    scanf("%d", &n);
  
    return n;
}


