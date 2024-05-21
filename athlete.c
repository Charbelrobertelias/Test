#ifndef ATHLETE_H
#define ATHLETE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nom[50];
    char prenom[50];
    char genre[10];
} Athlete;

Athlete* creerAthlete(char* nom, char* prenom, char* genre);
void afficherAthlete(Athlete* athlete);

#endif
