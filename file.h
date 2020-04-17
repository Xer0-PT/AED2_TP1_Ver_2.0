#include "library.h"

void Small_Letters(char *treeWord)
{
    char aux;
    int i = 0;

    while (treeWord[i] != '\0')
    {
        aux = treeWord[i];
        if (aux >= 'A' && aux <= 'Z')
        {
            treeWord[i] = treeWord[i] + 32;
        }
        i++;
    }
}

int Special_Characters(char *analyzeTree)
{
    /* Ignorar pontuação */
    if (analyzeTree[0] == 'F')
    {
        return 1;
    }
    return 0;
}

BTree *ReadFile(BTree *tempTree, int *ptrTotalWords, int *ptrTotalLines)
{
    FILE *file;
    Data tempData;

    char auxWord[100];
    char auxMotto[100];
    char auxAnalyze[100];

    int total = 0;

    file = fopen(_TEXT_FILE, "r");

    rewind(file);

    while (fscanf(file, "%s %s %s %f", auxWord, auxMotto, auxAnalyze, &tempData.prob) != EOF)
    {
        if (Special_Characters(auxAnalyze) == 0)
        {            
            ++total;
            Small_Letters(auxWord);

            tempData.word =     (char*) malloc(strlen(auxWord)*sizeof(char) + 1);
            tempData.motto =    (char*) malloc(strlen(auxMotto)*sizeof(char) + 1);
            tempData.analyze =  (char*) malloc(strlen(auxAnalyze)*sizeof(char) + 1);

            strcpy(tempData.word, auxWord);
            strcpy(tempData.motto, auxMotto);
            strcpy(tempData.analyze, auxAnalyze);

            tempTree = Insert_File_Tree(tempTree, tempData, ptrTotalWords);
        }
    }

    fclose(file);

    *ptrTotalLines = total;
    
    return tempTree;
}


void Print_Tree(BTree *tree)
{
    if (tree)
    {
        Print_Tree(tree->right);
        printf("%-15s %-15s %-15s\t%f\tAparece %d vezes e tem %d letras.\n", tree->data.word, tree->data.motto, tree->data.analyze,
                                                                        tree->data.prob, tree->data.totalOccurrences, tree->data.lenghtWord);
        Print_Tree(tree->left);
    }
}

BTree *Insert_File_Tree(BTree *tree, Data tempData, int *ptrTotalWords)
{
    if (tree)
    {
        if (strcmp(tree->data.word, tempData.word) < 0)
            tree->left = Insert_File_Tree(tree->left, tempData, ptrTotalWords);

        if (strcmp(tree->data.word, tempData.word) > 0)
            tree->right = Insert_File_Tree(tree->right, tempData, ptrTotalWords);
        
        if ((strcmp(tree->data.word, tempData.word) == 0) && (strcmp(tree->data.analyze, tempData.analyze) == 0))
            tree->data.totalOccurrences ++;

        if ((strcmp(tree->data.word, tempData.word) == 0) && (strcmp(tree->data.analyze, tempData.analyze) != 0))
            tree->right = Insert_File_Tree(tree->right, tempData, ptrTotalWords);
    }
    else
    {
        tree = (BTree*) malloc(sizeof(BTree));

        tree->data.word     =   (char*) malloc(strlen(tempData.word)    *   sizeof(char) + 1);
        tree->data.motto    =   (char*) malloc(strlen(tempData.motto)   *   sizeof(char) + 1);
        tree->data.analyze  =   (char*) malloc(strlen(tempData.analyze) *   sizeof(char) + 1);


        strcpy(tree->data.word,       tempData.word);
        strcpy(tree->data.motto,          tempData.motto);
        strcpy(tree->data.analyze,       tempData.analyze);
        
        tree->data.prob     =   tempData.prob;
        tree->data.totalOccurrences  =   1;
        tree->data.lenghtWord    =   strlen(tempData.word);

        tree->left = tree->right       =   NULL;

        /* Se entra aqui é porque é uma word diferente. */
        /* Então vamos incrementar o total de words. */
        ++*ptrTotalWords;
    }
    return tree;



}