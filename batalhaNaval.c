#include <stdio.h>

// Função que imprime o tabuleiro
void print_tabuleiro(int tabuleiro[10][10])
{
    // Declarando variáveis auxiliares
    int linhas[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    char colunas[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    // Impressão do cabeçalho e das colunas
    printf("+=+=+=+=+=+=TABULEIRO+=+=+=+==+=+\n");
    printf("    ");
    for (int i =0; i < 10; i++)
        printf("%c  ", colunas[i]);
    printf("\n");

    // Loops aninhados para percorrer e imprimir o tabuleiro
    for (int i = 0; i < 10; i++)
    {
        if (i != 9)     // Checagem para impressão alinhada das linhas
            printf("%d - ", linhas[i]);
        else
            printf("%d- ", linhas[i]);
        for (int j = 0; j < 10; j++)
        {
            printf("%d  ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    return;
}

void navio_horizontal(int tabuleiro[10][10], int navio_h, int linha, int coluna)
{
    int tamanho = 0;
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(i == linha && tamanho < navio_h && j >= coluna)
            {
                tabuleiro[i][j] = navio_h;
                tamanho++;
            }
        }
    }
    return;
}

void navio_vertical(int tabuleiro[10][10], int navio_v, int linha, int coluna)
{
    int tamanho = 0;
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(i >= linha && tamanho < navio_v && j == coluna)
            {
                tabuleiro[i][j] = navio_v;
                tamanho++;
            }
        }
    }
    return;
}

int main()
{
    // Iniciando as variáveis
    int tabuleiro[10][10] = {0};
    
    // Mostrando tabuleiro para o usuário
    print_tabuleiro(tabuleiro);
    
    // Posição do navio horizontal
    int horizontal_linha = 3;
    int horizontal_coluna = 3;

    // Posição do navio vertical
    int vertical_linha = 7;
    int vertical_coluna = 5;

    // Fazendo a validação das posições dos navios
    int h = horizontal_coluna < 8 ? 1 : 0;
    int v = vertical_linha < 8 ? 1 : 0;

    if (h == 1 && v == 1)
    {
        navio_horizontal(tabuleiro, 3, horizontal_linha, horizontal_coluna);
        navio_vertical(tabuleiro, 3, vertical_linha, vertical_coluna);
        print_tabuleiro(tabuleiro);
    }
    else
        printf("ERRO! Navios mal posicionados!\n");

    return 0;
}
