#include "File.h"

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 780



int main(){

	SDL_Window* pWindow = NULL;

	SDL_Surface* pSurface = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL n'a pas pu etre initialiser! SDL_Error : %s\n", SDL_GetError());
	}
	else {
		pWindow = SDL_CreateWindow("An SDL2 window", 640, 480, WINDOW_WIDTH, WINDOW_HEIGHT,
			SDL_WINDOW_SHOWN);

		if (pWindow == NULL) {
			printf("La fenêtre n'a pas pu être créée! SDL_error : %s\n", SDL_GetError());
		}
		else {
			pSurface = SDL_GetWindowSurface(pWindow);
			
			SDL_Rect pRect;
			pRect.x = 100;
			pRect.y = 100;
			pRect.w = 200;
			pRect.h = 200;

			SDL_FillRect(pSurface, pRect, SDL_MapRGB(pSurface->format, 50, 150, 0) );

			SDL_UpdateWindowSurface(pWindow);
			SDL_Delay(3000);
		}
	}



	listeChaine* liste = NULL;
	liste = (listeChaine*)malloc(sizeof(listeChaine));

	initFileChaine(liste);


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