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