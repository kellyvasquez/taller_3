#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define reservar_memoria (nodo*)malloc(sizeof(nodo))

struct nodo{
    int dato;
    nodo *siguiente; };

void insertar (nodo *&pila, int n);
int quitar (nodo *&pila, int &n);
bool pila_vacia (nodo *pila);
void operacion (nodo *pila, char arreglo[]);
void buscar_nodo (nodo *pila);
void imprimir (nodo *pila);
void eliminar_nodo (nodo *&pila);


int main() {

    int resultado;
    char cadena[20];

    printf("Ingrese la operacion en postfijo separada por espacios: ");
    fgets(cadena, 20, stdin);

    imprimir (nodo *pila);
    printf("\nEl resultado de la operacion es: %d", resultado);

    system("pause");
    return 0;
}

void insertar (nodo *&pila, int n) {
    nodo *nuevo_nodo = reservar_memoria;
    nuevo_nodo -> dato = n;
    nuevo_nodo -> siguiente = pila;
    pila = nuevo_nodo;
}

int quitar (nodo *&pila, int &n) {
    nodo *aux=pila;
    n = aux->dato;
    pila=aux->siguiente;
    free(aux);
}


bool pila_vacia (nodo *pila){
    return (pila==NULL)? true:false;
    printf("Pila vacia");
}


void operacion (nodo **pila, char arreglo[])
{
    int a, b, i=0, numero_pila;
    char numero, espacio, operador;

        if(arreglo[i]==numero(arreglo[i])){
            numero=strcat(numero, arreglo[i]);
        } i+=1;

        if(arreglo[i])== espacio (arreglo[i]){
           numero_pila= float (numero);
           insertar (pila, numero_pila);
           numero = 0; i+=1; }

        if(arreglo[i])== operador (arreglo[i]){
            a = eliminar_nodo (pila);
            b = eliminar_nodo (pila);
            insertar (pila, a+b) i+=2;
        }
}

void imprimir (nodo *pila){
    nodo *primero = reservar_memoria;
    primero=pila;
    if (pila != NULL){
        while(primero!=NULL){
            printf("%d", primero -> dato);
            primero = primero -> siguiente; }
    }else{
        printf ("\n Pila vacia"); }
}

void buscar_nodo (nodo *pila){

    int dato_buscado;
    bool encontrado;

    nodo *primero = reservar_memoria;
    primero = pila;
    if (pila != NULL){
        while (primero != NULL){
            if (primero -> dato == dato_buscado){
                encontrado=true; }
        primero = primero -> siguiente;
        }
    }else{
        printf("\n Pila vacia"); }
    if (encontrado){
        printf("\n Esta en el nodo en la posicion ... "); }
}

void eliminar_nodo (nodo *&pila){

    int dato_buscado;
    nodo *primero = reservar_memoria;
    primero = pila;
    if (pila != NULL){
        while (pila != NULL){
            if (pila -> dato == dato_buscado){
                if (pila == primero){
                    pila=primero->siguiente;
                    free(primero); }
                else{
                    primero->siguiente=pila->siguiente;
                    free (pila); }
            }
            primero = pila;
            pila=pila->siguiente;
        }
    }else{ printf("\n Pila Vacia"); }
}
