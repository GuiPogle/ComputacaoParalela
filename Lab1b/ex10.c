// Ex. 10

void multiplicarLinha(int matriz[][COLUNAS], int linha, int colunas, int multiplicador) {
    for(int i = 0; i < colunas; i++) {
        matriz[linha][i] = multiplicador;
    }
}

void multiplicarColuna(int matriz[][COLUNAS], int linhas, int coluna, int multiplicador) {
    for(int i = 0; i < linhas; i++) {
        matriz[i][coluna]= multiplicador;
    }
}
