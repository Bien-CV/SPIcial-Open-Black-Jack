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
    
    
/*
typedef enum {COEURS, CARREAUX, PIQUES, TREFLES}t_couleur;
typedef enum {as = 1, deux, trois, quatre, cinq, six, cept, huit, neuf, dix, valet, dame, rois}t_num;

struct {t_num numero; t_couleur couleur;}s_carte;
*/

int main()
{
    int indice1, indice2;
    nbAsBanque = 0;
    nbAsJoueur = 0;
    short carteTiree;
    
    
    carteTiree = tirer_carte(BANQUE_CACHEE);
    carteTiree = tirer_carte(BANQUE);
    
    carteTiree = tirer_carte(JOUEUR);
    carteTiree = tirer_carte(JOUEUR);
    
    

    return 0;
}
