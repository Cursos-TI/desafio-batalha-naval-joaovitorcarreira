#include <stdio.h>
#include <stdbool.h>

#define TAMANHO 10
#define TAMANHO_NAVIO 3

// Inicializa todas as posições com 0 (água)
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0; 
        }
    }
}

bool podePosicionarNavioHorizontal(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
     // Verifica se o navio cabe na linha
    if (coluna + TAMANHO_NAVIO > TAMANHO) return false;
     // Verifica se há sobreposição
    for (int i = 0; i < TAMANHO_NAVIO; i++) {   
        if (tabuleiro[linha][coluna + i] != 0) return false;
    }
    return true;
}

bool podePosicionarNavioVertical(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    // Verifica se o navio cabe na coluna
    if (linha + TAMANHO_NAVIO > TAMANHO) return false; 
    // Verifica se há sobreposição
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] != 0) return false; 
    }
    return true;
}

bool podePosicionarNavioDiagonal(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    // Verifica se o navio cabe na diagonal
    if (linha + TAMANHO_NAVIO > TAMANHO || coluna + TAMANHO_NAVIO > TAMANHO) return false; 
    // Verifica se há sobreposição na diagonal
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna + i] != 0) return false; 
    return true;
}
 // Marca a posição do navio com 3 (Horizontal)
void posicionarNavioHorizontal(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = 3;
    }
}
 // Marca a posição do navio com 3 (Vertical)
void posicionarNavioVertical(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = 3;
    }
}
// Marca a posição do navio com 3 (Diagonal)
void posicionarNavioDiagonal(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna + i] = 3; 
    }
}
 // Exibe o tabuleiro com alinhamento
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);

    // Coordenadas iniciais dos navios
    int linhaNavioHorizontal = 2;
    int colunaNavioHorizontal = 1;
    int linhaNavioVertical = 5;
    int colunaNavioVertical = 5;
    int linhaNavioDiagonal1 = 0; // Navio diagonal 1
    int colunaNavioDiagonal1 = 0;
    int linhaNavioDiagonal2 = 7; // Navio diagonal 2
    int colunaNavioDiagonal2 = 3;

    // Verifica se é possível posicionar os navios
    if (podePosicionarNavioHorizontal(tabuleiro, linhaNavioHorizontal, colunaNavioHorizontal)) {
        posicionarNavioHorizontal(tabuleiro, linhaNavioHorizontal, colunaNavioHorizontal);
    } else {
        printf("Não é possível posicionar o navio horizontalmente.\n");
    }

    if (podePosicionarNavioVertical(tabuleiro, linhaNavioVertical, colunaNavioVertical)) {
        posicionarNavioVertical(tabuleiro, linhaNavioVertical, colunaNavioVertical);
    } else {
        printf("Não é possível posicionar o navio verticalmente.\n");
    }

    if (podePosicionarNavioDiagonal(tabuleiro, linhaNavioDiagonal1, colunaNavioDiagonal1)) {
        posicionarNavioDiagonal(tabuleiro, linhaNavioDiagonal1, colunaNavioDiagonal1);
    } else {
        printf("Não é possível posicionar o navio diagonalmente (navio 1).\n");
    }

    if (podePosicionarNavioDiagonal(tabuleiro, linhaNavioDiagonal2, colunaNavioDiagonal2)) {
        posicionarNavioDiagonal(tabuleiro, linhaNavioDiagonal2, colunaNavioDiagonal2);
    } else {
        printf("Não é possível posicionar o navio diagonalmente (navio 2).\n");
    }

    // Exibe o tabuleiro
    exibirTabuleiro(tabuleiro); 

    return 0;
}
