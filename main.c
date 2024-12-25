#include "main.h"
#include "util.h" 
#include "arbre.h"

void AfficherResultatNilEstBienAllouerOuPas(){
	arbreRN_t* arbre = AllouerAbreRN();
	printf("\n1 est bien allouer mais si c'est 0 non\n");
	printf("\nres :%d\n ",EstNoir(&(arbre -> nil -> couleur)));

	
}
void TestLaFonction(){
	AfficherResultatNilEstBienAllouerOuPas();

}

int main(void) {
    TestLaFonction();
    return 0;
}
