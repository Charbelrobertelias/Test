
#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include "performance.h"

// Sauvegarde une performance dans un fichier
void sauvegarderPerformance(char* nom, Performance* performance);
// Lit l'historique des performances d'un athlète
void lireHistorique(char* nom);

#endif
