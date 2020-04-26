#include "library.h"

/* Verifica se a palavra inserida pelo utilizador existe*/
/* Se existir, totalOcurrencesLine6 toma o valor das ocorrencias da palavra */
void IsInTree(BTree *tree, char *word, int *ptrTotalOcurrencesLine6)
{
    if(tree)
    {
        if(strcmp(tree->data.word, word) < 0)
            IsInTree(tree->left, word, ptrTotalOcurrencesLine6);
        
        if(strcmp(tree->data.word, word) > 0)
            IsInTree(tree->right, word, ptrTotalOcurrencesLine6);

        if(strcmp(tree->data.word, word) == 0)
            *ptrTotalOcurrencesLine6 = tree->data.totalOccurrences;
    }
}

/* Travessia sobre a árvore do ficheiro para */ 
/* verificar qual a palavra que se repete mais vezes. */
/* Para posteriormente fazer o cálculo dos quartis sobre esse número */
/* MaxCount toma o valor da palavra que mais se repete */
void MaxCount(BTree *tree, int *ptrMaxCount)
{
    if (tree)
    {
        MaxCount(tree->left, ptrMaxCount);
        if (tree->data.totalOccurrences > *ptrMaxCount)
        {
            *ptrMaxCount = tree->data.totalOccurrences;
        }
        MaxCount(tree->right, ptrMaxCount);
    }
}

/* Recebe o valor da palavra que se repete mais vezes */
/* e quantas vezes se repete a palavra inserida pelo utilizador */
/* Cálculo dos quartis e retorna o quartil a que pertence a palavra */
int Quartiles(int maxCount, int totalOcurrencesLine6)
{
    float quartile_1 = (float)maxCount / 4;
    float quartile_2 = (float)maxCount / 2;
    float quartile_3 = (float)maxCount / 4 + quartile_2;

    puts("Quartis:");
    printf("\tQ1 -> 0 a %.0f", quartile_1);
    printf("\n\tQ2 -> %.0f a %.0f", quartile_1 + 1, quartile_2);
    printf("\n\tQ3 -> %.0f a %.0f", quartile_2 + 1, quartile_3);
    printf("\n\tQ4 -> %.0f a %d", quartile_3 + 1, maxCount);

    if (totalOcurrencesLine6 <= quartile_1)
        return 1;

    if (totalOcurrencesLine6 > quartile_1 && totalOcurrencesLine6 <= quartile_2)
        return 2;

    if (totalOcurrencesLine6 > quartile_2 && totalOcurrencesLine6 <= quartile_3)
        return 3;
    
    return 4;
}