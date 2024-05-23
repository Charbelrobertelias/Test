#include <stdio.h>
#include <stdlib.h>
#include "athlete.h"
#include "performance.h"
#include "file_utils.h"
#include "stats.h"

// Affiche le menu principal
void menu() {
    printf("Gestion des performances des athlètes\n");
    printf("1. Ajouter un nouvel entraînement\n");
    printf("2. Consulter l'historique des entraînements\n");
    printf("3. Consulter les statistiques et la progression d'un athlète\n");
    printf("4. Voir les 3 meilleurs athlètes pour chaque épreuve et les envoyer aux JO\n");
    printf("5. Quitter\n");
}

// Déclare la fonction pour envoyer les athlètes aux JO
void envoyerAuxJO();

// Déclare la fonction pour consulter les statistiques des athlètes et afficher la progression
void consulterStatsEtProgression();

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
                consulterStatsEtProgression();
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

// Affiche les statistiques des athlètes et permet d'afficher la progression d'un athlète
void consulterStatsEtProgression() {
    int choix;
    char nom[50], epreuve[50], date1[11], date2[11];
    
    printf("1. Consulter les statistiques\n");
    printf("2. Afficher la progression d'un athlète\n");
    printf("Choisissez une option : ");
    scanf("%d", &choix);
    
    switch (choix) {
        case 1:
            printf("Nom de l'athlète: ");
            scanf("%s", nom);
            printf("Epreuve: ");
            scanf("%s", epreuve);
            afficherStats(nom, epreuve);
            break;
        case 2:
            printf("Nom de l'athlète: ");
            scanf("%s", nom);
            printf("Epreuve: ");
            scanf("%s", epreuve);
            printf("Date de début (AAAA-MM-JJ): ");
            scanf("%s", date1);
            printf("Date de fin (AAAA-MM-JJ): ");
            scanf("%s", date2);
            afficherProgression(nom, epreuve, date1, date2);
            break;
        default:
            printf("Option invalide, retour au menu principal.\n");
    }
}
