#include <stdio.h>
#include <stdlib.h>
#include "arquivo.h"
#include "matriz_esparsa.h"

matriz_esparsa *lerMatriz(char *nome){ //nome ou endereco do arquivo
    matriz_esparsa *mat;

    char linha[TAM_BUFFER];

    int m=0, n=0;
    int l=0, c=0;
    float valor=0.0;

    FILE *arquivo;

    arquivo = fopen(nome,"r");
    if (!arquivo){
      arquivo = fopen("arquivo.txt","w");
      fprintf(arquivo, "Erro ao abrir arquivo\n");
      fclose(arquivo);
      return NULL;
    }

    fgets(linha, TAM_BUFFER, arquivo); //le primeira linha
    sscanf(linha, "%d %d", &m, &n);

    if (m<=0 || n<=0){
        return 0;
    }

    mat = cria_matriz_esparsa(m, n);

    while(fgets(linha, TAM_BUFFER, arquivo)){
        sscanf(linha, "%d %d %f", &l, &c, &valor);
        if (valor){
            insere(mat, l, c, valor);
        }
    }
    fclose(arquivo);
    return mat;
}

