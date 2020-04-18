#include "Polinomios.h"

NoLOG* criaListaLOG(){ /* Crear lista de LOG*/
    return NULL;
}

/* Inserte operaciones de usuario y resultados al comienzo de la lista LOG */
NoLOG* InsereInicioLOG (NoLOG* l, char* info)
{
    NoLOG* novo = (NoLOG*) malloc(sizeof(NoLOG));
    if(novo == NULL){ printf("Error."); exit(1);}

    novo->info = info;
    novo->proximo = l;

    return novo;
}

/** La función recibe una lista L y la inserta en el archivo **/
void escreveLOG(FILE *log, NoLOG* lista)
{
    NoLOG *l = lista;

    while(l != NULL){ /** Hasta que la lista llegue al final, inserte la cadena NoLOG para cada char * en la lista en el archivo, línea por línea **/
        fputs (l->info, log);
        l = l->proximo;
    }
}

void imprimeLOG(FILE *log){ /** Función que imprime el REGISTRO **/
    char s[20];
    log = fopen("log.txt", "r");

    if(log == NULL){ printf("Error, no se pudo abrir el archivo\n");}

    else{
            while(fscanf(log,"%s", &s) != EOF){ /* Printa linha a linha */
                    printf("%s \n", s);
            }
        }

    fclose(log);
}
