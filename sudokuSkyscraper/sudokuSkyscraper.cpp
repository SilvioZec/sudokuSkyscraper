#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE 9
/// <summary>
/// verifica se a linha ou coluna entregue em forma de array possui o mesmo valor que total, de acordo com as regras do skyscraper
/// </summary>
/// <param name="total"></param>
/// <param name="array"></param>
/// <param name="tamanho"></param>
/// <returns></returns>
bool verificaLinhaColuna(int total, int array[], int tamanho) {
    int contador = 0;
    int i = 0;
    int numero = 0;
    while (i < tamanho)
    {
        if (array[i] > numero)
        {
            contador++;
            numero = array[i];
        }
        i++;
    }
    //confere se o valor dado com contador bate com total
    if (total == contador)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/// <summary>
/// recebe uma matriz e divide ela em arrays de acordo com a orientacao.
/// </summary>
/// <param name="matriz"></param>
/// <param name="tamanho"> tamanho da matriz</param>
/// <param name="numeroArray"> array a ser devolvido, de 1 ate tamanho </param>
/// <param name="orient"> 1 - cima pra baixo, 2 - baixo pra cima, 3 - esquerda pra direita, 4 - direita pra esquerda </param>
/// <returns></returns>
int* constroiArray(int matriz[][MAX_SIZE], int tamanho, int numeroArray, int orient) {
    // Verifica se o número do array é válido
    if (numeroArray < 1 || numeroArray > tamanho) {
        printf("Numero de array invalido.\n");
        return NULL;
    }

    // Calcula o índice do array desejado
    int indiceArray = numeroArray - 1;

    // Cria o array de destino e copia os elementos do array desejado
    int* array = (int*)malloc(sizeof(int) * tamanho);

    // de cima para baixo
    if (orient == 1) {
        for (size_t i = 0; i < tamanho; i++) {
            array[i] = matriz[i][indiceArray];
        }
    }

    // de baixo para cima
    if (orient == 2) {
        for (int i = tamanho - 1; i >= 0; i--) {
            array[tamanho - i - 1] = matriz[i][indiceArray];
        }
    }

    // da esquerda pra direita
    if (orient == 3) {
        for (int i = 0; i < tamanho; i++) {
            array[i] = matriz[indiceArray][i];
        }
    }

    // da direita pra esquerda
    if (orient == 4) {
        for (int i = tamanho - 1; i >= 0; i--) {
            array[tamanho - i - 1] = matriz[indiceArray][i];
        }
    }

    return array;
}

/// <summary>
/// funcao usada na main para preencher matriz parametros. não é correto usar leituras e escritas fora da main mas la esta
/// </summary>
/// <param name="tamanho"></param>
/// <param name="matrizParametros"></param>
void preencheMatrizParametros(int tamanho, int(*matrizParametros)[MAX_SIZE]) {
    printf("Defina os parametros da matriz: \n");
    
        printf("\nlinha de cima:\n");
        for (int j = 0; j < tamanho; j++) {
            scanf("%d", &matrizParametros[0][j]);
        }
        printf("\nlinha de baixo:\n");
        for (int j = 0; j < tamanho; j++) {
            scanf("%d", &matrizParametros[1][j]);
        }
        printf("\ncoluna esquerda:\n");
        for (int j = 0; j < tamanho; j++) {
            scanf("%d", &matrizParametros[2][j]);
        }
        printf("\ncoluna direita:\n");
        for (int j = 0; j < tamanho; j++) {
            scanf("%d", &matrizParametros[3][j]);
        }
   
}

/// <summary>
/// recebe tamanho, matriz e parametros. analisa todas as linhas e colunas de acordo com as regras do sudoku skyscraper
/// </summary>
/// <param name="tamanho"></param>
/// <param name="matrizParametros"></param>
/// <param name="matriz"></param>
/// <returns>true se validada, false se nao</returns>
bool validaMatriz(int tamanho, int(*matrizParametros)[MAX_SIZE], int(*matriz)[MAX_SIZE]) {
    bool validado = true;
    //cima para baixo
    for (size_t i = 0; i < tamanho; i++)
    {

        int* arrayP = constroiArray(matriz, tamanho, i + 1, 1);
        if (!verificaLinhaColuna(matrizParametros[0][i], arrayP, tamanho)) {
            validado = false;
        }

        free(arrayP);
    }

    //baixo para cima
    for (size_t i = 0; i < tamanho; i++)
    {

        int* arrayP = constroiArray(matriz, tamanho, i + 1, 2);
        if (!verificaLinhaColuna(matrizParametros[1][i], arrayP, tamanho)) {
            validado = false;
        }

        free(arrayP);
    }

    //esquerda a direita
    for (size_t i = 0; i < tamanho; i++)
    {
        int* arrayP = constroiArray(matriz, tamanho, i + 1, 3);
        if (!verificaLinhaColuna(matrizParametros[2][i], arrayP, tamanho)) {
            validado = false;
        }

        free(arrayP);
    }

    for (size_t i = 0; i < tamanho; i++)
    {
        int* arrayP = constroiArray(matriz, tamanho, i + 1, 4);
        if (!verificaLinhaColuna(matrizParametros[3][i], arrayP, tamanho)) {
            validado = false;
        }

        free(arrayP);
    }

    return validado;
}

/// <summary>
/// funcao recursiva que preenche a matriz ate que a funcao validaMatriz seja satisfeita.
/// </summary>
/// <param name="tamanho">tamanho da matriz principal</param>
/// <param name="matriz"></param>
/// <param name="matrizParametros"></param>
/// <returns>true se foi possivel alguma solucao, false se nao </returns>
bool preencherMatriz(int tamanho, int matriz[][MAX_SIZE], int(*matrizParametros)[MAX_SIZE]) {
    // Verifique se a matriz está completamente preenchida
    int linha = -1;
    int coluna = -1;

    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (matriz[i][j] == 0) {
                linha = i; // Atualiza somente a linha para célula não preenchida
                coluna = j;
                break;
            }
        }
        if (linha != -1) {
            break;
        }
    }

    if (linha == -1) {
        // Verifique se a matriz é válida com a função validarMatriz
        if (validaMatriz(tamanho, matrizParametros, matriz)) {
            return true;
        }
        else {
            return false;
        }
    }

    // Tente preencher a célula com números de 1 a tamanho
    for (int numero = 1; numero <= tamanho; numero++) {
        bool numeroRepetido = false;

        // Verifique se o número já existe na mesma linha ou coluna
        for (int i = 0; i < tamanho; i++) {
            if (matriz[linha][i] == numero || matriz[i][coluna] == numero) {
                numeroRepetido = true;
                break;
            }
        }

        if (!numeroRepetido) {
            matriz[linha][coluna] = numero;

            if (preencherMatriz(tamanho, matriz, matrizParametros)) {
                return true;
            }

            matriz[linha][coluna] = 0;
        }
    }

    return false;
}

/// <summary>
/// imprime matriz na tela
/// </summary>
/// <param name="tamanho"></param>
/// <param name="matriz"></param>
void imprimirMatriz(int tamanho, int matriz[][MAX_SIZE]) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    //recebe tamanho da matriz e o valida (4x4 a 9x9)
    int tamanho;
    printf("Digite o tamanho da matriz: ");
    scanf("%d", &tamanho);

    if (tamanho < 4 || tamanho > 9) {
        printf("Tamanho de matriz inválido. O tamanho deve estar entre 4 e 9.\n");
        return 0;
    }

    //cria matriz principal e matriz dos parametros

    int matriz[MAX_SIZE][MAX_SIZE] = { 0 };
    int matrizParametros[4][MAX_SIZE] = { 0 };

    //preenche paramentros
    preencheMatrizParametros(tamanho, matrizParametros);

    //cria matrizes ate preencher a condicao
    if (preencherMatriz(tamanho, matriz, matrizParametros))
    {
        printf("\nMatriz solucao:\n");
        imprimirMatriz(tamanho, matriz);
    }
    else
    {
        printf("Nao foi possivel encontrar uma solucao para o Sudoku.\n");
    }

    return 0;
}