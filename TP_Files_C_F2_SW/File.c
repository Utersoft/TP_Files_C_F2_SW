#include "File.h"


//But : initialisation de la chaine à vide
void initFileChaine(listeChaine* liste)
{
	liste->element_debut = NULL;
	liste->element_fin = NULL;
	liste->n_taille = 0;
}

//But : insérer un élément dans une chaine vide
int insertFileVide(listeChaine* liste, char* s_chaine)
{	
	Element* element = NULL;
	element = (Element*)malloc(sizeof(Element));
	//On vérifie qu'element existe avant de d'attribuer de la place à s_chaine
	if (element) {
		element->s_chaine = (char*)malloc(30 * sizeof(char));
	}
	
	//On vérifie qu'element ou s_chaine ne sont pas null avant d'intégrer l'élément et son contenu dans la liste
	if (element == NULL) {
		return 0;
	}
	else if (element->s_chaine == NULL){
		return 0;
	}else{
		//On entre la chaine dans l'élément puis on insére l'élément dans la liste vide
		strcpy_s(element->s_chaine, strlen(s_chaine) + 1, s_chaine);
		element->p_precedent = NULL;
		element->p_suivant = NULL;
		liste->element_debut = element;
		liste->element_fin = element;
		liste->n_taille++;

		return 1;
	}
}

//but insérer un élément en début de liste
int insertFileDebut(listeChaine* liste, char* s_chaine)
{
	Element* nouvel_element = NULL;
	nouvel_element = (Element*)malloc(sizeof(Element));
	
	//On vérifie qu'element existe avant de d'attribuer de la place à s_chaine
	if (nouvel_element) {
		nouvel_element->s_chaine = (char*)malloc(30 * sizeof(char));
	}
	
	//On vérifie qu'element ou s_chaine ne sont pas null avant d'intégrer l'élément et son contenu dans la liste
	if (nouvel_element == NULL) {
		return 0;
	}
	else if (nouvel_element->s_chaine == NULL){
		return 0;
	} else {

		//On entre la chaine dans l'élément puis on insére l'élément en premier position
		strcpy_s(nouvel_element->s_chaine, strlen(s_chaine) + 1, s_chaine);
		nouvel_element->p_precedent = NULL;
		nouvel_element->p_suivant = liste->element_debut;
		
		liste->element_debut = nouvel_element;
		liste->element_debut->p_suivant->p_precedent = nouvel_element;
		liste->n_taille++;

		return 1;
	}
}

//but : insérer un element à une certaine position dans la liste
int insertListePos(listeChaine* liste, char* s_chaine, int n_pos)
{
	//On vérifie que la liste a au moins 2 element sinon on quitte la fonction, on preferera utiliser les fonction debut ou fin au lieu de celle-ci pour ajouter un element dans ce cas
	if (liste->n_taille < 2) {
		return 0;
	}

	//On verifie que l'utilisateur n'a pas rentré de valeur erronée (plus grande que la liste ou inférieur à 1 (premier element))
	if (n_pos > liste->n_taille || n_pos < 1) {
		return 0;
	}
	
	Element* nouvel_element = NULL;
	Element* element_courant = NULL;
	nouvel_element = (Element*)malloc(sizeof(Element));
	
	//on vérifie que nouvel_element existe avant de mettre la chaine
	if (nouvel_element) {
		nouvel_element->s_chaine = (char*)malloc(30 * sizeof(char));
	}
	

	element_courant = liste->element_debut;

	//On vérifie qu'element ou s_chaine ne sont pas null avant d'intégrer l'élément et son contenu dans la liste
	if (nouvel_element == NULL) {
		return 0;
	}else if (nouvel_element->s_chaine == NULL){
		return 0;
	}else{
		//On cherche l'emplacement de l'élément pour pouvoir insérer le nouvel élément à cette endroit là
		for (int n_i = 1; n_i < n_pos - 1; n_i++) {
			element_courant = element_courant->p_suivant;
		}
		
		if (element_courant->p_suivant == NULL) {
			return 0;
		}

		//On entre la chaine dans l'élément puis on insére l'élément à la place de l'élément présent qu'on place à la suite
		strcpy_s(nouvel_element->s_chaine, strlen(s_chaine) + 1, s_chaine);
		nouvel_element->p_suivant = element_courant->p_suivant;
		nouvel_element->p_precedent = element_courant;
		element_courant->p_suivant = nouvel_element;

		liste->n_taille++;

		return 1;
	}
}


//but : insérer un élément en fin de liste
int insertFileFin(listeChaine* liste, Element* element_courant, char* s_chaine)
{
	Element* nouvel_element = NULL;
	nouvel_element = (Element*)malloc(sizeof(Element));

	if (nouvel_element) {
		nouvel_element->s_chaine = (char*)malloc(30 * sizeof(char));
	}

	//On vérifie qu'element ou s_chaine ne sont pas null avant d'intégrer l'élément et son contenu dans la liste
	if (nouvel_element == NULL) {
		return 0;
	}
	else if (nouvel_element->s_chaine == NULL) {
		return 0;
	}
	else {
		//On entre la chaine dans l'élément puis on insére l'élément à la fin de la liste
		strcpy_s(nouvel_element->s_chaine, strlen(s_chaine) + 1, s_chaine);
		element_courant->p_suivant = nouvel_element;
		nouvel_element->p_suivant = NULL;
		nouvel_element->p_precedent = element_courant;
		liste->element_fin = nouvel_element;

		liste->n_taille++;

		return 1;
	}
}

//but : on supprime un élément à un emplacement donné
int suppPosListe(listeChaine* liste, int n_pos)
{
	if (liste->n_taille <= 1 || n_pos < 1 || n_pos >= liste->n_taille) {
		return 0;
	}

	Element* suppression = NULL;
	Element* element_courant = NULL;

	element_courant = liste->element_debut;

	for (int n_i = 1; n_i < n_pos - 1; n_i++) {
		element_courant = element_courant->p_suivant;
	}

	suppression = element_courant->p_suivant;
	element_courant->p_suivant = element_courant->p_suivant->p_suivant;

	if (element_courant->p_suivant == NULL) {
		liste->element_fin = element_courant;
	}

	if (suppression) {
		free(suppression->s_chaine);
	}
	free(suppression);
	
	liste->n_taille--;

	return 1;
}


//but afficher la liste complète
void afficheListe(listeChaine* liste)
{
	Element* tmp_element = liste->element_debut;
	int n_i = 0;
	while(tmp_element != NULL) {
		n_i++;
		printf("Element %i de la liste : %s\n", n_i, tmp_element->s_chaine);
		tmp_element = tmp_element->p_suivant;
	}

	free(tmp_element);
}

//but : récupérer la taille de la liste
int getTailleListe(listeChaine* liste)
{
	return liste->n_taille;
}

//but : récupérer le string du premier element
char* getPremierElement(listeChaine* liste)
{
	return liste->element_debut->s_chaine;
}

//but : réucpérer le string du dernier element
char* getDernierElement(listeChaine* liste)
{
	return liste->element_fin->s_chaine;
}

//On supprime le premier element de la liste
int suppDebutListe(listeChaine* liste)
{
	if (liste->n_taille == 0) {
		return 0;
	}

	Element* suppression = NULL;
	suppression = liste->element_debut;
	liste->element_debut = liste->element_debut->p_suivant;

	if (liste->n_taille == 1) {
		liste->element_fin = NULL;
	}

	if (suppression) {
		free(suppression->s_chaine);
	}

	free(suppression);

	liste->n_taille--;

	return 1;
}

//but : supprimer la liste par le debut (FIFO)
int destuctListe(listeChaine* liste)
{
	if (liste->n_taille == 0) {
		return 0;
	}

	while (liste->n_taille > 0) {
		suppDebutListe(liste);
	}

	return 1;
}


