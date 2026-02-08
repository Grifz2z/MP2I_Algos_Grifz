#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/// ------------------------------------------------------------------- Tri par
/// sélection
/// ------------------------------------------------------------------------
/*
entrée : un tableau T
sortie : une permutation triée de T, en place

tri_selection(tableau t)
      n ← longueur(t)
      pour i de 0 à n - 2
          min ← i
          pour j de i + 1 à n - 1
              si t[j] < t[min], alors min ← j
          fin pour
          si min ≠ i, alors échanger t[i] et t[min]
      fin pour
  fin procédure
*/

void tri_selection(int *tab, int len) {
  int min, temp;

  for (int i = 0; i < len; i++) {
    min = i;
    // Recherce du minimum
    for (int j = i + 1; j < len; j++) {
      if (tab[j] < tab[min]) {
        min = j;
      }
    }
    // Echange du minimum de ce qui reste et de l'indice où on est
    if (min != i) {
      temp = tab[min];
      tab[min] = tab[i];
      tab[i] = temp;
    }
  }
}

// Deuxième version :
/*
i := 1
tant que i ≤ n faire :
    j := i
    k := i+1
    tant que k < n :
        si t[k] < t[j] :
            j := k
        finsi
        k := k+1
    fintantque
    t := Echanger (t, i, j)
    i := i+1
fintantque
 * */

void echanger(int *t, int i, int j) {
  int tmp = t[i];
  t[i] = t[j];
  t[j] = tmp;
}

void tri_selection2(int *tab, int n) {
  int i = 0;
  int j, mini;

  while (i < n) {
    mini = i;
    j = i + 1;
    while (j < n) {
      if (tab[j] < tab[mini]) {
        mini = j;
      }
      j++;
    }
    echanger(tab, i, j);
    i++;
  }
}

/// ---------------------------------------------------- Fonctions annexes (ne
/// pas les mettre sur le document)
/// ---------------------------------------------------
// Crée une chaîne de caractéres représentant le tableau t intégralement
char *str_tab(int *tab, int n) {
  char *chaine = malloc(12 * n + 4);
  char temp[32];

  chaine[0] = '\0';

  chaine = strcat(chaine, "[ ");

  for (int i = 0; i < n; i++) {
    // sprintf(buf, "%s\n"); pour convertir un int en char*
    sprintf(temp, "%d ", tab[i]);
    chaine = strcat(chaine, temp);
  }
  chaine = strcat(chaine, "]");
  return chaine;
}

int *tab_alea(int n) {
  int *tab = malloc(sizeof(int) * n);

  for (int i = 0; i < n; i++) {
    tab[i] = rand() % 11;
  }

  return tab;
}

int main(int argc, char *argv[]) {
  srand(time(NULL));

  // int* tab1 = tab_alea(10);
  int *tab2 = tab_alea(10);
  // char* s1 = str_tab(tab1, 10);
  char *s2 = str_tab(tab2, 10);

  // printf("Tableau 1 : %s\n", s1);
  printf("Tableau 2 : %s\n", s2);
  // free(s1);
  free(s2);

  // tri_insertion(tab1, 10);
  tri_selection(tab2, 10);

  // s1 = str_tab(tab1, 10);
  s2 = str_tab(tab2, 10);
  // printf("Tableau 1 avec tri_insertion: %s\n", s1);
  printf("Tableau 2 avec tri_selection: %s\n", s2);
  // free(s1);
  free(s2);

  return 0;
}
