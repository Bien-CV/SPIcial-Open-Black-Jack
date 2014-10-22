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
#define DEB_TREFLE 39
#define FIN_TREFLE 51
//typedef enum {as = 1, deux, trois, quatre, cinq, six, cept, huit, neuf, dix, valet, dame, rois}t_num;
void afficher_carte(short num)
{
	if ( ( num >= DEB_COEURS ) && ( num <= FIN_COEURS ) ) {
		printf("%i de coeur",num%13);
	}else if ( ( num >= DEB_CARREAUX ) && ( num <= FIN_CARREAUX ) ) {
		printf("%i de coeur",num%13);
	}else if ( ( num >= DEB_PIQUES ) && ( num <= FIN_PIQUES ) ) {
		printf("%i de coeur",num%13);
	}else if ( ( num >= DEB_TREFLE ) && ( num <= FIN_TREFLE ) ) {
		printf("%i de coeur",num%13);
	}else{
		printf("Carte incorrecte.");
	}
}


int main()
{
int i;
for(i=0;i<51;i++){
afficher_carte(i);
}
return 0;
}

