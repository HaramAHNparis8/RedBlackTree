#include <stdio.h>
#include <unistd.h> // sleep(), usleep()
#include <time.h> // time

#define clignotement 500000
#define letempsdourant 5

typedef int element_entree;

int entrelavaleur() {
    element_entree n;
    time_t debut = time(NULL);
    time_t courant;

    while (1) {
        courant = time(NULL);

       
        if (courant - debut >= letempsdourant) {
            break;
        }

        
        printf("\033[5mEntrez la valeur que vous voulez ajouter.\033[0m\r");
	printf("\n");
	printf("\033[5m->\033[0m\r");

        fflush(stdout); 

        usleep(clignotement); 

     
        printf("\r                        \r");
        fflush(stdout);

        usleep(clignotement); 
    }

    printf("Entrez la valeur que vous voulez ajouter.\n");
    printf("-> ");
    fflush(stdout); 

    if (scanf("%d", &n) != 1) { 
        printf("Erreur d'entrée. Valeur par défaut utilisée: 0\n");
        return 0;
    }

    return n;
}


int main(void){
	int n;
	n = entrelavaleur();
	printf("\n res : %d\n", n);
	return 0;
}
