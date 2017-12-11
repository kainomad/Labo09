/*
\file [Werkle_Chevalley_Baudin_Labo08_Fonction.h]
\brief { Ce programme proposera 8 petits exercices de manipulations de tableaux en
 *       fontion de la saisie utilisateur (1-8)}
\details { 1) Permet de saisir des valeurs entières croissantes dane le premier tableau
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

using namespace std;

const int N = 7;

/**
 * \brief Fonction de copie de table vers table2
 * \param[in] table1
 * \param[in] table 2
 * \param[in] N entier qui définit la taille des tableaux
 *
 * Cette Fonction permet de copier toutes les valeurs de table1 vers table2
 */
void copieTable1Table2(int table1[], int table2[], int N);

/**
 * \brief Fonction de changement de valeur dans table2
 * \param[in] table2
 * \param[in] N entier qui définit la taille du tableau
 *
 * Cette Fonction permet d'intervertir toutes les valeurs consécutives 2 à 2
 * dans table2
 */
void changerValTable2(int table2[], int N);

/**
 * \brief Fonction d'affichage des valeurs des tableaux
 * \param[in] table 1
 * \param[in] table 2
 * \param[in] N entier qui définit la taille du tableau
 *
 * Cette Fonction permet d'afficher les valeurs de table1 et table2
 */
void afficherTableau( int table1[], int table2[], int N);

/**
 \brief Insère une valeur dans un tableau
 * \param[in] tab contient un tableau de numériques entiers
 * \param[in] N contient la taille du tableau
 * \param[in] val contient la valeur à insérer
 *
 * Insère dans un tableau une valeur numérique en respectant l'ordre
 * de croissance
 */
void inserer(int tab[], const int N, int val);

/**
 \brief Supprime les doublons d'un tableau
 * \param[in] tab contient un tableau de numériques entiers
 * \param[in] N contient la taille du tableau
 *
 * Supprime dans un tableau les doublons et remplace les valeurs laissées vides par
 * des 0
 */
void supprimerDoublons(int tab[], const int N);

/**
 \brief Supprime les valeurs paires d'un tableau
 * \param[in] table1 contient un tableau de numériques entiers
 * \param[in] N contient la taille du tableau
 *
 * Parcourt le tableau et supprime les valeurs paires de celui-ci.
 */
void supprimerValeursPaires(int table1[], int N);

/**
 \brief vide la saisie faite précédemment dans le cin
 * \param[in] texteEnSortie contient le texte libellé associé
 * \param[in] val contient la valeur à resaisir
 *
 * vide une saisie erronée faite précédemment dans le cin
 */
void viderSaisie(string& texteEnSortie, int& val);

/**
 \brief saisie d'une valeur
 * \param[in] texteEnSortie contient le texte libellé associé
 * \param[in] val contient la valeur à saisir
 *
 * Saisie d'une valeur avec un texte libellé associé
 */
void saisieValeur(string& texteEnSortie, int& val);

/**
 \brief saisie d'une valeur
 * \param[in] tab contient un tableau de numériques entiers
 * \param[in] N contient la taille du tableau
 * \param[in] val contient la valeur de laquelle ont souhaite connaître la position
 * \return la position à laquelle la valeur viendra s'insérer, basé sur l'algorithme
 * de la fonction inserer(int tab[], const int N, int val)
 *
 * Détermine la position à laquelle un entier viendra s'insérer dans
 * un tableau en respectant un ordre croissant
 */
int positionOrdreCroissant (int tab[], int N, int val);