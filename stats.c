#include <float.h>
#include "stats.h"
#include "performance.h"
#include "file_utils.h"

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

