#include <stdio.h>
#include <stdlib.h>
#include "athlete.h"
#include "performance.h"
#include "file_utils.h"
#include "stats.h"

void menu() {
    printf("Gestion des performances des athlètes\n");
    printf("1. Ajouter un nouvel entraînement\n");
    printf("2. Consulter l'historique des entraînements\n");
    printf("3. Consulter les statistiques\n");
    printf("4. Voir les 3 meilleurs athlètes pour chaque épreuve et les envoyer aux JO\n");
    printf("5. Quitter\n");
}

void envoyerAuxJO();

int main() {
    int choix;
    do {
        menu();
        printf("Choisissez une option : ");
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                ajouterEntrainement();
                break;
            case 2:
                consulterHistorique();
                break;
            case 3:
                consulterStats();
                break;
            case 4:
                envoyerAuxJO();
                break;
            case 5:
                printf("Au revoir!\n");
                break;
            default:
                printf("Option invalide, veuillez réessayer.\n");
        }
    } while (choix != 5);

    return 0;
}         
