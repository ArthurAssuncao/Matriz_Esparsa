#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "matriz_esparsa.h"
#include "arquivo.h"
#include "constantes.h"

int main(){
    TITULO_JANELA("title Arthur Assuncao - Estrutura de Dados 1 - Matriz Esparsa && color 0a");
    int opcao = 0;
    int mat = 0;
    char nome[TAM_BUFFER];

    matriz_esparsa *matrizA = NULL;
    matriz_esparsa *matrizB = NULL;
    matriz_esparsa *matrizC = NULL;

    do{ //loop do menu
        LIMPA_TELA();
        printf("\n\t1. Ler Matriz");
        printf("\n\t2. Imprimir Matriz");
        printf("\n\t3. Apagar Matriz");
        printf("\n\t4. Somar Matrizes");
        printf("\n\t5. Multiplicar Matrizes");
        printf("\n\t6. Realizar testes do Livro do Nivio Ziviani");
        printf("\n\t0. Sair");
        printf("\n\nOpcao: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:{ //Ler Matriz
                LIMPA_TELA();
                printf("Forneca o nome ou endereco do arquivo q sera aberto\n");
                LIMPA_BUFFER();
                scanf(" "); //evita q o fgets aceite nome q comece com espaco ou linha em branco
                fgets(nome, TAM_BUFFER, stdin);
                nome[strlen(nome)-1] = '\0'; //tira o \n do final da string
                LIMPA_BUFFER();
                printf("O arquivo será aberto na matriz A-1 ou na B-2 ?\n");
                scanf("%d", &mat);
                switch(mat){
                    case 1:{
                        if (matrizA){
                            apagaMatriz(matrizA);
                        }
                        matrizA = lerMatriz(nome);
                        if(matrizA == NULL){
                            printf("Erro ao abrir arquivo");
                        }
                        break;
                    }
                    case 2:{
                        if (matrizB){
                            apagaMatriz(matrizB);
                        }
                        matrizB = lerMatriz(nome);
                        if(matrizB == NULL){
                            printf("Erro ao abrir arquivo");
                        }
                        break;
                    }
                }
                PAUSA_TELA();
                break;
            }
            case 2:{ //Imprime Matriz
                LIMPA_TELA();
                printf("Qual matriz sera impressa na tela? A-1, B-2, C-3\n");
                scanf("%d", &mat);
                switch(mat){
                    case 1:{
                        if (!matrizA){
                            break;
                        }
                        imprimeMatriz(matrizA);
                        break;
                    }
                    case 2:{
                        if (!matrizB){
                            break;
                        }
                        imprimeMatriz(matrizB);
                        break;
                    }
                    case 3:{
                        if (!matrizC){
                            break;
                        }
                        imprimeMatriz(matrizC);
                        break;
                    }
                }
                PAUSA_TELA();
                break;
            }
            case 3:{ //Apagar Matriz
                LIMPA_TELA();
                printf("Qual matriz sera apagada? A-1, B-2, C-3\n");
                scanf("%d", &mat);
                switch(mat){
                    case 1:{
                        if(matrizA){
                            apagaMatriz(matrizA);
                        }
                        break;
                    }
                    case 2:{
                        if (matrizB){
                            apagaMatriz(matrizB);
                        }
                        break;
                    }
                    case 3:{
                        if (matrizC){
                            apagaMatriz(matrizC);
                        }
                        break;
                    }
                }
                PAUSA_TELA();
                break;
            }
            case 4:{ //Somar Matrizes
                LIMPA_TELA();
                if (matrizA && matrizB){
                    printf("A matriz C recebera o resultado de A + B\n");
                    matrizC = somaMatriz(matrizA, matrizB);
                }
                PAUSA_TELA();
                break;
            }
            case 5:{ //Multiplicar Matrizes
                LIMPA_TELA();
                if (matrizA && matrizB){
                    printf("A matriz C recebera o resultado de A x B\n");
                    matrizC = multiplicaMatriz(matrizA, matrizB);
                }
                PAUSA_TELA();
                break;
            }
            case 6:{ //Testes do Livro
                LIMPA_TELA();
                if (matrizA){
                    apagaMatriz(matrizA);
                }
                if (matrizB){
                    apagaMatriz(matrizB);
                }
                if (matrizC){
                    apagaMatriz(matrizC);
                }

                matrizA = lerMatriz("matriz_A.txt");
                imprimeMatriz(matrizA);

                matrizB = lerMatriz("matriz_B.txt");
                imprimeMatriz(matrizB);

                matrizC = somaMatriz(matrizA, matrizB);
                imprimeMatriz(matrizC);

                apagaMatriz(matrizC);
                matrizC = multiplicaMatriz(matrizA, matrizB);
                apagaMatriz(matrizB);
                apagaMatriz(matrizC);
                matrizB = lerMatriz("matriz_B.txt");
                imprimeMatriz(matrizA);
                imprimeMatriz(matrizB);
                matrizC = somaMatriz(matrizA, matrizB);
                imprimeMatriz(matrizC);
                matrizC = multiplicaMatriz(matrizA, matrizB);
                imprimeMatriz(matrizC);
                matrizC = multiplicaMatriz(matrizB, matrizB);
                imprimeMatriz(matrizB);
                imprimeMatriz(matrizC);
                apagaMatriz(matrizA);
                apagaMatriz(matrizB);
                apagaMatriz(matrizC);

                PAUSA_TELA();
                break;
            }
        }

    }while(opcao != 0);

    printf("\n\n");

    PAUSA_TELA();
    return 0;
}
