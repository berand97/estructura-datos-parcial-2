#include "Polinomios.h"

/*La función crea un resultado de división vacío.*/
ResultadoDivisao* criaResultadoDivisao()
{
    ResultadoDivisao* novo = (ResultadoDivisao*) malloc(sizeof(ResultadoDivisao));

    novo->quociente = NULL;
    novo->resto = NULL;

    return novo;
}

/*La función crea una lista vacía.*/
No* criaLista()
{
    return NULL;
}

/* insertar al inicio: devuelve la lista actualizada */
No* insereInicio (No* l, float coef, int exp)
{
    No* novo = (No*) malloc(sizeof(No));
    if(novo == NULL){ printf("Erro."); exit(1);}

    novo->coef = coef;
    novo->exp = exp;

    return novo;
}

/* insertar al final: devuelve la lista actualizada */
No* insereFim (No* l, float coef, int exp)
{
    No *novo, *p;
    p = l;

    if(p == NULL)
    {
        l = insereInicio(l, coef, exp);
        return l;
    }

    novo = (No*) malloc(sizeof(No));
    if(novo==NULL){ printf("Erro."); exit(1);}

    while(p->proximo != NULL)                        /*Buscando el final de la lista*/
    {
        p = p->proximo;
    }

    p->proximo = novo;

    novo->coef = coef;
    novo->exp = exp;
    novo->proximo = NULL;

    return l;
}

/* Función ordenada: inserta el elemento en orden y devuelve la lista actualizada*/
No* insereOrdenado (No* l, float coef, int exp)
{
    No* novo;
    No* ant = NULL;                         /* puntero al elemento antes de la posición de inserción*/
    No* post = l;                           /* puntero al elemento después de la posición de inserción*/

    /* posición de inserción de búsqueda */
    while (post != NULL && post->exp > exp)
    {
        ant = post;
        post = post->proximo;
    }

    /* crear nuevo elemento */
    novo = (No*) malloc(sizeof(No));
    if(novo==NULL)
    {
        printf("Error.");                                 /*prueba si hubo asignación */
        exit(1);
    }
    novo->coef = coef;
    novo->exp = exp;

    /* elemento de cadenas en la posición correcta */
    if (ant == NULL)                                    /* prueba si el elemento estará al principio*/
    {
        novo->proximo = l;
        l = novo;
    }
    else /* inserta un elemento en el medio o al final de la lista */
    {
        novo->proximo = ant->proximo;
        ant->proximo = novo;
    }
    return l;
}

/* la función elimina un no: el usuario ingresa un
o del nodo a eliminar*/
No* removeNo (No* l, No *endereco)
{
    No *ant, *atual;
    ant = NULL;
    atual = l;

    while((atual != NULL) && (atual!=endereco))
    {
        ant = atual;
        atual = atual->proximo;
    }

    if(atual == NULL) return l;
    if(ant == NULL)
    {
        l = atual->proximo;
    }
    else
    {
        ant->proximo = atual->proximo;
    }

    free(atual);

    return l;
}

/* función imprime: imprime valores de elementos */
void imprimeLista (No* l)
{
    No* p;
    p = l;

    if(p == NULL) printf("Lista vacía!");

    while(p != NULL)
    {
        printf("(%0.2f, %d) ", p->coef, p->exp);
        p = p->proximo;
    }
}

/*La función desasigna la lista*/
void destroiLista(No* l)
{
    No *atual, *prox;
    atual = l;

    while(atual != NULL)
    {
        prox = atual->proximo;
        free(atual);
        atual = prox;
    }
}
