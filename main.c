#include "file.h"
#ifdef FILE_H
#define FILE_H



int main()
{    
    BTree *tree = NULL;

    CumCol3 *treeClass = (CumCol3 *) malloc (sizeof(CumCol3)); 


    int totalWords = 0;

    int *ptrTotalWords = &totalWords;

    printf("\n------------------------\n\tA ler ficheiro\n------------------------\n");

    tree = ReadFile(tree, ptrTotalWords);


    Print_Tree(tree);

    

    strcpy(treeClass->analyze, tree->data.analyze);
    treeClass->count = 0;

    printf("1 %s %d \n", treeClass->analyze, treeClass->count);
    GenerateByClassification(tree, treeClass);

    printf("2 %s %d \n", treeClass->analyze, treeClass->count);

    InOrderClassification(treeClass);



    return 0;
}

#endif