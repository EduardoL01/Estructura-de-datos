#include<stdio.h>
#include "string.h"

/* 
int buscar(int *a, int n, int x) {
    for(int i=0; i<n; i++)
        if(a[i]==x)
            return i;
    return -1;
}

int buscar2(int *a, int n, int x) {
    int i;
    for(i=0; i<n && a[i]<x; i++);
    if(a[i]==x)
        return i;
    return -1;
}

void insertAt(int *a, int *n, int pos, int x) {
    for(int i=*n; i<pos; i--) {
        a[i]=a[i-1];
    }
    a[pos]=x;
    (*n)++;
}

void deleteAt(int *a,int *n, int pos) {
    for(int i=pos; i< *(n)-1; i++)
        a[i]=a[i+1];
    (*n)--;
}

int main()
{
    int a[20]= {1,24,61,5,3,7,17,57,3};
    int n =9; //(int) sizeof(a)/sizeof(a[0]);
    //int x=-1;

    insertAt(a,&n,3,45);

    insertAt(a,&n,0,42);
    insertAt(a,&n,0,41);


    for(int i=0; i<n; i++) {
        printf("%d ",a[i]);
    }

    puts("");
    deleteAt(a, &n,2);

    for(int i=0; i<n; i++)
        printf("%d ",a[i]);

    //int pos = buscar(a,n,x);
    //printf("la posición en dónde se encuentra %d es: %d\n",x, buscar(a,n,x));
    //printf("la posición en dónde se encuentra %d es: %d\n",x, buscar(a,n,x));

    return 0;
} */


//1.- lista de usurios maximo 10 personas
//2.-usuario: nombre, edad, carrera
//3.-buscar un usuario por nombre y editar su edad

struct usuario {
    char nombre[20];
    char edad[20];
    char carrera[20];
};

//lista de usuarios maximo 10 personas

struct usuario lista[10];
int n=0;

void insertar() {
    if(n<10) {
        printf("Nombre: ");
        scanf("%s",lista[n].nombre);
        printf("Edad: ");
        scanf("%s",lista[n].edad);
        printf("Carrera: ");
        scanf("%s",lista[n].carrera);
        n++;
    } else {
        printf("Lista llena\n");
    }
}

//buscar por nombre y editar edad

void editar() {
    char nombre[20];
    printf("Nombre: ");
    scanf("%s",nombre);
    for(int i=0; i<n; i++) {
        if(strcmp(nombre,lista[i].nombre)==0) {
            printf("Edad: ");
            scanf("%s",lista[i].edad);
            return;
        }
    }
    printf("No se encontró el usuario\n");
}

//buscar por nombre y listar sus datos

void listar() {
    char nombre[20];
    printf("Nombre: ");
    scanf("%s",nombre);
    for(int i=0; i<n; i++) {
        if(strcmp(nombre,lista[i].nombre)==0) {
            printf("Nombre: %s\n",lista[i].nombre);
            printf("Edad: %s\n",lista[i].edad);
            printf("Carrera: %s\n",lista[i].carrera);
            return;
        }
    }
    printf("No se encontró el usuario\n");
}

//main

int main() {
    int opcion;
    do {
        printf("1.- Insertar\n");
        printf("2.- Editar\n");
        printf("3.- Listar\n");
        printf("4.- Salir\n");
        printf("Opción: ");
        scanf("%d",&opcion);
        switch(opcion) {
            case 1:
                insertar();
                break;
            case 2:
                editar();
                break;
            case 3:
                listar();
                break;
            case 4:
                printf("Adios\n");
                break;
            default:
                printf("Opción no válida\n");
        }
    } while(opcion!=4);
    return 0;
}

