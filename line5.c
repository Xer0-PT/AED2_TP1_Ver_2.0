#include "library.h"
/* 
#define SIZEHISTOGRAMA 50.0 int tamanho[128];

tamanho[strlen(palavra)]++;

int histograma[SIZEHISTOGRAMA];

histograma[round((probabilidade *SIZEHISTOGRAMA))]++ 

for(int i) class = i/SIZEHISTOGRAMA
 */

/* Travessia na árvore do ficheiro para contar o */
/* total de letras contidas em todas as palavras do ficheiro */
/* Acrescenta na variável totalLetters o tamanho da palavra e */
/* multiplica pelo numero de vezes que essa palavra aparece  */
void TreeTraversal_Total_Letters(BTree *tree, unsigned long int *totalLetters)
{
    if (tree)
    {
        TreeTraversal_Total_Letters(tree->left, totalLetters);

        *totalLetters += tree->data.lenghtWord * tree->data.totalOccurrences;

        TreeTraversal_Total_Letters(tree->right, totalLetters);
    }
}

/* Cálculo da Média do tamanho das palavras */
float Average_Line_5(unsigned long int totalLetters, int totalWords)
{
    return (float)totalLetters / totalWords;
}

/* Mostrar o total de letras e a média */
void PrintResults_Line_5(unsigned long int totalLetters ,float averageLength)
{
    printf("\nTotal Letras: %lu", totalLetters);
    printf("\nMedia Tamanho Palavras: %.3f\n\n", averageLength);
}

/* Travessia da árvore do ficheiro para o cálculo da Moda */
void TreeTraversal_Mode_Letters(BTree * tree, BtreeMode * treeMode)
{
    if (tree != NULL)
    {
        TreeTraversal_Mode_Letters(tree->left, treeMode);

        treeMode = ModeCalculus(tree, treeMode);

        TreeTraversal_Mode_Letters(tree->right, treeMode);
    }
}

/* Árvore Auxiliar para guardar o cálculo da Moda */
BtreeMode * ModeCalculus(BTree * tree, BtreeMode * treeMode)
{
    if(treeMode)
    {
        if(tree->data.lenghtWord == treeMode->wordLength)
            treeMode->wordCount += tree->data.totalOccurrences;

        if (tree->data.lenghtWord < treeMode->wordLength)
            treeMode->left = ModeCalculus(tree, treeMode->left);

        if (tree->data.lenghtWord > treeMode->wordLength)
            treeMode->right = ModeCalculus(tree, treeMode->right);
    }
    else
    {
        treeMode = (BtreeMode*) malloc (sizeof(BtreeMode));

        treeMode->wordLength = tree->data.lenghtWord;
        treeMode->wordCount = tree->data.totalOccurrences;
        treeMode->left = treeMode->right = NULL;
    }
    return treeMode;   
}

void PrintMode(BtreeMode *treeMode)
{
    if (treeMode)
    {
        PrintMode(treeMode->left);

        printf("\nTamanho Palavra: %d", treeMode->wordLength);
        printf("\nNumero de palavras com este tamanho: %d", treeMode->wordCount);

        PrintMode(treeMode->left);
    }
}