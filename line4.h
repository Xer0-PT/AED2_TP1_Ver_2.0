#ifndef LINE_4_H
#define LINE_4_H

#include "library.h"



CumCol4 *SortTree_4_Media(CumCol4 * treeLine4,  BTree * tree)
{
    if(treeLine4)
    {
        if(strcmp(treeLine4->analyze, tree->data.analyze) == 0 )
        {
            treeLine4->count += tree->data.totalOccurrences;
            treeLine4->prob += tree->data.prob;
            treeLine4->totalStrDev = 0;
        }

        if(strcmp(treeLine4->analyze, tree->data.analyze) < 0)
                treeLine4->left = SortTree_4_Media( treeLine4->left , tree );

        if(strcmp(treeLine4->analyze, tree->data.analyze) > 0)
                treeLine4->right = SortTree_4_Media( treeLine4->right , tree );
    }
    else
    {
        treeLine4 = (CumCol4 *) malloc ( sizeof ( CumCol4 ) ) ;

        treeLine4->analyze     =   (char*) malloc   (strlen(tree->data.analyze)    *   sizeof(char) + 1);

        strcpy(treeLine4->analyze, tree->data.analyze);
        treeLine4->count = tree->data.totalOccurrences;
        treeLine4->prob = tree->data.prob;
        treeLine4->totalStrDev = 0;

        treeLine4->left = treeLine4->right = NULL ;
    }
    return treeLine4;
}

void GenerateLine4_Media(BTree * tree,  CumCol4 * treeLine4)
{
    if(tree != NULL)
    {

        /* printf("%s", tree->data.analyze); */
        GenerateLine4_Media(tree->left, treeLine4);

        treeLine4  = SortTree_4_Media(treeLine4, tree);
        
        GenerateLine4_Media(tree->right, treeLine4);
    }
    
}

void InOrderMedia(CumCol4 * treeLine4)
{
	if (treeLine4)
	{
        InOrderMedia (treeLine4->left);
	
        /* Sem este if está a imprimir o nodo que está NULL. PORQUÊ? */
        if(treeLine4->count != 0)
        {
		    treeLine4->media=(float) treeLine4->prob / treeLine4->count;
            printf("%s: %f\n", treeLine4->analyze, treeLine4->media);
        }
        InOrderMedia (treeLine4->right);
		
	}
}


void GenerateLine4_StrDev(BTree * tree,  CumCol4 * treeLine4)
{
    if(tree != NULL)
    {

        /* printf("%s", tree->data.analyze); */
        GenerateLine4_StrDev(tree->left, treeLine4);

        treeLine4  = SortTree_4_StrDev(treeLine4, tree);
        
        GenerateLine4_StrDev(tree->right, treeLine4);
    }
    
}


CumCol4 *SortTree_4_StrDev(CumCol4 * treeLine4,  BTree * tree)
{
    if(treeLine4)
    {
        if(strcmp(treeLine4->analyze, tree->data.analyze) == 0  && treeLine4->prob != tree->data.prob)
                treeLine4->right = SortTree_4_StrDev( treeLine4->right , tree );

        if(strcmp(treeLine4->analyze, tree->data.analyze) == 0  && treeLine4->prob == tree->data.prob)
                treeLine4->count++;

        if(strcmp(treeLine4->analyze, tree->data.analyze) < 0)
                treeLine4->left = SortTree_4_StrDev( treeLine4->left , tree );

        if(strcmp(treeLine4->analyze, tree->data.analyze) > 0)
                treeLine4->right = SortTree_4_StrDev( treeLine4->right , tree );
    }
    else
    {
        treeLine4 = (CumCol4 *) malloc ( sizeof ( CumCol4 ) ) ;

        treeLine4->analyze     =   (char*) malloc   (strlen(tree->data.analyze)    *   sizeof(char) + 1);

        strcpy(treeLine4->analyze, tree->data.analyze);
        treeLine4->count = tree->data.totalOccurrences;
        treeLine4->prob = tree->data.prob;
        treeLine4->totalStrDev = 0;

        treeLine4->left = treeLine4->right = NULL ;
    }
    return treeLine4;
}

void InOrderStrDev(CumCol4 * treeLine4)
{
	if (treeLine4)
	{
        InOrderStrDev (treeLine4->left);
	
        /* Sem este if está a imprimir o nodo que está NULL. PORQUÊ? */
        if(treeLine4->count != 0)
        {
            printf("%s: %f\n", treeLine4->analyze, treeLine4->prob);
        }
        InOrderStrDev (treeLine4->right);
		
	}
}


void GenerateLine4_Final(CumCol4 * treeLine4,  CumCol4 * treeLine4Aux)
{
    if(treeLine4)
    {

        /* printf("%s", tree->data.analyze); */
        GenerateLine4_Final(treeLine4->left, treeLine4Aux);

        treeLine4Aux = SortTree_4_Final(treeLine4Aux, treeLine4);
        
        GenerateLine4_Final(treeLine4->right, treeLine4Aux);
    }
    
}

CumCol4 *SortTree_4_Final(CumCol4 * treeLine4Aux,  CumCol4 * treeLine4)
{
    if(treeLine4Aux)
    {

        if(strcmp(treeLine4Aux->analyze, treeLine4->analyze) == 0)
        {
                treeLine4Aux->totalStrDev += treeLine4Aux->count * ((treeLine4->prob - treeLine4Aux->media) * (treeLine4->prob - treeLine4Aux->media));
        }
        if(strcmp(treeLine4->analyze, treeLine4Aux->analyze) < 0)
                treeLine4Aux->left = SortTree_4_Final( treeLine4->left , treeLine4Aux ) ;

        if(strcmp(treeLine4->analyze, treeLine4Aux->analyze) > 0)
                treeLine4Aux->right = SortTree_4_Final( treeLine4->right , treeLine4Aux );
    }
    else
    {
        return treeLine4Aux;
    }
    
        return treeLine4Aux;
}

void InOrderFinal(CumCol4 * treeLine4)
{
	if (treeLine4)
	{
        InOrderFinal (treeLine4->left);
	
        /* Sem este if está a imprimir o nodo que está NULL. PORQUÊ? */
        if(treeLine4->count != 0)
        {
            printf("%f", treeLine4->totalStrDev);
            treeLine4->totalStrDev = treeLine4->totalStrDev / treeLine4->count;
            printf("\n%s:  %f, %f\n", treeLine4->analyze, treeLine4->media, treeLine4->totalStrDev);
        }
        InOrderFinal (treeLine4->right);
		
	}
    else
    {
        return;
    }
    
}





#endif