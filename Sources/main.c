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

typedef enum {COEURS, CARREAUX, PIQUES, TREFLES}t_couleur;
typedef enum {as = 1, deux, trois, quatre, cinq, six, cept, huit, neuf, dix, valet, dame, rois}t_num;

struct {t_num numero; t_couleur couleur;}s_carte;


short TirerCarte(short joueur)
{
    int numCarteTiree = rand()%(51)
}


int main()
{
    short cartes[52];
    short nbAsJoueur;
    short nbAsBanque;

    int indice1, indice2;

    for(indice1 = 0; indice2 < NB_CARTES; indice1++)
    {
        cartes[indice1] = LIBRE;
    }

    return 0;
}
