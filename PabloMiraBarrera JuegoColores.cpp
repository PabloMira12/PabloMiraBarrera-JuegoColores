// PabloMiraBarrera JuegoColores.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include<stdlib.h>
#include"PilaLista.h"

using namespace std;
int main()
{
    int T1 = 0, T2 = 0, num = 0;

    cout << "\tBienvenido ! Comenzemos el juego " << endl;
    system("pause");
    system("cls");
    cout << "\nExplicacion : " << endl;
    cout << "\nDebes dejar todos los 1s en una Pila y todos los  2 sen la otra Pila. " << endl;
    cout << "Ejemplo : \n\t |1|1|1|1|1| \n\t |2|2|2|2|2| \n\t | | | | | | " << endl;

    PilaLista* P1 = new PilaLista(5);
    PilaLista* P2 = new PilaLista(5);
    PilaLista* aux;

    cout << "\nLas Pilas van a tener un Limite de 5 " << endl;
    system("pause");
    system("cls");
    P1->Apilar(1);
    P1->Apilar(2);
    P1->Apilar(1);
    P1->Apilar(2);
    P1->Apilar(1);
    P2->Apilar(2);
    P2->Apilar(1);
    P2->Apilar(2);
    P2->Apilar(1);
    P2->Apilar(2);

    cout << "\tAhora comienca el Juego !! " << endl;
    aux = P1;
    P1->Colores(P2, aux);
}
