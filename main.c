#include "file.h"
#include "line2.h"
#include "line3.h"
#include "line4.h"
#include "line5.h"
#include "line6.h"


int main()
{    
    BTree *tree = NULL;

    CumCol3 *treeClass = (CumCol3 *) malloc ( sizeof ( CumCol3 ) ) ;

    CumCol3 *treeClassOcur = (CumCol3 *) malloc ( sizeof ( CumCol3 ) ) ;

    CumCol4 *treeLine4Aux = (CumCol4 *) malloc ( sizeof ( CumCol4 ) ) ;

    CumCol4 *treeLine4Aux2 = (CumCol4 *) malloc ( sizeof ( CumCol4 ) ) ;

    BtreeMode *treeMode = (BtreeMode*) malloc (sizeof(BtreeMode));

    int opMenu;

    int totalWords = 0;

    int *ptrTotalWords = &totalWords;

    int totalLines = 0;

    int *ptrTotalLines = &totalLines;

    /* Line 5 Variables */
    /* Como sabemos que o valor é sempre positivo e se trata de muitos dados */
    /* declaramos o totalLength como unsigned long int */
    unsigned long int totalLetters = 0;
    unsigned long int *ptrTotalLetters = &totalLetters;
    float averageLength;
    int totalNiLine3 = 0;

    int *ptrTotalNiLine3 = &totalNiLine3;

    double totalFiLine3 = 0;

    double *ptrTotalFiLine3 = &totalFiLine3;

    int line6;
    int *ptrLine6 = &line6;

    int maxCount = 0;
    int *ptrMaxCount = &maxCount;

    char *wordLine6;

    int quartile;
    


    do
    {
        line6 = -1;

        puts("");
        puts("");
        puts("1 - Ler Ficheiro");
        puts("2 - Tabela Frequencias - Categoria Gramatical");
        puts("3 - Tabela Frequencias - Tamanho Palavras");
        puts("4 - Media - Categoria Gramatical");
        puts("5 - Media - Tamanho Palavras");
        puts("6 - Quartis - Frequencia Palavras");
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

            case 5:
                TreeTraversal_Total_Letters(tree, ptrTotalLetters);
                averageLength = Average_Line_5(totalLetters, totalLines);
                PrintResults_Line_5(totalLetters, averageLength);
                TreeTraversal_Mode_Letters(tree, treeMode);
                PrintMode(treeMode);               
                break;

            case 6:
                printf("\nIndique a palavra: ");
                scanf("%s", wordLine6);

                Small_Letters(wordLine6);

                IsInTree(tree, wordLine6, ptrLine6);

                if (line6 != -1)
                {
                    MaxCount(tree, ptrMaxCount);
                    quartile = Quartiles(maxCount, line6);

                    printf("\n\nA palavra ' %s ' tem ' %d ' ocorrencias e pertence ao quartil ' %d '.", wordLine6, line6, quartile);
                }
                else
                    printf("\nPalavra nao existe!");
                
                break;

            default:
                break;
        }
    } while (opMenu != 0);

    return 0;
}