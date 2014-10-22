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
short cartes[52];
short nb_as_joueur;
short nb_as_banque;


short tirer_carte(short joueur)
{
    int numCarteTiree;
    do
    {
        numCarteTiree = rand()%(51);
    }while(cartes[numCarteTiree] != LIBRE);
    cartes[numCarteTiree] = joueur;
    return(numCarteTiree+1);
}
