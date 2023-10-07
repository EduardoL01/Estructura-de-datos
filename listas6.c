// Eduardo Garcia Lopez

// Concatenar dos listas: Desarrolle una función que tome dos listas como parámetros y las concatene, es decir, que la segunda lista se convierta en la continuación de la primera.

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

// definir uns estructura para almacenar otros alumnos
struct OtroAlumno
{
    char nombre[20];
    char apellido[20];
    int edad;
    int calificacion;
    struct OtroAlumno *siguiente; // apunta al siguiente alumno en la lista
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

// Función para crear un nuevo alumno de la estructura OtroAlumno
struct OtroAlumno *crearOtroAlumno(const char nombre[], const char apellido[], int edad, int calificacion)
{
    // Asigna memoria para un nuevo alumno
    struct OtroAlumno *nuevoAlumno = (struct OtroAlumno *)malloc(sizeof(struct OtroAlumno));

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

// Función para insertar un alumno al final de la lista de la estructura OtroAlumno
void insertarAlFinalOtroAlumno(struct OtroAlumno **lista, struct OtroAlumno *nuevoAlumno)
{
    if (*lista == NULL)
    {
        // Si la lista está vacía, el nuevo alumno se convierte en el primer elemento
        *lista = nuevoAlumno;
    }
    else
    {
        struct OtroAlumno *aux = *lista;
        while (aux->siguiente != NULL)
        {
            aux = aux->siguiente; // Avanza al siguiente elemento en la lista
        }
        aux->siguiente = nuevoAlumno; // Enlaza el nuevo alumno al último elemento
    }
}

// funcion para que tome hambas listas como parametros y las concatene una continua de la otra
void concatenarListas(struct Alumno **lista1, struct OtroAlumno **lista2)
{
    if (*lista1 == NULL) //
    {
        *lista1 = *lista2; // si la lista 1 esta vacia, la lista 2 se convierte en la lista 1
    }
    else
    {
        struct Alumno *aux = *lista1;  // si no, se crea un auxiliar que apunte a la lista 1
        while (aux->siguiente != NULL) // se recorre la lista 1 hasta el final
        {
            aux = aux->siguiente;
        }
        aux->siguiente = *lista2; // se enlaza la lista 2 al final de la lista 1
    }
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
    struct OtroAlumno *lista2 = NULL;

    // Inserta varios alumnos al final de la lista
    insertarAlFinal(&lista, crearAlumno("Lalo", "garcia", 20, 10));
    insertarAlFinal(&lista, crearAlumno("Eli", "sanchez", 21, 9));
    insertarAlFinal(&lista, crearAlumno("Julissa", "galindo", 22, 8));
    insertarAlFinal(&lista, crearAlumno("Cesar", "cortez", 23, 7));
    insertarAlFinal(&lista, crearAlumno("Karlangas", "mariscal", 24, 6));

    // Inserta varios alumnos al final de la lista de la estructura OtroAlumno
    insertarAlFinalOtroAlumno(&lista2, crearOtroAlumno("yair", "valdes", 25, 10));
    insertarAlFinalOtroAlumno(&lista2, crearOtroAlumno("daniel", "murguia", 26, 9));
    insertarAlFinalOtroAlumno(&lista2, crearOtroAlumno("edith", "colorado", 27, 8));

    // llama a la funcion concatenarListas
    concatenarListas(&lista, &lista2);

    // llama a la funcion imprimirLista
    imprimirLista(lista);

    return 0;
}