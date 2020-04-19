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

    CumCol4 *treeLine4 = (CumCol4 *) malloc ( sizeof ( CumCol4 ) ) ;

    BtreeMode *treeMode = NULL;

    int opMenu;
    int totalWords = 0;
    int *ptrTotalWords = &totalWords;
    int totalLines = 0;
    int *ptrTotalLines = &totalLines;


    /* Variaveis Line 2 */
    int totalNiLine2 = 0;
    int *ptrTotalNiLine2 = &totalNiLine2;
    double totalFiLine2 = 0;
    double *ptrTotalFiLine2 = &totalFiLine2;
    /* ------------------- */

    /* Variaveis Line 5 */
    /* Como sabemos que o valor é sempre positivo e se trata de muitos dados */
    /* declaramos o totalLength como unsigned long int */
    unsigned long int totalLetters = 0;
    unsigned long int *ptrTotalLetters = &totalLetters;
    float averageLength;
    /* ------------------- */

    /* Variaveis Line 6 */
    int totalOcurrencesLine6;
    int *ptrTotalOcurrencesLine6 = &totalOcurrencesLine6;
    int maxCount = 0;
    int *ptrMaxCount = &maxCount;
    char *wordLine6;
    int quartile;
    /* ------------------- */
    
    do
    {
        totalOcurrencesLine6 = -1;

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
                printf("\n\n|\tFicheiro Carregado!\t\t\t\t\t|");
                printf("\n|\tTotal palavras (nao inclui repeticoes):\t%d\t\t|", totalWords);
                printf("\n|\tTotal linhas com conteudo valido:\t%d\t\t|", totalLines);
                break;
            
            case 2:
                treeClass->analyze = (char*) malloc   (strlen(tree->data.analyze)    *   sizeof(char) + 1);
                strcpy(treeClass->analyze, tree->data.analyze);
                treeClass->count = 0;
                treeClass->prob = tree->data.prob;

                GenerateByClassification(tree, treeClass);

                SortTree(treeClass, treeClassOcur);
                PrintHeadTable();
                InOrderAscending(treeClassOcur, ptrTotalLines, ptrTotalNiLine2, ptrTotalFiLine2);
                PrintEndTable(totalNiLine2, totalFiLine2);
                break;

            case 3:
                Line_3_Word_Frequency_Table(tree);
                break;

            case 4:
                printf("\n\nTipo\tMedia\n\n");
                treeLine4->analyze = (char*) malloc   (strlen(tree->data.analyze)    *   sizeof(char) + 1);
                strcpy(treeLine4->analyze, tree->data.analyze);
                treeLine4->count = tree->data.totalOccurrences;
                treeLine4->prob = tree->data.prob; 
                GenerateLine4_Media(tree, treeLine4);
                InOrderMedia(treeLine4);
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

                IsInTree(tree, wordLine6, ptrTotalOcurrencesLine6);

                if (totalOcurrencesLine6 != -1)
                {
                    MaxCount(tree, ptrMaxCount);
                    quartile = Quartiles(maxCount, totalOcurrencesLine6);

                    printf("\n\nA palavra ' %s ' tem ' %d ' ocorrencias e pertence ao quartil ' %d '.", wordLine6, totalOcurrencesLine6, quartile);
                }
                else
                    printf("\nPalavra nao existe!");
                
                break;

            case 0:
                    BTree_free(tree);
                    Cumcol3_free(treeClass);
                    Cumcol3_free(treeClassOcur);
                    CumCol4_free(treeLine4);
                    BtreeMode_free(treeMode);
                break;

            default:
                printf("\n\nOpcao invalida!!!\n\n");
                break;
        }
    }while (opMenu != 0);

    return 0;
}

void BTree_free(BTree* root)
{
    if (root)
    {
        BTree_free(root->left);
        BTree_free(root->right);
        free(root);
    }
}

void Cumcol3_free(CumCol3* root)
{
    if (root)
    {
        Cumcol3_free(root->left);
        Cumcol3_free(root->right);
        free(root);
    }
}

void BtreeMode_free(BtreeMode* root)
{
    if (root)
    {
        BtreeMode_free(root->left);
        BtreeMode_free(root->right);
        free(root);
    }
}

void CumCol4_free(CumCol4* root)
{
    if (root)
    {
        CumCol4_free(root->left);
        CumCol4_free(root->right);
        free(root);
    }
}