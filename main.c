#include "main.h"
#include "util.h" 
#include "arbre.h"

void AfficherResultatNilEstBienAllouerOuPas(){
	arbreRB_t* arbre = AllouerAbreRB();
	printf("\n1 est bien allouer mais si c'est 0 non\n");
	printf("\nres :%d\n ",EstRouge(&(arbre -> nil -> couleur));

	
}
void TestLaFonction(){
	AfficherResultatNilEstBienAllouerOuPas();

}

int main(void) {
    TestLaFonction(); 
    return 0;
}
