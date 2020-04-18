#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 20

struct no
{
    float coef;                              /*coeficiente*/
    int exp;                                 /*exponente*/
    struct no *proximo;                      /*sucesor de no*/
};
typedef struct no No;

struct resultadoDivisao
{
    struct no *quociente;
    struct no *resto;
};
typedef struct resultadoDivisao ResultadoDivisao;

struct noLOG{
    char* info;
    struct noLOG *proximo;
};typedef struct noLOG NoLOG;

No* criaLista();
No* insereInicio (No* l, float coef, int exp);
No* insereFim (No* l, float coef, int exp);
No* insereOrdenado (No* l, float coef, int exp);
No* removeNo (No* l, No *endereco);
void imprimeLista (No* l);
void destroiLista(No* l);
No* transformaString(char* str);
void apagarParteString(char* str, int tam);
void copiaParteNumerica(char* str1, char* str2);
No *somaPolinomio(No *l1,No *l2);
No* subtrairPolinomios(No* polinomio1, No* polinomio2);
No* multiplicaPolinomio(No *l1,No *l2);
ResultadoDivisao* criaResultadoDivisao();
ResultadoDivisao* dividirPolinomios(No* polinomio1, No* polinomio2);
/**DERIVADA**/
No* simplificaPolinomio(No *l);

int verificaString(char* str);
float integralPolinomio(No* polinomio, int intervaloSuperior, int intervaloInferior);
No* integral(No* polinomio);

float resultadoPolinomio(No *l,float v);
float compostoPolinomio(No *l1,No *l2,float v);
float n_compostoPolinomio(float v);

/** Cada vez que realice una nueva operación, inserte la cadena de usuario o el resultado de la operación
(ej: Resultado = 3x ^ 2 + 2x) en la lista de REGISTRO, al final, cuando uso para solicitar el archivo de registro, todo desde
La lista se escribe e imprime desde el archivo. **/
char *transformaPolinomio(No* polinomio);
NoLOG* criaListaLOG(); /**Arrancar a principal**/
NoLOG* InsereInicioLOG(NoLOG* l, char* info); /** Nueva función **/
void escreveLOG(FILE *log, NoLOG *lista); /** Nueva función **/
void imprimeLOG(FILE *log); /** Nueva función **/
