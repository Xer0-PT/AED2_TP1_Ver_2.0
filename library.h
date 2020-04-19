#ifndef LIBRARY_H_
#define LIBRARY_H_

/* Includes */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/* File Constant */

/* #define _TEXT_FILE "teste_alinea_5.txt" */
#define _TEXT_FILE "slate-tagged.txt"
/* #define _TEXT_FILE "ficheiro_teste_1M.txt" */
/* #define _TEXT_FILE "texto.txt" */



/* Data Structures */

typedef struct _CumCol3
{
    char *analyze;
    float prob;
    int count;
    struct _CumCol3 *left, *right;
} CumCol3;

/* data da word */
typedef struct _Data
{
    /* data presentes no ficheiro */
    char *word;
    char *motto;
    char *analyze;
    float prob;

    /* Contagem de data em relação a cada word */
    int totalOccurrences; /*Total de vezes que a word aparece no ficheiro*/
    int lenghtWord; /*Número de letras na word*/
}Data;

typedef struct _Btree
{
    Data data;

    struct _Btree *left, *right;
}BTree;

/* Mode Line 5 */
typedef struct _BtreeMode
{
    int wordLength;
    int wordCount;

    struct _BtreeMode *left, *right;
}BtreeMode;


typedef struct _CumCol4
{
    char *analyze;
    float prob;
    int count;
    float media;
    float StrDev;
    float totalStrDev;
    struct _CumCol4 *left, *right;
} CumCol4;

/* This function is needed in more than 1 file */
/* So in this file is accessible anywhere */
void Small_Letters(char *treeWord)
{
    char aux;
    int i = 0;

    while (treeWord[i] != '\0')
    {
        aux = treeWord[i];
        if (aux >= 'A' && aux <= 'Z')
        {
            treeWord[i] = treeWord[i] + 32;
        }
        i++;
    }
}

/* Signatures */

/* File */
BTree *ReadFile(BTree *tempTree, int *ptrTotalWords, int *ptrTotalLines);
int Special_Characters(char *analyzeTree);
void Print_Tree(BTree *tree);
BTree *Insert_File_Tree(BTree *tree, Data tempData, int *ptrTotalWords);

/* Line 2 */
void GenerateByClassification(BTree * tree,  CumCol3 * treeClassification);
CumCol3 *InsertOrCount(CumCol3 * treeClass,  BTree * tree);
void InOrderAscending(CumCol3 * treeClassification, int *ptrTotalLines, int *totalNi, double *totalFi);
void SortTree(CumCol3 * treeClassification, CumCol3 * treeClassOcur);
CumCol3 *NewTreeAscending (CumCol3 * treeClass, CumCol3 *treeClassOcur);
void PrintHeadTable();
void PrintEndTable(int totalNiLine3, double totalFiLine3);

/* Line 3 */
void Line_3_Word_Frequency_Table(BTree *tree);
void TreeTraversal_Line_3(BTree *tree, int *ptr20, int *ptr40, int *ptr60, int *ptr80, int *ptr100);

/* Line 4*/
CumCol4 *SortTree_4_Media(CumCol4 * treeLine4,  BTree * tree);
void GenerateLine4_Media(BTree * tree,  CumCol4 * treeLine4);
void InOrderMedia(CumCol4 * treeLine4);
void InOrderStrDev(CumCol4 * treeLine4);
CumCol4 *SortTree_4_StrDev(CumCol4 * treeLine4,  BTree * tree);
void GenerateLine4_StrDev(BTree * tree,  CumCol4 * treeLine4);
void InOrderFinal(CumCol4 * treeLine4);
CumCol4 *SortTree_4_Final(CumCol4 * treeLine4Aux,  CumCol4 * treeLine4);
void GenerateLine4_Final(CumCol4 * treeLine4,  CumCol4 * treeLine4Aux);



/* Line 5 */
void TreeTraversal_Total_Letters(BTree *tree, unsigned long int *totalLength);
float Average_Line_5(unsigned long int totalLength, int totalWords);
void PrintResults_Line_5(unsigned long int totalLetters ,float averageLength);
void TreeTraversal_Mode_Letters(BTree *tree, BtreeMode *treeMode);
BtreeMode * ModeCalculus(BTree * tree, BtreeMode * treeMode);
void PrintMode(BtreeMode *treeMode);


/* Line 6 */
void IsInTree(BTree *tree, char *word, int *ptrLine6);


#endif