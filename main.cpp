/*
\file [Werkle_Chevallley_Baudin_Labo08.cpp]
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
#include "Werkle_Chevalley_Baudin_Labo08_Fonction.h"


using namespace std;

int main() {

   vector<int> v1 = 0;
   vector<int> v2 = 0;

   int choixEx, val;
   string texteEnSortie;
   string texteChoixEx = "Veuillez choisir un exercice [1-8] et [0] pour quitter : ";

   do {
      saisieValeur(texteChoixEx, choixEx);

      while(cin.fail() || choixEx < 0 || choixEx > 6)
      {
         viderSaisie(texteChoixEx, choixEx);
      }

      switch (choixEx) {
         case 1:
         {
            texteEnSortie = "Veuillez saisir une valeur entiere a inserer dans "
            "le tableau 1 : ";

            saisieValeur(texteEnSortie, val);

            while(cin.fail())
            {
               viderSaisie(texteEnSortie, val);
            }

            inserer(table1, N, val);
            break;
         }
         case 2:
         {
            afficherTableau(table1, table2, N);
            break;
         }
         case 3:
         {
            copieTable1Table2(v1, v2);
            break;
         }
         case 4:
         {
            supprimerDoublons(table1, N);
            break;
         }
         case 5:
         {
            supprimerValeursPaires(table1, N);
            break;
         }
         case 6:
         {
            changerValTable2(table2, N);
            break;
         }
      }
   } while (choixEx != 0);

   cout << "Fin du Labo 08" << endl;

   return EXIT_SUCCESS;
}



