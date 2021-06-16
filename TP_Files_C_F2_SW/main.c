#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "File.h"



int main() {

	listeChaine* liste = NULL;
	liste = (listeChaine*)malloc(sizeof(listeChaine));

	initFileChaine(liste);

	//int choix = -1;

	/*while (choix != 0) {
		printf("Veuillez choisir l'action a faire.\n1. Ajouter un premier element.\n2. Ajouter un element.\n3. Supprimer un element.\n4. Afficher la liste.\n5. Afficher la taille de la liste.\n");
		scanf("%d", &choix);
		switch (choix){
			case 1 :

		}
	}*/

	if (insertFileVide(liste, "je ")) {
		printf("Insert dans liste vide ok.\n");
	}

	if (insertFileDebut(liste, "Bonjour, ")) {
		printf("Insert en debut de liste ok.\n");
	}
	if (liste && insertFileFin(liste, liste->element_fin, "Stephane.")) {
		printf("Insert en fin de liste ok.\n");
	}

	if (insertListePos(liste, "m'appelle ", 3)) {
		printf("Insert a la position 3 ok.\n");
	}

	afficheListe(liste);

	printf("Taille de la liste : %i.\n", getTailleListe(liste));
	printf("Premier element de liste : %s.\n", getPremierElement(liste));
	printf("Dernier element de liste : %s.\n", getDernierElement(liste));

	destuctListe(liste);

	free(liste);
	

	return 0;
}