#ifndef UTIL_H
#define UTIL_H
#include <stdio.h>
#include <unistd.h>  // sleep(), usleep()
#include <time.h>    // time()
#include "arbre.h"
#include <string.h>

#define clignotement 200000 
#define letempsdourant 2  
#define OeufDePâques 12000
typedef int element_int; // origine PIA

void AfficherLeMessage(void(*f)(void));
void afficherMessageEntrezLeval();
element_int entrelavaleur();
int EstRouge(couleur_t* couleur);
int EstNoir(couleur_t* couleur);
const char *getMessage();
void typeEffect(const char *text, useconds_t delay);
void AfficherLeMessageOeuf();


#endif
