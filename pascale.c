#include <stdio.h>

// Fonction récursive pour calculer la factorielle
int factorielle(int x) {
    if (x <= 1)
        return 1;
    return x * factorielle(x - 1);
}

// Fonction pour calculer le coefficient binomial C(n, k)
int coeff_binomial(int n, int k) {
    return factorielle(n) / (factorielle(k) * factorielle(n - k));
}

int mains() {
    int n;
    printf("Entrez le nombre de lignes du triangle de Pascal : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {  // boucle externe (lignes)
        for (int j = 0; j <= i; j++) {  // boucle interne (valeurs)
            printf("%d ", coeff_binomial(i, j));
        }
        printf("\n");
    }

    return 0;
}
