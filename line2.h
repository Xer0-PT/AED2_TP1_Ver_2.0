#ifndef LINE2_H
#define LINE2_H

#include "library.h"


/*Insere noutra Arcvore faz comparacao alfabetica. Se for maior manda pa direita, se for menor manda pa esquerda e se for igual
adiciona as vezes que aparece a contagem*/
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
/*Funcao que percorre a arvore orginal para copiar para a segunda*/
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

/*Imprime a arvore de forma ascendente*/

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
            printf("|\t%s\t\t|\t%d\t|\t%f\t| \t%d\t|  \t%f\t|\n", treeClassification->analyze, auxNi, auxFi, *totalNi, *totalFi);
        }
        InOrderAscending (treeClassification->right, ptrTotalLines, totalNi, totalFi);
		
	}
}

/*Funcao para percorrer a primeira arvore e mandar para a segunda*/
void SortTree(CumCol3 * treeClassification, CumCol3 * treeClassOcur)
{
    if (treeClassification)
    {        
        SortTree(treeClassification->left, treeClassOcur);

        treeClassOcur = NewTreeAscending(treeClassification, treeClassOcur);

        SortTree(treeClassification->right, treeClassOcur);
    }
}


/*Ordena a arvore pelas vezes em que aparece*/
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

/*Impressao da cabeca da tabela*/
void PrintHeadTable()
{
    printf("---------------------------------------------------------------------------------------------------------\n");
    printf("|   Classification\t|\tni\t|\tfi\t\t|\tCum ni\t|\tCum fi\t\t|\n");
    printf("---------------------------------------------------------------------------------------------------------\n");
}

/*Impressao do fim da tabela*/
void PrintEndTable(int totalNiLine3, double totalFiLine3)
{
    printf("---------------------------------------------------------------------------------------------------------\n");
    printf("|\tTOTAL  \t\t|\t%d\t|\t%f\t|               |                       |\n", totalNiLine3, totalFiLine3);
    printf("---------------------------------------------------------------------------------------------------------\n");
}

#endif