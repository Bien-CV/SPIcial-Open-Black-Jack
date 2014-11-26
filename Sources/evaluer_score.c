/**
 * \file evaluer_score.c
 * \brief fichier de la fonction
 * \author Arthur LEMEE, Yann GUENVER, Jean-Baptiste DUBOIS, Baptiste CANOVAS-VIRLY.
 * \version 1.0
 * \date 22 octobre 2014
 * 
 * Afficher la main de la banque
 * 
 */



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

/**
 * \fn short donner_valeur_carte(short joueur,short carte)
 * \brief Retourne la valeur de la carte prise en paramètre.
 */
short donner_valeur_carte(short joueur,short carte){
  carte=carte%13;
  
  if(!carte){
    if(joueur==JOUEUR) nb_as_joueur++;
    if(joueur==BANQUE) nb_as_banque++;
    return 11;
  }
  
  if(carte>=9) return 10;
  return (carte+1);
}

/**
 * \fn short evaluer_score(short joueur,short carte_recue,short *score)
 * \brief Met à jour le score du joueur courant.
 */
short evaluer_score(short joueur,short carte_recue,short *score){
  return(*score=(*score)+donner_valeur_carte(joueur,carte_recue));
}
