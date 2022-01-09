#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef char t_chaine50[51];
typedef char t_chaine10[11];

typedef struct{
     t_chaine50 c_nom;  // nom de l’abonné
     t_chaine10 c_num;// numéro de cet abonné
     int c_duree; // durée pour laquelle il est abonné   
} t_abonne;

void menu(t_abonne * abo) {
    int choix;
    FILE * fichier_abo ;
    t_abonne tmp;
    printf("\nTapez : \n 1 pour créer un fichier contenant les renseignements sur les abonné\n 2 : lister le fichier \n 3 : ajouter un nouvel abonné à la fin du tableau\n ");
    scanf("%d", &choix);
    switch (choix) {
        case 1 :
            fichier_abo = fopen("ABONNE.DATA", "wb");
            printf("Fichier créer; \n"); 
            printf("Saisissez un nom : ");
            scanf("%s", (*abo).c_nom );
            while (strcmp((*abo).c_nom , "*") != 0){
                printf("Saisissez un numéros : ");
                scanf("%s", (*abo).c_num );
                printf("Saisissez une durée : ");
                scanf("%d", &(*abo).c_duree );
                fwrite(&abo, sizeof(abo), 1, fichier_abo);
                printf("Saisissez un nom : ");
                scanf("%s", (*abo).c_nom );
            }
            break;
        case 2 :
            fichier_abo = fopen("ABONNE.DATA", "rb");
            fread(&tmp, sizeof(tmp), 1, fichier_abo);
            while(!feof(fichier_abo)) {
              printf("%s", (*abo).c_nom );
              printf("%s", (*abo).c_num );
              printf("%d", (*abo).c_duree );
              fread(&tmp, sizeof(tmp), 1, fichier_abo);
            }
            break;
        case 3 : 
            fichier_abo = fopen("ABONNE.DATA", "ab");
            printf("Saisissez un nom : ");
            scanf("%s", (*abo).c_nom );
            while (strcmp((*abo).c_nom , "*") != 0){
                printf("Saisissez un numéros : ");
                scanf("%s", (*abo).c_num );
                printf("Saisissez une durée : ");
                scanf("%d", &(*abo).c_duree );
                fwrite(&abo, sizeof(abo), 1, fichier_abo);
                printf("Saisissez un nom : (* si terminer) ");
                scanf("%s", (*abo).c_nom );
            }
            break;
    }
}

int main() {
    t_abonne abo;
    int choix = 0;

    while (choix == 0){
        menu(&abo);
        printf("Continuer 0 = oui 1 = non :");
        scanf("%d", &choix);
    }
    
    return EXIT_SUCCESS;
}
/* 
Ouvrir un fichier 

f =fopen("Planetes.data", "");
"r" = lire
"w" = écraser
"a" = ajouter

fermer un fichier 

fclose(f);

lire un fichier 

fread(&tmp,sizeof(tmp), 1, f);

fin de fichier : feof(f)
exemple : while (!feof(f)) = tant que l'on est pas à la fin du fichier
*/