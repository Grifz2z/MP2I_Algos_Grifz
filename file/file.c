/* ***************************************************************************
 */
/*                                                                             */
/*        Alvarez Martinez Anton */
/*        Algorithmes au programme de MP2I */
/*                                                                             */
/*        Implémentation des files en langage C */
/*                                                                             */
/*        1ère partie : (i)  Implémentation naïve par maillons chaînés */
/*                      (ii) Indice de début et fin */
/*        2nde partie : file de taille bornée – utilisation de tableaux */
/*                                                                             */
/* ***************************************************************************
 */

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

/* 1 (i) - Maillons chaînés */

// Défintion du type
typedef struct sMaillon {
  int data;
  struct sMaillon *queue;
} maillon;

// Algos

/// Retour : vrai si la pile est vide, faux sinon
bool estVide1(maillon *f) { return (f == NULL); }

/// Initialise une pile (maillon) à vide et renvoie un pointeur dessus
maillon *creerVide1() { return NULL; }

/// Initialise une tete de file seule avec un élement e
maillon *creerTete1(int e) {
  maillon *f = malloc(sizeof(maillon));
  f->data = e;
  f->queue = NULL;
  return f;
}

/// Retour : ∅ ; Enfile un maillon à la tête de la liste
void enfiler1(maillon **f, int e) {
  maillon *der = malloc(sizeof(maillon));
  der->data = e;
  der->queue = NULL;

  if (estVide1(*f)) {
    *f = der;
    return;
  }

  maillon *tmp = *f;

  while (tmp->queue != NULL) {
    tmp = tmp->queue;
  }

  tmp->queue = der;
}

// Retour : Maillon en tête de file sous preuve d'existence, lève une erreur
// sinon
int defiler1(maillon **f) {
  assert(!(estVide1(*f)));

  maillon *tmp = (*f)->queue;
  int data = (*f)->data;
  free(*f);

  *f = tmp;
  return data;
}

/* 2 (ii) - avec deux indices */

// Défintion des type
typedef struct sMaillon1 {
  int data;
  struct sMaillon1 *suivant;
} maillon;

typedef struct sFile {
  maillon *tete;
  maillon *queue;
} file;

// Algos

bool estVide(file *f) { return f->tete == NULL; }

file *creerVide() {
  file *f = malloc(sizeof(file));
  f->tete = NULL;
  f->queue = NULL;

  return f;
}

void enfiler(file *f, int e) {
  maillon *nouveau = malloc(sizeof(maillon));
  nouveau->data = e;
  nouveau->suivant = NULL;

  if (estVide(f)) {
    f->tete = nouveau;
    f->queue = nouveau;
    return;
  }

  f->tete->suivant = nouveau;
  f->tete = nouveau;
}

int defiler(file *f) {
  assert(!estVide(f));

  maillon *tmp = f->queue;
  int res = tmp->data;

  if (tmp->suivant == NULL) {
    f->queue = NULL;
    f->tete = NULL;
  } else {
    f->queue = f->queue->suivant;
  }

  free(tmp);
  return res;
}

/* 2 - File de taille bornée (tableaux statiques)*/

const int TAILLE = 10;

typedef struct {
  int *tab;
  int tete;
  int queue;
  int taille;
} fileStat;

bool estVideStat(fileStat *f) { return f->taille == 0; }

bool estPleineStat(fileStat *f) { return f->taille == TAILLE; }

fileStat *creerVideStat(int *tab) {
  fileStat *f = malloc(sizeof(fileStat));
  f->tab = tab;
  f->tete = 0;
  f->queue = 0;
  f->taille = 0;
  return f;
}

void enfilerStat(fileStat *f, int e) {
  assert(!estPleineStat(f));

  f->tab[f->queue] = e;
  f->queue = (f->queue + 1) % TAILLE;
  f->taille++;
}

int defilerStat(fileStat *f) {
  assert(!estVideStat(f));

  int val = f->tab[f->tete];
  f->tete = (f->tete + 1) % TAILLE;
  f->taille--;

  return val;
}
