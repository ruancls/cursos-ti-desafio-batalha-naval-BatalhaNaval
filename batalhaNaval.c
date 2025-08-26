#include <stdio.h>

int main(void) {
    // Matriz do tabuleiro (10x10), inicializada com água (0)
    int tabuleiro[10][10] = {0};

    // Representação dos navios (3 posições cada um)
    int navio1[3] = {3, 3, 3}; // Navio horizontal
    int navio2[3] = {3, 3, 3}; // Navio vertical

    // Coordenadas iniciais dos navios
    int linha_navio_horizontal = 2; // Linha 2
    int coluna_navio_horizontal = 4; // Começa na coluna 4

    int linha_navio_vertical = 5; // Começa na linha 5
    int coluna_navio_vertical = 7; // Coluna 7

    // Posicionando navio horizontal
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha_navio_horizontal][coluna_navio_horizontal + i] = navio1[i];
    }

    // Posicionando navio vertical
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha_navio_vertical + i][coluna_navio_vertical] = navio2[i];
    }

    // Coordenadas das linhas e colunas
    char coordenadas_A[10] = {'A','B','C','D','E','F','G','H','I','J'};
    int coordenadas_B[10]  = {1,2,3,4,5,6,7,8,9,10};

    printf("===== Tabuleiro =====\n");

    // Cabeçalho com letras (colunas)
    printf("    ");
    for (int i = 0; i < 10; i++) {
        printf(" %1c", coordenadas_A[i]);
    }

    printf("\n    ");
    printf("--------------------\n");

    // Exibição do tabuleiro
    for (int i = 0; i < 10; i++) {
        printf("%2d |", coordenadas_B[i]);
        for (int j = 0; j < 10; j++) {
            printf("%2d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}

/*
Desafio: nível novato
Posicionando Navios no Tabuleiro

Neste primeiro desafio, você dará o primeiro passo na construção do seu jogo de Batalha Naval. Você utilizará seus conhecimentos de vetores (arrays unidimensionais) em C 
para representar um tabuleiro simplificado e posicionar dois navios nele: um na vertical e outro na horizontal. Continue o desenvolvimento no mesmo programa iniciado anteriormente.

1 - O que você vai fazer:
* Represente o Tabuleiro: Utilize uma matriz (array bidimensional) para representar o tabuleiro do Batalha Naval. Neste nível novato, o tabuleiro terá um tamanho fixo 10x10. 
* Inicialize todas as posições do tabuleiro com o valor 0, representando água.
* Posicione os Navios: Declare e inicialize dois vetores (arrays unidimensionais) para representar os navios. Cada navio ocupará um número fixo de posições no tabuleiro (defina esse tamanho, por exemplo, 3 posições). 
* Um navio será posicionado horizontalmente e o outro verticalmente. Represente as posições ocupadas pelos navios na matriz do tabuleiro com o valor 3. 
* Você deverá escolher as coordenadas iniciais de cada navio e garantir que eles estejam completamente dentro dos limites do tabuleiro e não se sobreponham. 
Dica: O posicionamento do navio pode ser feito copiando o valor 3 de cada posição do vetor do navio para as posições correspondentes na matriz do tabuleiro, de acordo com a orientação (horizontal ou vertical) do navio.
* Exiba o Tabuleiro: Utilize loops aninhados e o comando printf para exibir o tabuleiro no console. Mostre a matriz completa, com 0s representando água e 3s representando as partes dos navios. 
* A saída deve ser clara e organizada, permitindo visualizar facilmente a posição dos navios. 
Dica: Imprima um espaço ou outro caractere separador entre os elementos da matriz para facilitar a visualização.

2 - Requisitos funcionais
* O programa deve receber as coordenadas iniciais (linha e coluna) de cada navio como entrada (pode ser definido diretamente no código).
* O programa deve validar se as coordenadas e o tamanho dos navios são válidos dentro dos limites do tabuleiro.
* O programa deve garantir que os navios não se sobreponham.
* O programa deve exibir o tabuleiro no console com os navios posicionados corretamente.

3 - Requisitos não funcionais
* Performance: O programa deve executar de forma eficiente, sem causar atrasos perceptíveis.
* Documentação: O código deve ser bem documentado, com comentários claros explicando a lógica e o propósito de cada parte do programa. 
* Utilize comentários para explicar a função de cada variável, loop e bloco de código.
* Legibilidade: O código deve ser escrito de forma clara, organizada e fácil de entender, com nomes de variáveis descritivos e indentação consistente.

4 - Simplificações para o nível básico
* O tamanho do tabuleiro e dos navios é fixo (10x10).
* Os navios têm tamanho fixo igual a 3.
* As coordenadas dos navios são definidas diretamente no código, sem input do usuário.
* Não é necessário implementar a lógica do jogo (ataques, acertos, etc.) neste nível.
* A validação de sobreposição de navios pode ser simplificada.
*/
