Matriz Esparsa
==============

**Matriz esparsa** desenvolvida em **C** utilizando **Lista encadeada circular**. Apresentado na disciplina de **Estrutura de Dados I**.

Matrizes esparsas são matrizes nas quais a maioria das posições são preenchidas por zeros. Para estas matrizes, podemos economizar um espaço significativo de memória se apenas os termos diferentes de zero forem armazenados. As operações usuais sobre estas matrizes (somar, multiplicar, inverter, pivotar) também podem ser feitas em tempo muito menor se não armazenarmos as posições que contém zeros. Uma maneira eficiente de representar estruturas com tamanho variável e/ou desconhecido é através de alocação encadeada, utilizando listas. Vamos usar esta representação para armazenar as matrizes esparsas. Cada coluna da matriz será representada por uma lista linear circularListas!circulares com uma célula cabeça. Da mesma maneira, cada linha da matriz também será representada por uma lista linear circular com uma célula cabeça. Cada célula da estrutura, além das células-cabeça, representará os termos diferentes de zero da matriz e devem ter o seguinte tipo:

```c
typedef struct t_celula{
    struct t_celula *direita, *abaixo;
    int linha, coluna;
    float valor;
}tipo_celula;
```

O campo Abaixo deve ser usado para apontar o próximo elemento diferente de zero na mesma coluna. O campo Direita deve ser usado para apontar o próximo elemento diferente de zero na mesma linha. Dada uma matriz *A*, para um valor A(i,j) diferente de zero, deverá haver uma célula com o campo Valor contendo A(i,j), o campo Linha contendo *i* e o campo Coluna contendo *j*. Esta célula deverá pertencer à lista circular da linha *i* e também deverá pertencer à lista circular da coluna *j*. Ou seja, cada célula pertencerá a duas listas ao mesmo tempo. Para diferenciar as células cabeça, coloque -1 nos campos Linha e Coluna destas células. Considere a matriz esparsa seguinte:

![Matriz Esparsa Exemplo](https://raw.github.com/ArthurAssuncao/Matriz_Esparsa/master/img/matriz_esparsa_exemplo.gif)

A representação da matriz *A* pode ser vista na Figura 1.

*Figura 1: Exemplo de Matriz Esparsa*

![Matriz Esparsa Lista Encadeada Circular](https://raw.github.com/ArthurAssuncao/Matriz_Esparsa/master/img/matriz_esparsa_lista_encadeada_circular.gif)

Com esta representação, uma matriz esparsa com *r* elementos diferentes de zero gastará (m + n + r) células. É bem verdade que cada célula ocupa vários bytes na memória; no entanto, o total de memória usado será menor do que as  posições necessárias para representar a matriz toda, desde que *r* seja suficientemente pequeno.

*Texto de explicação retirado do Livro Projeto de Algoritmos com Implementações em Pascal e C de Nivio Ziviani, página 59, exercício 3.*
