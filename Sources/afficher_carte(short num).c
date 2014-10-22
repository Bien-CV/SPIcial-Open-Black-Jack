#include <stdio.h>
#include <stdlib.h>
#define NB_CARTES 52
#define LIBRE 0
#define BANQUE 1
#define JOUEUR 2
#define BANQUE_CACHEE 3
#define DEB_COEURS 0
#define FIN_COEURS 12
#define DEB_CARREAUX 13
#define FIN_CARREAUX 25
#define DEB_PIQUES 26
#define FIN_PIQUES 38
#define DEB_TREFLES 39
#define FIN_TREFLES 51
//typedef enum {as = 1, deux, trois, quatre, cinq, six, cept, huit, neuf, dix, valet, dame, rois}t_num;
void afficher_carte(short num)
{
	if ( ( num < DEB_COEURS ) && ( num > FIN_TREFLES ) ) {
		printf("Carte incorrecte.");
		return;
	}
	
	if ( num%13 == 10 ){ // Affiche valeur
			printf("valet");
		} else if ( num%13 == 11 ){
			printf("dame");
		} else if ( num%13 == 12 ){
			printf("roi");
		} else if ( num%13 == 0 ){
			printf("as");
		} else {
			printf("%i",num%13+1);
		}
	
	printf(" "); // séparateur valeur/couleur
		
	if ( ( num >= DEB_COEURS ) && ( num <= FIN_COEURS ) ) {// Affiche couleur
		printf("de coeur");
	}else if ( ( num >= DEB_CARREAUX ) && ( num <= FIN_CARREAUX ) ) {
		printf("de carreau");
	}else if ( ( num >= DEB_PIQUES ) && ( num <= FIN_PIQUES ) ) {
		printf("de pique");
	}else if ( ( num >= DEB_TREFLES ) && ( num <= FIN_TREFLES ) ) {
		printf("de trefle");
	}
	printf("\n");
	return;
}


int main()
{
int i;
for(i=0;i< NB_CARTES ;i++){
afficher_carte(i);
}
return 0;
}
