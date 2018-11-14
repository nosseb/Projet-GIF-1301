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
 *		7	Recherche dans une Ville une certaine capacit?
 *		8	Recherche n'importe quelle Ville une certaine capacit?
 *		9	Transfert d'un chauffeur d'une Ville 1 ? une Ville 2
 *		10	Enregistrer dans un fichier
 **/

#include <stdio.h>
#include <stdlib.h>

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

typedef tVille * ptVille;
typedef tLivraison * ptLivraison;

// Afficher Liste Ville
void afficherListeVille(ptVille px) {
	printf("Liste de villes :\n");
	while (px->villeSuivante != NULL) {
		printf("%d\n", px->numVille);
		px = px->villeSuivante;
	}
	printf("Fin de la liste des villes\n\n\n");
}

// 1- Ajouter Ville
void ajouterVille(ptVille px, int valVille) {
	px->villeSuivante->villePrecedente = (ptVille) malloc (sizeof (tVille));
	px->villeSuivante->villePrecedente->villeSuivante = px->villeSuivante;
	px->villeSuivante->villePrecedente->villePrecedente = px;
	px->villeSuivante = px->villeSuivante->villePrecedente;
	px->villeSuivante->numVille = valVille;
	
	px->villeSuivante->listeLivraison = NULL;
}

// 2- Modifier Ville
void modifierVille(ptVille px, int num, int nouvVal) {
	while (px->villeSuivante != NULL) {
		if(px->numVille == num) {
			px->numVille = nouvVal;
			break;
		}
		px = px->villeSuivante;
	}
}

// 3- Supprimer Ville
void supprimerVille(ptVille px, int num) {
	while (px->villeSuivante != NULL) {
		if(px->villeSuivante->numVille == num) {
			px->villeSuivante->villeSuivante->villePrecedente = px;
			px->villeSuivante = px->villeSuivante->villeSuivante;
			break;
		}
		px = px->villeSuivante;
	}
}

// 4- Ajouter une livraison dans une ville
void ajouteLivraison() {
	
}

int main() {
	
	ptVille pdebutVille = (ptVille) malloc (sizeof (tVille));
	ptVille pfinVille = (ptVille) malloc (sizeof (tVille));
	pdebutVille->villeSuivante = pfinVille;
	pfinVille->villePrecedente = pdebutVille;
	pdebutVille->villePrecedente = NULL;
	pfinVille->villeSuivante = NULL;
	pdebutVille->listeLivraison = NULL;
	pfinVille->listeLivraison = NULL;
	ptVille px = pdebutVille;
	
	
	int c = -1;
	while (c != 20) {
		printf("1- Ajouter Ville\n");
		printf("2- Modifier Ville\n");
		printf("3- Supprimer Ville");
		printf("4- Ajouter une nouvelle livraison dans une Ville\n");
		printf("5- Supprimer une livraison dans une Ville\n");
		printf("6- Modifier livraison dans une Ville\n");
		printf("7- Recherche dans une Ville une certaine capacite\n");
		printf("8- Recherche n'importe quelle Ville une certaine capacite\n");
		printf("9- Transfert d'un chauffeur d'une Ville 1 a une Ville 2\n");
		printf("10- Enregistrer fichier\n");
		printf("11- Charger fichier\n");
		printf("20- Quitter\n");
		
		printf("\n\nEntrez le numero de la fonction a appeler: ");
		scanf("%d", &c);
		while (c < 0 || c > 10) {
			printf("\nEntrez le numero de la fonction a appeler: ");
			scanf("%d", &c);
		}
		
		if (c == 1) {
			int nouvVal;
			px = pdebutVille;
			printf("Entrer le numero de la ville: ");
			scanf("%d", &nouvVal);
			ajouterVille(px, nouvVal);
			px = pdebutVille->villeSuivante;
			afficherListeVille(px);
			
		} else if (c == 2) {
			int nouvVal, ancienneVal;
			printf("Entrer le numero de la ville actuelle: ");
			scanf("%d", &ancienneVal);
			printf("Entrer le nouveau numero de la ville: ");
			scanf("%d", &nouvVal);
			px = pdebutVille->villeSuivante;
			modifierVille(px, ancienneVal, nouvVal);
			px = pdebutVille->villeSuivante;
			afficherListeVille(px);
			
		} else if (c == 3) {
			int valSupp;
			printf("Entrer le numero de la ville a supprimer: ");
			scanf("%d", &valSupp);
			px = pdebutVille->villeSuivante;
			supprimerVille(px, valSupp);
			px = pdebutVille->villeSuivante;
			afficherListeVille(px);
			
		} else if (c == 4) {
			
		} else if (c == 5) {
			
		} else if (c == 6) {
			
		} else if (c == 7) {
			
		} else if (c == 8) {
			
		} else if (c == 9) {
			
		}
	}
	
	return 1;
}
