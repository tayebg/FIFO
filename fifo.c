#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*structure pour représenter un processus*/
typedef struct process
{
    int date_arrivee;
    int duree_execution;
    int temps_sejour;
    int date_fin_execution;
    int temps_attente;
} process;

int main() {
    int i, nb, somme_duree_execution, somme_temps_sejour, somme_temps_attente, somme_temps_reponse, somme_temps_rotation;
    process* proc;
    char politique[20];
    process permut;
    float temps_moyen_sejour, temps_moyen_attente, temps_moyen_reponse, temps_moyen_rotation;
    int temps_total_pris;

    /*demander le nombre de processus*/
    printf("Entrez le nombre de processus : ");
    scanf("%d", &nb);

    /*allouer le tableau de manière dynamique avec malloc*/
    proc = (process*)malloc(sizeof(process) * nb);
    if (proc == NULL) {
        printf("Erreur d'allocation de mémoire.\n");
        return 1;
    }

    /*demander la politique choisie*/
    printf("Entrez la politique de planification : ");
    scanf("%s", politique);

    if (strcmp(politique, "FIFO") == 0) {
        /*FIFO*/
        /*attribuer à chaque processus une date d'arrivée et un temps d'exécution*/
        for (i = 0; i < nb; i++)
        {
            printf("\nEntrez l'heure d'arrivée du processus (%d) : ", i + 1);
            scanf("%d", &proc[i].date_arrivee);
            printf("Entrez le temps d'exécution du processus (%d) : ", i + 1);
            scanf("%d", &proc[i].duree_execution);
        }

        /*trier le tableau par ordre croissant d'heure d'arrivée*/
        for (i = 0; i < nb - 1; i++)
        {
            for (int j = 0; j < nb - i - 1; j++)
            {
                if (proc[j].date_arrivee > proc[j + 1].date_arrivee)
                {
                    permut = proc[j];
                    proc[j] = proc[j + 1];
                    proc[j + 1] = permut;
                }
            }
        }

        /*afficher l'ordonnancement appliqué*/
        printf("\n------------------->\n");
        printf("Ordonnancement FIFO\n");
        printf("------------------->\n");
        printf("Processus\t DA\t TE\n");
        /*afficher la date d'arrivée et le temps d'exécution de chaque processus*/
        for (i = 0; i < nb; i++)
        {
            printf("P(%d)\t\t %dms\t %dms\n", i + 1, proc[i].date_arrivee, proc[i].duree_execution);
        }
        printf("\n");

        /*calculer les différentes métriques*/
        somme_duree_execution = 0;
        somme_temps_sejour = 0;
        somme_temps_attente = 0;
        for (i = 0; i < nb; i++)
        {
            somme_duree_execution += proc[i].duree_execution;
            proc[i].date_fin_execution = somme_duree_execution;
            proc[i].temps_sejour = proc[i].date_fin_execution - proc[i].date_arrivee;
            proc[i].temps_attente = proc[i].temps_sejour - proc[i].duree_execution;
            somme_temps_sejour += proc[i].temps_sejour;
            somme_temps_attente += proc[i].temps_attente;
        }

        /*calculer les métriques moyennes*/
        temps_moyen_sejour = (float)somme_temps_sejour / nb;
        temps_moyen_attente = (float)somme_temps_attente / nb;
        temps_total_pris = somme_duree_execution;

        /*afficher les résultats*/
        printf("---------------------------------------->\n");
        printf("Date de fin d'exécution des %d processus\n", nb);
        printf("---------------------------------------->\n");
        for (i = 0; i < nb; i++)
        {
            printf("P(%d)\t", i + 1);
        }
        printf("\n");
        for (i = 0; i < nb; i++)
        {
            printf("%dms\t", proc[i].date_fin_execution);
        }
        printf("\n");

        printf("\n------------------------->\n");
        printf("TEMPS DE SEJOUR(ROTATION)\n");
        printf("------------------------->\n");
        for (i = 0; i < nb; i++)
        {
            printf("P(%d)\t", i + 1);
        }
        printf("\n");
        for (i = 0; i < nb; i++)
        {
            printf("%dms\t", proc[i].temps_sejour);
        }
        printf("\n");

        printf("\n--------------------->\n");
        printf("TEMPS MOYEN DE SEJOUR\n");
        printf("--------------------->\n");
        printf("Le temps moyen de sejour = %.6fms\n", temps_moyen_sejour);

        printf("\n------------------------>\n");
        printf("TEMPS D'ATTENTE(REPONSE)\n");
        printf("------------------------>\n");
        for (i = 0; i < nb; i++)
        {
            printf("P(%d)\t", i + 1);
        }
        printf("\n");
        for (i = 0; i < nb; i++)
        {
            printf("%dms\t", proc[i].temps_attente);
        }
        printf("\n");

        printf("\n--------------------->\n");
        printf("TEMPS MOYEN D'ATTENTE\n");
                printf("--------------------->\n");
        printf("Le temps moyen d'attente = %.6fms\n", temps_moyen_attente);
        
        printf("\n---------------->\n");
        printf("TEMPS TOTAL PRIS\n");
        printf("---------------->\n");
        printf("Temps total pris = %d unités\n", temps_total_pris);
    }
    else {
        printf("Politique de planification non supportée.\n");
        free(proc);
        return 1;
    }

    /*libérer la mémoire allouée*/
    free(proc);

    return 0;
}
