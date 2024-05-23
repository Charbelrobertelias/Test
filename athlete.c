#include "athlete.h"

// Crée un athlète et initialise ses informations
Athlete* creerAthlete(char* nom, char* prenom) {
    Athlete* athlete = (Athlete*) malloc(sizeof(Athlete));
    strcpy(athlete->nom, nom);
    strcpy(athlete->prenom, prenom);
    return athlete;
}

// Affiche les informations d'un athlète
void afficherAthlete(Athlete* athlete) {
    printf("Nom: %s, Prénom: %s\n", athlete->nom, athlete->prenom);
}
