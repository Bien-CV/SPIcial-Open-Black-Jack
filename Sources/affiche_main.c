void afficher_mains(short joueur)
{
  int i;
  for(i=0; i<cartes[52]; i++)
    {
    if(cartes[i]==JOUEUR)
      {
        afficher_carte(num);
      }
    }
}

