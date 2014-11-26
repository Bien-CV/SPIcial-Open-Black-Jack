void test_tirer_carte(){
	CU_ASSERT(joueur<=3 && joueur>=0);	
}

void test_afficher_carte()
{
	CU_ASSERT(( num < DEB_COEURS ) || ( num > FIN_TREFLES ));
}

void test_afficher_mains()
{
	
}

void test_afficher_mains_cachee()
{
	
}

void test_donner_valeur_carte()
{

}

void evaluer_score()
{

}

int main()
{
    srand((unsigned)time(NULL));
    nb_as_banque = 0;
    nb_as_joueur = 0;
    as_banque_cachee = 0;
    scoreJoueur = 0;
    scoreBanque = 0;
    scoreBanqueCachee = 0;
    int choixJoueur = -1;
    moinsDix_Banque = 0;
    moinsDix_BanqueCachee = 0;
    moinsDix_joueur = 0;


    carteTiree = tirer_carte(BANQUE_CACHEE);
    scoreBanqueCachee = evaluer_score(BANQUE_CACHEE, carteTiree, &scoreBanqueCachee);
	CU_ASSERT();
    carteTiree = tirer_carte(BANQUE);
    scoreBanque = evaluer_score(BANQUE, carteTiree, &scoreBanque);

    carteTiree = tirer_carte(JOUEUR);
    scoreJoueur = evaluer_score(JOUEUR, carteTiree, &scoreJoueur);
    carteTiree = tirer_carte(JOUEUR);
    scoreJoueur = evaluer_score(JOUEUR, carteTiree, &scoreJoueur);



    while((scoreJoueur < 21) && ((scoreBanque + scoreBanqueCachee) < 21) && ((choixJoueur != 2) || ((scoreBanque + scoreBanqueCachee) < 17)))
    {
        if((scoreBanque + scoreBanqueCachee) < 17)
        {
            carteTiree = tirer_carte(BANQUE);
            scoreBanque = evaluer_score(BANQUE, carteTiree, &scoreBanque);
        }
        if((scoreBanque + scoreBanqueCachee) > 21)
        {
            if(as_banque_cachee == 1 && moinsDix_BanqueCachee < as_banque_cachee)
            {
                scoreBanqueCachee = scoreBanqueCachee - 10;
                moinsDix_BanqueCachee++;
            }
            else if(nb_as_banque > 0 && moinsDix_Banque < nb_as_banque)
            {
                scoreBanque = scoreBanque - 10;
                moinsDix_Banque++;
            }
        }
        if((scoreBanque + scoreBanqueCachee) < 21)
        {

            printf("\nvotre main:\n");
            afficher_mains(JOUEUR);
            printf("\nMain de la banque:\n");
            afficher_mains(BANQUE);
            printf("\nle score:\nVous: %i / Banque: %i", scoreJoueur, scoreBanque);
            do
            {
                printf("\n1 - Tirer une autre carte\n2 - s'arreter la\n-------------\nVotre choix: ");
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
            if(scoreJoueur != (scoreBanque + scoreBanqueCachee))
            {
                if(scoreJoueur == 21)
                {
                    printf("vous avez gagne avec un BlackJack contre un score de %i\n^^ :D ;P", scoreBanque + scoreBanqueCachee);
                }else
                {
                    printf("vous avez gagne avec un score de %i contre un score de %i\n:D", scoreJoueur, scoreBanque + scoreBanqueCachee);
                }
            }else printf("il y a egalite entre vous et la banque avec un score de %i\n>_<",scoreJoueur);
        }
    }else
    {
        if(scoreJoueur > 21)
        {
            printf("Vous avez perdu, votre score %i est superieur à 21\nscore de la banque: %i\n:'(", scoreJoueur, scoreBanque+scoreBanqueCachee);
        }else
        {
            if((scoreBanque + scoreBanqueCachee) > 21)
            {
                printf("Vous avez gagne!!! Le score de la banque %i est superieur à 21\nvotre score: %i\n^^ ;P :D", scoreBanque+scoreBanqueCachee, scoreJoueur);
            }
        }
    }
    printf("\n\nvotre main:\n");
    afficher_mains(JOUEUR);
    printf("\nMain de la banque:\n");
    afficher_mains_cachee();


    return 0;

}
