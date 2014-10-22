/**
 * \author Arthur LEMEE
 */
#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"

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
    
short carteTiree;
short scoreJoueur;
short scoreBanque;
short scoreBanqueCachee;
    
    
/*
typedef enum {COEURS, CARREAUX, PIQUES, TREFLES}t_couleur;
typedef enum {as = 1, deux, trois, quatre, cinq, six, cept, huit, neuf, dix, valet, dame, rois}t_num;

struct {t_num numero; t_couleur couleur;}s_carte;
*/


/**
 * \fn int main()
 * \brief fonction principale
 * distribue les cartes, puis demande à la banque et au joueur s'ils veulent tirer des cartes.'
 * Arrête le jeu lorsque le score est trop élevé ou quand les joueur ne tirent plus de carte'
 */
int main()
{
    int indice1, indice2;
    nb_as_banque = 0;
    nb_as_joueur = 0;
    scoreJoueur = 0;
    scoreBanque = 0;
    scoreBanqueCachee = 0;
    int choixJoueur = -1;
    
    
    carteTiree = tirer_carte(BANQUE_CACHEE);
    scoreBanqueCachee = evaluer_score(BANQUE_CACHEE, carteTiree, &scoreBanqueCachee);
    carteTiree = tirer_carte(BANQUE);
    scoreBanque = evaluer_score(BANQUE, carteTiree, &scoreBanque);
    
    carteTiree = tirer_carte(JOUEUR);
    scoreJoueur = evaluer_score(JOUEUR, carteTiree, &scoreJoueur);
    carteTiree = tirer_carte(JOUEUR);
    scoreJoueur = evaluer_score(JOUEUR, carteTiree, &scoreJoueur);
    
    
    
    While((scoreJoueur <= 21) && ((scoreBanque + scoreBanqueCachee) <= 21) && ((choixJoueur != 2) && ((scoreBanque + scoreBanqueCachee) >= 17)))
    {
        if((scoreBanque + scoreBanqueCache) < 17)
        {
            carteTiree = tirer_carte(BANQUE);
            scoreBanque = evaluer_score(BANQUE, carteTiree, &scoreBanque);
        }
        if((scoreBanque + scoreBanqueCachee) < 21)
        {
            
            printf("\nvotre main: ");
            afficher_main(JOUEUR);
            printf("\nMain de la banque: ");
            afficher_main(BANQUE);
            printf("\nle score:\nVous: %i / Banque: %i", scoreJoueur, scoreBanque);
            do
            {
                print("\n1 - Tirer une autre carte\n2 - s'arreter la\n-------------\nVotre choix:");
                scanf("%i", &choixJoueur);
            }while(choixJoueur != 1 && choixJoueur != 2);
            if(choixJoueur == 1)
            {
                carteTiree = tirer_carte(JOUEUR);
                scoreJoueur = evaluer_score(JOUEUR, carteTiree, &scoreJoueur);
            }
        }
    }
    
    if(scoreJoueur <=21 && (scoreBanque + scoreBanqueCachee) <= 21)
    {
        if(scoreJoueur < (scoreBanque + scoreBanqueCachee))
        {
            if((scoreBanque + scoreBanqueCachee) == 21)
            {
                printf("Vous avez perdu avec un score de %i contre un blackJack!\n:'(", scoreJoueur);
            }else
                printf("Vous avez perdu avec un score de %i contre un score de %i!\n:(", scoreJoueur, scoreBanque + scoreBanqueCachee);
        }else
        {
            if(scoreJoueur == 21)
            {
                printf("vous avez gagne avec un BlackJack contre un score de %i\n^^ :D ;P", scoreBanque + scoreBanqueCachee);
            }else
            {
                printf("vous avez gagne avec un score de %i contre un score de %i\n:D", scoreJoueur, scoreBanque + scoreBanqueCachee);
            }
        }
    }
    printf("\nvotre main: ");
    afficher_main(JOUEUR);
    printf("\nMain de la banque: ");
    afficher_main(BANQUE);
    

    return 0;
}
