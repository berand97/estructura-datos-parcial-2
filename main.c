#include "Polinomios.h"

int main(void)
{
    char stringPolinomio[MAX];
    FILE *arquivo, *log; /* log = registro de entradas de usuario */
    NoLOG *historico;
    int n, aux = 1, valor, valor2;
    float res;

    No *polinomio1, *polinomio2, *polinomio3, *lista;

    lista = criaLista();
    historico = criaListaLOG();

    polinomio1 = criaLista();
    polinomio2 = criaLista();
    polinomio3 = criaLista();

    arquivo = fopen("arquivo.txt", "a+");
    if(arquivo == NULL)  /* Abrir archivo */
    {
            printf("Erro na abertura do arquivo");
            exit(1);
    }

    do /* Comprueba si el usuario escribió un número no válido*/
    {
        printf("\ndigite una opcion:");
        printf("\n1- leer  polinomio de un archivo.");
        printf("\n2- leer  polinomio de  teclado:\n");
        scanf("%d", &n);

    }
    while(n != 1 && n != 2);

    switch(n)  /*Verifica se por onde o usario quer enviar o polinomio*/
    {
    case 1:/* Leer los polinomios de un archivo */
        while (!feof(arquivo))
        {
            fgets(stringPolinomio, MAX, arquivo);
            printf("\n%s", stringPolinomio);
            lista = transformaString(stringPolinomio);
            imprimeLista(lista);
        }

        break;

    case 2:/* Leer los polinomios del teclado */
        do /* Continúe leyendo los polinomios hasta que el usuario elija detener */
        {
            printf("Ingrese el polinomio:\n");
            setbuf(stdin, NULL);
            scanf("%s", &stringPolinomio);
            setbuf(stdin, NULL);

            fputs(stringPolinomio, arquivo);

            printf("\n¿Quieres agregar más polinomios??");
            printf("\ndigite una opcion:");
            printf("\n1- Continuar a agregar.");
            printf("\n0- Sair.\n");

            scanf("%d", &aux);
        }
        while(aux != 0);

        break;

    default:
        ;
    }

    do
    {

    printf("\n\ndigite una opcion:");
    printf("\n1- Sumar dos polinomios.");
    printf("\n2- Restar dos polinomios.");
    printf("\n3- Multiplicar dos polinomios.");
    printf("\n4- Dividir dos polinomios.");
    printf("\n5- Calcular la derivada de un polinomio.");
    printf("\n6- Simplificar um polinomio.");
    printf("\n7- Calcule el polinomio dado un valor para x.");
    printf("\n8- Calcular um polinomio composto Q(P(x)) dado x.");
    printf("\n9- Calcule un polinomio compuesto de tantos polinomios como desee.");
    printf("\n10- Integral definida.");
    printf("\n11- Integral indefinida.");
    printf("\n0- Sair.\n\n");

    scanf("%d", &n);

        switch(n) /* Switch-case das operacoes polinomiais */
        {
        case 1:/* Suma */
            do
            {
                printf("\nEntra con el otro:\n");
                setbuf(stdin, NULL);
                scanf("%s", &stringPolinomio);
                setbuf(stdin, NULL);
                if(!verificaString(stringPolinomio)) printf("\nPolinomio invalido, digite nuevamente:\n");
            }
            while(!verificaString(stringPolinomio));

            polinomio1 = transformaString(stringPolinomio);

            do
            {
                printf("\nEntra con el otro polinomio:\n");
                setbuf(stdin, NULL);
                scanf("%s", &stringPolinomio);
                setbuf(stdin, NULL);
                if(!verificaString(stringPolinomio)) printf("\nPolinomio invalido, digite nuevamente:\n");
            }
            while(!verificaString(stringPolinomio));

            polinomio2 = transformaString(stringPolinomio);

            polinomio3 = somaPolinomio(polinomio1, polinomio2);

            printf("Resultado = ");
            imprimeLista(polinomio3);

            break;

        case 2:/* Resta */
            do
            {
                printf("\nEntra con el otro:\n");
                setbuf(stdin, NULL);
                scanf("%s", &stringPolinomio);
                setbuf(stdin, NULL);
                if(!verificaString(stringPolinomio)) printf("\nPolinomio invalido, digite nuevamente:\n");
            }
            while(!verificaString(stringPolinomio));

            polinomio1 = transformaString(stringPolinomio);

            do
            {
                printf("\nEntra con el otro polinomio:\n");
                setbuf(stdin, NULL);
                scanf("%s", &stringPolinomio);
                setbuf(stdin, NULL);
                if(!verificaString(stringPolinomio)) printf("\nPolinomio invalido, digite nuevamente:\n");
            }
            while(!verificaString(stringPolinomio));

            polinomio2 = transformaString(stringPolinomio);

            polinomio3 = subtrairPolinomios(polinomio1, polinomio2);

            printf("Resultado = ");
            imprimeLista(polinomio3);

            break;
        case 3:/* Multiplicacion */
            do
            {
                printf("\nEntra con el otro:\n");
                setbuf(stdin, NULL);
                scanf("%s", &stringPolinomio);
                setbuf(stdin, NULL);
                if(!verificaString(stringPolinomio)) printf("\nPolinomio invalido, digite nuevamente:\n");
            }
            while(!verificaString(stringPolinomio));

            polinomio1 = transformaString(stringPolinomio);

            do
            {
                printf("\nEntra con el otro polinomio:\n");
                setbuf(stdin, NULL);
                scanf("%s", &stringPolinomio);
                setbuf(stdin, NULL);
                if(!verificaString(stringPolinomio)) printf("\nPolinomio invalido, digite nuevamente:\n");
            }
            while(!verificaString(stringPolinomio));

            polinomio2 = transformaString(stringPolinomio);

            polinomio3 = multiplicaPolinomio(polinomio1, polinomio2);

            printf("Resultado = ");
            imprimeLista(polinomio3);

            break;

        case 4: /* Division */
            do
            {
                printf("\nEntra con el otro:\n");
                setbuf(stdin, NULL);
                scanf("%s", &stringPolinomio);
                setbuf(stdin, NULL);
                if(!verificaString(stringPolinomio)) printf("\nPolinomio invalido, digite nuevamente:\n");
            }
            while(!verificaString(stringPolinomio));

            polinomio1 = transformaString(stringPolinomio);

            do
            {
                printf("\nEntra con el otro polinomio:\n");
                setbuf(stdin, NULL);
                scanf("%s", &stringPolinomio);
                setbuf(stdin, NULL);
                if(!verificaString(stringPolinomio)) printf("\nPolinomio invalido, digite nuevamente:\n");
            }
            while(!verificaString(stringPolinomio));

            polinomio2 = transformaString(stringPolinomio);

            polinomio3 = dividirPolinomios(polinomio1, polinomio2);

            printf("Resultado = ");
            imprimeLista(polinomio3);

            break;

        case 5:/* Derivada */
            do
            {
                printf("\nEntra con el otro polinomio:\n");
                setbuf(stdin, NULL);
                scanf("%s", &stringPolinomio);
                setbuf(stdin, NULL);
                if(!verificaString(stringPolinomio)) printf("\nPolinomio invalido, digite nuevamente:\n");
            }
            while(!verificaString(stringPolinomio));

            polinomio1 = transformaString(stringPolinomio);

            polinomio2 = calculaDerivada(polinomio1);

            printf("Resultado = ");
            imprimeLista(polinomio2);

            break;
        case 6:/* Simplificar */
            do
            {
                printf("\nEntra con el otro:\n");
                setbuf(stdin, NULL);
                scanf("%s", &stringPolinomio);
                setbuf(stdin, NULL);
                if(!verificaString(stringPolinomio)) printf("\nPolinomio invalido, digite nuevamente:\n");
            }
            while(!verificaString(stringPolinomio));

            polinomio1 = transformaString(stringPolinomio);

            polinomio2 = simplificaPolinomio(polinomio1);

            printf("Resultado = ");
            imprimeLista(polinomio2);

            break;

        case 7:/* Calcule P (x) a partir de x */
            do
            {
                printf("\nEntra con el otro:\n");
                setbuf(stdin, NULL);
                scanf("%s", &stringPolinomio);
                setbuf(stdin, NULL);
                if(!verificaString(stringPolinomio)) printf("\nPolinomio invalido, digite nuevamente:\n");
            }
            while(!verificaString(stringPolinomio));

            polinomio1 = transformaString(stringPolinomio);

            printf("\nEntre com o valor:\n");
            scanf("%f", &valor);

            res = resultadoPolinomio(polinomio1, valor);

            printf("Resultado = %f", valor);

            break;

        case 8:/* Q(P(x)) */
            do
            {
                printf("\nEntra con el otro:\n");
                setbuf(stdin, NULL);
                scanf("%s", &stringPolinomio);
                setbuf(stdin, NULL);
                if(!verificaString(stringPolinomio)) printf("\nPolinomio invalido, digite nuevamente:\n");
            }
            while(!verificaString(stringPolinomio));

            polinomio1 = transformaString(stringPolinomio);

            do
            {
                printf("\nEntra con el otro:\n");
                setbuf(stdin, NULL);
                scanf("%s", &stringPolinomio);
                setbuf(stdin, NULL);
                if(!verificaString(stringPolinomio)) printf("\nPolinomio invalido, digite nuevamente:\n");
            }
            while(!verificaString(stringPolinomio));

            polinomio2 = transformaString(stringPolinomio);

            printf("\nEntre com o valor:\n");
            scanf("%f", &valor);

            res = compostoPolinomio(polinomio1, polinomio2, valor);

            printf("Resultado = %f", valor);

            break;

        case 9: /* Polinomios compuestos */

            printf("\nEntre com o valor:\n");
            scanf("%f", &valor);

            res = n_compostoPolinomio(valor);

            printf("Resultado = %f", valor);

            break;

        case 10: /* Integral definida */
            do
            {
                printf("\nEntra con el otro:\n");
                setbuf(stdin, NULL);
                scanf("%s", &stringPolinomio);
                setbuf(stdin, NULL);
                if(!verificaString(stringPolinomio)) printf("\nPolinomio invalido, digite nuevamente:\n");
            }
            while(!verificaString(stringPolinomio));

            polinomio1 = transformaString(stringPolinomio);

            printf("\nIngrese el valor del rango superior:\n");
            scanf("%f", &valor);

            printf("\nIngrese el valor del rango superior:\n");
            scanf("%f", &valor2);

            res = integralPolinomio(polinomio1, valor, valor2);

            printf("Resultado = %f", res);

            break;

        case 11: /*Integral indefinida*/
            do
            {
                printf("\nEntra con el otro:\n");
                setbuf(stdin, NULL);
                scanf("%s", &stringPolinomio);
                setbuf(stdin, NULL);
                if(!verificaString(stringPolinomio)) printf("\nPolinomio invalido, digite nuevamente:\n");
            }
            while(!verificaString(stringPolinomio));

            polinomio1 = transformaString(stringPolinomio);

            polinomio2 = integral(polinomio1);

            printf("Resultado = ");
            imprimeLista(polinomio2);

            break;

        default:;
        }

    } while(n != 0);

    fclose(arquivo);

    return 0;
}
