#include "file.h"
#include "line2.h"


  

/* #include "library.h" */

int main()
{    
    BTree *tree = NULL;

    CumCol3 *treeClass = (CumCol3 *) malloc (sizeof(CumCol3)); 


    int totalWords = 0;

    int *ptrTotalWords = &totalWords;

    printf("\n------------------------\n\tA ler ficheiro\n------------------------\n");

    tree = ReadFile(tree, ptrTotalWords);


    /*Print_Tree(tree);*/

    

    strcpy(treeClass->analyze, tree->data.analyze);
    treeClass->count = 0;

  


    GenerateByClassification(tree, treeClass);


    InOrderClassification(treeClass);



    return 0;
}