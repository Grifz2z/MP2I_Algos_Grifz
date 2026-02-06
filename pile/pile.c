/* ***************************************************************************
 */
/*                                                                             */
/*        Alvarez Martinez Anton */
/*        Algorithmes au programme de MP2I */
/*                                                                             */
/*        Implémentation des piles en langage C */
/*                                                                             */
/*        1ère partie : Implémentation naïve par maillons chaînés */
/*        2nde partie : Pile de taille bornée – utilisation de tableaux */
/*                                                                             */
/* ***************************************************************************
 */

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

/* 1 - Maillons chaînés */

// Défintion du type
typedef struct sMaillon {
  int data;
  struct sMaillon *queue;
} maillon;

// Algos

/// Retour : vrai si la pile est vide, faux sinon
bool estVide(maillon *p) { return (p == NULL); }

/// Initialise une pile (maillon) à vide et renvoie un pointeur dessus
maillon *creerVide() {
  maillon *pile = malloc(sizeof(maillon));
  return pile;
}

/// Empile un nouvel élement dans la pile
void empiler(maillon *p, int e) {
  maillon *new = malloc(sizeof(maillon));

  new->data = e;
  new->queue = p;

  p = new;
}

/// Retour : Dernier élément ajouté dans la liste ; Modification en place de p
/// pour enlever l'élement retourné la pile pour qu
int depiler(maillon *p) {
  assert(!estVide(p));

  int tmp = p->data;
  maillon *q = p->queue;
  free(p);
  p = q;
  return tmp;
}

/* 2 - Pille de taille bornée */

int N = 10; // Taille de la pile

typedef struct {
  int data[10]; // Taille arbitraire
  int sommet;   // indice choisi pour faire office de sommet
} pile;

bool estVide(pile *p) { return true; }
