#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




typedef struct fileChaine {
	char* s_chaine;
	struct fileChaine* p_suivant;
	struct fileChaine* p_precedent;
}Element;

typedef struct listeChaine{
	Element *element_debut;
	Element *element_fin;
	int n_taille;
}listeChaine;


void initFileChaine(listeChaine* liste);
int insertFileVide(listeChaine* liste, char* s_chaine);
int insertFileDebut(listeChaine* liste, char* s_chaine);
int insertListePos(listeChaine* liste, char* s_chaine, int pos);
int insertFileFin(listeChaine* liste, Element* element_courant, char* s_chaine);
int suppPosListe(listeChaine* liste, int n_pos);
void afficheListe(listeChaine* liste);
int getTailleListe(listeChaine* liste);
char* getPremierElement(listeChaine* liste);
char* getDernierElement(listeChaine* liste);
int suppDebutListe(listeChaine* liste);
int destuctListe(listeChaine* liste);
	
