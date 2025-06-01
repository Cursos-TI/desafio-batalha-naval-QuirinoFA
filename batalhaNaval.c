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
                if (tabuleiro[i][j] == 0)
                {
                    tabuleiro[i][j] = navio_h;
                    tamanho++;
                }
                else
                {
                    printf("ERRO! Navio sobreposto!\n");
                    return;
                }
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
                if( tabuleiro[i][j] == 0)
                {
                    tabuleiro[i][j] = navio_v;
                    tamanho++;
                }
                else
                {
                    printf("ERRO! Navio sobreposto!\n");
                }
            }
        }
    }
    return;
}

void navio_diagonal_principal(int tabuleiro[10][10], int navio_v, int linha, int coluna)
{
    int tamanho = 0;
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(i == linha + tamanho && tamanho < navio_v && j == coluna + tamanho)
            {
                if( tabuleiro[i][j] == 0)
                {
                    tabuleiro[i][j] = navio_v;
                    tamanho++;
                }
                else
                {
                    printf("ERRO! Navio sobreposto!\n");
                }
            }
        }
    }
    return;
}

void navio_diagonal_secundaria(int tabuleiro[10][10], int navio_v, int linha, int coluna)
{
    int tamanho = 0;
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(i == linha + tamanho && tamanho < navio_v && j == coluna - tamanho)
            {
                if( tabuleiro[i][j] == 0)
                {
                    tabuleiro[i][j] = navio_v;
                    tamanho++;
                }
                else
                {
                    printf("ERRO! Navio sobreposto!\n");
                }
            }
        }
    }
    return;
}

int main()
{
    // Iniciando as variáveis
    int tabuleiro[10][10] = {0};
    int tam_navio = 3;
    
    // Mostrando tabuleiro para o usuário
    print_tabuleiro(tabuleiro);
    
    // Posição do navio horizontal
    int horizontal_linha = 1;
    int horizontal_coluna = 1;

    // Posição do navio vertical
    int vertical_linha = 7;
    int vertical_coluna = 5;

    // Posição do navio diagonal principal
    int principal_linha = 6;
    int principal_coluna = 1;

    // Posição do navio diagonal secundária
    int secundaria_linha = 1;
    int secundaria_coluna = 8;

    // Fazendo a validação das posições dos navios
    int h = horizontal_coluna + tam_navio <= 10 ? 1 : 0;
    int v = vertical_linha + tam_navio <= 10 ? 1 : 0;
    int p = principal_linha + tam_navio <= 10 && principal_coluna + tam_navio <= 10 ? 1 : 0;
    int s = secundaria_linha +tam_navio <= 10 && secundaria_coluna - tam_navio >= 0 ? 1 : 0;

    if (h == 1 && v == 1 && p == 1 && s == 1)
    {
        navio_horizontal(tabuleiro, tam_navio, horizontal_linha, horizontal_coluna);
        navio_vertical(tabuleiro, tam_navio, vertical_linha, vertical_coluna);
        navio_diagonal_principal(tabuleiro, tam_navio, principal_linha, principal_coluna);
        navio_diagonal_secundaria(tabuleiro, tam_navio, secundaria_linha, secundaria_coluna);
        print_tabuleiro(tabuleiro);
    }
    else
        printf("ERRO! Navios mal posicionados!\n");

    return 0;
}
