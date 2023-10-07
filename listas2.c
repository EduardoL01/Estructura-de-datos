// Eduardo Garcia Lopez

// Obtener la longitud de una lista: Escriba una función que determine y retorne la cantidad de elementos en una lista.

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

// Función para imprimir la lista de alumnos
void imprimirLista(struct Alumno *lista)
{
    struct Alumno *aux = lista; // Inicializa el puntero auxiliar en el primer elemento de la lista

    printf("\nLista de Alumnos\n");
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

// Función para obtener la longitud de una lista
int longitudLista(struct Alumno *lista)
{
    int longitud = 0;
    struct Alumno *aux = lista; // se inicializa el puntero auxiliar en el primer elemento de la lista
    while (aux != NULL)
    {
        longitud++;           // Incrementa la longitud siempre y cuando el puntero auxiliar no sea NULL
        aux = aux->siguiente; // auxiliar avanza al siguiente elemento en la lista
    }
    return longitud;
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
    imprimirLista(lista);

    // llama a la funcion longitudLista e imprime el resultado
    int longitud = longitudLista(lista);
    printf("Longitud de la lista: %d\n", longitud);

    return 0;
}