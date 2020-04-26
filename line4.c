#include "library.h"

/*Vindo da segunda arvore comeca a copiar para outra arvore*/
CumCol4 *SortTree_4_Media(CumCol4 * treeLine4,  BTree * tree)
{
    if(treeLine4)
    {
        if(strcmp(treeLine4->analyze, tree->data.analyze) == 0 )
        {
            treeLine4->count += tree->data.totalOccurrences;
            treeLine4->prob += tree->data.prob;
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

        treeLine4->left = treeLine4->right = NULL ;
    }
    return treeLine4;
}


/*Percorre a primeira arvore e manda para a segunda*/
void GenerateLine4_Media(BTree * tree,  CumCol4 * treeLine4)
{
    if(tree != NULL)
    {
        GenerateLine4_Media(tree->left, treeLine4);

        treeLine4  = SortTree_4_Media(treeLine4, tree);
        
        GenerateLine4_Media(tree->right, treeLine4);
    }
}

/* Imprime a media da categoria 3 existente*/
void InOrderMedia(CumCol4 * treeLine4)
{
	if (treeLine4)
	{
        InOrderMedia (treeLine4->left);
	
        /* Sem este if está a imprimir o nodo que está NULL. PORQUÊ? */
        if(treeLine4->count != 0)
        {
		    treeLine4->media=(float) treeLine4->prob / treeLine4->count;
            
            printf("%s:\t%f\n", treeLine4->analyze, treeLine4->media);
        }
        InOrderMedia (treeLine4->right);
	}
}