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

const char *getMessage() {
    return "Bonjour, M.Sven De Félice,\n\n"
           "Cela fait déjà quatre ans. Quand je suis arrivé à Paris pour la première fois, je ne connaissais personne, et je doutais vraiment de ma capacité à étudier l'informatique, surtout avec mes lacunes en mathématiques. Mais je me souviens encore très bien de votre premier cours, Informatique Fondamentale, où vous écriviez tout soigneusement au tableau. Cette attention aux détails m'a été d'une grande aide.\n\n"
           "Au début, il m'arrivait souvent de ne pas comprendre certaines parties du cours ou de manquer des notes en essayant de tout suivre. Pourtant, à chaque fois que je vous posais des questions avec mon français maladroit, vous ne vous êtes jamais montré agacé. Au contraire, vous m'avez toujours aidé avec gentillesse. Votre patience et votre enseignement m'ont beaucoup soutenu, et sans cela, j'aurais peut-être abandonné ma vie à Paris. Grâce à vous, j'ai trouvé la force de continuer à apprendre et à grandir.\n\n"
           "Et regardez ! Aujourd'hui, je suis capable de créer un petit programme avec un oeuf de Pâques. Même si j'ai commencé avec un code trouvé sur Internet, je suis maintenant en mesure d'utiliser la logique et les bases que vous m'avez enseignées pour développer mes propres idées. Tout cela, c'est grâce à vous.\n\n"
           "Je tiens encore une fois à vous remercier sincèrement, Monsieur.";
}

void typeEffect(const char *text, useconds_t delay) {
    size_t i;
    printf("\033[32m");
    for (i = 0; i < strlen(text); i++) {
        printf("%c", text[i]); 
        fflush(stdout);        
        usleep(delay);         
    }
    printf("\033[0m\n"); 
}

void AfficherLeMessageOeuf(){
	const char *message = getMessage();
	typeEffect(message,OeufDePâques);

}

int entrelavaleur() {
    
    element_int n; 
    printf("\n-> ");
    scanf("%d", &n);
  
    return n;
}

int EstRouge(couleur_t* couleur){

	return (*couleur == rouge) ? 1 : 0;
}
int EstNoir(couleur_t* couleur){

	return (*couleur == noir) ? 1 : 0;
}
