// Eduardo Garcia Lopez

// Eliminar duplicados en una lista: Implemente una función que elimine todos los elementos duplicados de una lista, dejando solo una instancia de cada uno.
// me di cuenta de que me complique haciendolo con un struct de datos de alumnos, asi que ahora ocupare numeros.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// definir una estructura para almacenar dato numerico
struct Numero
{
    int numero;
    struct Numero *siguiente; // apunta al siguiente numero en la lista
};

// Función para crear un nuevo numero
struct Numero *crearNumero(int numero)
{
    // Asigna memoria para un nuevo numero
    struct Numero *nuevoNumero = (struct Numero *)malloc(sizeof(struct Numero));

    // Verifica si se asignó correctamente la memoria
    if (nuevoNumero != NULL)
    {
        // Copia el numero al nuevo numero
        nuevoNumero->numero = numero;
        nuevoNumero->siguiente = NULL; // Establece el siguiente como NULL
    }
    return nuevoNumero;
}

// Función para insertar un numero al final de la lista
void insertarAlFinal(struct Numero **lista, struct Numero *nuevoNumero)
{
    if (*lista == NULL)
    {
        // Si la lista está vacía, el nuevo numero se convierte en el primer elemento
        *lista = nuevoNumero;
    }
    else
    {
        struct Numero *aux = *lista;
        while (aux->siguiente != NULL)
        {
            aux = aux->siguiente; // Avanza al siguiente elemento en la lista
        }
        aux->siguiente = nuevoNumero; // Enlaza el nuevo numero al último elemento
    }
}

// Función para imprimir la lista de numeros
void imprimirLista(struct Numero *lista)
{
    struct Numero *aux = lista; // Inicializa el puntero auxiliar en el primer elemento de la lista

    while (aux != NULL)
    {
        printf("%d ", aux->numero); // Imprime el numero
        aux = aux->siguiente;       // Avanza al siguiente elemento de la lista
    }
    printf("\n");
}

// Función para eliminar elementos duplicados de la lista
void eliminarDuplicados(struct Numero *lista)
{
    // Inicia desde el principio de la lista
    struct Numero *actual = lista;

    while (actual != NULL)
    {
        // crea un puntero para comparar el elemento actual con los siguientes
        struct Numero *comparador = actual;

        // recorre por cada elemento que se encuntre delante del actual
        while (comparador->siguiente != NULL)
        {
            // Comprobar si el siguiente elemento es un duplicado del actual
            if (comparador->siguiente->numero == actual->numero)
            {
                // Si es un duplicado, eliminar el duplicado
                struct Numero *duplicado = comparador->siguiente;
                comparador->siguiente = duplicado->siguiente;
                free(duplicado); // Liberar memoria del duplicado
            }
            else
            {
                // Si no es un duplicado, avanzar al siguiente elemento en la lista
                comparador = comparador->siguiente;
            }
        }

        // Avanzar al siguiente elemento en la lista principal
        actual = actual->siguiente;
    }
}

int main()
{
    struct Numero *lista = NULL; // Inicializa la lista como vacía

    // Inserta varios numeros al final de la lista
    insertarAlFinal(&lista, crearNumero(1));
    insertarAlFinal(&lista, crearNumero(2));
    insertarAlFinal(&lista, crearNumero(3));
    insertarAlFinal(&lista, crearNumero(4));
    insertarAlFinal(&lista, crearNumero(3));
    insertarAlFinal(&lista, crearNumero(6));
    insertarAlFinal(&lista, crearNumero(7));
    insertarAlFinal(&lista, crearNumero(4));

    // Imprime la lista de numeros
    printf("\nLista de numeros\n");
    imprimirLista(lista);

    // Elimina los elementos duplicados de la lista
    eliminarDuplicados(lista);

    // Imprime la lista de numeros
    printf("\nLista de numeros sin duplicados\n");
    imprimirLista(lista);

    return 0;
}