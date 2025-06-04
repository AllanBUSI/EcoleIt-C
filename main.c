#include <stdio.h>

#define TAILLE 3

// Initialise la grille avec des espaces
void initialiserGrille(char grille[TAILLE][TAILLE]) {
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            grille[i][j] = ' ';
        }
    }
}

// Affiche la grille à l’écran
void afficherGrille(char grille[TAILLE][TAILLE]) {
    printf("\n");
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            printf(" %c ", grille[i][j]);
            if (j < TAILLE - 1) printf("|");
        }
        printf("\n");
        if (i < TAILLE - 1) printf("---+---+---\n");
    }
    printf("\n");
}

// Tente de jouer un coup
int jouerCoup(char grille[TAILLE][TAILLE], int ligne, int colonne, char joueur) {
    if (ligne < 0 || ligne >= TAILLE || colonne < 0 || colonne >= TAILLE)
        return 0;
    if (grille[ligne][colonne] != ' ')
        return 0;
    grille[ligne][colonne] = joueur;
    return 1;
}

// Vérifie si le joueur a gagné
int verifierVictoire(char grille[TAILLE][TAILLE], char joueur) {
    // Vérifie lignes et colonnes
    for (int i = 0; i < TAILLE; i++) {
        if ((grille[i][0] == joueur && grille[i][1] == joueur && grille[i][2] == joueur) ||
            (grille[0][i] == joueur && grille[1][i] == joueur && grille[2][i] == joueur))
            return 1;
    }

    // Vérifie diagonales
    if ((grille[0][0] == joueur && grille[1][1] == joueur && grille[2][2] == joueur) ||
        (grille[0][2] == joueur && grille[1][1] == joueur && grille[2][0] == joueur))
        return 1;

    return 0;
}

// Vérifie si la grille est pleine
int grillePleine(char grille[TAILLE][TAILLE]) {
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            if (grille[i][j] == ' ')
                return 0;
        }
    }
    return 1;
}

int main() {
    char grille[TAILLE][TAILLE];
    char joueur = 'X';
    int ligne, colonne;

    initialiserGrille(grille);

    while (1) {
        afficherGrille(grille);
        printf("Joueur %c - Entrez ligne et colonne (1 à 3) : ", joueur);
        scanf("%d %d", &ligne, &colonne);
        ligne--; colonne--;

        if (!jouerCoup(grille, ligne, colonne, joueur)) {
            printf("❌ Coup invalide. Réessayez.\n");
            continue;
        }

        if (verifierVictoire(grille, joueur)) {
            afficherGrille(grille);
            printf("🎉 Le joueur %c a gagné !\n", joueur);
            break;
        }

        if (grillePleine(grille)) {
            afficherGrille(grille);
            printf("🤝 Match nul !\n");
            break;
        }

        joueur = (joueur == 'X') ? 'O' : 'X';
    }

    return 0;
}
