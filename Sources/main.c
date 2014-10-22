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


    short cartes[52];
    short nb_as_joueur;
    short nb_as_banque;
    
    

typedef enum {COEURS, CARREAUX, PIQUES, TREFLES}t_couleur;
typedef enum {as = 1, deux, trois, quatre, cinq, six, cept, huit, neuf, dix, valet, dame, rois}t_num;

struct {t_num numero; t_couleur couleur;}s_carte;


short tirer_carte(short joueur)
{
    int numCarteTiree
    do
    {
        numCarteTiree = rand()%(51)
    }while(cartes[numCarteTiree] != LIBRE)
    cartes[numCarteTiree] = joueur;
    
}


int main()
{
    int indice1, indice2;
    nbAsBanque = 0;
    nbAsJoueur = 0;

    for(indice1 = 0; indice2 < NB_CARTES; indice1++)
    {
        cartes[indice1] = LIBRE;
    }

    return 0;
}
