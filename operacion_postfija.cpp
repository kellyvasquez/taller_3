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
void buscar_nodo (nodo *pila);
void imprimir (nodo *pila);
void eliminar_nodo (nodo *&pila);
void esOperador ();
bool esNumero ();
bool esEspacio ();
float operacion ();

int main() {

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


float operacion (float a, float b, float c)
{
    float resultado;
    int op=c;

    switch (op){
        case 43:
            resultado=a+b;
            break;
        case 45:
            resultado=a-b;
            break;
        case 42:
            resultado=a*b;
            break;
        case 47:
            resultado=a/b;
            break;
        }
}

void esOperador(nodo *&pila, float &a, float &b, int &z){
    a=eliminar_nodo(pila);
    b=eliminar_nodo(pila);
    z=operacion(a,b);
    insertar(pila, z);
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
        printf("\n Nodo encontrado"); }
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
