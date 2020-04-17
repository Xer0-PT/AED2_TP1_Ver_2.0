#include "file.h"
#include "line2.h"
#include "line3.h"



  

/* #include "library.h" */

int main()
{    
    BTree *tree = NULL;

    CumCol3 *treeClass = (CumCol3 *) malloc ( sizeof ( CumCol3 ) ) ;

    int opMenu;

    int totalWords = 0;

    int *ptrTotalWords = &totalWords;

    int totalLines = 0;

    int *ptrTotalLines = &totalLines;    

    do
    {
        puts("1 - Read File");
        puts("2 - Line 2");
        puts("3 - Line 3");
        puts("0 - Exit");
        puts("");
        printf("Opcao: ");
        scanf("%d", &opMenu);
    
        switch (opMenu)
        {
            case 1:
                tree = ReadFile(tree, ptrTotalWords, ptrTotalLines);
                
                /* Print_Tree(tree); */

                printf("\n\nTotal palavras: %d\n\n", totalWords);
                printf("\n\nTotal linhas: %d\n\n", totalLines);
                break;
            
            case 2:
                treeClass->analyze = (char*) malloc   (strlen(tree->data.analyze)    *   sizeof(char) + 1); 
                strcpy(treeClass->analyze, tree->data.analyze);
                treeClass->count = 0;

                GenerateByClassification(tree, treeClass);

                InOrderClassification(treeClass);

                ThroughTree(treeClass, ptrTotalLines);
                break;

            case 3:
                Line_3_Word_Frequency_Table(tree);
                break;

            default:
                break;
        }
    } while (opMenu != 0);

    return 0;
}