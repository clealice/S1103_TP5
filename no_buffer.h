#include <stdio.h>

// Bibliothèque permettant de capturer des frappes de touche isolées
// Ne fonctionne que sous (certains) *nix, à compiler avec les options POSIX :
// gcc -c *.c -Wall -std=c99 -D_POSIX_C_SOURCE=200112L
// Toute cette bibliothèque est inspirée de : http://c-faq.com/osdep/cbreak.html

int tty_break() ;
    // À lancer avant la saisie

int tty_getchar() ;
    // Le getchar dont on a besoin pour ne pas avoir à attendre <Entrée>

int tty_fix() ;
    // À lancer en fin de programme pour restaurer l’état de la console
