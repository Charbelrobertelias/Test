#ifndef STATS_H
#define STATS_H

// Affiche les statistiques des performances d'un athlète pour une épreuve donnée
void afficherStats(char* nom, char* epreuve);
// Affiche les trois meilleurs athlètes pour chaque épreuve et les envoie aux JO
void envoyerAuxJO();
// Affiche la progression d'un athlète pour une même épreuve entre deux dates
void afficherProgression(char* nom, char* epreuve, char* date1, char* date2);

#endif
