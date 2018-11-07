/**
 *	Auteurs : Loan Veyer, Robinson Besson
 *	Du 07/11/2018 au XX/XX/XXXX
 **/






/**
 *	Liste programmes:
 *		1- Ajouter Ville
 *		2- Modifier Ville
 *		3- Supprimer Ville
 *		4- Ajouter une nouvelle livraison dans une Ville
 *		5- Supprimer une livraison dans une Ville
 *		6- Modifier livraison dans une Ville
 *		7- Recherche dans une Ville une certaine capacité
 *		8- Recherche n'importe quelle Ville une certaine capacité
 *		9- Transfert d'un chauffeur d'une Ville 1 à une Ville 2
**/





#pragma warning(disable : 4996)	// Désactives les allertes causés par scanf





#include <stdio.h>
#include <stdlib.h>	// Malloc





struct Livraison;	// Redéfinit par la suite, nécessaire pour déclarer struct Ville


typedef struct Ville {
	int numVille;	// Numéro de la ville
	struct Ville * villeSuivante;
	struct Ville * villePrecedente;
	struct Livraison * listeLivraison;
} tVille;


typedef struct Livraison {
	int chauffeur;
	int capacite;
	int disponible;
	struct Livraison * livraisonSuivante;
	tVille * enLivraison;
} tLivraison;


typedef tVille * ptVille;	// Définition type pointeur vers struct tVille
typedef tLivraison * ptLivraison;	// Définition type pointeur vers struct tLivraison





int main() {
	
	// Création des bidons
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
	


	// Entrée pour menu
	int c = -1;
	
	// Boucle menu
	while (c != 10) {
		printf("1- Ajouter Ville\n");
		printf("2- Modifier Ville\n");
		printf("3- Supprimer Ville");
		printf("4- Ajouter une nouvelle livraison dans une Ville\n");
		printf("5- Supprimer une livraison dans une Ville\n");
		printf("6- Modifier livraison dans une Ville\n");
		printf("7- Recherche dans une Ville une certaine capacite\n");
		printf("8- Recherche n'importe quelle Ville une certaine capacite\n");
		printf("9- Transfert d'un chauffeur d'une Ville 1 a une Ville 2\n");
		printf("10- Quitter\n");
		
		printf("Entrez le numero de la fonction a appeler: ");
		scanf("%d", &c);

		// Boucle entrée non valide
		while (c < 0 || c > 10) {
			printf("\n");
			printf("Entrez le numero de la fonction a appeler: ");
			scanf("%d", &c);
		}
		

		switch (c) {
			case 1:
				printf("%d", c);
				break;
			
			case 2:
				printf("%d", c);
				break;
			
			case 3:
				printf("%d", c);
				break;
			
			case 4:
				printf("%d", c);
				break;
			
			case 5:
				printf("%d", c);
				break;
			
			case 6:
				printf("%d", c);
				break;
			
			case 7:
				printf("%d", c);
				break;
			
			case 8:
				printf("%d", c);
				break;
			
			case 9:
				printf("%d", c);
				break;
		}
	}
	
	return 1;
}


