#include "performance.h"
#include "file_utils.h"
#include "stats.h"

Performance* creerPerformance(char* date, char* epreuve, float temps, int positionRelais) {
    Performance* performance = (Performance*) malloc(sizeof(Performance));
    strcpy(performance->date, date);
    strcpy(performance->epreuve, epreuve);
    performance->temps = temps;
    performance->positionRelais = positionRelais;
    return performance;
}

void afficherPerformance(Performance* performance) {
    printf("Date: %s, Epreuve: %s, Temps: %.2f", performance->date, performance->epreuve, performance->temps);
    if (performance->positionRelais != -1) {
        printf(", Position Relais: %d", performance->positionRelais);
    }
    printf("\n");
}

int validerDate(char* date) {
    int annee, mois, jour;
    if (sscanf(date, "%4d-%2d-%2d", &annee, &mois, &jour) != 3) {
        return 0; // Format incorrect
    }
    if (annee < 1900 || annee > 2100 || mois < 1 || mois > 12 || jour < 1 || jour > 31) {
        return 0; // Valeurs invalides
    }
    // Vérification des jours par mois
    if ((mois == 4 || mois == 6 || mois == 9 || mois == 11) && jour > 30) {
        return 0; // Mois de 30 jours
    }
    if (mois == 2) {
        // Vérification des années bissextiles
        int bissextile = (annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0);
        if (jour > 29 || (jour == 29 && !bissextile)) {
            return 0; // Février trop de jours
        }
    }
    return 1; // Date valide
}

int validerTemps(float temps) {
    if (temps > 0 && temps < 86400) { // Vérifie que le temps est positif et raisonnable (< 24 heures)
        return 1;
    }
    return 0;
}

int validerEpreuve(char* epreuve) {
    const char* epreuves[] = {"100m", "400m", "5000m", "marathon", "relais"};
    for (int i = 0; i < 5; i++) {
        if (strcmp(epreuve, epreuves[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int validerGenre(char* genre) {
    if (strcmp(genre, "Homme") == 0 || strcmp(genre, "Femme") == 0) {
        return 1;
    }
    return 0;
}

void ajouterEntrainement() {
    char nom[50], prenom[50], genre[10], date[11], epreuve[50];
    float temps;
    int positionRelais = -1;

    printf("Nom: ");
    scanf("%s", nom);
    printf("Prénom: ");
    scanf("%s", prenom);
    
    do {
        printf("Genre (Homme/Femme): ");
        scanf("%s", genre);
        if (!validerGenre(genre)) {
            printf("Genre invalide. Veuillez entrer 'Homme' ou 'Femme'.\n");
        }
    } while (!validerGenre(genre));

    do {
        printf("Date (AAAA-MM-JJ): ");
        scanf("%s", date);
        if (!validerDate(date)) {
            printf("Date invalide. Veuillez entrer une date valide au format AAAA-MM-JJ.\n");
        }
    } while (!validerDate(date));

    do {
        printf("Epreuve (choisissez parmi '100m', '400m', '5000m', 'marathon', 'relais'): ");
        scanf("%s", epreuve);
        if (!validerEpreuve(epreuve)) {
            printf("Epreuve invalide. Veuillez choisir une épreuve valide.\n");
        }
    } while (!validerEpreuve(epreuve));

    int validInput = 0;
    do {
        printf("Temps: ");
        if (scanf("%f", &temps) == 1 && validerTemps(temps)) {
            validInput = 1;
        } else {
            printf("Temps invalide. Veuillez entrer un temps positif.\n");
            while (getchar() != '\n'); // Nettoie le buffer d'entrée
        }
    } while (!validInput);

    if (strcmp(epreuve, "relais") == 0) {
        printf("Position dans le relais (1-4): ");
        scanf("%d", &positionRelais);
    }

    Athlete* athlete = creerAthlete(nom, prenom, genre);
    Performance* performance = creerPerformance(date, epreuve, temps, positionRelais);
    sauvegarderPerformance(nom, performance);
    afficherAthlete(athlete);
    free(athlete);
    free(performance);
}

void consulterHistorique() {
    char nom[50];
    printf("Nom de l'athlète: ");
    scanf("%s", nom);
    lireHistorique(nom);
}

void consulterStats() {
    char nom[50], epreuve[50];
    printf("Nom de l'athlète: ");
    scanf("%s",nom)
    printf("Epreuve: ");
    scanf("%s", epreuve);
    afficherStats(nom, epreuve);
}
