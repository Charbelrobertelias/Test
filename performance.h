#ifndef PERFORMANCE_H
#define PERFORMANCE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "athlete.h"

// Structure représentant une performance
typedef struct {
    char date[11];
    char epreuve[50];
    float temps;
    int positionRelais; // -1 si ce n'est pas une épreuve de relais
} Performance;

// Crée une performance
Performance* creerPerformance(char* date, char* epreuve, float temps, int positionRelais);
// Affiche une performance
void afficherPerformance(Performance* performance);
// Ajoute un nouvel entraînement
void ajouterEntrainement();
// Consulte l'historique des entraînements
void consulterHistorique();
// Valide le format d'une date
int validerDate(char* date);
// Valide le format d'un temps
int validerTemps(float temps);
// Valide le nom d'une épreuve
int validerEpreuve(char* epreuve);

#endif
