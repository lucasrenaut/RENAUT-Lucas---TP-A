#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


//fonction de sauvegarde pour obtenir 

void sauvegarder_score(char* nom_joueur, int score) {
    FILE *file;
    char ligne[200];
    int trouve = 0;
    time_t t;
    struct tm *tm_info;
    char date_heure[26];

// Obtenir l'heure actuelle pour le fichier
    time(&t);
    tm_info = localtime(&t);
    strftime(date_heure, sizeof(date_heure), "%Y-%m-%d %H:%M:%S", tm_info);

    file = fopen("scores.txt", "r+"); // Ouvre en mode lecture
    if (file == NULL) {
        file = fopen("scores.txt", "w"); // Crée le fichier s'il n'existe pas
    }
    
    if (file != NULL) {
        // Cherche si le joueur existe déjà dans le fichier
        while (fgets(ligne, sizeof(ligne), file)) {
            char nom_lu[100];
            int score_lu;
            if (sscanf(ligne, "Nom: %[^,], score: %d, date: %s", nom_lu, &score_lu, date_heure) == 3) {
                if (strcmp(nom_joueur, nom_lu) == 0) {
                    trouve = 1;
                    break;
                }
            }
        }
        
        // Si le joueur est trouvé, met à jour son score et la date
        if (trouve) {
            fclose(file);
            file = fopen("scores.txt", "r+"); // Ouvre à nouveau en mode lecture/écriture
            FILE *temp_file = fopen("temp.txt", "w"); // Crée un fichier temporaire pour la mise à jour

            while (fgets(ligne, sizeof(ligne), file)) {
                char nom_lu[100];
                int score_lu;
                if (sscanf(ligne, "Nom: %[^,], score: %d, date: %s", nom_lu, &score_lu, date_heure) == 3) {
                    if (strcmp(nom_joueur, nom_lu) == 0) {
                        fprintf(temp_file, "Nom: %s, score: %d, date: %s\n", nom_joueur, score, date_heure); // Mettre à jour le score et la date
                    } else {
                        fprintf(temp_file, "%s", ligne); // Conserver les autres lignes
                    }
                }
            }
            fclose(file);
            fclose(temp_file);
            remove("scores.txt"); // Supprimer l'ancien fichier
            rename("temp.txt", "scores.txt"); // Renommer le fichier temporaire
        } else {
            // Si le joueur n'existe pas encore, ajouter un nouvel enregistrement avec la date et l'heure
            fprintf(file, "Nom: %s, score: %d, date: %s\n", nom_joueur, score, date_heure);
        }
        fclose(file);
    }
}

void charger_score(char *nom_joueur, int *compteur) {
    FILE *file;
    char ligne[200];
    char nom_lu[100];
    int score_lu;
    char date_lu[26];
    int trouve = 0;

    file = fopen("scores.txt", "r");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier. Assurez-vous que le fichier existe.\n");
        return;
    }

    // Lecture ligne par ligne
    while (fgets(ligne, sizeof(ligne), file)) {
        // Extraire le nom, le score et la date de la ligne
        if (sscanf(ligne, "Nom: %[^,], score: %d, date: %s", nom_lu, &score_lu, date_lu) == 3) {
            // Si le nom correspond à l'utilisateur, on charge son score et la date
            if (strcmp(nom_joueur, nom_lu) == 0) {
                *compteur = score_lu; // Charger le score existant
                printf("Bienvenue %s, votre score est : %d, enregistré le : %s\n", nom_joueur, *compteur, date_lu);
                trouve = 1;
                break; // Sortir de la boucle une fois le score trouvé
            }
        }
    }
    fclose(file);

    // Si le joueur n'a pas de score enregistré, initialiser à 0
    if (!trouve) {
        *compteur = 0;
        printf("Bienvenue %s, vous n'avez aucun enregistrement de score. Votre score a été initialisé  à 0\n", nom_joueur);
    }
}

//fonction compteur des points

int compteur=0;
void comptage(int cpt){
    compteur+=cpt;
    printf("%d",compteur);
}

//fonction addition

void addition(int *compteur){
    int nb1,nb2,nb3,resultat,cpt;
    printf("addition\n");
    srand (time(NULL)); //on appelle la fonction pour générer des nombres aléatoire
    nb1=("%d",rand()%101); 
    nb2=("%d",rand()%101);
    printf("%d+%d= ?\n",nb1,nb2);
    resultat=nb1+nb2;
    printf("Entrez le résultat :\nvous avez entrez ");
    scanf("%d",&nb3);
    if (resultat==nb3){
        printf("bravo\nvotre score est de :");
        comptage(10); //on ajoute 10 points si réussi du 1er coup
        }
    else {
        printf("retentez votre chance\nEntrez le résultat :\nvous avez entrez ");
        scanf("%d",&nb3);
        if(resultat==nb3){
            printf("bravo\nvotre score est de :");
            comptage(5); //on ajoute 5 points si réussi du 2éme coup
        }
        else{
            printf("derniere chance\nEntrez le résultat :\nvous avez entrez ");
            scanf("%d",&nb3);
            if(resultat==nb3){
            printf("bravo\nvotre score est de :");
            comptage(1); //on ajoute 1 point si réussi du 3éme coup
            }
            else{
                printf("le resultat etait %d\nvotre score est de :",resultat);
                comptage(0); //on ajoute 0 point car le joueur n'a pas réusi à trouver le résultat et affiche le résultat
                }
            }
        }
    }
    
void multiplication (int *compteur){
    int nb1,nb2,nb3,resultat,cpt;
    printf("multiplication\n");
    srand(time(NULL)); //on appelle la fonction pour générer des nombres aléatoire
    nb1=("%d",rand()%10+1);
    nb2=("%d",rand()%10+1);
    printf("%d*%d= ?\n",nb1,nb2);
    resultat=nb1*nb2;
    printf("Entrez le résultat :\nvous avez entrez ");
    scanf("%d",&nb3);
    if (resultat==nb3){
        printf("bravo\nvotre score est de :");
        comptage(10); //on ajoute 10 points si réussi du 1er coup
        }
    else {
        printf("retentez votre chance\nEntrez le résultat :\nvous avez entrez ");
        scanf("%d",&nb3);
        if(resultat==nb3){
            printf("bravo\nvotre score est de :");
            comptage(5); ////on ajoute 5 points si réussi du 2éme coup
        }
        else{
            printf("derniere chance\nEntrez le résultat :\nvous avez entrez ");
            scanf("%d",&nb3);
            if(resultat==nb3){
            printf("bravo\nvotre score est de :");
            comptage(1); //on ajoute 1 point si réussi du 3éme coup
            }
            else{
                printf("le resultat etait %d\nvotre score est de :",resultat);
                comptage(0); //on ajoute 0 point car le joueur n'a pas réusi à trouver le résultat et affiche le résultat
                }
            }
        }
    }

void soustraction (int *compteur){
    int nb1,nb2,nb3,resultat;
    printf("soustraction\n");
    srand(time(NULL));
    nb1=("%d",rand()%101);
    nb2=("%d",rand()%101);
    if (nb1>nb2){
        printf("%d-%d= ?\n",nb1,nb2);
        resultat=nb1-nb2;
        printf("Entrez le résultat :\nvous avez entrez ");
        scanf("%d",&nb3);
    }
    else {
        printf("%d-%d= ?\n",nb2,nb1);
        resultat=nb2-nb1;
        printf("Entrez le résultat :\nvous avez entrez ");
        scanf("%d",&nb3);
    }
    if (resultat==nb3){
        printf("bravo\nvotre score est de :");
        comptage(10) //on ajoute 10 points si réussi du 1er coup
        }
    else {
        printf("retentez votre chance\nEntrez le résultat :\nvous avez entrez ");
        scanf("%d",&nb3);
        if(resultat==nb3){
            printf("bravo\nvotre score est de :");
            comptage(5); //on ajoute 5 points si réussi du 2éme coup
        }
        else{
            printf("derniere chance\nEntrez le résultat :\nvous avez entrez ");
            scanf("%d",&nb3);
            if(resultat==nb3){
            printf("bravo\nvotre score est de :");
            comptage(1); //on ajoute 1 point si réussi du 3éme coup
            }
            else{
                printf("le resultat etait %d\nvotre score est de :",resultat);
                comptage(0); //on ajoute 0 point car le joueur n'a pas réusi à trouver le résultat et affiche le résultat
                }
            }
        }
    }

void table_multi (int *compteur){
    printf("+------------------------------------+\n");
    printf("|1 : Table de 1                      |\n");
    printf("|2 : Table de 2                      |\n");
    printf("|3 : Table de 3                      |\n");
    printf("|4 : Table de 4                      |\n");
    printf("|5 : Table de 5                      |\n");
    printf("|6 : Table de 6                      |\n");
    printf("|7 : Table de 7                      |\n");
    printf("|8 : Table de 8                      |\n");
    printf("|9 : Table de 9                      |\n");
    printf("|10 : Table de 10                    |\n");
    printf("+------------------------------------+\n");
       int nb,resultat,nb3;
    printf("Sur quelle table de multiplication voulez vous travailler\n");
    scanf("%d",&nb);
    for (int i=0;i<11;i++){
        printf("\n%d*%d\t= ",nb,i);
        resultat=nb*i;
        scanf("%d",&nb3);
        if (resultat==nb3){
        printf("bravo\nvotre score est de :");
        comptage(3); //on ajoute 3 points si réussi du 1er coup
        }
        else {
        printf("retentez votre chance\nEntrez le résultat :\nvous avez entrez ");
        scanf("%d",&nb3);
        if(resultat==nb3){
            printf("bravo\nvotre score est de :");
            comptage(2 //on ajoute 2 points si réussi du 2éme coup
        }
        else{
            printf("derniere chance\nEntrez le résultat :\nvous avez entrez ");
            scanf("%d",&nb3);
            if(resultat==nb3){
            printf("bravo\nvotre score est de :");
            comptage(1); //on ajoute 1 points si réussi du 3éme coup
            }
            else{
                printf("le resultat etait %d\nvotre score est de :",resultat);
                comptage(0 //on ajoute 0 point car le joueur n'a pas réusi à trouver le résultat et affiche le résulta
                }
            }
        }
    }
}

//fonction division

int division (int *compteur){
    printf("division\ndans cette exercice on vous demande le reste et le quotient\n");
    int nb1,nb2,r1,q1,r2,q2;
    srand(time(NULL));
    nb1=("%d",rand()%101);
    nb2=("%d",rand()%100+1);
    printf("%d/%d\n",nb1,nb2);
    printf("le reste est ");
    scanf("%d",&r1);
    printf("\nle quotient est ");
    scanf("%d",&q1);
    r2=nb1%nb2;
    q2=nb1/nb2;
    if (r1==r2 && q1==q2){
        printf("bravo\n votre score est de ");
        comptage(10); //on ajoute 10 points si réussi du 1er coup
    }
    else {
        printf("retentez votre chance\nle reste est ");
        scanf("%d",&r1);
        printf("\n le quotient est ");
        scanf("%d",&q1);
        if(r1==r2 && q1==q2){
            printf("bravo\nvotre score est de :");
            comptage(5); //on ajoute 5 points si réussi du 2éme coup
        }
        else{
            printf("derniere chance\nle reste est ");
            scanf("%d",&r1);
            printf("\nle quotient est ");
            scanf("%d",&q1);
            if(r1==r2 && q1==q2){
            printf("bravo\nvotre score est de :");
            comptage(1); //on ajoute 1 points si réussi du 3éme coup
            }
            else{
                printf("voici les resultats\nle reste etait %d\nle quotient etait %d\nvotre score est de :",r2,q2);
                comptage(0); //on ajoute 0 point car le joueur n'a pas réusi à trouver le résultat et affiche le résulta
             }
        }
    }
}

//fonction périmétre

void perimetre (int*compteur) {
    int cas,cote,longueur,largeur,cote1,cote2,resultat,reponse;
    printf("perimetre\n");
    srand(time(NULL));
    cas=("%d",rand()%3+1);
    switch(cas){
    case 1 :
        cote=("%d",rand()%30+1);
        printf("calculer le perimetre d'un carre de %d \nquelle est votre reponse\nvous avez entrez ",cote);
        scanf("%d",&reponse);
        resultat=cote*4;
        if(resultat==reponse){
        printf("\nbravo\nvotre score est de :");
        comptage(10); //on ajoute 10 points si réussi du 1er coup
        }
        else{
        printf("retentez votre chance\nEntrez le résultat :\nvous avez entrez ");
        scanf("%d",&reponse);
        if(resultat==reponse){
            printf("bravo\nvotre score est de :");
            comptage(5);
        }
        else{
            printf("derniere chance\nEntrez le résultat :\nvous avez entrez ");
            scanf("%d",&reponse);
            if(resultat==reponse){
            printf("bravo\nvotre score est de :");
            comptage(1);
            }
            else{
                printf("le resultat etait %d\nvotre score est de :",resultat);
                comptage(0);
                }
            }

        }
        break;

    case 2 :
        longueur=("%d",rand()%30+1);
        largeur=("%d",rand()%30+1);
        printf("calculer le perimetre d'un rectangle de largeur %d et de longueur %d \nquelle est votre reponse\nvous avez entrez ",largeur,longueur);
        scanf("%d",&reponse);
        resultat=(longueur+largeur)*2;
        if(resultat==reponse){
        printf("\nbravo\nvotre score est de :");
        comptage(10); //on ajoute 10 points si réussi du 1er coup
        }
        else{
        printf("retentez votre chance\nEntrez le résultat :\nvous avez entrez ");
        scanf("%d",&reponse);
        if(resultat==reponse){
            printf("bravo\nvotre score est de :");
            comptage(5);
        }
        else{
            printf("derniere chance\nEntrez le résultat :\nvous avez entrez ");
            scanf("%d",&reponse);
            if(resultat==reponse){
            printf("bravo\nvotre score est de :");
            comptage(1);
            }
            else{
                printf("le resultat etait %d\nvotre score est de :",resultat);
                comptage(0);
                }
            }

        }
        break;

    case 3 :
        cote=("%d",rand()%30+1);
        cote1=("%d",rand()%30+1);
        cote2=("%d",rand()%30+1);
        printf("calculer le perimetre d'un triangle de %d et %d et %d de cote \nquelle est votre reponse\nvous avez entrez ",cote,cote1,cote2);
        scanf("%d",&reponse);
        resultat=cote+cote1+cote2;
        if(resultat==reponse){
        printf("\nbravo\nvotre score est de :");
        comptage(10); //on ajoute 10 points si réussi du 1er coup
        }
        else{
        printf("retentez votre chance\nEntrez le résultat :\nvous avez entrez ");
        scanf("%d",&reponse);
        if(resultat==reponse){
            printf("bravo\nvotre score est de :");
            comptage(5);
        }
        else{
            printf("derniere chance\nEntrez le résultat :\nvous avez entrez ");
            scanf("%d",&reponse);
            if(resultat==reponse){
            printf("bravo\nvotre score est de :");
            comptage(1);
            }
            else{
                printf("le resultat etait %d\nvotre score est de :",resultat);
                comptage(0);
                }
            }

        }
        break;

    }


}

//fonction aire

void aire (int*compteur){
    int cas,cote,longueur,largeur,cote1,resultat,reponse;
    printf("aire\n");
    srand(time(NULL));
    cas=("%d",rand()%3+1);
    switch(cas){
    case 1 :
        cote=("%d",rand()%10+1);
        printf("calculer l'aire d'un carre de %d \nquelle est votre reponse\nvous avez entrez ",cote);
        scanf("%d",&reponse);
        resultat=cote*cote;
        if(resultat==reponse){
        printf("\nbravo\nvotre score est de :");
        comptage(10); //on ajoute 10 points si réussi du 1er coup
        }
        else{
        printf("retentez votre chance\nEntrez le résultat :\nvous avez entrez ");
        scanf("%d",&reponse);
        if(resultat==reponse){
            printf("bravo\nvotre score est de :");
            comptage(5);
        }
        else{
            printf("derniere chance\nEntrez le résultat :\nvous avez entrez ");
            scanf("%d",&reponse);
            if(resultat==reponse){
            printf("bravo\nvotre score est de :");
            comptage(1);
            }
            else{
                printf("le resultat etait %d\nvotre score est de :",resultat);
                comptage(0);
                }
            }

        }
        break;

    case 2 :
        longueur=("%d",rand()%10+1);
        largeur=("%d",rand()%10+1);
        printf("calculer l'aire d'un rectangle de largeur %d et de longueur %d \nquelle est votre reponse\nvous avez entrez ",largeur,longueur);
        scanf("%d",&reponse);
        resultat=longueur*largeur*2;
        if(resultat==reponse){
        printf("\nbravo\nvotre score est de :");
        comptage(10); //on ajoute 10 points si réussi du 1er coup
        }
        else{
        printf("retentez votre chance\nEntrez le résultat :\nvous avez entrez ");
        scanf("%d",&reponse);
        if(resultat==reponse){
            printf("bravo\nvotre score est de :");
            comptage(5);
        }
        else{
            printf("derniere chance\nEntrez le résultat :\nvous avez entrez ");
            scanf("%d",&reponse);
            if(resultat==reponse){
            printf("bravo\nvotre score est de :");
            comptage(1);
            }
            else{
                printf("le resultat etait %d\nvotre score est de :",resultat);
                comptage(0);
                }
            }

        }
        break;

    case 3 :
        cote=("%d",rand()%10+1);
        cote1=("%d",rand()%10+1);
        printf("calculer l'aire d'un triangle avec une base de %d et d'une hauteur de %d \nquelle est votre reponse\nvous avez entrez ",cote,cote1);
        scanf("%d",&reponse);
        resultat=(cote*cote1)/2;
        if(resultat==reponse){
        printf("\nbravo\nvotre score est de :");
        comptage(10); //on ajoute 10 points si réussi du 1er coup
        }
        else{
        printf("retentez votre chance\nEntrez le résultat :\nvous avez entrez ");
        scanf("%d",&reponse);
        if(resultat==reponse){
            printf("bravo\nvotre score est de :");
            comptage(5);
        }
        else{
            printf("derniere chance\nEntrez le résultat :\nvous avez entrez ");
            scanf("%d",&reponse);
            if(resultat==reponse){
            printf("bravo\nvotre score est de :");
            comptage(1);
            }
            else{
                printf("le resultat etait %d\nvotre score est de :",resultat);
                comptage(0);
                }
            }

        }
        break;

    }



}
//fonction mélange de calcul

void calcul (int*compteur){
    int nb,nb1,nb2,reponse,resultat,cas;
    printf("melange de calcul\n");
    srand(time(NULL));
    nb1=("%d",rand()%10);
    nb2=("%d",rand()%10);
    nb=("%d",rand()%10);
    cas=("%d",rand()%4+1);
    switch (cas){
    case 1 :
        printf("calcul avec multiplication addition\n%d+%d*%d\n",nb1,nb2,nb);
        resultat=nb1+nb2*nb;
        scanf("%d",&reponse);
        if(resultat==reponse){
        printf("\nbravo\nvotre score est de :");
        comptage(10); //on ajoute 10 points si réussi du 1er coup
        }
        else{
        printf("retentez votre chance\nEntrez le résultat :\nvous avez entrez ");
        scanf("%d",&reponse);
        if(resultat==reponse){
            printf("bravo\nvotre score est de :");
            comptage(5);
        }
        else{
            printf("derniere chance\nEntrez le résultat :\nvous avez entrez ");
            scanf("%d",&reponse);
            if(resultat==reponse){
            printf("bravo\nvotre score est de :");
            comptage(1);
            }
            else{
                printf("le resultat etait %d\nvotre score est de :",resultat);
                comptage(0);
                }
            }

        }
        break;

    case 2 :
        printf("calcul avec multiplication addition\n%d*%d+%d\n",nb1,nb,nb2);
        resultat=nb1*nb+nb2;
        scanf("%d",&reponse);
        if(resultat==reponse){
        printf("\nbravo\nvotre score est de :");
        comptage(10); //on ajoute 10 points si réussi du 1er coup
        }
        else{
        printf("retentez votre chance\nEntrez le résultat :\nvous avez entrez ");
        scanf("%d",&reponse);
        if(resultat==reponse){
            printf("bravo\nvotre score est de :");
            comptage(5);
        }
        else{
            printf("derniere chance\nEntrez le résultat :\nvous avez entrez ");
            scanf("%d",&reponse);
            if(resultat==reponse){
            printf("bravo\nvotre score est de :");
            comptage(1);
            }
            else{
                printf("le resultat etait %d\nvotre score est de :",resultat);
                comptage(0);
                }
            }

        }
        break;

    case 3 :
        printf("calcul avec uniquement des addition\n%d+%d+%d\n",nb1,nb2,nb);
        resultat=nb1+nb2+nb;
        scanf("%d",&reponse);
        if(resultat==reponse){
        printf("\nbravo\nvotre score est de :");
        comptage(10); //on ajoute 10 points si réussi du 1er coup
        }
        else{
        printf("retentez votre chance\nEntrez le résultat :\nvous avez entrez ");
        scanf("%d",&reponse);
        if(resultat==reponse){
            printf("bravo\nvotre score est de :");
            comptage(5);
        }
        else{
            printf("derniere chance\nEntrez le résultat :\nvous avez entrez ");
            scanf("%d",&reponse);
            if(resultat==reponse){
            printf("bravo\nvotre score est de :");
            comptage(1);
            }
            else{
                printf("le resultat etait %d\nvotre score est de :",resultat);
                comptage(0);
                }
            }

        }
    break;
    }
}

int main(){

//VARIABLES

char nom_joueur[100];
int choix,cpt;

//demande du nom d'utilisateur

printf("Entrez votre nom d'utilisateur : ");
scanf("%s", nom_joueur);

charger_score(nom_joueur, &compteur);

//programme principale

printf("+------------------------------------+\n");
printf("|1 : Addition                        |\n");
printf("|2 : Soustraction                    |\n");
printf("|3 : Multiplication                  |\n");
printf("|4 : Tables des multiplications      |\n");
printf("|5 : Divisions                       |\n");
printf("|6 : perimetre                       |\n");
printf("|7 : aire                            |\n");
printf("|8 : melange de calcul               |\n");
printf("|0 : Sortir du jeu                   |\n");
printf("+------------------------------------+\n");
printf("Quel est votre choix ?\n");


scanf("%d",&choix);
while (choix!=0){
    switch(choix){
    case 1 :
        addition(&compteur);
            break;
    case 2 :
        soustraction (&compteur);
        break;

    case 3 :
        multiplication(&compteur);
        break;

    case 4 :
        table_multi(&compteur);
        break;

    case 5 :
        division(&compteur);
        break;
        
       case 6 :
        perimetre(&compteur);
        break;
        
    case 7 :
        aire(&compteur);
        break;
        
    case 8 :
        calcul(&compteur);
    break;
    }

printf("\n\n+------------------------------------+\n");
printf("|1 : Addition                        |\n");
printf("|2 : Soustraction                    |\n");
printf("|3 : Multiplication                  |\n");
printf("|4 : Tables des multiplications      |\n");
printf("|5 : Divisions                       |\n");
printf("|6 : perimetre                       |\n");
printf("|7 : aire                            |\n");
printf("|8 : melange de calcul               |\n");
printf("|0 : Sortir du jeu                   |\n");
printf("+------------------------------------+\n");
printf("Quel est votre choix ?\n");

scanf("%d",&choix);

}
printf("merci de votre visite ! \n\n");

sauvegarder_score(nom_joueur, compteur);

return 0;
}
