#ifndef PERFORMANCE_H
#define PERFORMANCE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "athlete.h"

typedef struct {
    char date[11];
    char epreuve[50];
    float temps;
    int positionRelais; // -1 si ce n'est pas une épreuve de relais
} Performance;

Performance* creerPerformance(char* date, char* epreuve, float temps, int positionRelais);
void afficherPerformance(Performance* performance);
void ajouterEntrainement();
void consulterHistorique();
void consulterStats();

#endif
