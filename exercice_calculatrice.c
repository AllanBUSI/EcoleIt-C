#include <stdio.h>

int mains() {

    int a, b;
    char op;
    printf("Entrez le premier nombre : ");
    scanf("%d", &a);
    printf("Entrez le second nombre : ");
    scanf("%d", &b);
    printf("Entrez l'opération (+, -, *, /) : ");
    scanf(" %c", &op);  // espace avant %c pour ignorer les espaces

    switch(op) {
        case '+':
            printf("Résultat : %d + %d = %d\n", a, b, a + b);
            break;
        case '-':
            printf("Résultat : %d - %d = %d\n", a, b, a - b);
            break;
        case '*':
            printf("Résultat : %d * %d = %d\n", a, b, a * b);
            break;
        case '/':
            if (b != 0)
                printf("Résultat : %d / %d = %d\n", a, b, a / b);
            else
                printf("Erreur : division par zéro !\n");
            break;
        default:
            printf("Opération invalide !\n");
    }

    return 0;
}

