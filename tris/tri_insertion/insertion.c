#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
entrée : un tableau T
sortie : une permutation triée de T, en place

tri_insertion(tableau T)
  pour i de 1 à taille(T) - 1
    x ← T[i]                       // mémoriser T[i] dans x
    j ← i                          // Décaler les éléments T[0]..T[i-1] qui sont
                                   // plus grands que x, en partant de T[i-1]

    tant que j > 0 et T[j - 1] > x
      T[j] ← T[j - 1] j ← j - 1    // Placer x dans le "trou"
    fintannque                     // laissé par le décalage
   T[j] ←x
  finpour
*/

void tri_insertion(int *tab, int len) {
  int x, j;

  for (int i = 0; i < len; i++) {
    // On prend l'élement actuel de tab
    x = tab[i];
    j = i;

    // Tant que les élements avant x sont plus grands, on les décale vers la
    // gauche
    while (j > 0 && tab[j - 1] > x) {
      tab[j] = tab[j - 1];
      j--;
    }

    tab[j] = x; // On remet x à sa place
  }
}

/// ------------------------------------------------------
/// Fonctions annexes (ne pas les mettre sur le document)
/// ------------------------------------------------------

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

  int *tab1 = tab_alea(10);
  // int* tab2 = tab_alea(10);
  char *s1 = str_tab(tab1, 10);
  // char* s2 = str_tab(tab2, 10);

  printf("Tableau 1 : %s\n", s1);
  // printf("Tableau 2 : %s\n", s2);
  free(s1);
  // free(s2);

  tri_insertion(tab1, 10);
  // tri_selection(tab2, 10);

  s1 = str_tab(tab1, 10);
  // s2 = str_tab(tab2, 10);
  printf("Tableau 1 avec tri_insertion: %s\n", s1);
  // printf("Tableau 2 avec tri_selection: %s\n", s2);
  free(s1);
  // free(s2);

  return 0;
}
