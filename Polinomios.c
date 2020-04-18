#include "Polinomios.h"

/*La función toma los coeficientes y exponentes de una cadena (en forma de polinomio) y la coloca en una lista*/
No* transformaString(char* str)
{
    No* polinomio = criaLista();

    char strCoef[MAX] = "\0";
    char strExp[MAX] = "\0";
    char sinal = '+';

    float coef = 0;
    int expo = 0;

    while(strlen(str))                                      /*se ejecuta mientras la cadena str no está vacía*/
    {
        if (str[0] == '+' || str[0] == '-')                 /*guarda la señal y elimina la cadena str*/
        {
            sinal = str[0];
            apagarParteString(str, 1);
        }

        copiaParteNumerica(str, strCoef);                   /*copia el coeficiente a la cadena strNumero*/

        if(strlen(strCoef) == 0) coef = 1;                  /*comprueba si tiene un coeficiente*/
        else apagarParteString(str, strlen(strCoef));       /*eliminar la cadena strNumero desde el principio de str*/

        if(str[0] == 'x')                                   /*comprueba si el primer carácter de str es 'x'*/
        {
            apagarParteString(str,1);                       /*Si es así, elimine el carácter 'x' del principio de la cadena str*/

            if(str[0] == '^')                               /*comprueba si x tiene un exponente*/
            {
                apagarParteString(str, 1);                  /*si lo tiene, elimine el carácter '^' al comienzo de la cadena str*/

                copiaParteNumerica(str, strExp);           /*copie el exponente a la cadena strExp*/

                apagarParteString(str, strlen(strExp));     /*eliminar la cadena strExp desde el principio de la cadena str*/
            }
            else expo = 1;                                  /*si no tiene un exponente, determina que el exponente es igual a 1*/
        }
        else expo = 0;                                      /*si no tiene un exponente, determina que el exponente es igual a 1...
                                                            si el primer carácter de la cadena str no es 'x'...*/
        if(strlen(strCoef)) coef = atof(strCoef);           /*comprueba que las cadenas no son nulas*/
        if(strlen(strExp)) expo = atoi(strExp);
        if(sinal == '-') coef = coef*(-1);                  /*si el signo es negativo
                                                            el coeficiente se multiplica por -1*/

        polinomio = insereOrdenado(polinomio, coef, expo);          /*inserta nodo en la lista con coeficiente y exponente obtenido*/

                                                            /*borra todas las variables auxiliares*/
        coef = 0;
        expo = 0;
        sinal = '+';

        strcpy(strCoef,"\0");
        strcpy(strExp,"\0");
    }

    return polinomio;                                           /*devuelve la lista*/
}

/*La función borra el número de caracteres desde el principio.*/
void apagarParteString(char* str, int qnt)
{
    int tam, i;

    tam = strlen(str) - qnt;

    for (i = 0; str[tam] != '\0'; i++)
    {
        str[i] = str[qnt];
        qnt++;
    }

    str[tam] = '\0';
}

/*La función copia la parte numérica desde el comienzo de la primera cadena a la segunda cadena*/
void copiaParteNumerica(char* str1, char* str2)
{
    int i;

    for (i = 0; ( (str1[i] >= '0' && str1[i] <= '9') || str1[i] == '.') ; i++)
    {
        str2[i] = str1[i];
    }

    str2[i] = '\0';
}

/* La función inserta los dos polinomios que se agregarán y
luego los simplifica ya que la inserción está ordenada*/
No *somaPolinomio(No *l1,No *l2)
{

    No *l3,*p1,*p2;

    l3=criaLista();
    p1=l1;
    p2=l2;

    while(p1!=NULL || p2!=NULL)
    {
        if(p1!=NULL)
        {
            l3=insereOrdenado(l3,p1->coef,p1->exp);
            p1=p1->proximo;
        }
        if(p2!=NULL)
        {
            l3=insereOrdenado(l3,p2->coef,p2->exp);
            p2=p2->proximo;
        }
    }

    l3=simplificaPolinomio(l3);

    return l3;
}

No* subtrairPolinomios(No* polinomio1, No* polinomio2)
{
    No *polinomioResultante, *p1, *p2;

    polinomioResultante = criaLista();

    p1 = polinomio1;
    p2 = polinomio2;

    if(polinomio1 == NULL && polinomio2 == NULL) return NULL;       /*prueba si los polinomios no son nulos*/

    while(p1 != NULL || p2 != NULL)                                 /*desplazarse por las listas hasta el final de los dos*/
    {
        if(p1 != NULL && p2 != NULL)                         /*Si p1 y p2 son diferentes de nulo*/
        {

            if(p1->exp == p2->exp)                          /*Si tienen exponentes iguales*/
            {
                if((p1->coef - p2->coef) != 0)              /*si el coeficiente p1 menos el
                                                            coeficiente de p2 no es igual a cero,
                                                            inserta en la lista resultante*/
                {
                    polinomioResultante = insereOrdenado(polinomioResultante, (p1->coef - p2->coef), p1->exp);
                    p1 = p1->proximo;
                    p2 = p2->proximo;
                }
                else                                       /*si no apunta a la siguiente*/
                {
                    p1 = p1->proximo;
                    p2 = p2->proximo;
                }
            }
            else                                          /*si los coeficientes son diferentes*/
            {
                if(p1->exp > p2->exp)                     /*si el exponente de p1 es mayor que el de p2,
                                                          si el exponente de p1 es mayor que el de p2*/
                {
                    polinomioResultante = insereOrdenado(polinomioResultante, p1->coef, p1->exp);
                    p1 = p1->proximo;
                }
                else                                      /*si no inserta p2 y apunta al siguiente*/
                {
                    polinomioResultante = insereOrdenado(polinomioResultante, (p2->coef* (-1)), p2->exp);
                    p2 = p2->proximo;
                }
            }
        }
        else                                              /*Si una de las listas es nula*/
        {
            if(p1 != NULL)                                /*Si p1 no es el nulo se inserta en
                                                          lista resultante y puntos a la siguiente*/
            {
                polinomioResultante = insereOrdenado(polinomioResultante, p1->coef, p1->exp);
                p1 = p1->proximo;
            }
            if(p2 != NULL)                                 /*Si p2 no es la inserción nula en
                                                           lista resultante y puntos a la siguiente*/
            {
                polinomioResultante = insereOrdenado(polinomioResultante, -p2->coef, p2->exp);
                p2 = p2->proximo;
            }
        }
    }

    return polinomioResultante;
}

/* La siguiente función multiplica dos polinomios.*/
No* multiplicaPolinomio(No *l1,No *l2)
{
    No* l3,*p1,*p2;
    l3=criaLista();

    p1=l1;
    p2=l2;

    while(p1!=NULL)
    {

        while(p2!=NULL)
        {

            if(p1->exp!=0 && p2->exp==0) /*Si el exponente del segundo polinomio es cero*/
                l3 = insereOrdenado(l3,p1->coef*p2->coef,p1->exp);

            else if(p1->exp==0 && p2->exp!=0) /*Si el exponente del segundo polinomio es cero...*/
                l3 = insereOrdenado(l3,p1->coef*p2->coef,p2->exp);
            else
                l3 = insereOrdenado(l3,p1->coef*p2->coef,p1->exp+p2->exp); /*Si los dos exponentes son diferentes de 0*/
            p2=p2->proximo;
        }
        p2=l2;
        p1=p1->proximo;
    }

    l3=simplificaPolinomio(l3);

    /**Escribir en el archivo**/

    return l3;
}

ResultadoDivisao* dividirPolinomios(No* polinomio1, No* polinomio2)
{
    ResultadoDivisao* resultado;
    No *pAux, *p;

    float coef;
    int expo;

    resultado = criaResultadoDivisao();                 /*Escribir en el archivo... */
    pAux = criaLista();

    if(polinomio1->exp < polinomio2->exp)               /*si el exponente de la primera en
                                                        el polinomio 1 es menor que el
                                                        exponente del primer número de polinomio2*/
    {
        p = polinomio1;

        while(p != NULL)                                /*inserta polinomio1 en el resto
                                                        el resultado, y el cociente es cero*/
        {
            resultado->resto = insereOrdenado(resultado->resto, p->coef, p->exp);
            p = p->proximo;
        }

        return resultado;
    }

    p = polinomio1;

    do
    {
        coef = (p->coef / polinomio2->coef);                        /*divide los coeficientes*/
        expo = (p->exp - polinomio2->exp);                          /*resta exponentes*/

        resultado->quociente = insereOrdenado(resultado->quociente, coef, expo);     /*almacena el resultado en el cociente*/

        pAux = insereInicio(pAux, coef, expo);                      /*almacena el coeficiente calculado y el exponente*/

        pAux = multiplicaPolinomio(pAux, polinomio2);               /*guarda el resultado de la multiplicación de
                                                                    valores del último número del coeficiente por polinomio2*/

        resultado->resto = subtrairPolinomios(p, pAux);             /*recibe el resultado de la resta de p po pAux*/

        pAux = removeNo(pAux, pAux);                                /*elimina el único número de pAux*/

        p = resultado->resto;                                       /*p señala al resto*/
    }
    while( (resultado->resto != NULL) && (resultado->resto->exp >= polinomio2->exp) );  /*haz esto mientras el resto
                                                                                         es diferente de cero y el exponente
                                                                                         del primero en el resto es
                                                                                         mayor / igual al exponente de
                                                                                         primero en el polinomio2*/

    return resultado;                                               /*devuelve el resultado*/
}

/* En esta función, se compara nodo por nodo para ver si es posible la simplificación
entonces se agregan los coeficientes y se elimina un nodo */
No* simplificaPolinomio(No *l)
{

    No *atual,*post;

    atual=l;
    post=l->proximo;

    while(post!=NULL)
    {

        if(atual->exp==post->exp)
        {
            post->coef+=atual->coef;
            l=removeNo(l,atual);
        }
        atual=post;
        post=post->proximo;
    }

    return l;
}

/* La función lee un valor real y calcula el resultado del polinomio. */
float resultadoPolinomio(No *l,float v)
{

    float res=0;
    No *p;

    p=l;

    while(p!=NULL)
    {

        res+=p->coef*pow(v,p->exp);
        p=p->proximo;
    }

    /*TODO
   ¡ESCRIBA EL RESULTADO EN EL ARCHIVO!*/
    return res;
}


/* La composición calcula el valor insertado en un polinomio y
tome este resultado calculando el próximo polinomio  */
float compostoPolinomio(No *l1,No *l2,float v){

    No *q=l1;
    No *p=l2;

    float res;

    res=resultadoPolinomio(q,v);
    res=resultadoPolinomio(p,res);

    return res;
}

/* En la enésima composición se recibe el valor de x,
luego se lee el polinomio y se calcula el valor de cada polinomio insertado
siempre usando el último resultado calculado*/
float n_compostoPolinomio(float v){

    char stringPolinomio[MAX];

    while(1){
        No *l=criaLista();
        printf("Ingrese el polinomio i-esimo (tecla S para salir),\n");
        fflush(stdin);
        gets(stringPolinomio);
        if(stringPolinomio[0]=='S' || stringPolinomio[0]=='s')
            break;
        l=transformaString(stringPolinomio);
        v=resultadoPolinomio(l,v);
        destroiLista(l);
    }
    return v;
}

int verificaString(char* str)
{
    int i, contemX = 0;
    char numero;

    for(i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == 'x') contemX = 1;

        if( !(str[i] >= '0' && str[i] <= '9') && str[i] != 'x' && str[i] != '^' && str[i] != '+' && str[i] != '-' && str[i] != '.')
        {
            return 0;
        }

        if(str[i] == 'x' && (str[i+1] != '^' && str[i+1] != '+' && str[i+1] != '-' && str[i+1] != '\0' ) )
        {
            return 0;
        }

        if(str[i] == '^' &&  !(str[i+1] >= '0' && str[i+1] <='9'))
        {
            return 0;
        }
    }

    if(contemX) return 1;
    else return 0;
}

/*La función integra un polinomio en un intervalo*/
float integralPolinomio(No* polinomio, int intervaloSuperior, int intervaloInferior)
{
    No* polinomioResultante;
    float resultado;

    polinomioResultante = criaLista();

    polinomioResultante = integral(polinomio);          /*integra el polinomio
                                                         y luego calcula el resultado */

    resultado = resultadoPolinomio(polinomioResultante, intervaloSuperior) - resultadoPolinomio(polinomioResultante, intervaloInferior);

    return resultado;
}

/*Integra el polinomio y el polinomio resultante se almacena en otra lista. Nota: no considera la constante generada después de la integral*/
No* integral(No* polinomio)
{
    No* polinomioResultante, *p;

    polinomioResultante = criaLista();

    p = polinomio;

    while(p != NULL)             /*mientras que p no apunta a nulo inserta un nuevo nodo en el polinomio*/
    {
                                /*el coeficiente de cada nodo del polinomio es el coeficiente que p puntos dividido por el exponente agregado con 1
                                 y el exponente es el exponente que p agrega a 1*/
        polinomioResultante = insereOrdenado(polinomioResultante, (p->coef/(p->exp + 1)), (p->exp + 1));
        p = p->proximo;
    }

    return polinomioResultante;
}

No* calculaDerivada(No* polinomio){

    No *polinomioResultante, *p1;

    polinomioResultante = criaLista();

    p1 = polinomio;

    if(polinomio == NULL) return NULL;       /*prueba si el polinomio no es nulo*/

    while(p1 != NULL)
    {
        if(p1->exp >= 1)    /* Deriva de para el alto> = 1, porque la derivada de una constante es cero */
        {
            polinomioResultante = insereOrdenado(polinomioResultante, (p1->coef * p1->exp), p1->exp - 1);
        }

        p1 = p1->proximo;
    }

    return polinomioResultante;
}


/** La función convierte una lista de un polinomio en una cadena **/

char *transformaPolinomio(No* polinomio)
{
    No* p = polinomio;
    char stringPolinomio[MAX], aux[10];

    while(p != NULL)
    {
        if(p->coef == 1 && p->coef != 0) strcat(stringPolinomio, "x");
        else
        {
            ftoa(p->coef, aux);
            strcat(stringPolinomio, aux);
            strcat(stringPolinomio, "x");
        }

        if(p->exp > 1)
        {
            strcat(stringPolinomio, "^");
            itoa(p->exp, aux, 10);
            strcat(stringPolinomio, aux);
        }

        p = p->proximo;
    }

    return stringPolinomio;
}

