#include <stdio.h>
#include <unistd.h> // sleep(), usleep()
#include <time.h> // time

#define clignotement 500000
#define letempsdourant 5

typedef int element_entree;

int entrelavaleur(){
	element_entree n;
	time_t debut = time(NULL);
	time_t courant;
	while(1){

		printf("\033[5m entrez la valeur que vous voulez ajoute.\033[0m\r\n");		
		printf("\033[5m -> \033[0m\r\n");
		fflush(stdout);
		
		usleep(clignotement);
		printf("                        \r");
		fflush(stdout);
		usleep(clignotement);
		
		courant = time(NULL);	
		if(courant - debut > letempsdourant){

			break;
		};
	}
	printf("entrez la valeur que vous voulez ajoute.\n");
	printf("-> \n");
	scanf("%d ", &n);
	return n;
	
}


int main(void){
	int n;
	n = entrelavaleur();
	printf("\n res : %d\n", n);
	return 0;
}
