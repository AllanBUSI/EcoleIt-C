// Permet d'utiliser les fonctions d'entrée/sortie comme printf et scanf
#include <stdio.h>
#include <stdlib.h>

#define TAILLE 3  // Taille de la grille (3x3 pour le morpion)

// Met des espaces (' ') dans chaque case de la grille pour qu’elle soit vide au départ
void initialiserGrille(char grille[TAILLE][TAILLE]) {
    for (int i = 0; i < TAILLE; i++) {           // Pour chaque ligne
        for (int j = 0; j < TAILLE; j++) {       // Pour chaque colonne
            grille[i][j] = ' ';                  // Met un espace vide
        }
    }
}

// Affiche chaque case avec des séparateurs pour ressembler à une grille de morpion
void afficherGrille(char grille[TAILLE][TAILLE]) {
    printf("\n");  // Ligne vide avant d'afficher la grille
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            printf(" %c ", grille[i][j]);        // Affiche la case (vide ou X/O)
            if (j < TAILLE - 1) printf("|");     // Affiche le séparateur vertical
        }
        printf("\n");
        if (i < TAILLE - 1) printf("---+---+---\n");  // Séparateur horizontal
    }
    printf("\n");
}

// Met le symbole du joueur (X ou O) si la case est vide et valide
int jouerCoup(char grille[TAILLE][TAILLE], int ligne, int colonne, char joueur) {
    if (ligne < 0 || ligne >= TAILLE || colonne < 0 || colonne >= TAILLE)
        return 0;  // Coordonnées hors limites

    if (grille[ligne][colonne] != ' ')
        return 0;  // Case déjà prise

    grille[ligne][colonne] = joueur;  // Place le pion du joueur
    return 1;  // Coup valide
}

// Vérifie si le joueur a gagné en ligne, colonne ou diagonale
int verifierVictoire(char grille[TAILLE][TAILLE], char joueur) {
    for (int i = 0; i < TAILLE; i++) {
        // Vérifie chaque ligne et chaque colonne
        if ((grille[i][0] == joueur && grille[i][1] == joueur && grille[i][2] == joueur) ||
            (grille[0][i] == joueur && grille[1][i] == joueur && grille[2][i] == joueur))
            return 1;  // Le joueur a aligné 3 symboles
    }

    // Vérifie les deux diagonales
    if ((grille[0][0] == joueur && grille[1][1] == joueur && grille[2][2] == joueur) ||
        (grille[0][2] == joueur && grille[1][1] == joueur && grille[2][0] == joueur))
        return 1;

    return 0;  // Pas de victoire
}


// Si aucune case vide n’est trouvée, la grille est pleine
int grillePleine(char grille[TAILLE][TAILLE]) {
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            if (grille[i][j] == ' ')  // Case encore vide
                return 0;  // Pas encore pleine
        }
    }
    return 1;  // Toutes les cases sont remplies
}

int mains() {
    char grille[TAILLE][TAILLE];  // La grille de jeu (3x3)
    char joueur = 'X';            // Premier joueur est X
    int ligne, colonne;           // Coordonnées du coup

    initialiserGrille(grille);    // Vide la grille au début

    while (1) {  // Boucle infinie jusqu’à victoire ou match nul
        afficherGrille(grille);  // Montre la grille actuelle
        printf("Joueur %c - Entrez ligne et colonne (1 à 3) : ", joueur);
        scanf("%d %d", &ligne, &colonne);  // Lire les coordonnées
        ligne--; colonne--;  // Adapter (1 à 3) → (0 à 2) pour tableau

        if (!jouerCoup(grille, ligne, colonne, joueur)) {
            printf("❌ Coup invalide. Réessayez.\n");
            continue;  // Rejouer ce tour
        }

        if (verifierVictoire(grille, joueur)) {
            afficherGrille(grille);  // Montre la grille finale
            printf("🎉 Le joueur %c a gagné !\n", joueur);
            exit(1);  // Fin de jeu
        }

        if (grillePleine(grille)) {
            afficherGrille(grille);
            printf("🤝 Match nul !\n");
            exit(1);
        }

        joueur = (joueur == 'X') ? 'O' : 'X';  // Alterne joueur
    }

    return 0;  // Fin du programme
}

