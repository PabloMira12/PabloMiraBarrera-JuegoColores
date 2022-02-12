#include "PilaLista.h"
#include<iostream>
using namespace std;

PilaLista::PilaLista(int T)
{
	Punta = nullptr;
	Tope = 0;
	Limite = T;
}

void PilaLista::Apilar(int n)
{
	Tope++;
	InsertarInicio(n);
}

int PilaLista::Desapilar()
{
	Nodo* p = Punta;
	int r = p->GetD();
	Punta = Punta->GetL();
	Tope--;
	delete (p);

	return r;
}

bool PilaLista::PilaLlena()
{
	if (Tope == Limite)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool PilaLista::PilaVacia()
{
	if (Tope == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void PilaLista::LlenarPila(PilaLista* a)
{
	while (a->PilaVacia() == false)
	{
		Apilar(a->Desapilar());
	}
}

void PilaLista::InsertarInicio(int d2)
{
	Nodo* x2 = new Nodo();
	x2->SetD(d2);
	if (Punta == nullptr)
	{
		Punta = x2;
	}
	else
	{
		x2->SetL(Punta);
		Punta = x2;
	}
}

void PilaLista::MostrarPila()
{
	int P = 0;
	PilaLista* aux = new PilaLista(Limite);

	while (PilaVacia() == false)
	{
		P = Desapilar();			//vacio la p1 para que salga cada dato a mostrar
		cout << "|" << P << "|";
		aux->Apilar(P);				//apilo en p2 para que no se peirdan los datod
	}
	LlenarPila(aux);					//lleno a p1 otra vez con los datos
}

void PilaLista::Menu()
{
	cout << "\tMenu del Juego" << endl;
	cout << "Opcion 1. Pila 1" << endl;
	cout << "Opcion 2. Pila 2" << endl;
	cout << "Opcion 3. Pila 3" << endl;

}

bool PilaLista::Validacion_Juego(PilaLista* P1, PilaLista* P2, PilaLista* P3)
{
	if (P1->PilaLlena() && P2->PilaLlena() && P3->PilaVacia())
	{
		Nodo* x = P1->Punta, * x1 = x->GetL();
		Nodo* y = P2->Punta, * y1 = y->GetL();
		if (x->GetD() == P1->Punta->GetD())
		{
			while (x->GetL() != nullptr)
			{
				if (x->GetD() != x1->GetD())
				{
					return false;
				}
				x = x1;
				x1 = x1->GetL();
			}
		}
		else
		{
			return false;
		}
		if (y->GetD() == P2->Punta->GetD())
		{
			while (y->GetL() != nullptr)
			{
				if (y->GetD() != y1->GetD())
				{
					return false;
				}
				y = y1;
				y1 = y1->GetL();
			}
		}
		else
		{
			return false;
		}
		return true;
	}

	if (P1->PilaLlena() && P2->PilaVacia() && P3->PilaLlena())
	{
		Nodo* x = P1->Punta, * x1 = x->GetL();
		Nodo* z = P3->Punta, * z1 = z->GetL();
		if (x->GetD() == P1->Punta->GetD())
		{
			while (x->GetL() != nullptr)
			{
				if (x->GetD() != x1->GetD())
				{
					return false;
				}
				x = x1;
				x1 = x1->GetL();
			}
		}
		else
		{
			return false;
		}
		if (z->GetD() == P3->Punta->GetD())
		{
			while (z->GetL() != nullptr)
			{
				if (z->GetD() != z1->GetD())
				{
					return false;
				}
				z = z1;
				z1 = z1->GetL();
			}
		}
		else
		{
			return false;
		}
		return true;
	}

	if (P1->PilaVacia() && P2->PilaLlena() && P3->PilaLlena())
	{
		Nodo* y = P2->Punta, * y1 = y->GetL();
		Nodo* z = P3->Punta, * z1 = z->GetL();
		if (y->GetD() == P2->Punta->GetD())
		{
			while (y->GetL() != nullptr)
			{
				if (y->GetD() != y1->GetD())
				{
					return false;
				}
				y = y1;
				y1 = y1->GetL();
			}
		}
		else
		{
			return false;
		}

		if (z->GetD() == P3->Punta->GetD())
		{
			while (z->GetL() != nullptr)
			{
				if (z->GetD() != z1->GetD())
				{
					return false;
				}
				z = z1;
				z1 = z1->GetL();
			}
		}
		else
		{
			return false;
		}
		return true;
	}
	return false;

}

void PilaLista::Colores(PilaLista* P2, PilaLista* P1)
{
	PilaLista* P3 = new PilaLista(Limite);
	int opc = 0, opc1, opc2;

	do
	{
		Menu();
		cout << "Salen y entran por la  izquierda Pila 1: \t"; MostrarPila(); cout << "\n";
		cout << "Salen y entran por la  izquierda Pila 2: \t"; P2->MostrarPila(); cout << "\n";
		cout << "Salen y entran por la  izquierda Pila 3: \t"; P3->MostrarPila();
		cout << "\nIngrese el número de la pila a desapilar : "; cin >> opc1;

		switch (opc1)
		{
		case 1:
			if (P1->PilaVacia() == true)
			{
				cout << "\nNo se puede hacer ya que la Pila esta vacia" << endl;
				system("pause");
			}
			else
			{
				cout << "\nIngrese el número donde voy a apilar :"; cin >> opc2;
				if (opc2 == 2)
				{
					if (P2->PilaLlena() == true)
					{
						cout << "\nNo se puede hacer ya que la Pila está llena" << endl;
						system("pause");
					}
					else
					{
						if (P2->PilaVacia() == true)
						{
							P2->Apilar(P1->Desapilar());
						}
						else
						{
							if (P1->Punta->GetD() == P2->Punta->GetD())
							{
								P2->Apilar(P1->Desapilar());
							}
							else
							{
								cout << "\nNo se puede ya que los # no son iguales";
								system("pause");
							}
						}
					}
				}
				else
				{
					if (opc2 == 3)
					{
						if (P3->PilaLlena() == true)
						{
							cout << "\nNo se puede hacer ya que la Pila está llena" << endl;
							system("pause");
						}
						else
						{
							if (P3->PilaVacia() == true)
							{
								P3->Apilar(P1->Desapilar());
							}
							else
							{
								if (P1->Punta->GetD() != P3->Punta->GetD())
								{
									cout << "\nNo se puede ya que los # no son iguales";
									system("pause");
								}
								else
								{
									P3->Apilar(P1->Desapilar());
								}
							}
						}
					}
				}
			}
			break;

		case 2:
			if (P2->PilaVacia() == true)
			{
				cout << "No se puede hacer ya que la Pila esta vacia" << endl;
				system("pause");
			}
			else
			{
				cout << "Ingrese el número donde voy a apilar : "; cin >> opc2;
				if (opc2 == 1)
				{
					if (P1->PilaLlena() == true)
					{
						cout << "\nNo se puede hacer ya que la Pila está llena" << endl;
						system("pause");
					}
					else
					{
						if (P1->PilaVacia() == true)
						{
							P1->Apilar(P2->Desapilar());
						}
						else
						{
							if (P2->Punta->GetD() != P1->Punta->GetD())
							{
								cout << "\nNo se puede ya que los # no son iguales";
								system("pause");
							}
							else
							{
								P1->Apilar(P2->Desapilar());
							}
						}
					}
				}
				else
				{
					if (opc2 == 3)
					{
						if (P3->PilaLlena() == true)
						{
							cout << "\nNo se puede hacer ya que la Pila está llena" << endl;
							system("pause");
						}
						else
						{
							if (P3->PilaVacia() == true)
							{
								P3->Apilar(P2->Desapilar());
							}
							else
							{
								if (P2->Punta->GetD() != P3->Punta->GetD())
								{
									cout << "\nNo se puede ya que los # no son iguales";
									system("pause");
								}
								else
								{
									P3->Apilar(P2->Desapilar());
								}
							}
						}
					}
				}

			}
			break;

		case 3:
			if (P3->PilaVacia() == true)
			{
				cout << "No se puede hacer ya que la Pila esta vacia" << endl;
				system("pause");
			}
			else
			{
				cout << "Ingrese el número donde voy a apilar : "; cin >> opc2;
				if (opc2 == 1)
				{
					if (P1->PilaLlena() == true)
					{
						cout << "\nNo se puede hacer ya que la Pila está llena" << endl;
						system("pause");
					}
					else
					{
						if (P1->PilaVacia() == true)
						{
							P1->Apilar(P3->Desapilar());
						}
						else
						{
							if (P3->Punta->GetD() != P1->Punta->GetD())
							{
								cout << "\nNo se puede ya que los # no son iguales";
								system("pause");
							}
							else
							{
								P1->Apilar(P3->Desapilar());
							}
						}
					}
				}
				else
				{
					if (opc2 == 2)
					{
						if (P2->PilaLlena() == true)
						{
							cout << "\nNo se puede hacer ya que la Pila está llena" << endl;
							system("pause");
						}
						else
						{
							if (P2->PilaVacia() == true)
							{
								P2->Apilar(P3->Desapilar());
							}
							else
							{
								if (P3->Punta->GetD() != P2->Punta->GetD())
								{
									cout << "\nNo se puede ya que los # no son iguales";
									system("pause");
								}
								else
								{
									P2->Apilar(P3->Desapilar());
								}
							}
						}
					}
				}

			}
			break;
		case 4:
			break;
		default:
			cout << "Opcion incorrecta vuelve a intentar";
			system("pause");
			break;
		}

		cout << "Salen y entran por la  izquierda Pila 1: \t"; MostrarPila(); cout << "\n";
		cout << "Salen y entran por la  izquierda Pila 2: \t"; P2->MostrarPila(); cout << "\n";
		cout << "Salen y entran por la  izquierda Pila 3: \t"; P3->MostrarPila();
		system("pause");
		system("cls");

		if (Validacion_Juego(P1, P2, P3) == true)
		{
			opc = 1;
		}

	} while (opc != 1);
	system("cls");
	cout << "\n\t Felicitaciones, Lo Lograste " << endl;
}

