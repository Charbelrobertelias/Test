
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

void ajouterEntrainement() {
    char nom[50], date[11], epreuve[50];
    float temps;
    int positionRelais = -1;
    
    printf("Nom de l'athlète: ");
    scanf("%s", nom);
    printf("Date (AAAA-MM-JJ): ");
    scanf("%s", date);
    printf("Epreuve: ");
    scanf("%s", epreuve);
    printf("Temps: ");
    scanf("%f", &temps);
    
    if (strcmp(epreuve, "relais") == 0) {
        printf("Position dans le relais (1-4): ");
        scanf("%d", &positionRelais);
    }

    Performance* performance = creerPerformance(date, epreuve, temps, positionRelais);
    sauvegarderPerformance(nom, performance);
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
    scanf("%s", nom);
    printf("Epreuve: ");
    scanf("%s", epreuve);
    afficherStats(nom, epreuve);
}

