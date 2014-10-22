

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
