#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


/* CONSTANTES */
/* #define FILE "slate-tagged.txt" */
/* #define FILE "ficheiro_teste_1M.txt" */
#define _TEXT_FILE "texto.txt"


/* ESTRUTURAS DE data */
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


/* ASSINATURAS */
BTree *ReadFile(BTree *tempTree, int *ptrTotalWords);
void Small_Letters(char *treeWord);
int Special_Characters(char *analyzeTree);
void Print_Tree(BTree *tree);
BTree *Insert_File_Tree(BTree *tree, Data tempData, int *ptrTotalWords);







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


int Special_Characters(char *analyzeTree)
{
    if (analyzeTree[0] == 'F')
    {
        return 1;
    }
    return 0;
}







BTree *ReadFile(BTree *tempTree, int *ptrTotalWords)
{
    FILE *file;
    Data tempData;
    
    file = fopen(_TEXT_FILE, "r");

    rewind(file);

    while (fscanf(file, "%s %s %s %f", tempData.word, tempData.motto, tempData.analyze, &tempData.prob) != EOF)
    {
        if (Special_Characters(tempData.analyze) == 0)
        {            
            Small_Letters(tempData.word);

            tempTree = Insert_File_Tree(tempTree, tempData, ptrTotalWords);
        }
    }

    fclose(file);
    
    return tempTree;
}


void Print_Tree(BTree *tree)
{
    if (tree)
    {
        Print_Tree(tree->left);
        printf("%-15s %-15s %-15s\t%f\tAparece %d vezes e tem %d letras.\n", tree->data.word, tree->data.motto, tree->data.analyze,
                                                                        tree->data.prob, tree->data.totalOccurrences, tree->data.lenghtWord);
        Print_Tree(tree->right);
    }
}




BTree *Insert_File_Tree(BTree *tree, Data tempData, int *ptrTotalWords)
{
    if (tree)
    {
        if (strcmp(tree->data.word, tempData.word) < 0)
            tree->left = Insert_File_Tree(tree->left, tempData, ptrTotalWords);

        if (strcmp(tree->data.word, tempData.word) > 0)
            tree->right = Insert_File_Tree(tree->right, tempData, ptrTotalWords);
        
        if ((strcmp(tree->data.word, tempData.word) == 0) && (strcmp(tree->data.analyze, tempData.analyze) == 0))
            tree->data.totalOccurrences ++;

        if ((strcmp(tree->data.word, tempData.word) == 0) && (strcmp(tree->data.analyze, tempData.analyze) != 0))
            tree->right = Insert_File_Tree(tree->right, tempData, ptrTotalWords);
    }
    else
    {
        tree = (BTree*) malloc(sizeof(BTree));


        strcpy(tree->data.word,       tempData.word);
        strcpy(tree->data.motto,          tempData.motto);
        strcpy(tree->data.analyze,       tempData.analyze);
        
        tree->data.prob     =   tempData.prob;
        tree->data.totalOccurrences  =   1;
        tree->data.lenghtWord    =   strlen(tempData.word);

        tree->left = tree->right       =   NULL;

        /* Se entra aqui é porque é uma word diferente. */
        /* Então vamos incrementar o total de words. */
        ++*ptrTotalWords;
    }
    return tree;
}