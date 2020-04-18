#include "file.h"
#include "line2.h"
#include "line3.h"
#include "line4.h"



  

/* #include "library.h" */

int main()
{    
    BTree *tree = NULL;

    CumCol3 *treeClass = (CumCol3 *) malloc ( sizeof ( CumCol3 ) ) ;

    CumCol3 *treeClassOcur = (CumCol3 *) malloc ( sizeof ( CumCol3 ) ) ;

    CumCol4 *treeLine4Aux = (CumCol4 *) malloc ( sizeof ( CumCol4 ) ) ;

    CumCol4 *treeLine4Aux2 = (CumCol4 *) malloc ( sizeof ( CumCol4 ) ) ;

    int opMenu;

    int totalWords = 0;

    int *ptrTotalWords = &totalWords;

    int totalLines = 0;

    int *ptrTotalLines = &totalLines;

    int totalNiLine3 = 0;

    int *ptrTotalNiLine3 = &totalNiLine3;

    double totalFiLine3 = 0;

    double *ptrTotalFiLine3 = &totalFiLine3;   

    do
    {
        puts("1 - Read File");
        puts("2 - Line 2");
        puts("3 - Line 3");
        puts("4 - Line 4");
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
                treeClass->prob = tree->data.prob;

                GenerateByClassification(tree, treeClass);

                InOrderClassification(treeClass);


                printf("\n\nNova Ordem\n\n");


                SortTree(treeClass, treeClassOcur);


                PrintHeadTable();
                InOrderAscending(treeClassOcur, ptrTotalLines, ptrTotalNiLine3, ptrTotalFiLine3);
                PrintEndTable(totalNiLine3, totalFiLine3);

                break;

            case 3:
                Line_3_Word_Frequency_Table(tree);
                break;

            case 4:
                treeLine4Aux->analyze = (char*) malloc   (strlen(tree->data.analyze)    *   sizeof(char) + 1);
                strcpy(treeLine4Aux->analyze, tree->data.analyze);
                treeLine4Aux->count = tree->data.totalOccurrences;
                treeLine4Aux->prob = tree->data.prob; 
                GenerateLine4_Media(tree, treeLine4Aux);

                InOrderMedia(treeLine4Aux);

                treeLine4Aux2->analyze = (char*) malloc   (strlen(tree->data.analyze)    *   sizeof(char) + 1);
                strcpy(treeLine4Aux2->analyze, tree->data.analyze);
                treeLine4Aux2->count = tree->data.totalOccurrences;
                treeLine4Aux2->prob = tree->data.prob; 
                GenerateLine4_StrDev(tree, treeLine4Aux2);
                
                GenerateLine4_Final(treeLine4Aux2, treeLine4Aux);
                InOrderFinal(treeLine4Aux);


                break;

            default:
                break;
        }
    } while (opMenu != 0);

    return 0;
}