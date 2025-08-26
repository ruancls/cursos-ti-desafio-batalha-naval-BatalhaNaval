#include <stdio.h>
#include <stdlib.h> // Para abs()

// Função para aplicar área de efeito tipo cone (triângulo invertido)
void aplicarCone(int tabuleiro[10][10], int origem_linha, int origem_coluna) {
    for (int i = 0; i < 3; i++) { // Altura do cone
        for (int j = -i; j <= i; j++) { // Largura do cone
            int linha = origem_linha + i;
            int coluna = origem_coluna + j;
            if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10 && tabuleiro[linha][coluna] == 0) {
                tabuleiro[linha][coluna] = 5;
            }
        }
    }
}

// Função para aplicar área de efeito tipo cruz
void aplicarCruz(int tabuleiro[10][10], int origem_linha, int origem_coluna) {
    for (int i = -2; i <= 2; i++) {
        if (origem_linha + i >= 0 && origem_linha + i < 10 && tabuleiro[origem_linha + i][origem_coluna] == 0) {
            tabuleiro[origem_linha + i][origem_coluna] = 5;
        }
        if (origem_coluna + i >= 0 && origem_coluna + i < 10 && tabuleiro[origem_linha][origem_coluna + i] == 0) {
            tabuleiro[origem_linha][origem_coluna + i] = 5;
        }
    }
}

// Função para aplicar área de efeito tipo octaedro (losango)
void aplicarOctaedro(int tabuleiro[10][10], int origem_linha, int origem_coluna) {
    for (int i = -2; i <= 2; i++) {
        for (int j = -2; j <= 2; j++) {
            if (abs(i) + abs(j) <= 2) {
                int linha = origem_linha + i;
                int coluna = origem_coluna + j;
                if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10 && tabuleiro[linha][coluna] == 0) {
                    tabuleiro[linha][coluna] = 5;
                }
            }
        }
    }
}

int main(void) {
    // Matriz 10x10 inicializada com água (valor 0)
    int tabuleiro[10][10] = {0};

    // Cada navio ocupa 3 posições
    int navio1[3] = {3, 3, 3}; // Navio horizontal
    int navio2[3] = {3, 3, 3}; // Navio vertical
    int navio3[3] = {3, 3, 3}; // Navio diagonal principal (↘)
    int navio4[3] = {3, 3, 3}; // Navio diagonal secundária (↙)

    // Coordenadas iniciais dos navios
    int linha_navio_horizontal = 2;
    int coluna_navio_horizontal = 4;

    int linha_navio_vertical = 5;
    int coluna_navio_vertical = 7;

    int linha_navio_diag1 = 0;
    int coluna_navio_diag1 = 0;

    int linha_navio_diag2 = 0;
    int coluna_navio_diag2 = 9;

    // Posiciona navio horizontal (↔)
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha_navio_horizontal][coluna_navio_horizontal + i] = navio1[i];
    }

    // Posiciona navio vertical (↕)
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha_navio_vertical + i][coluna_navio_vertical] = navio2[i];
    }

    // Posiciona navio diagonal principal (↘)
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha_navio_diag1 + i][coluna_navio_diag1 + i] = navio3[i];
    }

    // Posiciona navio diagonal secundária (↙)
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha_navio_diag2 + i][coluna_navio_diag2 - i] = navio4[i];
    }

    // Aplica habilidades especiais
    aplicarCone(tabuleiro, 6, 2);       // Cone com origem em (6,2)
    aplicarCruz(tabuleiro, 4, 4);       // Cruz com origem em (4,4)
    aplicarOctaedro(tabuleiro, 8, 8);   // Octaedro com origem em (8,8)

    // Cabeçalho do Tabuleiro
    char coordenadas_A[10] = {'A','B','C','D','E','F','G','H','I','J'};
    int coordenadas_B[10]  = {1,2,3,4,5,6,7,8,9,10};

    // Impressão do Tabuleiro
    printf("===== Tabuleiro =====\n");
    printf("    ");
    for (int i = 0; i < 10; i++) {
        printf(" %c", coordenadas_A[i]);
    }
    printf("\n    --------------------\n");

    for (int i = 0; i < 10; i++) {
        printf("%2d |", coordenadas_B[i]);
        for (int j = 0; j < 10; j++) {
            printf(" %d", tabuleiro[i][j]);
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

Desafio: nível aventureiro
Tabuleiro Completo e Navios Diagonais

Neste desafio, o programa simula um tabuleiro de Batalha Naval com quatro navios posicionados: dois em direções tradicionais (horizontal e vertical) 
e dois em diagonais (↘ e ↙).

1 - O que o programa faz:
* Representa o tabuleiro com uma matriz 10x10, inicializada com o valor 0 (água).
* Declara quatro navios, cada um com tamanho fixo de 3 posições.
* Posiciona os navios no tabuleiro:
  - Navio 1: horizontal (linha fixa, coluna variável).
  - Navio 2: vertical (coluna fixa, linha variável).
  - Navio 3: diagonal principal (linha e coluna crescem juntas).
  - Navio 4: diagonal secundária (linha cresce, coluna decresce).
* Preenche as posições dos navios com o valor 3.
* Exibe o tabuleiro completo no console, com cabeçalho de coordenadas e visualização clara das posições ocupadas.

2 - Requisitos funcionais atendidos:
* Utiliza matriz 10x10 para representar o tabuleiro.
* Posiciona quatro navios, incluindo dois diagonais.
* Garante que os navios estejam dentro dos limites do tabuleiro.
* Exibe o tabuleiro com os navios corretamente posicionados.

3 - Requisitos não funcionais atendidos:
* Performance eficiente, sem atrasos perceptíveis.
* Código bem documentado, com comentários explicativos em cada etapa.
* Legibilidade mantida com nomes de variáveis descritivos e indentação consistente.

4 - Simplificações aplicadas:
* Tamanho do tabuleiro e dos navios é fixo.
* Coordenadas dos navios são definidas diretamente no código.
* Validação de sobreposição é simplificada.
* Não há lógica de ataque ou acerto neste nível.

Desafio: Nível Mestre
Habilidades Especiais e Áreas de Efeito
Neste desafio final, você adicionará habilidades especiais ao jogo, com áreas de efeito visuais sobre o tabuleiro.

1 - O que você vai fazer:
* Manter o tabuleiro 10x10 como base.
* Criar três matrizes de habilidade (5x5 ou 7x7) para representar:
  - Cone: forma triangular expandindo para baixo.
  - Cruz: linhas central horizontal e vertical.
  - Octaedro: formato de losango (diamante).
* Definir um ponto de origem para cada habilidade no tabuleiro.
* Sobrepor as matrizes de habilidade ao tabuleiro, marcando as áreas afetadas com o valor 5.
* Exibir o tabuleiro com símbolos distintos:
  - Água (0)
  - Navio (3)
  - Área de habilidade (5)

2 - Requisitos funcionais:
* Matrizes de habilidade com valores 0 e 1.
* Ponto de origem definido diretamente no código.
* Sobreposição dinâmica com loops aninhados e condicionais.
* Impressão clara do tabuleiro com os efeitos visuais.

3 - Requisitos não funcionais:
* Execução eficiente.
* Código bem documentado, explicando a lógica das áreas de efeito.
* Legibilidade com nomes descritivos e estrutura organizada.

4 - Simplificações:
* Tamanho fixo das matrizes de habilidade.
* Sem entrada do usuário.
* Sem lógica de dano ou interação com navios.
* Validação de limites simplificada.
*/
