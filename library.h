#ifndef LIBRARY_H_
#define LIBRARY_H_

/* Includes */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/* File Constant */

/* #define FILE "slate-tagged.txt" */
/* #define FILE "ficheiro_teste_1M.txt" */
#define _TEXT_FILE "texto.txt"


/* Data Structures */

typedef struct _CumCol3
{
    char analyze[100];
    int count;
    struct _CumCol3 *left, *right;
} CumCol3;

/* data da word */
typedef struct _Data
{
    /* data presentes no ficheiro */
    char word[100];
    char motto[100];
    char analyze[100];
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



/* Signatures */

/* File */
BTree *ReadFile(BTree *tempTree, int *ptrTotalWords);
void Small_Letters(char *treeWord);
int Special_Characters(char *analyzeTree);
void Print_Tree(BTree *tree);
BTree *Insert_File_Tree(BTree *tree, Data tempData, int *ptrTotalWords);

/* Line 2 */
void GenerateByClassification(BTree * tree,  CumCol3 * treeClassification);
CumCol3 *InsertOrCount(CumCol3 * treeClass,  BTree * tree);
void InOrderClassification(CumCol3 * treeClassification);




#endif