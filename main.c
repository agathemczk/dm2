#include <stdio.h>

char secretword [8] = {'M','O','N','T','A','G','N','E'};
char guessword [8] = {'_','_','_','_','_','_','_','_'};
int error=0;

int main () {

    printf("Voici le mot que tu dois deviner : _ _ _ _ _ _ _ _\n");

    while ( error < 6 ) {
        printf("Donne moi une lettre : \n");
        char letter;
        scanf(" %c",&letter);

        char found = 0;

        for (int i = 0; i < 8; ++i) {
            if (letter == secretword[i]) {
                guessword [i] = secretword[i] ;
                found = 1 ;
            }
        }
        if (!found) {
            error += 1;
            printf("Lettre incorrecte, il te reste %d erreur(s). \n", 6 - error);
        } else {
            printf("Bien joué !\n");
        }

        printf("Mot actuel : ");
        for (int i = 0; i < 8; ++i) {
            printf("%c", guessword[i]);
        }
        printf("\n");

        if (error == 6) {
            printf("Perdu ! Le mot secret était : ");
            for (int i = 0; i < 8; ++i) {
                printf("%c", secretword[i]);
            }
            printf("\n");
            return 1;
        }

        int correct = 1;
        for (int i = 0; i < 8; ++i) {
            if (guessword[i] == '_') {
                correct = 0;
                break;
            }
        }

        if (correct) {
            printf("Bravo ! Tu as gagné ! Le mot secret était : ");
            for (int i = 0; i < 8; ++i) {
                printf("%c", secretword[i]);
            }
            printf("\n");
            return 0;
        }
    }

    return 0;
}