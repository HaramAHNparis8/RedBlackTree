#ifndef UTIL_H
#define UTIL_H
#include <stdio.h>
#include <unistd.h>  // sleep(), usleep()
#include <time.h>    // time()

#define clignotement 200000 
#define letempsdourant 2  

typedef int element_int;

void AfficherLeMessage(void(*f)(void));
void afficherMessageEntrezLeval();
int entrelavaleur();

#endif
