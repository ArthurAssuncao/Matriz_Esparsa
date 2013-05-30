#ifndef ARQUIVO_H
#define ARQUIVO_H
#include "matriz_esparsa.h"

#define TAM_BUFFER 255
#define LIMPA_VARIAVEIS(_string, _tamanho) memset(_string,'\0',_tamanho)
#define TAM_NUMERO 10

matriz_esparsa *lerMatriz(char *nome); //nome ou endereco do arquivo


#endif //ARQUIVO_H
