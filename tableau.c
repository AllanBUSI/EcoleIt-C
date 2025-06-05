#include <stdio.h>

int main() {
    int myNumbers[] = {25, 50, 75,88, 100};
    int i;

    // Affichage du tableau original
    printf("Tableau original : ");
    for (i = 0; i < 5; i++) {
        printf("%d ", myNumbers[i]);
    }

    // Affichage du tableau inversé
    printf("\nTableau inversé : ");
    for (i = 4; i >= 0; i--) {
        printf("%d ", myNumbers[i]);
    }

    printf("\n");

    return 0;
}
