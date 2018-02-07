#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct {
  int taillemax; // nombre maximum d'éléments dans la file
  int taille; 	// nombre d'éléments actuels dans la file
  int tete; // indice du prochain élément à dépiler
	int queue;	// indice du dernier élément empilé
	char* tableau; 	// adresse du tableau de la file
} File ;

File * initialiser(int taillemax) {
  // renvoit une nouvelle file (vide) intitialisée
  File file = malloc(sizeof(File));
  if(file) {
    file->tableau = malloc(sizeof(char) * taillemax);
    if(!file->tableau) {
      printf("L'allocation de mémoire de la pile n'a pas fonctionné.\n");
    }
    else {
      file->taillemax = taillemax;
      file->taille = 0;
      file->tete = 0;
      file->queue = -1;
    }
  }
  return file;
}

void freeFile(File *file) {
  // désalloue la file et ce qu’elle contient
  free(file->tableau);
  free(file);
}

bool fileVide(File *file) {
  return file->taille == 0;
}

bool filePleine(File *file) {
  return file->taille == file->taillemax;
}

char tete(File *file) {
  // renvoit la valeur de l’élément stocké en tête de la file
  return file->tableau[file->tete];
}

char* queue(File *file) {
  // renvoit l'adresse de l'élément stocké en queue de la file
  return &(file->tableau[file->queue]);
}

bool enfiler(File *file, char element) {
  // retourne vrai si l’enfilage a réussi
  ++file->queue %= file->taillemax //incrémentation de l'indice; si l'indice est égal à la taille max alors file->queue = 0
  file->tableau[file->queue] = element;
  return true;
}

bool defiler(/* À COMPLÉTER */) {
  // retourne vrai si le defilage a réussi

}

void afficher(File *file) {
  int compteur;
  printf("File :\n\t[ ");
  if(file->taille > 0) {
    for(compteur = 0; compteur < file->taille; compteur++) {
      if(file->queue >= file->taillemax) {
        file->queue = 0;
      }
      printf("%c | ", file->tableau[compteur]);
    }
    printf("%c ]\n", file->tableau[compteur]);
  }
  else {
    printf("]\n");
  }
}
