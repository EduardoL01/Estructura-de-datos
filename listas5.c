// Eduardo Garcia Lopez

// Obtener el máximo y mínimo: Cree una función que identifique y retorne el valor máximo y mínimo de una lista.

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

    // Recorre la lista hasta el final
    while (aux != NULL)
    {
        printf("%d ", aux->numero); // Imprime el numero
        aux = aux->siguiente;       // Avanza al siguiente elemento de la lista
    }
    printf("\n");
}

// Función para obtener el numero mas grande y el mas pequeño e imprimirlos
void obtenerMaxMin(struct Numero *lista)
{
    struct Numero *aux = lista; // Inicializa el puntero auxiliar en el primer elemento de la lista
    int max = aux->numero;      // Inicializa el maximo con el primer numero de la lista
    int min = aux->numero;      // Inicializa el minimo con el primer numero de la lista

    // Recorre la lista hasta el final
    while (aux != NULL)
    {
        if (aux->numero > max) // Si el numero actual es mayor que el maximo
        {
            max = aux->numero; // El numero actual se convierte en el nuevo maximo
        }
        if (aux->numero < min) // Si el numero actual es menor que el minimo
        {
            min = aux->numero; // El numero actual se convierte en el nuevo minimo
        }
        aux = aux->siguiente; // Avanza al siguiente elemento de la lista
    }
    printf("\nEl numero mas grande es: %d\n", max);
    printf("El numero mas pequeño es: %d\n", min);
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

    // llama a la funcion obtenerMaxMin
    obtenerMaxMin(lista);

    return 0;
}