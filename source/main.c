/**
 *	Auteurs : Loan Veyer, Robinson Besson
 *	Du 07/11/2018 au XX/XX/XXXX
 **/


/**
 *	Liste programmes:
 *		1	Ajouter Ville
 *		2	Modifier Ville
 *		3	Supprimer Ville
 *		4	Ajouter une nouvelle livraison dans une Ville
 *		5	Supprimer une livraison dans une Ville
 *		6	Modifier livraison dans une Ville
 *		7	Recherche dans une Ville une certaine capacit�
 *		8	Recherche n'importe quelle Ville une certaine capacit�
 *		9	Transfert d'un chauffeur d'une Ville 1 � une Ville 2
 *		10	Enregistrer dans un fichier
 *		11	Charger un fichier
 **/



#pragma warning(disable : 4996)	// D�sactives les allertes caus�s par scanf



#include <stdio.h>
#include <stdlib.h>	// Malloc




struct Livraison;	// Red�finit par la suite, n�cessaire pour d�clarer struct Ville


typedef struct Ville
{
	int numVille;	// Num�ro de la ville
	struct Ville * villeSuivante;
	struct Ville * villePrecedente;
	struct Livraison * listeLivraison;
} tVille;


typedef struct Livraison
{
	int chauffeur;
	int capacite;
	int disponible;
	struct Livraison * livraisonSuivante;
	tVille * enLivraison;
} tLivraison;


typedef tVille * ptVille;	// D�finition type pointeur vers struct tVille
typedef tLivraison * ptLivraison;	// D�finition type pointeur vers struct tLivraison





// Afficher Liste Ville
void afficherListeVille(ptVille px)
{
	printf("Liste de villes :\n");
	while (px->villeSuivante != NULL)
	{
		printf("%d\n", px->numVille);
		px = px->villeSuivante;
	}
	printf("Fin de la liste des villes\n\n\n");
}


// Afficher Liste Livraison
void afficherListeLivraison(ptVille px, int valVille)
{
	printf("Liste de Livraison de la ville %d :\n", valVille);
	printf("chauffeur / capacite / disponible / destination\n\n");
	while (px->villeSuivante != NULL)
	{
		if (px->numVille == valVille)
		{
			ptLivraison py = px->listeLivraison;
			if (py != NULL)
			{
				while (py != NULL)
				{
					if (py->disponible == 0)
					{
						printf("%d / %d / Pas disponible / %d \n", py->chauffeur, py->capacite, py->enLivraison->numVille);
					}
					else
					{
						printf("%d / %d / Disponible \n", py->chauffeur, py->capacite);
					}
					py = py->livraisonSuivante;
				}
			}
		}
		px = px->villeSuivante;
	}
	printf("Fin de la liste des livraisons\n\n\n");
}


// 1- Ajouter Ville
void ajouterVille(ptVille px, int valVille)
{
	px->villeSuivante->villePrecedente = (ptVille)malloc(sizeof(tVille));
	px->villeSuivante->villePrecedente->villeSuivante = px->villeSuivante;
	px->villeSuivante->villePrecedente->villePrecedente = px;
	px->villeSuivante = px->villeSuivante->villePrecedente;
	px->villeSuivante->numVille = valVille;

	px->villeSuivante->listeLivraison = NULL;
}


// 2- Modifier num�ro Ville
void modifierVille(ptVille px, int num, int nouvVal)
{
	while (px->villeSuivante != NULL)
	{
		if (px->numVille == num)
		{
			px->numVille = nouvVal;
			break;
		}
		px = px->villeSuivante;
	}
}


// 3- Supprimer Ville
void supprimerVille(ptVille px, int num)
{
	while (px->villeSuivante != NULL)
	{
		if (px->villeSuivante->numVille == num)
		{
			px->villeSuivante->villeSuivante->villePrecedente = px;
			px->villeSuivante = px->villeSuivante->villeSuivante;
			break;
		}
		px = px->villeSuivante;
	}
}


// 4- Ajouter une livraison dans une ville
void ajouteLivraison(ptVille px, ptVille pz, int valVille, int villeDestination, int chauffeur, int capacite, int disponible)
{
	while (px->villeSuivante != NULL)
	{
		if (px->numVille == valVille)
		{
			ptLivraison py = px->listeLivraison;

			if (py == NULL)
			{
				px->listeLivraison = (ptLivraison)malloc(sizeof(tLivraison));

				py = px->listeLivraison;

			}
			else
			{
				while (py->livraisonSuivante != NULL)
				{
					py = py->livraisonSuivante;
				}
				py->livraisonSuivante = (ptLivraison)malloc(sizeof(tLivraison));
				py = py->livraisonSuivante;
			}

			py->chauffeur = chauffeur;
			py->capacite = capacite;
			py->disponible = disponible;
			py->livraisonSuivante = NULL;

			if (pz != NULL)
			{
				while (pz->villeSuivante != NULL)
				{
					if (pz->numVille == villeDestination)
					{
						py->enLivraison = pz;
					}
					pz = pz->villeSuivante;
				}
			}

		}
		px = px->villeSuivante;
	}
}


// 5- Supprimer une livraison dans une Ville
void supprimerLivraison(ptVille px, int valVille, int chauffeur)
{
	while (px->villeSuivante != NULL)
	{
		if (px->numVille == valVille)
		{

			ptLivraison py = px->listeLivraison;
			if (py != NULL) {
				if (py->chauffeur == chauffeur)
				{
					py = NULL;
					printf("essaye 1");
					break;
				}

				while (py->livraisonSuivante != NULL)
				{
					if (py->livraisonSuivante->chauffeur == chauffeur)
					{
						py->livraisonSuivante = py->livraisonSuivante->livraisonSuivante;
					}
					py = py->livraisonSuivante;
				}
			}
		}
		px = px->villeSuivante;
	}
}


// 11- Charger structure depuis un fichier
void chargerStructure(ptVille pdebut, ptVille px)
{
	FILE *fich;	// poiteur vers fichier
	fich = fopen("Toto.dat", "rt");	//ouverture fichier en lecture
	if (fich == NULL) printf("Probleme d'ouverture du fichier");	// v�rifie la bonne ouverture du fichier

	ptVille debut = px;	// pointeur vers d�but d'insertion

	int hash = -1;		// compte nombre #
	int doll = 0;		// compte nombre $

	int sec = 0;		// indicateur section
	int sub = 0;		// indicateur sous-section
	int champ = 0;		// indicateur champ de donn�es

	char c;
	int value;

	while (feof(fich) != 0) 
	{
		c = fgetc(fich);	// Lecture caract�re actif

		if (hash != -1)		// Si on n'est pas au d�but du fichier,
		{
			if (c == '#')
			{
				hash++;		// on contabilise les '#'
			}
			else if (c == '$')
			{
				doll++;		// et les '$'.
			}
		}

		if ( ( c >= '0' && c <= '9') || c == '-')	// Si on a un caract�re num�rique,
		{
			fwscanf(fich, "%d", &value);	// on lit la valeure num�rique.

			if (hash == -1)		// Si c'est la premi�re valeur num�rique,
			{
				ajouterVille(px, value);	// on cr�e une nouvelle ville.
				px = px->villeSuivante;

				hash = 0; doll = 0;
			}
			else	// Ce n'est pas la premi�re valeur du fichier.
			{
				if (sec == 0)	// Si on est dans la premi�re section (num�ros de villes).
				{
					if (hash == 1)	// Si il y a eu un seul '#' depuis l derni�re valeur,
					{
						sub++;		// on change de sous section
						ajouterVille(px, value);	// et on ajoute une ville.
						px = px->villeSuivante;

						hash = 0; value = 0;
					}
					else if (hash > 1)	// Si il y a eu plus d'un '#',
					{
						sec += hash / 2;	// On change de section (ajout de livraison dans une ville).
											// On change de ville pour chaque paire de '#'.
						sub = 0;	// La sous-section est r�initialis�e.
						px = debut;	// Il faut que l'insertion des livraison commence � la premi�re ville,
						for (int i = 0; i < hash / 2; i++)	// sauf si il y a plus d'une paire de '#'.
						{
							px = px->villeSuivante;
						}

						// Insertion de la livraison avec des valeurs par d�faut.
						ptLivraison py;
						py = (ptLivraison)malloc(sizeof(tLivraison));
						py->chauffeur = value;
						py->capacite = 0;
						py->disponible = 1;
						py->enLivraison = NULL;
						py->livraisonSuivante = px->listeLivraison;
						px->listeLivraison = py;

						hash = 0; doll = 0;
					}
				}
				else if (sec > 0)	// Si on est pas dans la premi�re section (ajout de livraison)
				{
					if (hash == 1)	// Si on a qu'un seul '#',
					{
						sub++;	// changement de sous-section (livraison diff�rente pour une m�me ville)
						champ = 0;	// et r�initialisation du champ de donn�.

						// Insertion de la livraison avec valeurs par d�faut.
						ptLivraison py;
						py = (ptLivraison)malloc(sizeof(tLivraison));
						py->chauffeur = value;
						py->capacite = 0;
						py->disponible = 1;
						py->enLivraison = NULL;
						py->livraisonSuivante = px->listeLivraison;
						px->listeLivraison = py;

						hash = 0; doll = 0;
					}
					else if (hash > 1)	// Si on a plus d'un '#',
					{
						sec += hash / 2;	// on change la ville o� on inserre les livraisons
						for (int i = 0; i < hash / 2; i++)	// �ventuellement en sautant des villes si plus de 2 '#'.
						{
							px = px->villeSuivante;
						}
						champ = 0;

						// Insertion de la livraison avec valeurs par d�faut.
						ptLivraison py;
						py = (ptLivraison)malloc(sizeof(tLivraison));
						py->chauffeur = value;
						py->capacite = 0;
						py->disponible = 1;
						py->enLivraison = NULL;
						py->livraisonSuivante = px->listeLivraison;
						px->listeLivraison = py;

						hash = 0; doll = 0;
					}
					else if (doll > 0)	// Si on a eu un '$' (ou plus),
					{
						champ += doll;	// on change de champ de donn�.
						
						// Celon le champ actif:
						if (champ == 1)
						{
							// changement de la capacit�;
							px->listeLivraison->capacite = value;
						}
						else if (champ == 2)
						{
							// changement de la disponibilit�;
							px->listeLivraison->disponible = value;
						}
						else if (champ == 3)
						{
							// ajout d'une destination.
							ptVille pz;
							pz = pdebut;

							if (value > 0)
							{
								while (pz->villeSuivante != NULL)	// On parcours l'ensemble des villes charg�es en m�moire,
								{
									if (pz->numVille == value)	// � la recherche de la ville avec le bon num�ro.
									{
										px->listeLivraison->enLivraison = pz;	// Si c'est le cas on ajoute un pointeur vers cette ville.
									}
								}
							}
							else
							{
								px->listeLivraison->enLivraison = NULL;
							}
						}
					}
				}
			}
		}



	}

}




int main()
{
	
	// Cr�ation des bidons
	ptVille pdebutVille = (ptVille) malloc (sizeof (tVille));
	ptVille pfinVille = (ptVille) malloc (sizeof (tVille));

	// Pointeurs entre les deux bidons
	pdebutVille->villeSuivante = pfinVille;
	pfinVille->villePrecedente = pdebutVille;

	// Indice des villes
	pdebutVille->numVille = -1;
	pfinVille->numVille = -1;

	// Pointeurs terminaux
	pdebutVille->villePrecedente = NULL;
	pfinVille->villeSuivante = NULL;

	// Pointeurs listes nulles
	pdebutVille->listeLivraison = NULL;
	pfinVille->listeLivraison = NULL;

	// Pointeur vers ville active
	ptVille px = pdebutVille;
	


	// Entr�e pour menu
	int c = -1;
	
	// Boucle menu
	while (c != 20)
	{
		printf("1-	Ajouter Ville\n");
		printf("2-	Modifier Ville\n");
		printf("3-	Supprimer Ville\n");
		printf("4-	Ajouter une nouvelle livraison dans une Ville\n");
		printf("5-	Supprimer une livraison dans une Ville\n");
		printf("6-	Modifier livraison dans une Ville\n");
		printf("7-	Recherche dans une Ville une certaine capacite\n");
		printf("8-	Recherche n'importe quelle Ville une certaine capacite\n");
		printf("9-	Transfert d'un chauffeur d'une Ville 1 a une Ville 2\n");
		printf("10-	Enregistrer fichier\n");
		printf("11-	Charger fichier\n");
		printf("12-	Afficher liste ville\n");
		printf("13-	Afficher livraison d'une ville\n");
		printf("20-	Quitter\n\n");
		
		printf("Entrez le numero de la fonction a appeler: ");
		scanf("%d", &c);

		
		while (c < 0 || c > 20)
		{
			// Boucle entr�e non valide
			printf("\n");
			printf("Entrez le numero de la fonction a appeler: ");
			scanf("%d\n", &c);
		}
		

		if (c == 1)
		{
			// Nouvelle ville
			int nouvVal;
			px = pdebutVille;
			printf("Entrer le numero de la ville: ");
			scanf("%d", &nouvVal);
			ajouterVille(px, nouvVal);
			px = pdebutVille->villeSuivante;
			afficherListeVille(px);
		}


		else if (c == 2)
		{
			// Modification ville
			int nouvVal, ancienneVal;
			printf("Entrer le numero de la ville actuelle: ");
			scanf("%d", &ancienneVal);
			printf("Entrer le nouveau numero de la ville: ");
			scanf("%d", &nouvVal);
			px = pdebutVille->villeSuivante;
			modifierVille(px, ancienneVal, nouvVal);
			px = pdebutVille->villeSuivante;
			afficherListeVille(px);
		}


		else if (c == 3)
		{
			// Supression Ville
			int valSupp;
			printf("Entrer le numero de la ville a supprimer: ");
			scanf("%d", &valSupp);
			px = pdebutVille;
			supprimerVille(px, valSupp);
			px = pdebutVille->villeSuivante;
			afficherListeVille(px);
		}


		else if (c == 4)
		{
			// Ajout livraison
			int chauffeur, capacite, disponible, valVille, villeLivraison;

			printf("Entrer le numero du chauffeur: ");
			scanf("%d", &chauffeur);

			printf("Entrer la capacite: ");
			scanf("%d", &capacite);

			printf("Entrer sa disponibilite: ");
			scanf("%d", &disponible);

			printf("Entrer le numero de la ville a laquelle il vient: ");
			scanf("%d", &valVille);

			if (disponible == 0)
			{
				printf("Entrer le numero de la ville dans laquelle il va: ");
				scanf("%d", &villeLivraison);

				px = pdebutVille->villeSuivante;
				ajouteLivraison(px, px, valVille, villeLivraison, chauffeur, capacite, disponible);
			}
			else
			{
				villeLivraison = -1;

				px = pdebutVille->villeSuivante;
				ajouteLivraison(px, NULL, valVille, villeLivraison, chauffeur, capacite, disponible);
			}
			printf("\n");

			px = pdebutVille->villeSuivante;
			afficherListeLivraison(px, valVille);
		}


		else if (c == 5)
		{
			// Suppression livraison
			int valVille, chauffeur;

			printf("Entrer le numero de la ville de la livraison: ");
			scanf("%d", &valVille);

			printf("Entrer le numero du chauffeur de la livraison a supprimer: ");
			scanf("%d", &chauffeur);

			px = pdebutVille->villeSuivante;
			supprimerLivraison(px, valVille, chauffeur);

			px = pdebutVille->villeSuivante;
			afficherListeLivraison(px, valVille);
		}


		else if (c == 6)
		{
			// Modifier livraison
		}


		else if (c == 7)
		{
			// Recherche capacit� dans ville
		}


		else if (c == 8)
		{
			// Recherche capacit� partout
		}


		else if (c == 9)
		{
			// Transfert chaufeur
		}


		else if (c == 10)
		{
			// Enregistre fichier
		}
		
		
		else if (c == 11)
		{
			// Chargement fichier
			chargerStructure(pdebutVille, px);
		}


		else if (c == 12)
		{
			// Affichage villes
			px = pdebutVille->villeSuivante;
			afficherListeVille(px);
		}


		else if (c == 13)
		{
			// Affichage ville
			int valVille;

			printf("Entrer le numero de la ville : ");
			scanf("%d", &valVille);

			px = pdebutVille->villeSuivante;
			afficherListeLivraison(px, valVille);
		}
	}
	
	return 1;
}
