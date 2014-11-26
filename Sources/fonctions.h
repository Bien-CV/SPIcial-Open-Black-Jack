/**
 * \file fonction.h
 * \brief Librairie des fonctions
 * \author Arthur LEMEE, Yann GUENVER, Jean-Baptiste DUBOIS, Baptiste CANOVAS-VIRLY.
 * \version 1.0
 * \date 22 octobre 2014
 * 
 * Librairie pour le programme "Black Jack"
 * 
 */
 
 //Prototype des fonctions
short tirer_carte(short joueur);
void afficher_carte(short num);
void afficher_mains(short joueur);
void afficher_mains_cachee(void);
short donner_valeur_carte(short joueur, short carte);
short evaluer_score (short joueur, short carte_recue, short *score);
