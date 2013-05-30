#ifndef MATRIZ_ESPARSA_H
#define MATRIZ_ESPARSA_H

typedef struct t_celula{
    struct t_celula *direita, *abaixo;
    int linha, coluna;
    float valor;
}tipo_celula;

typedef struct{
    int m, n;
    tipo_celula *inicio, *fimLinha, *fimColuna;
}tipo_matriz_esparsa;

typedef tipo_matriz_esparsa matriz_esparsa;


//funcoes
matriz_esparsa *cria_matriz_esparsa(int m, int n);
int iniciaCabecas(matriz_esparsa *mat);
int insereCabecaLinha(matriz_esparsa *mat);
int insereCabecaColuna(matriz_esparsa *mat);

int insere(matriz_esparsa *mat, int linha, int coluna, float valor);
int imprimeMatriz(matriz_esparsa *mat);
int apagaMatriz(matriz_esparsa *mat);
matriz_esparsa *somaMatriz(matriz_esparsa *matA, matriz_esparsa *matB);
matriz_esparsa *multiplicaMatriz(matriz_esparsa *matA, matriz_esparsa *matB);

float obtemElementoPeloIndice(matriz_esparsa *mat, int linha, int coluna);

#endif //MATRIZ_ESPARSA_H
