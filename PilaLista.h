#pragma once
#include"Nodo.h"

class PilaLista
{
	//atributos
public:

	Nodo* Punta;
	int Limite, Tope;

	//metodos
public:
	PilaLista(int);

	void Apilar(int);
	int Desapilar();
	bool PilaLlena();
	bool PilaVacia();
	void LlenarPila(PilaLista*);
	void InsertarInicio(int);
	void MostrarPila();
	void Colores(PilaLista*, PilaLista*);
	void Menu();
	bool Validacion_Juego(PilaLista*, PilaLista*, PilaLista*);
};

