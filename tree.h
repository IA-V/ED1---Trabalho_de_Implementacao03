#ifndef TNODE_H
#define	TNODE_H
typedef struct _tnode_ TNode;
typedef struct _aluno_ Aluno;

TNode *abpInserir(TNode *t, void *data, int (*cmp)(void *, void *));
TNode *abpRemover(TNode *t, void *key, int (*cmp)(void *, void *), void **data);
TNode *abpRemoveMaior(TNode *t, void *key, int(*cmp)(void *, void *), void **data);
void *abpBuscar(TNode *t, void *key, int (*cmp)(void *, void *));
TNode *abpEsvaziar(TNode *t);
int cmpMat(void *chave, void *item);
int cmpNota(void *chave, void *item);
int cmpNome(void *chave, void *item);
int cmpDadoNovo(void *chave, void *item);
void simetrico(TNode *t, void (*visit)(void *));

#endif
