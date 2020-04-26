#include "library.h"

void Line_3_Word_Frequency_Table(BTree *tree)
{
    /* 
        ni = total de palavras no intervalo
        
        fi = ni / N      (N = TOTAL)

        Cum ni = ni 1 + ni 2 + ... + ni 5

        Cum fi = fi 1 + fi 2 + ... + fi 5

    */

    /* Variáveis para o cálculo das frequências absolutas */
    int ni20    = 0;
    int ni40    = 0;
    int ni60    = 0;
    int ni80    = 0;
    int ni100   = 0;
    int totalNi = 0;

    /* Pointers para cada variável de frequências absolutas */
    int *ptr20  = &ni20;
    int *ptr40  = &ni40;
    int *ptr60  = &ni60;
    int *ptr80  = &ni80;
    int *ptr100 = &ni100;

    /* Variáveis para o cálculo das frequências relativas */
    float fi20;
    float fi40;
    float fi60;
    float fi80;
    float fi100;
    int totalFi;


    /* Chama a função para construção das classes, passando os pointers por parâmetro */
    TreeTraversal_Line_3(tree, ptr20, ptr40, ptr60, ptr80, ptr100);


    /* Cálculo do total das frequências absolutas */
    /* que deverá ser igual ao total de linhas com conteúdo válido */
    totalNi = ni20 + ni40 + ni60 + ni80 + ni100;
    

    /* Cálculo das frequências relativas */
    fi20  = (float)ni20   / totalNi;
    fi40  = (float)ni40   / totalNi;
    fi60  = (float)ni60   / totalNi;
    fi80  = (float)ni80   / totalNi;
    fi100 = (float)ni100  / totalNi;
    totalFi = fi20 + fi40 + fi60 + fi80 + fi100;

    /* Tabela de frequências */
    printf("---------------------------------------------------------------------------------------------------------\n");
    printf("|\tWord Length\t|\tni\t|\t  fi\t\t|\tCum ni\t|\tCum fi\t\t|\n");
    printf("---------------------------------------------------------------------------------------------------------\n");
    printf("|\t[  0 ; 20  [\t|\t%d\t|\t%f\t|\t%d\t|\t%f\t|\n", ni20,   fi20,   ni20, fi20);
    printf("|\t[ 20 ; 40  [\t|\t%d\t|\t%f\t|\t%d\t|\t%f\t|\n", ni40,   fi40,   ni20 + ni40, fi20 + fi40);
    printf("|\t[ 40 ; 60  [\t|\t%d\t|\t%f\t|\t%d\t|\t%f\t|\n", ni60,   fi60,   ni20 + ni40 + ni60, fi20 + fi40 + fi60);
    printf("|\t[ 60 ; 80  [\t|\t%d\t|\t%f\t|\t%d\t|\t%f\t|\n", ni80,   fi80,   ni20 + ni40 + ni60 + ni80, fi20 + fi40 + fi60 + fi80);
    printf("|\t[ 80 ; 100 [\t|\t%d\t|\t%f\t|\t%d\t|\t%.1f\t\t|\n", ni100,  fi100,  ni20 + ni40 + ni60 + ni80 + ni100, fi20 + fi40 + fi60 + fi80 + fi100);
    printf("|-------------------------------------------------------------------------------------------------------|\n");
    printf("|\t TOTAL \t\t|\t%d\t|\t%d\t\t|---------------|-----------------------|\n", totalNi, totalFi);
    printf("---------------------------------------------------------------------------------------------------------\n");
}

/* Travessia na árvore do ficheiro para a construção de cada classe */
/* Como se trata de apenas 5 classes, optamos por ter uma variável para cada classe */
void TreeTraversal_Line_3(BTree *tree, int *ptr20, int *ptr40, int *ptr60, int *ptr80, int *ptr100)
{
    if (tree)
    {
        TreeTraversal_Line_3(tree->left, ptr20, ptr40, ptr60, ptr80, ptr100);

        if (tree->data.lenghtWord <= 20)
            *ptr20 += tree->data.totalOccurrences;

        if (tree->data.lenghtWord > 20 && tree->data.lenghtWord <= 40)
            *ptr40 += tree->data.totalOccurrences;

        if (tree->data.lenghtWord > 40 && tree->data.lenghtWord <= 60)
            *ptr60 += tree->data.totalOccurrences;

        if (tree->data.lenghtWord > 60 && tree->data.lenghtWord <= 80)
            *ptr80 += tree->data.totalOccurrences;
        
        if (tree->data.lenghtWord > 80)
            *ptr100 += tree->data.totalOccurrences;

        TreeTraversal_Line_3(tree->right, ptr20, ptr40, ptr60, ptr80, ptr100);
    }    
}