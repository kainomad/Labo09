/*
\file [Werkle_Chevalley_Baudin_Labo08_Fonction.cpp]
\brief { Ce programme proposera 8 petits exercices de manipulations de tableaux en
 *       fontion de la saisie utilisateur (1-8)}
\details { 1) Permet de saisir des valeurs entières croissantes dane le 1er tableau
 *         2) Permet d'afficher le contenu des 2 tableau à une dimension
 *         3) Copie les valeurs du premier tableau vers le second, tous les 2
 *            à une dimension.
 *         4) Supprime les doublons du premier tableau
 *         5) Enlève toutes les valeures paires du premier tableau
 *         6) Echange les valeurs consécutives dans le deuxième tableau.
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
#include <vector>
#include "Werkle_Chevalley_Baudin_Labo08_Fonction.h"

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

void copieTable1Table2(vector<int> v1, vector<int> v2) {

   vector<int> v2(v1);
}

void changerValTable2(vector<int> v2) {

   if (v2.size() % 2 == 0) {
      
      for (size_t i = 0; i < v2.size(); i = i + 2) {
         int tmp = v2.at(i) + v2.at(i + 1);
         v2.at(i) = tmp - v2.at(i);
         v2.at(i + 1) = tmp - v2.at(i + 1);
      }
   }
   if (v2.size() % 2 != 0) {
      for (size_t i = 0; i < v2.size() - 1; i = i + 2) {
         int tmp = v2.at(i) + v2.at(i + 1);
         v2.at(i) = tmp - v2.at(i);
         v2.at(i + 1) = tmp - v2.at(i + 1);
      }
      v2.at(v2.size() - 1) = v2.at(v2.size() - 1);
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

