#include "file.h"


CumCol3 *InsereOuConta(CumCol3 * treeClass,  char * classificacao)
{   
    if(treeClass)
    {
		if(strcmp(treeClass->analyze, classificacao) == 0)
			treeClass->cont ++;

		if(strcmp(classificacao, treeClass->analyze) < 0)
				treeClass->left = InsereOuConta( treeClass->left , classificacao ) ;

		if(strcmp(classificacao, treeClass->analyze) > 0)
				treeClass->right = InsereOuConta( treeClass->right , classificacao ) ;

    }
    else
    {
        treeClass = (CumCol3 *) malloc ( sizeof ( CumCol3 ) ) ;

		strcpy(treeClass->analyze, classificacao);
		treeClass->cont = 1;

		treeClass->left = treeClass->right = NULL ;  
    }
    
    return treeClass;
}

void GerarPorClassificacao(BTree * arvore,  CumCol3 * arvoreClassificacao)
{
    if(arvore != NULL)
    {
        
 
        GerarPorClassificacao(arvore->left, arvoreClassificacao);


        printf("1.5 %s %d \n", arvoreClassificacao->analyze, arvoreClassificacao->cont);


        arvoreClassificacao  = InsereOuConta(arvoreClassificacao, arvore->data.analyze);
        
        GerarPorClassificacao(arvore->right, arvoreClassificacao);
        
    }
    
}


void InorderClassificacao(CumCol3 * arvoreClassificacao)
{
	if (arvoreClassificacao)
	{

		InorderClassificacao (arvoreClassificacao->left) ;

	
		printf("A classificacao '%s' tem  %d palavras.\n", arvoreClassificacao->analyze, arvoreClassificacao->cont);


		InorderClassificacao (arvoreClassificacao->right) ;
	}
    else
    {
       
    }
    

}



int main()
{    
    BTree *tree = NULL;

    CumCol3 *treeClass = (CumCol3 *) malloc (sizeof(CumCol3)); 


    int totalWords = 0;

    int *ptrTotalWords = &totalWords;

    printf("\n------------------------\n\tA ler ficheiro\n------------------------\n");

    tree = ReadFile(tree, ptrTotalWords);


    Print_Tree(tree);

    

    strcpy(treeClass->analyze, tree->data.analyze);
    treeClass->cont = 0;

    printf("1 %s %d \n", treeClass->analyze, treeClass->cont);
    GerarPorClassificacao(tree, treeClass);

    printf("2 %s %d \n", treeClass->analyze, treeClass->cont);

    InorderClassificacao(treeClass);



    return 0;
}