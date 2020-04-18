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
        treeClass->prob = tree->data.prob;

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
		    printf("A classification '%s' tem  %d palavras. Media aritmetica: %f\n", treeClassification->analyze, treeClassification->count, treeClassification->prob);

        InOrderClassification (treeClassification->right);
		
	}
}

void InOrderAscending(CumCol3 * treeClassification, int *ptrTotalLines, int *totalNi, double *totalFi)
{
    double auxFi = 0;
    int auxNi = 0;
	if (treeClassification)
	{
        InOrderAscending (treeClassification->left, ptrTotalLines, totalNi, totalFi);
	
        /* Sem este if está a imprimir o nodo que está NULL. PORQUÊ? */
        if(treeClassification->count != 0)
        {
		    auxFi = (double)treeClassification->count / *ptrTotalLines;
            auxNi = treeClassification->count;
            *totalNi = *totalNi + auxNi;
            *totalFi = *totalFi + auxFi;
            printf("|\t%s\t\t|\t%d\t|\t%f\t\| \t%d\t\|  \t%f\t|\n", treeClassification->analyze, auxNi, auxFi, *totalNi, *totalFi);
        }
        InOrderAscending (treeClassification->right, ptrTotalLines, totalNi, totalFi);
		
	}
}


void SortTree(CumCol3 * treeClassification, CumCol3 * treeClassOcur)
{
    if (treeClassification)
    {        
        SortTree(treeClassification->left, treeClassOcur);

        treeClassOcur = NewTreeAscending(treeClassification, treeClassOcur);

        SortTree(treeClassification->right, treeClassOcur);
    }
}

CumCol3 *NewTreeAscending (CumCol3 * treeClass, CumCol3 *treeClassOcur)
{
    if (treeClassOcur)
    {
        if (treeClass->count < treeClassOcur->count)
            treeClassOcur->left = NewTreeAscending(treeClass, treeClassOcur->left);
        
        if (treeClass->count > treeClassOcur->count)
            treeClassOcur->right = NewTreeAscending(treeClass, treeClassOcur->right);
    }
    else
    {
        treeClassOcur = (CumCol3 *) malloc (sizeof (CumCol3));

        treeClassOcur->analyze = (char *) malloc (strlen(treeClass->analyze) * sizeof(char) + 1);

        strcpy(treeClassOcur->analyze, treeClass->analyze);
        treeClassOcur->count = treeClass->count;

        treeClassOcur->left = treeClassOcur->right = NULL;
    }
    return treeClassOcur;    
}


void PrintHeadTable()
{
    printf("---------------------------------------------------------------------------------------------------------\n");
    printf("|   Classification\t|\tni\t|\tfi\t\t|\tCum ni\t|\tCum fi\t\t|\n");
    printf("---------------------------------------------------------------------------------------------------------\n");
}


void PrintEndTable(int totalNiLine3, double totalFiLine3)
{
    printf("---------------------------------------------------------------------------------------------------------\n");
    printf("|\tTOTAL  \t\t|\t%d\t|\t%f\t|               |                       |\n", totalNiLine3, totalFiLine3);
    printf("---------------------------------------------------------------------------------------------------------\n");
}

#endif