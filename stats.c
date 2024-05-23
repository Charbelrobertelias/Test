#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include "stats.h"
#include "performance.h"
#include "file_utils.h"

// Structure représentant les performances moyennes d'un athlète
typedef struct {
    char nom[50];
    float tempsMoyen;
} AthletePerformance;

// Affiche les statistiques des performances d'un athlète pour une épreuve donnée
void afficherStats(char* nom, char* epreuve) {
    char filename[60];
    sprintf(filename, "%s.txt", nom);
    FILE* file = fopen(filename, "r");
    if (file != NULL) {
        char line[100];
        float meilleurTemps = FLT_MAX, pireTemps = 0, sommeTemps = 0;
        int nbEntrainements = 0;
        
        while (fgets(line, sizeof(line), file)) {
            char date[11], event[50];
            float temps;
            int positionRelais;
            sscanf(line, "%10[^,],%49[^,],%f,%d", date, event, &temps, &positionRelais);
            if (strcmp(event, epreuve) == 0) {
                if (temps < meilleurTemps) meilleurTemps = temps;
                if (temps > pireTemps) pireTemps = temps;
                sommeTemps += temps;
                nbEntrainements++;
            }
        }
        fclose(file);
        
        if (nbEntrainements > 0) {
            printf("Statistiques pour %s dans l'épreuve %s:\n", nom, epreuve);
            printf("Meilleur temps: %.2f\n", meilleurTemps);
            printf("Pire temps: %.2f\n", pireTemps);
            printf("Temps moyen: %.2f\n", sommeTemps / nbEntrainements);
        } else {
            printf("Aucun entraînement trouvé pour %s dans l'épreuve %s\n", nom, epreuve);
        }
    } else {
        printf("Pas d'historique trouvé pour cet athlète\n");
    }
}

// Fonction de comparaison des athlètes par temps moyen
int comparerAthletes(const void* a, const void* b) {
    AthletePerformance* athleteA = (AthletePerformance*)a;
    AthletePerformance* athleteB = (AthletePerformance*)b;
    if (athleteA->tempsMoyen < athleteB->tempsMoyen) return -1;
    if (athleteA->tempsMoyen > athleteB->tempsMoyen) return 1;
    return 0;
}

// Affiche les trois meilleurs athlètes pour chaque épreuve et les envoie aux JO
void envoyerAuxJO() {
    const char* epreuves[] = {"100m", "400m", "5000m", "marathon", "relais"};
    int nbEpreuves = 5;
    char athletes[100][50]; // Tableau pour stocker les noms des athlètes
    int nbAthletes = 0;

    // Charger la liste des athlètes
    FILE* athletesFile = fopen("athletes.txt", "r");
    if (athletesFile != NULL) {
        while (fgets(athletes[nbAthletes], sizeof(athletes[nbAthletes]), athletesFile)) {
            athletes[nbAthletes][strcspn(athletes[nbAthletes], "\n")] = '\0'; // Retirer le saut de ligne
            nbAthletes++;
        }
        fclose(athletesFile);
    } else {
        perror("Erreur lors de l'ouverture du fichier des athlètes");
        return;
    }

    // Pour chaque épreuve, trouver les trois meilleurs athlètes
    for (int i = 0; i < nbEpreuves; i++) {
        AthletePerformance performances[100];
        int nbPerformances = 0;

        for (int j = 0; j < nbAthletes; j++) {
            char filename[60];
            sprintf(filename, "%s.txt", athletes[j]);
            FILE* file = fopen(filename, "r");
            if (file != NULL) {
                char line[100];
                float sommeTemps = 0;
                int nbEntrainements = 0;

                while (fgets(line, sizeof(line), file)) {
                    char date[11], event[50];
                    float temps;
                    int positionRelais;
                    sscanf(line, "%10[^,],%49[^,],%f,%d", date, event, &temps, &positionRelais);
                    if (strcmp(event, epreuves[i]) == 0) {
                        sommeTemps += temps;
                        nbEntrainements++;
                    }
                }
                fclose(file);

                if (nbEntrainements > 0) {
                    performances[nbPerformances].tempsMoyen = sommeTemps / nbEntrainements;
                    strcpy(performances[nbPerformances].nom, athletes[j]);
                    nbPerformances++;
                }
            } else {
                perror("Erreur lors de l'ouverture du fichier de performances");
            }
        }

        // Trier les performances pour trouver les trois meilleurs
        qsort(performances, nbPerformances, sizeof(AthletePerformance), comparerAthletes);

        // Afficher les trois meilleurs
        printf("Les trois meilleurs athlètes pour l'épreuve %s sont:\n", epreuves[i]);
        for (int k = 0; k < 3 && k < nbPerformances; k++) {
            printf("%d. %s avec un temps moyen de %.2f\n", k + 1, performances[k].nom, performances[k].tempsMoyen);
        }
    }
}

// Affiche la progression d'un athlète pour une même épreuve entre deux dates
void afficherProgression(char* nom, char* epreuve, char* date1, char* date2) {
    char filename[60];
    sprintf(filename, "%s.txt", nom);
    FILE* file = fopen(filename, "r");
    if (file != NULL) {
        char line[100];
        float temps1 = -1, temps2 = -1;

        while (fgets(line, sizeof(line), file)) {
            char date[11], event[50];
            float temps;
            int positionRelais;
            sscanf(line, "%10[^,],%49[^,],%f,%d", date, event, &temps, &positionRelais);
            if (strcmp(event, epreuve) == 0) {
                if (strcmp(date, date1) == 0) {
                    temps1 = temps;
                }
                if (strcmp(date, date2) == 0) {
                    temps2 = temps;
                }
            }
        }
        fclose(file);

        if (temps1 == -1 || temps2 == -1) {
            printf("Erreur : L'athlète n'a pas de temps enregistré pour les deux dates spécifiées.\n");
        } else {
            printf("Progression de %s dans l'épreuve %s entre %s et %s : %.2f secondes\n", nom, epreuve, date1, date2, temps2 - temps1);
        }
    } else {
        printf("Pas d'historique trouvé pour cet athlète\n");
    }
}
