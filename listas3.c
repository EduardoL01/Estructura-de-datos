// Eduardo Garcia Lopez

// Revertir una lista: Diseñe una función que invierta el orden de los elementos de una lista.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definir una estructura para almacenar información de un alumno
struct Alumno
{
    char nombre[20];
    char apellido[20];
    int edad;
    int calificacion;
    struct Alumno *siguiente; // apunta al siguiente alumno en la lista
};

// Función para crear un nuevo alumno
struct Alumno *crearAlumno(const char nombre[], const char apellido[], int edad, int calificacion)
{
    // Asigna memoria para un nuevo alumno
    struct Alumno *nuevoAlumno = (struct Alumno *)malloc(sizeof(struct Alumno));

    // Verifica si se asignó correctamente la memoria
    if (nuevoAlumno != NULL)
    {
        // Copia el nombre, edad y calificación al nuevo alumno
        strcpy(nuevoAlumno->nombre, nombre);
        strcpy(nuevoAlumno->apellido, apellido);
        nuevoAlumno->edad = edad;
        nuevoAlumno->calificacion = calificacion;
        nuevoAlumno->siguiente = NULL; // Establece el siguiente como NULL
    }
    return nuevoAlumno;
}

// Función para insertar un alumno al final de la lista
void insertarAlFinal(struct Alumno **lista, struct Alumno *nuevoAlumno)
{
    if (*lista == NULL)
    {
        // Si la lista está vacía, el nuevo alumno se convierte en el primer elemento
        *lista = nuevoAlumno;
    }
    else
    {
        struct Alumno *aux = *lista;
        while (aux->siguiente != NULL)
        {
            aux = aux->siguiente; // Avanza al siguiente elemento en la lista
        }
        aux->siguiente = nuevoAlumno; // Enlaza el nuevo alumno al último elemento
    }
}

// Función para revertir la lista de alumnos
void revertirLista(struct Alumno **lista)
{
    struct Alumno *anterior = NULL;  // Puntero al elemento anterior
    struct Alumno *actual = *lista;  // Puntero al elemento actual
    struct Alumno *siguiente = NULL; // Puntero al elemento siguiente

    while (actual != NULL)
    {
        siguiente = actual->siguiente; // Guarda el puntero al siguiente elemento
        actual->siguiente = anterior;  // Enlaza el elemento actual al anterior
        anterior = actual;             // Avanza el puntero al anterior
        actual = siguiente;            // Avanza el puntero al actual
    }
    *lista = anterior; // El último elemento se convierte en el primero
}

// Función para imprimir la lista de alumnos
void imprimirLista(struct Alumno *lista)
{
    struct Alumno *aux = lista; // Inicializa el puntero auxiliar en el primer elemento de la lista

    while (aux != NULL)
    {
        // Imprimir los datos del alumno actual
        printf("\nNombre: %s\n", aux->nombre);
        printf("Apellido: %s\n", aux->apellido);
        printf("Edad: %d\n", aux->edad);
        printf("Calificación: %d\n", aux->calificacion);
        aux = aux->siguiente; // auxiliar avanza al siguiente elemento en la lista
    }
}

int main()
{
    struct Alumno *lista = NULL; // Inicializa la lista como vacía

    // Inserta varios alumnos al final de la lista
    insertarAlFinal(&lista, crearAlumno("Lalo", "garcia", 20, 10));
    insertarAlFinal(&lista, crearAlumno("Eli", "sanchez", 21, 9));
    insertarAlFinal(&lista, crearAlumno("Julissa", "galindo", 22, 8));
    insertarAlFinal(&lista, crearAlumno("Cesar", "cortez", 23, 7));
    insertarAlFinal(&lista, crearAlumno("Karlangas", "mariscal", 24, 6));

    // llama a la funcion imprimirLista
    printf("\nLista de Alumnos\n");
    imprimirLista(lista);

    // llama a la funcion revertirLista
    revertirLista(&lista);

    // llama a la funcion imprimirLista
    printf("\nLista de Alumnos invertida\n");
    imprimirLista(lista);

    return 0;
}