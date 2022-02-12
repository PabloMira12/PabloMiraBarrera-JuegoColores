#include "Nodo.h"

Nodo::Nodo()
{
	Dato = 0;
	Liga = nullptr;
}

void Nodo::SetD(int d)
{
	Dato = d;
}

int Nodo::GetD()
{
	return Dato;
}

void Nodo::SetL(Nodo* l)
{
	Liga = l;
}

Nodo* Nodo::GetL()
{
	return Liga;
}
