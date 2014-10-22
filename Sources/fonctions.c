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






//Fonction-tirer_carte.c

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






//afficher_carte(short num).c

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






//afficher_mains.c

void afficher_mains(short joueur)
{
  int i;
  for(i=0; i<cartes[52]; i++)
    {
    if(joueur==JOUEUR)
      {
        afficher_carte(num);
      }
      else{
        afficher_mains_cachee();
      }
    }
}






//afficher_mains_cachee.c

void afficher_mains_cachee(short joueur)
{
	int i;
  for(i=0; i<cartes[52]; i++)
    {
    if(joueur==BANQUE)
      {
        afficher_carte(num);
       
      }
      else if(joueur==BANQUE_CACHEE)
      {
		afficher_carte(num);  
	}
}





//evaluer_score.c

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
