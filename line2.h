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
                treeClass->left = InsertOrCount( treeClass->left , tree ) ;

        if(strcmp(treeClass->analyze, tree->data.analyze) > 0)
                treeClass->right = InsertOrCount( treeClass->right , tree ) ;
    }
    else
    {
        treeClass = (CumCol3 *) malloc ( sizeof ( CumCol3 ) ) ;

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

        /*         printf("%s", tree->data.analyze);*/
        GenerateByClassification(tree->left, treeClassification);

        treeClassification  = InsertOrCount(treeClassification, tree);
        
        GenerateByClassification(tree->right, treeClassification);
    }
    
}


void InOrderClassification(CumCol3 * treeClassification)
{
	if (treeClassification)
	{

		InOrderClassification (treeClassification->left) ;

	
		printf("A classification '%s' tem  %d palavras.\n", treeClassification->analyze, treeClassification->count);


		InOrderClassification (treeClassification->right) ;
	}
    else
    {
       
    }
    

}

#endif