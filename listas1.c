// Eduardo Garcia Lopez

// Insertar un elemento al final: Desarrolle una función que permita agregar un nuevo elemento al final de una lista.

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
        // Imprimi los datos del alumno actual
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

    // inserta alumnos por teclado
    char nombre[20];
    char apellido[20];
    int edad, calificacion;
    int i, n;
    printf("Numero de alumnos: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nNombre: ");
        scanf("%s", nombre);
        printf("Apellido: ");
        scanf("%s", apellido);
        printf("Edad: ");
        scanf("%d", &edad);
        printf("Calificacion: ");
        scanf("%d", &calificacion);

        // Crea un nuevo alumno
        struct Alumno *nuevoAlumno = crearAlumno(nombre, apellido, edad, calificacion);

        // Inserta el nuevo alumno al final de la lista
        insertarAlFinal(&lista, nuevoAlumno);
    }

    // llama a la funcion imprimirLista
    imprimirLista(lista);

    return 0;
}