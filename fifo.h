#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct {
  int taille; 	// nombre d'éléments maximum dans la pile
	int queue;	// indice du sommet de la pile (dernier élément empilé)
	int *adresse; 	// adresse de la base de la pile
} File ;

File * initialiser(int taille) ;
    // renvoit une nouvelle file (vide) intitialisée

void freeFile(File *file) ;
    // désalloue la file et ce qu’elle contient

bool fileVide(File *file) ;

bool filePleine(File *file);

char tete(File *file) ;
    // renvoit la valeur de l’élément stocké en tête de la file

char * queue(File *file) ;
    // renvoit l'adresse de l'élément stocké en queue de la file

bool enfiler(File *file, char element) ;
    // retourne vrai si l’enfilage a réussi

/* À COMPLÉTER */ defiler(/* À COMPLÉTER */) ;
    // retourne vrai si le defilage a réussi

void afficher(File *file) ;
