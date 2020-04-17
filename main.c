#include "file.h"
#include "line2.h"



  

/* #include "library.h" */

int main()
{    
    BTree *tree = NULL;

    CumCol3 *treeClass = (CumCol3 *) malloc ( sizeof ( CumCol3 ) ) ;

    int totalWords = 0;

    int *ptrTotalWords = &totalWords;

    int totalLines = 0;

    int *ptrTotalLines = &totalLines;


    printf("\n------------------------\n\tA ler ficheiro\n------------------------\n");

    tree = ReadFile(tree, ptrTotalWords, ptrTotalLines);


    /* Print_Tree(tree); */

    printf("\n\nTotal palavras: %d\n\n", totalWords);
    printf("\n\nTotal linhas: %d\n\n", totalLines);

    treeClass->analyze = (char*) malloc   (strlen(tree->data.analyze)    *   sizeof(char) + 1); 
    
    strcpy(treeClass->analyze, tree->data.analyze);
    treeClass->count = 0;


    GenerateByClassification(tree, treeClass);

    InOrderClassification(treeClass);

    ThroughTree(treeClass, ptrTotalLines);




    return 0;
}