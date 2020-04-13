#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "file.h"
#ifndef LINE2_H
#define LINE2_H




void GenerateByClassification(BTree * tree,  CumCol3 * treeClassification);
CumCol3 *InsertOrCount(CumCol3 * treeClass,  char * classification);
void InOrderClassification(CumCol3 * treeClassification);


CumCol3 *InsertOrCount(CumCol3 * treeClass,  char * classification)
{   
    if(treeClass)
    {
		if(strcmp(treeClass->analyze, classification) == 0)
			treeClass->count ++;

		if(strcmp(classification, treeClass->analyze) < 0)
				treeClass->left = InsertOrCount( treeClass->left , classification ) ;

		if(strcmp(classification, treeClass->analyze) > 0)
				treeClass->right = InsertOrCount( treeClass->right , classification ) ;

    }
    else
    {
        treeClass = (CumCol3 *) malloc ( sizeof ( CumCol3 ) ) ;

		strcpy(treeClass->analyze, classification);
		treeClass->count = 1;

		treeClass->left = treeClass->right = NULL ;  
    }
    
    return treeClass;
}

void GenerateByClassification(BTree * tree,  CumCol3 * treeClassification)
{
    if(tree != NULL)
    {
        
 
        GenerateByClassification(tree->left, treeClassification);


        printf("1.5 %s %d \n", treeClassification->analyze, treeClassification->count);


        treeClassification  = InsertOrCount(treeClassification, tree->data.analyze);
        
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