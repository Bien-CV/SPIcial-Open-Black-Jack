void afficher_mains(short joueur)
{
  int i,j;
  for(i=0; i<cartes[52]; i++)
    {
    if(cartes[i]==joueur)
      {
        afficher_carte(num);
      }
    }
}
