#ifndef ATHLETE_H
#define ATHLETE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure représentant un athlète
typedef struct {
    char nom[50];
    char prenom[50];
} Athlete;

// Crée un athlète
Athlete* creerAthlete(char* nom, char* prenom);
// Affiche les informations d'un athlète
void afficherAthlete(Athlete* athlete);

#endif
