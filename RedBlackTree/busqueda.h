#pragma once

#include"nodo.h"
using namespace std;
//clase arbol_binario

class arbol_binario_busqueda {
public:
	//constructor 
	arbol_binario* raiz;
	arbol_binario_busqueda(int data)
	{
		raiz = insertar_nodo(data);
		raiz->color = negro;
		cout << "Se ha creado un arbol binario de busqueda con raiz " << " " << raiz->data << endl;
	}

	//metodos 

	arbol_binario* insertar(int data);
	arbol_binario* busqueda(int data);
	void borrar(int data);
	arbol_binario* obtener_menor(arbol_binario* nodo);
	void inorder(arbol_binario* nodo);
};

arbol_binario* arbol_binario_busqueda::insertar(int data_1) {

	arbol_binario* nuevo = insertar_nodo(data_1);
	arbol_binario* x = raiz;
	arbol_binario* y = NULL;
	//Encontramos el lugar para insertar "nuevo"
	while (x != NULL) {
		y = x;//"y" sera el padre de "x", el cual recorrera el arbol hasta que sea NULL 
		if (data_1 < x->data)
			x = x->hijo_izquierdo;
		else
			x = x->hijo_derecho;
	}

	// Si el arbol esta vacio "y"representa la raiz y "nuevo " es ahora la raiz 
	if (y == NULL) {
		y = nuevo;
		return y;
	}

	//Si "y" no es la raiz, entonces:
	else if (data_1 < y->data) { // Si "nuevo" es menor que el padre "y" entonces se posiciona en la izquierda

		y->hijo_izquierdo = nuevo;
		y->hijo_izquierdo->padre = y;
		return y->hijo_izquierdo;
	}
	else {// si no, se posiciona en el derecho

		y->hijo_derecho = nuevo;
		y->hijo_derecho->padre = y;
		return y->hijo_derecho;
	}

}
arbol_binario* arbol_binario_busqueda::busqueda(int data)
{
	arbol_binario* tem = raiz;
	while (raiz != NULL && data != raiz->data)
	{
		if (data < raiz->data)
		{
			raiz = raiz->hijo_izquierdo;
		}
		else raiz = raiz->hijo_derecho;
	}
	arbol_binario* tem_1 = raiz;
	raiz = tem;

	return tem_1;
}





void arbol_binario_busqueda::inorder(arbol_binario* nodo)
{
	if (nodo != NULL)
	{
		inorder(nodo->hijo_izquierdo);
		cout << nodo->data << endl;
		if (nodo->color == rojo) {
			cout << "rojo" << endl;
		}
		else cout << "negro" << endl;
		inorder(nodo->hijo_derecho);
	}
}


arbol_binario* arbol_binario_busqueda::obtener_menor(arbol_binario* nodo) {
	arbol_binario* tem = nodo;
	while (tem != NULL && tem->hijo_izquierdo != NULL) {
		tem = tem->hijo_izquierdo;
	}
	return tem;
}


void arbol_binario_busqueda::borrar(int data) {

	arbol_binario* eliminado = busqueda(data);

	if (eliminado->hijo_derecho != NULL && eliminado->hijo_izquierdo != NULL)
	{
		arbol_binario* sucesor = eliminado->hijo_izquierdo;

		while (sucesor->hijo_derecho != NULL)
		{
			sucesor = sucesor->hijo_derecho;
		}
		eliminado->data = sucesor->data;
		if (sucesor->hijo_izquierdo != NULL)
		{
			sucesor->hijo_izquierdo->padre = sucesor->padre;
			sucesor->padre->hijo_derecho = sucesor->hijo_izquierdo;
			delete (sucesor);
		}
		else {


			if (sucesor->padre->hijo_derecho == sucesor)
				sucesor->padre->hijo_derecho = NULL;
			else
				sucesor->padre->hijo_izquierdo = NULL;

			delete(sucesor);
		}

	}
	else if (eliminado->hijo_izquierdo == NULL && eliminado->hijo_derecho != NULL) {
		arbol_binario* sucesor = eliminado->hijo_derecho;
		eliminado->padre->hijo_derecho = sucesor;
		sucesor->padre = eliminado->padre;
		delete(eliminado);

	}
	else if (eliminado->hijo_derecho == NULL && eliminado->hijo_izquierdo != NULL) {
		arbol_binario* sucesor = eliminado->hijo_izquierdo;
		eliminado->padre->hijo_izquierdo = sucesor;
		sucesor->padre = eliminado->padre;
		delete(eliminado);
	}
	else {
		if (eliminado->padre->hijo_derecho == eliminado)
			eliminado->padre->hijo_derecho = NULL;
		else
			eliminado->padre->hijo_izquierdo = NULL;

		delete (eliminado);
	}

}
