#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define reservar_memoria (nodo*)malloc(sizeof(nodo))
#define tam 100

struct nodo{
    float dato;
    nodo *siguiente; };

void menu();

/*FUNCIONES DE LA PILA*/
void insertar_elementos (nodo *&, float);
float quitar_elementos (nodo *&);
bool pila_vacia (nodo *);
void imprimir (nodo *);

/*FUNCIONES PARA REALIZAR LA OPERACION EN POSTFIJO*/
void ingresarExpresion(char [tam]);
void mostrarExpresion(char [tam]);
bool esOperador (char);
bool esNumero (char);
bool esEspacio (char);
float realziar_operacion (float, float, char);
void operacion_postfijo (nodo *&, char [tam]);
float convertir_cad_num (char [tam]);
void resultado_postfijo (nodo *&, char [tam]);

int main() {
    menu();
    return 0;
}

void menu(){

    nodo *pila = NULL;
    char arreglo[tam];
    int opc;

    do{
        printf("\n  ********** MENU NOTACION POSTFIJA **********\n\n");
        printf("    1. Ingresar una expresion postfija.\n");
        printf("    2. Mostrar expresion ingresada.\n");
        printf("    3. Realizar la operacion postfija.\n");
        printf("    4. Imprimir los resultados de la operacion postfija.\n");
        printf("    0. Salir.\n\n");
        printf("    Ingrese una opcion: "); scanf("%d", &opc);

        switch(opc){
            case 0:
                exit(0);
                break;
            case 1:
                ingresarExpresion(arreglo);
                break;
            case 2:
                mostrarExpresion(arreglo);
                break;
            case 3:
                operacion_postfijo (pila, arreglo);
                printf("\n  La operacion se realizo correctamente.\n\n");
                break;
            case 4:
                resultado_postfijo (pila, arreglo);
                printf("\n\n");
                break;
            default:
                printf("\n  La opcion ingresada no es valida, intentelo de nuevo.\n");
                break;
        }

        system("pause");
        system("cls");
    }while(opc != 0);
}

/*FUNCIONES DE LA PILA*/
void insertar_elementos (nodo *&pila, float n) {
    nodo *nuevo_nodo = reservar_memoria;
    nuevo_nodo -> dato = n;
    nuevo_nodo -> siguiente = pila;
    pila = nuevo_nodo;
}

float quitar_elementos (nodo *&pila) {
    float n;
    nodo *aux=pila;
    n = aux->dato;
    pila=aux->siguiente;
    free(aux);
    return n;
}


bool pila_vacia (nodo *pila){
    return (pila==NULL)? true:false;
}

void imprimir (nodo *pila){
    while(pila_vacia(pila)!= true);{
        printf("%d",pila -> dato);
        pila = pila -> siguiente; }
}

/*FUNCIONES PARA REALIZAR OPERACION POSTFIJA*/
void ingresarExpresion(char arreglo[tam]){
    fflush(stdin);
    int longitud;
    printf("\n Ingrese una expresion en postfijo: ");
    fgets(arreglo, tam, stdin);
    longitud = strlen(arreglo);
    printf("\n La expresion se almaceno con exito \n");
    printf("\nExpresion ingresada: %s\n", arreglo);
}
void mostrarExpresion(char arreglo[tam]){
    int longitud;
    longitud = strlen(arreglo);
    printf("\nLongitud de la expresion: %d", longitud);
    printf("\nExpresion ingresada: %s\n", arreglo);
}

float realziar_operacion (float a, float b, char c) {
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
        case 94:
            resultado=pow(a,b);
            break;
    } return resultado;
}

bool esNumero(char valor){
    int numero = valor;
    return (numero > 47 && numero < 58) ? true: false;
}
bool esOperador(char valor){
    int numero = valor;
    return (numero == 43 || numero == 45 || numero == 42 || numero == 47 || numero == 94) ? true: false;
}
bool esEspacio(char valor){
    int numero = valor;
    return (numero == 32) ? true: false;
}

void operacion_postfijo (nodo *&pila, char arreglo[tam]){

    int i, j=0, longitud;
    float numero_insertar, a, b, c;
    char num[tam];

    longitud = strlen(arreglo);
    for(i=0; i<longitud; i++){
        if(esNumero(arreglo[i])){
            num[j] = arreglo[i];
            j++;
        }
        if(esEspacio(arreglo[i])){
            numero_insertar = convertir_cad_num (num);
            insertar_elementos(pila, numero_insertar);
            j=0;
        }
        if(esOperador(arreglo[i])){
            a = quitar_elementos(pila);
            b = quitar_elementos(pila);
            c = realziar_operacion (a,b,arreglo[i]);
            insertar_elementos (pila,c);
            i++; }
    }

}

void resultado_postfijo (nodo *&pila, char arreglo[tam]){
    printf("%s =  %0.0f",arreglo, pila -> dato);
}
float convertir_cad_num (char numero[tam]){
    float num;
    num = atoi(numero);
    return num;
}
