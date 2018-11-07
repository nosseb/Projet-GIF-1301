/******************************
* Loan Veyer, Robinson Besson *
* Du 07/11/2018 au XX/XX/XXXX *
*******************************/

/************************************************************
* Liste programme:											*
* 1- Ajouter Ville											*
* 2- Modifier Ville											*
* 3- Supprimer Ville										*
* 4- Ajouter une nouvelle livraison dans une Ville			*
* 5- Supprimer une livraison dans une Ville					*
* 6- Modifier livraison dans une Ville						*
* 7- Recherche dans une Ville une certaine capacité			*
* 8- Recherche n'importe quelle Ville une certaine capacité *
* 9- Transfert d'un chauffeur d'une Ville 1 à une Ville 2	*
*************************************************************/

#include <stdio.h>

struct Livraison;

typedef struct Ville {
	int numVille;
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

int main() {
	int c = -1;
	
	while (c != 10) {
		printf("1- Ajouter Ville");
		printf("\n2- Modifier Ville");
		printf("\n3- Supprimer Ville");
		printf("\n4- Ajouter une nouvelle livraison dans une Ville");
		printf("\n5- Supprimer une livraison dans une Ville");
		printf("\n6- Modifier livraison dans une Ville");
		printf("\n7- Recherche dans une Ville une certaine capacite");
		printf("\n8- Recherche n'importe quelle Ville une certaine capacite");
		printf("\n9- Transfert d'un chauffeur d'une Ville 1 a une Ville 2");
		printf("\n10- Quitter");
		
		printf("\nEntrez le numero de la fonction a appeler: ");
		scanf("%d", &c);
		while (c < 0 || c > 10) {
			printf("\nEntrez le numero de la fonction a appeler: ");
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

