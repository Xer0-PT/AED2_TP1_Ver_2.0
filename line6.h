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

#endif
