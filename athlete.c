#include "athlete.h"

Athlete* creerAthlete(char* nom, char* prenom, char* genre) {
    Athlete* athlete = (Athlete*) malloc(sizeof(Athlete));
    strcpy(athlete->nom, nom);
    strcpy(athlete->prenom, prenom);
    strcpy(athlete->genre, genre);
    return athlete;
}

void afficherAthlete(Athlete* athlete) {
    printf("Nom: %s, Prénom: %s, Genre: %s\n", athlete->nom, athlete->prenom, athlete->genre);
}


