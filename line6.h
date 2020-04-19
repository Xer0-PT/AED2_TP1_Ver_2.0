#ifndef LINE6_H
#define LINE6_H

#include "library.h"

void IsInTree(BTree *tree, char *word, int *ptrLine6)
{
    if(tree)
    {
        if(strcmp(tree->data.word, word) < 0)
            IsInTree(tree->left, word, ptrLine6);
        
        if(strcmp(tree->data.word, word) > 0)
            IsInTree(tree->right, word, ptrLine6);

        if(strcmp(tree->data.word, word) == 0)
            *ptrLine6 = tree->data.totalOccurrences;
    }
}

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

int Quartiles(int maxCount, int line6)
{
    float quartile_1 = (float)maxCount / 4;
    float quartile_2 = (float)maxCount / 2;
    float quartile_3 = (float)maxCount / 4 + quartile_2;

    puts("Quartis:");
    printf("\nQ1 -> 0 a %.0f", quartile_1);
    printf("\nQ2 -> %.0f a %.0f", quartile_1 + 1, quartile_2);
    printf("\nQ3 -> %.0f a %.0f", quartile_2 + 1, quartile_3);
    printf("\nQ4 -> %.0f a %d", quartile_3 + 1, maxCount);

    if (line6 <= quartile_1)
        return 1;

    if (line6 > quartile_1 && line6 <= quartile_2)
        return 2;

    if (line6 > quartile_2 && line6 <= quartile_3)
        return 3;
    
    return 4;
}

#endif