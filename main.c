#include <stdio.h>
#include <stdlib.h>

struct s_nodo
{
    int valor;
    struct s_nodo *pSig;
};

typedef struct s_nodo t_nodo;
typedef struct s_nodo* t_nodoPtr;

void enqueue(t_nodoPtr* ptrNodo, int valor);
int dequeue(t_nodoPtr* ptrNodo);
t_nodoPtr crear_nodo(int valor);

int main()
{
    int val;
    t_nodoPtr ptrCola = NULL;

    printf("\nEncolando 1 2 3 4...\n");
    enqueue(&ptrCola, 1);
    enqueue(&ptrCola, 2);
    enqueue(&ptrCola, 3);
    enqueue(&ptrCola, 4);

    printf("\nLos elementos de la cola, desencolados, son:\n");
    while (ptrCola != NULL)
    {
        val = dequeue(&ptrCola);
        printf("%d ", val);
    }
    printf("\n");

    return 0;
}

/**
 * Función que agrega un nodo a la cola (por el final de la cola)
 */
void enqueue(t_nodoPtr* ptrNodo, int valor)
{
    if (*ptrNodo == NULL)
    {
        *ptrNodo = crear_nodo(valor);
    }
    else
    {
        enqueue(&(*ptrNodo)->pSig, valor);
    }
}

/**
 * Función que saca un nodo de la cola (por el principio de la cola)
 * @return el valor del nodo que se saca
 */
int dequeue(t_nodoPtr* ptrNodo)
{
    int valor = (*ptrNodo)->valor;

    t_nodoPtr ptrElim = *ptrNodo;
    *ptrNodo = (*ptrNodo)->pSig;

    free(ptrElim);

    return valor;
}

/**
 * Función que crea un nodo
 * @return un puntero al nodo creado, o NULL
 */
 t_nodoPtr crear_nodo(int valor)
 {
    t_nodoPtr ptrNuevo = malloc(sizeof(t_nodo));

    if (ptrNuevo != NULL)
    {
        ptrNuevo->valor = valor;
        ptrNuevo->pSig = NULL;
    }

    return ptrNuevo;
 }
