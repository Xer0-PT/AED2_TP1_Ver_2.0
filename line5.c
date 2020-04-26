#include "library.h"
/* 
#define SIZEHISTOGRAMA 50.0 int tamanho[128];

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

/* Travessia da árvore do ficheiro para o cálculo da Moda */
void TreeTraversal_Mode_Letters(BTree * tree, int wordSize[])
{
    if (tree != NULL)
    {
        TreeTraversal_Mode_Letters(tree->left, wordSize);

        wordSize[tree->data.lenghtWord] += tree->data.totalOccurrences;

        TreeTraversal_Mode_Letters(tree->right, wordSize);
    }
}