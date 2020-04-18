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
        InOrderClassification (treeClassification->left);
	
        /* Sem este if está a imprimir o nodo que está NULL. PORQUÊ? */
        if(treeClassification->count != 0)
		    printf("A classification '%s' tem  %d palavras.\n", treeClassification->analyze, treeClassification->count);

        InOrderClassification (treeClassification->right);
		
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

void ordenarArvore(CumCol3 * treeClassification, CumCol3 * testeOrdenar)
{
    if (treeClassification)
    {        
        ordenarArvore(treeClassification->left, testeOrdenar);

        testeOrdenar = NovaArvore(treeClassification, testeOrdenar);

        ordenarArvore(treeClassification->right, testeOrdenar);
    }
}

CumCol3 *NovaArvore (CumCol3 * treeClass, CumCol3 *testeOrdenar)
{
    if (testeOrdenar)
    {
        if (treeClass->count < testeOrdenar->count)
            testeOrdenar->left = NovaArvore(treeClass, testeOrdenar->left);
        
        if (treeClass->count > testeOrdenar->count)
            testeOrdenar->right = NovaArvore(treeClass, testeOrdenar->right);
    }
    else
    {
        testeOrdenar = (CumCol3 *) malloc (sizeof (CumCol3));

        testeOrdenar->analyze = (char *) malloc (strlen(treeClass->analyze) * sizeof(char) + 1);

        strcpy(testeOrdenar->analyze, treeClass->analyze);
        testeOrdenar->count = treeClass->count;

        testeOrdenar->left = testeOrdenar->right = NULL;
    }
    return testeOrdenar;    
}

#endif