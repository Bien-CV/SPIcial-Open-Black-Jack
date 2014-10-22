/**
 * \fn void afficher_mains(short joueur)
 * \brief 
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

