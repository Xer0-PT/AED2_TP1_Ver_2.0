#ifndef LINE5_H
#define LINE5_H

#include "library.h"

void TreeTraversal_Total_Letters(BTree *tree, unsigned long int *totalLetters)
{
    if (tree)
    {
        TreeTraversal_Total_Letters(tree->left, totalLetters);

        /* Acrescenta na variavel Total Letras o tamanho da palavra * o numero de vezes que essa palavra aparece */
        *totalLetters += tree->data.lenghtWord * tree->data.totalOccurrences;

        TreeTraversal_Total_Letters(tree->right, totalLetters);
    }
}

float Average_Line_5(unsigned long int totalLetters, int totalWords)
{
    /* Média do tamanho das palavras */
    return (float)totalLetters / totalWords;
}

void PrintResults_Line_5(unsigned long int totalLetters ,float averageLength)
{
    printf("\nTotal Letras: %lu", totalLetters);
    printf("\nMedia Tamanho Palavras: %.3f\n\n", averageLength);
}

void TreeTraversal_Mode_Letters(BTree * tree, BtreeMode * treeMode)
{
    if (tree)
    {
        TreeTraversal_Mode_Letters(tree->left, treeMode);

        treeMode = ModeCalculus(tree, treeMode);

        TreeTraversal_Mode_Letters(tree->right, treeMode);
    }
}

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

#endif