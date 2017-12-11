/*
\file [Werkle_Chevalley_Baudin_Labo09_Fonction.cpp]
\brief { Ce programme proposera 8 petits exercices de manipulations de tableaux en
 *       fontion de la saisie utilisateur (1-8)}
\details { 1) Permet de saisir des valeurs entières croissantes dane le 1er tableau
 *         2) Permet d'afficher le contenu des 2 tableau à une dimension
 *         3) Copie les valeurs du premier tableau vers le second, tous les 2
 *            à une dimension.
 *         4) Supprime les doublons du premier tableau
 *         5) Enlève toutes les valeures paires du premier tableau
 *         6) Echange les valeurs consécutives dans le deuxième tableau.
 *         7) Copie les valeurs de du deuxième tableau dans la ième colone du
 *            tableau à 2 dimensions, puis affiche ses valeurs ligne par ligne.
 *         8) Modifie le tableau à 2 dimensions pour obtenir une symétrie de la
 *            diagonale partant de la partie supérieur gauche vers la partie
 *            inférieure droite. }
 *
\author { Werkle Johann, Chevalley Gaël, Baudin Fanny }
\date { 06.12.2017 }
\version { 1.0 }
\copyright { © CamelSoft }
 */

#include <cstdlib>
#include <climits>
#include <iostream>
#include <string>
#include "Werkle_Chevalley_Baudin_Labo09_Fonction.h"

void inserer(int tab[], const int N, int val) {
   int positionInsertion;
   bool positionAssignee = false;

   //Cas où le tableau contient encore des valeurs vides (donc des 0)
   for (int i = 0; i < N - 2; i++) {
      if (!positionAssignee) {
         if (tab[0] == 0 && tab[N - 1] == 0) {
            positionInsertion = i;
            positionAssignee = true;
         } else if (val >= tab[i] && tab[i + 1] == 0) {
            positionInsertion = i + 1;
            positionAssignee = true;
         } else if (val < tab[i] && tab[i + 1] == 0) {
            positionInsertion = i;
            positionAssignee = true;
         }
      }
   }

   //Cas où le tableau a déjà été intégralement remplis
   if (!positionAssignee) {
      positionInsertion = positionOrdreCroissant(tab, N, val);
   }
   //Décale vers la droite les valeurs du tableau supérieures à la valeur à insérer
   for (int i = N - 1; i >= positionInsertion; i--) {
      tab[i] = tab[i - 1];
   }


   //Insère la valeur dans le tableau en respectant l'ordre croissant
   tab[positionInsertion] = val;
}

int positionOrdreCroissant(int tab[], int N, int val) {
   int position = 0;

   //affecte la position du tableau à laquelle la valeur viendra s'insérer
   for (int i = 0; i < N; i++) {

      //Cas où 1a val à insérer est la plus petite de tout le tableau
      if (i == 0 && val < tab [i]) {
         position = 0;
      }//Cas où 1a val à insérer est la plus grande de tout le tableau
      else if (i == N - 1 && val > tab [i]) {
         position = N - 1;
      }//Cas où la val à insérer est située entre 2 val du tableau
      else if ((val == tab[i] && val < tab[i + 1]) || (val > tab[i] && val < tab[i + 1])) {
         position = i + 1;
      }
   }

   return position;
}

void supprimerDoublons(int tab[], const int N) {

   for (int i = 0; i < N - 1; i++) {

      //Compare la valeur de i avec toutes les suivantes du tableau et au besoin
      for (int j = i; j < N - 1; j++) {

         //Cas spécifique où le tableau commence par un triple (ou +) même nombre
         if (j == 1) {
            if (tab[j] == tab[j - 1]) {
               //Décalage des valeurs vers la gauche pour écraser le doublon
               for (int k = j - 1; k < N - 1; k++) {
                  tab[k] = tab[k + 1];
               }
               tab[N - 1] = 0;
            }
         }

         if (tab[j] == tab[j + 1]) {
            //Décalage des valeurs vers la gauche pour écraser le doublon
            for (int k = j; k < N - 1; k++) {
               tab[k] = tab[k + 1];
            }
            tab[N - 1] = 0;
         }
      }
   }
}

void insertionColonne(int tab[], int tabDeuxDim[][N], const int N, int val) {
   //La colonne choisie prend les valeurs du tableau 2
   for (int i = 0; i < N; i++) {
      tabDeuxDim[i][val - 1] = tab[i];
   }

   //Affiche le tableau mutidimentionnel
   for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
         cout << tabDeuxDim[i][j] << " ";

         if (j == N - 1) {
            cout << endl;
         }
      }
   }
}

void copieTable1Table2(int table1[], int table2[], int N) {
   for (int i = 0; i < N; i++) {
      table2[i] = table1[i];
   }

}

void changerValTable2(int table2[], int N) {

   if (N % 2 == 0) {
      for (int i = 0; i < N; i = i + 2) {
         int tmp = table2[i] + table2[i + 1];
         table2[i] = tmp - table2[i];
         table2[i + 1] = tmp - table2[i + 1];
      }
   }
   if (N % 2 != 0) {
      for (int j = 0; j < N - 1; j = j + 2) {
         int tmp = table2[j] + table2[j + 1];
         table2[j] = tmp - table2[j];
         table2[j + 1] = tmp - table2[j + 1];
      }
      table2[N - 1] = table2[N - 1];
   }
}

void afficherTableau(int table1[], int table2[], int N) {

   cout << "table1 : " << endl;

   for (int i = 0; i < N; i++) {
      cout << table1[i] << " ";
   }
   cout << endl;
   cout << "table2 : " << endl;
   for (int i = 0; i < N; i++) {
      cout << table2[i] << " ";
   }
   cout << endl;
}

void supprimerValeursPaires(int table1[], int N) {
   int tabTemp[N] = {};
   int j = 0;

   //Stock dans le tableau temporaire les valeurs impairs
   for (int i = 0; i < N; i++) {
      if (table1[i] % 2 != 0) {
         tabTemp[j] = table1[i];
         j++;
      }
   }

   //Assigne les valeurs du tableau temporaires à table1 pour n'avoir
   //plus que les valeurs impairs
   for (int i = 0; i < N; i++) {
      table1[i] = tabTemp[i];
   }
}

void inversionTableau2D(int table2Dim[][N], int N) {
   int tampon;
   for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
         if (i > j) {
            tampon = table2Dim[i][j];
            table2Dim[i][j] = table2Dim[j][i];
            table2Dim[j][i] = tampon;

         }
      }
   }
   //Afichage du tableau, nécessaire pour effectuer les tests
   for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
         cout << table2Dim[i][j] << " ";

         if (j == N - 1) {
            cout << endl;
         }
      }
   }
}

void saisieValeur(string& texteEnSortie, int& val) {
   cout << texteEnSortie;
   cin >> val;
}

void viderSaisie(string& texteEnSortie, int& val) {
   cin.clear();
   cin.ignore(INT_MAX, '\n');
   cout << "Erreur" << endl;
   saisieValeur(texteEnSortie, val);
}

