#include "tree.h"
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

typedef struct _tnode_ {
    void *data;
    struct _tnode_ *left;
    struct _tnode_ *right;
}TNode;

 typedef struct _aluno_{
    char nome[30];
    int matricula;
    float nota;
}Aluno;

TNode *abpInserir(TNode *t, void *data, int (*cmp)(void *, void *))
{
    TNode *newnode;
    if(t != NULL)
    {
        if(cmp(data, t->data) < 0)
        {
            t->left = abpInserir(t->left, data, cmp);
        }
        else
        {
            t->right = abpInserir(t->right, data, cmp);
        }
        return t;
    }
    else
    {
        newnode = (TNode *)malloc(sizeof(TNode));
        if(newnode != NULL)
        {
            newnode->data = data;
            newnode->left =	NULL;
            newnode->right= NULL;
            return newnode;
        }
        else
        {
            return NULL;
        }
    }
}

void *abpBuscar(TNode *t, void *key, int (*cmp)(void *, void *))
{
    void *data = NULL;
    int	stat;
    if(t != NULL)
    {
        stat = cmp(key, t->data);
        if(stat	== 1)
        {
            return t->data;
        }
        else
        {
            if((data = abpBuscar(t->left, key, cmp)) != NULL)
            {
                return data;
            }

            if((data = abpBuscar(t->right, key, cmp)) != NULL)
            {
                return data;
            }
        }
    }
    return data;
 }

TNode *abpRemover(TNode *t, void *key, int (*cmp)(void *, void *), void **data)
{
    void *data2, *aux;
    int stat;
    if(t != NULL)
    {
        stat = cmp(key, t->data);
        if(stat == 1)
        {
            if(t->left == NULL && t->right == NULL)
            {
                *data = t->data;
                free(t);
                return NULL;
            }
            else if(t->left == NULL)
            {
                aux = t->right;
                *data = t->data;
                free(t);
                return aux;
            }
            else if(t->right == NULL)
            {
                aux = t->left;
                *data = t->data;
                free(t);
                return aux;
            }
            else
            {
                *data = t->data;
                t->left = abpRemoveMaior(t->left, key, cmp, &data2);
                t->data	= data2;
                return t;
            }
        }
        else
        {
            t->left = abpRemover(t->left, key, cmp, data);
            t->right = abpRemover(t->right, key, cmp, data);
            return t;
        }
    }
}

TNode *abpRemoveMaior(TNode *t, void *key, int(*cmp)(void *, void *), void **data)
{
    void *data2, *aux;
    if	(t!= NULL)
    {
        if(t->right != NULL)
        {
            t->right = abpRemoveMaior(t->left, key, cmp, &data2);
        }
        else
        {
            if(t->left != NULL)
            {
                aux	= t->left;
                *data = t->data;
                free(t);
                return aux;
            }
            else
            {
                *data = t->data;
                free(t);
                return NULL;
            }
        }
        *data = NULL;
        return NULL;
    }
}

TNode *abpEsvaziar(TNode *t)
{
    if(t != NULL)
    {
        t->left = abpEsvaziar(t->left);
        t->right = abpEsvaziar(t->right);
        free(t);
        t = NULL;
    }
    return NULL;
}

int cmpMat(void *chave, void *item)
{
    int *chave_mat;
    Aluno *item_no;

    chave_mat = (int *)chave;
    item_no = (Aluno *)item;

    if (*chave_mat == item_no->matricula)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int cmpNota(void *chave, void *item)
{
    float *chave_nota;
    Aluno *item_no;

    chave_nota = (float *)chave;
    item_no= (Aluno *)item;

    if (*chave_nota == item_no->nota)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int cmpNome(void *chave, void *item)
{
    char chave_nome[30];
    Aluno *item_no;

    strcpy(chave_nome, (char *)chave);
    item_no = (Aluno *)item;

    if (strcmp(chave_nome, item_no->nome) == 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int cmpDadoNovo(void *chave, void *item)
{
    char *chave_nome;
    Aluno *item_no, *item_novo;

    item_novo = (Aluno *)chave;
    item_no = (Aluno *)item;

    return strcmp(item_novo->nome, item_no->nome);
}

void simetrico(TNode *t, void (*visit)(void *)){
    if (t != NULL){
        simetrico(t->left, visit);
        visit(t->data);
        simetrico(t->right, visit);
    }
}
