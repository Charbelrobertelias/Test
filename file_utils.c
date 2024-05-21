#include "file_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sauvegarderPerformance(char* nom, Performance* performance) {
    char filename[60];
    sprintf(filename, "%s.txt", nom);
    FILE* file = fopen(filename, "a");
    if (file != NULL) {
        fprintf(file, "%s,%s,%.2f,%d\n", performance->date, performance->epreuve, performance->temps, performance->positionRelais);
        fclose(file);
    } else {
        printf("Erreur d'ouverture du fichier\n");
    }
}

void lireHistorique(char* nom) {
    char filename[60];
    sprintf(filename, "%s.txt", nom);
    FILE* file = fopen(filename, "r");
    if (file != NULL) {
        char line[100];
        while (fgets(line, sizeof(line), file)) {
            char date[11], epreuve[50];
            float temps;
            int positionRelais;
            sscanf(line, "%10[^,],%49[^,],%f,%d", date, epreuve, &temps, &positionRelais);
            Performance* performance = creerPerformance(date, epreuve, temps, positionRelais);
            afficherPerformance(performance);
            free(performance);
        }
        fclose(file);
    } else {
        printf("Pas d'historique trouvé pour cet athlète\n");
    }
}
