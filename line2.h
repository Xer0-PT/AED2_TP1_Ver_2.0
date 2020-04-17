#ifndef LINE2_H
#define LINE2_H

#include "library.h"

CumCol3 *InsertOrCount(CumCol3 * treeClass,  BTree * tree)
{
    if(treeClass)
    {
        if(strcmp(treeClass->analyze, tree->data.analyze) == 0)
            treeClass->count += tree->data.totalOccurrences;

        if(strcmp(treeClass->analyze, tree->data.analyze) < 0)
                treeClass->left = InsertOrCount( treeClass->left , tree );

        if(strcmp(treeClass->analyze, tree->data.analyze) > 0)
                treeClass->right = InsertOrCount( treeClass->right , tree );
    }
    else
    {
        treeClass = (CumCol3 *) malloc ( sizeof ( CumCol3 ) ) ;

        treeClass->analyze     =   (char*) malloc   (strlen(tree->data.analyze)    *   sizeof(char) + 1);

        strcpy(treeClass->analyze, tree->data.analyze);
        treeClass->count = tree->data.totalOccurrences;

        treeClass->left = treeClass->right = NULL ;
    }
    return treeClass;
}

void GenerateByClassification(BTree * tree,  CumCol3 * treeClassification)
{
    if(tree != NULL)
    {

        /* printf("%s", tree->data.analyze); */
        GenerateByClassification(tree->left, treeClassification);

        treeClassification  = InsertOrCount(treeClassification, tree);
        
        GenerateByClassification(tree->right, treeClassification);
    }
    
}


void InOrderClassification(CumCol3 * treeClassification)
{
	if (treeClassification)
	{
        InOrderClassification (treeClassification->right);
	
		printf("A classification '%s' tem  %d palavras.\n", treeClassification->analyze, treeClassification->count);

        InOrderClassification (treeClassification->left);
		
	}
    
}



void ThroughTree(CumCol3 *treeClassification, int *ptrTotalLines)
{
    int auxNi = 0;
    double auxFi = 0;
    int totalNi;
    double totalFi;
    
    if (treeClassification)
    {
        ThroughTree(treeClassification->left, ptrTotalLines);

            auxFi = (double)treeClassification->count / *ptrTotalLines;
            auxNi = treeClassification->count;
            totalNi += auxNi;
            totalFi += auxFi;
            printf("%s: %f, %d, %d, %f, %d\n", treeClassification->analyze, auxFi, auxNi, totalNi, totalFi, *ptrTotalLines);
        
        ThroughTree(treeClassification->right, ptrTotalLines);
    }
}


void ordenarArvore(CumCol3 * treeClassification)
{
    puts("1");

    char auxAnalyse[100];
    int auxCount = 0;

    if (treeClassification->count < treeClassification->left->count)
    {
        /* testeOrdenar = treeClassification->left; */
        strcpy(auxAnalyse, treeClassification->left->analyze);
        auxCount = treeClassification->left->count;


        /* treeClassification->left = treeClassification; */
        strcpy(treeClassification->left->analyze, treeClassification->analyze);
        treeClassification->left->count = treeClassification->count;

        /* treeClassification = testeOrdenar; */
        strcpy(treeClassification->analyze, auxAnalyse);
        treeClassification->count = auxCount;
    }
    else
    {
        /* testeOrdenar = treeClassification->right; */
        strcpy(auxAnalyse, treeClassification->right->analyze);
        auxCount = treeClassification->right->count;


        /* treeClassification->right = treeClassification; */
        strcpy(treeClassification->right->analyze, treeClassification->analyze);
        treeClassification->right->count = treeClassification->count;

        /* treeClassification = testeOrdenar; */
        strcpy(treeClassification->analyze, auxAnalyse);
        treeClassification->count = auxCount;
    }
    
    ordenarArvore(treeClassification->left);
    ordenarArvore(treeClassification->right);
}


#endif