#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define TRUE 1
#define FALSE 0

void visit(void *no);

typedef struct _aluno_{
    char nome[30];
    int matricula;
    float nota;
}Aluno;

int main()
{
    int qtd_insercoes = 0, opcao, opcao_interna;
    TNode *raiz = NULL;

    do
    {
        //data = NULL;
        opcao = 0;
        printf("Selecione uma opcao:\n1 - Criar a arvore\n2 - Inserir um item na arvore\n3 - Buscar um item da arvore\n4 - Remover um item da arvore\n5 - Exibir os itens da arvore\n6 - Esvaziar a arvore\n7 - Destruir a arvore\n8 - Sair do programa\n");
        scanf("%d", &opcao);
        fflush(stdin);
        printf("\n");
        switch(opcao)
        {
            case 1:
                printf("A arvore ja existe, insira ou remova dados dela!\n");
                break;
            case 2: ;
                Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));
                if(aluno != NULL)
                {
                        printf("Insira um nome para o aluno:\n");
                        fgets(aluno->nome, 30, stdin);
                        printf("Insira uma matricula para o aluno:\n");
                        scanf("%d", &aluno->matricula);
                        fflush(stdin);
                        printf("Insira uma nota para o aluno:\n");
                        scanf("%f", &aluno->nota);
                        fflush(stdin);
                        if((raiz = abpInserir(raiz, (void *)aluno, cmpDadoNovo)) == NULL)
                        {
                            printf("Erro ao inserir aluno!\n");
                        }
                        else
                        {
                            //raiz = abpInserir(raiz, (void *)aluno, cmpDadoNovo);
                            printf("Aluno adicionado com sucesso!\n");
                            qtd_insercoes++;
                        }
                }
                break;
            case 3: ;
                    Aluno *a;
                    opcao_interna = 0;
                    printf("Deseja buscar o aluno pela matricula, pela nota ou pelo nome?\n1 - Matricula\n2 - Nota\n3 - Nome\n");

                    scanf("%d", &opcao_interna);
                    fflush(stdin);
                    printf("\n");

                    switch(opcao_interna)
                    {
                        case 1: ;
                            int mat;

                            printf("Digite a matricula:\n");
                            scanf("%d", &mat);
                            fflush(stdin);

                            a = (Aluno *)abpBuscar(raiz, (void *)&mat, cmpMat);
                            if(a != NULL)
                            {
                                printf("\nInformacoes do aluno:\n\nNome: %sMatricula: %d\nNota: %.1f\n", a->nome, a->matricula, a->nota);
                            }
                            else
                            {
                                printf("\nAluno nao encontrado ou arvore vazia!\n");
                            }
                            break;
                        case 2: ;
                            float nota;

                            printf("Digite a nota:\n");
                            scanf("%f", &nota);
                            fflush(stdin);

                            a = (Aluno *)abpBuscar(raiz, (void *)&nota, cmpNota);
                            if(a != NULL)
                            {
                                printf("\nInformacoes do aluno:\n\nNome: %sMatricula: %d\nNota: %.1f\n", a->nome, a->matricula, a->nota);
                            }
                            else
                            {
                                printf("\nAluno nao encontrado ou arvore vazia!\n");
                            }
                            break;
                        case 3: ;
                            char nome[30];

                            printf("Digite o nome:\n");
                            fgets(nome, 30, stdin);
                            fflush(stdin);

                            a = (Aluno *)abpBuscar(raiz, (void *)nome, cmpNome);
                            if(a != NULL)
                            {
                                printf("\nInformacoes do aluno:\n\nNome: %sMatricula: %d\nNota: %.1f\n", a->nome, a->matricula, a->nota);
                            }
                            else
                            {
                                printf("\nAluno nao encontrado ou arvore vazia!\n");
                            }
                            break;
                        default:
                            printf("Opcao invalida!\n");
                    }
                break;
            case 4: ;
                    Aluno *data = NULL;
                    TNode *aux;
                    opcao_interna = 0;
                    printf("Deseja remover o aluno pela matricula, pela nota ou pelo nome?\n1 - Matricula\n2 - Nota\n3 - Nome\n");

                    scanf("%d", &opcao_interna);
                    fflush(stdin);
                    printf("\n");

                    switch(opcao_interna)
                    {
                        case 1: ;
                            int mat;

                            printf("Digite a matricula:\n");
                            scanf("%d", &mat);
                            fflush(stdin);

                            aux = abpRemover(raiz, (void *)&mat, cmpMat, (void *)&data);
                            if(data != NULL)
                            {
                                printf("\nInformacoes do aluno removido:\n\nNome: %sMatricula: %d\nNota: %.1f\n", data->nome, data->matricula, data->nota);
                                raiz = aux;
                                if(qtd_insercoes > 0)
                                {
                                    qtd_insercoes--;
                                }
                                if(qtd_insercoes == 0)
                                {
                                    raiz = NULL;
                                }
                            }
                            else
                            {
                                printf("\nAluno nao encontrado ou arvore vazia!\n");
                            }
                            break;
                        case 2: ;
                            float nota;

                            printf("Digite a nota:\n");
                            scanf("%f", &nota);
                            fflush(stdin);

                            aux = abpRemover(raiz, (void *)&nota, cmpNota, (void *)&data);
                            if(data != NULL)
                            {
                                printf("\nInformacoes do aluno removido:\n\nNome: %sMatricula: %d\nNota: %.1f\n", data->nome, data->matricula, data->nota);
                                raiz = aux;
                                if(qtd_insercoes > 0)
                                {
                                    qtd_insercoes--;
                                }
                                if(qtd_insercoes == 0)
                                {
                                    raiz = NULL;
                                }
                            }
                            else
                            {
                                printf("\nAluno nao encontrado ou arvore vazia!\n");
                            }
                            break;
                        case 3: ;
                            char nome[30];

                            printf("Digite o nome:\n");
                            fgets(nome, 30, stdin);
                            fflush(stdin);

                            aux = abpRemover(raiz, (void *)nome, cmpNome, (void *)&data);
                            if(data != NULL)
                            {
                                printf("\nInformacoes do aluno removido:\n\nNome: %sMatricula: %d\nNota: %.1f\n", data->nome, data->matricula, data->nota);
                                raiz = aux;
                                if(qtd_insercoes > 0)
                                {
                                    qtd_insercoes--;
                                }
                                if(qtd_insercoes == 0)
                                {
                                    raiz = NULL;
                                }
                            }
                            else
                            {
                                printf("\nAluno nao encontrado ou arvore vazia!\n");
                            }
                            break;
                        default:
                            printf("Opcao invalida!\n");
                    }
                break;
            case 5:
                if(raiz == NULL){
                    printf("A arvore esta vazia!\n");
                }
                else
                {
                    printf("\nInformacoes dos alunos:\n");
                    simetrico(raiz, visit);
                }
                break;
            case 6:
                    raiz = abpEsvaziar(raiz);
                    if(raiz == NULL)
                    {
                        printf("A arvore ja esta vazia!\n");
                    }
                    else
                    {
                        qtd_insercoes = 0;
                        printf("Arvore esvaziada com sucesso!\n");
                    }
                break;
            case 7:
                printf("Nao existe estrutura para ser destruida!\n");
                break;
            case 8:
                abpEsvaziar(raiz);
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
        printf("\n");
    }while(opcao != 8);

    return 0;
}

void visit(void *no){
    Aluno *aluno = (Aluno *)no;
    printf("\nNome: %sMatricula: %d\nNota: %.1f\n", aluno->nome, aluno->matricula, aluno->nota);
}
