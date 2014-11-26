/**
 * \file afficher_mains.c
 * \brief fichier de la fonction
 * \author Arthur LEMEE, Yann GUENVER, Jean-Baptiste DUBOIS, Baptiste CANOVAS-VIRLY.
 * \version 1.0
 * \date 22 octobre 2014
 * 
 * Afficher la main d'un joueur
 * 
 */





/**
 * \fn void afficher_mains(short joueur)
 * \brief Affiche la main d'un joueur
 */


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

