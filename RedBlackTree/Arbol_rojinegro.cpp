#include<iostream>
#include "busqueda.h"
class arbol_rojo_negro {
public:
	//constructor 
	
	arbol_binario* raiz;
	arbol_rojo_negro(int data)
	{
		
		raiz = insertar_nodo(data);
		raiz->color = negro;
		cout << "Se ha creado un arbol binario rojo negro con raiz " << " " << raiz->data << endl;
	}

	//metodos 

	void insertar_RN(int data);
	void borrar_RN(arbol_binario* nodo, int data);
	//metodos auxiliares para la insercion
	arbol_binario* insertar_AB(int data);
		void insertar_1(arbol_binario* nodo);
		void insertar_2(arbol_binario* nodo);
		void insertar_3(arbol_binario* nodo);
		void insertar_4(arbol_binario* nodo);
	void Rotacion_izquierda(arbol_binario* nodo);
	void Rotacion_derecha(arbol_binario* nodo);
	void fixDoubleBlack(arbol_binario* nodo);
	void inorder_RN(arbol_binario* nodo);

};
void arbol_rojo_negro::inorder_RN(arbol_binario* nodo) 
{
	if (nodo != NULL)
	{
		inorder_RN(nodo->hijo_izquierdo);
		cout << nodo->data << endl;
		if (nodo->color == rojo) {
			cout << "rojo" << endl;
		}
		else cout << "negro" << endl;
		inorder_RN(nodo->hijo_derecho);
	}
}
void arbol_rojo_negro::Rotacion_izquierda(arbol_binario* nodo) {

	arbol_binario* y = nodo->hijo_derecho;
	nodo->hijo_derecho = y->hijo_izquierdo;
	if (y->hijo_izquierdo != NULL) {
		y->hijo_izquierdo->padre = nodo;

	}
	y->padre = nodo->padre;
	if (nodo->padre == NULL) {
		raiz = y;
	}
	else if (nodo == nodo->padre->hijo_izquierdo) {
		nodo->padre->hijo_izquierdo = y;
	}
	else {
		nodo->padre->hijo_derecho = y;
	}
	y->hijo_izquierdo = nodo;
	nodo->padre = y;
}
void arbol_rojo_negro::Rotacion_derecha(arbol_binario* nodo) {

	arbol_binario* y = nodo->hijo_izquierdo;
	nodo->hijo_izquierdo = y->hijo_derecho;
	if (y->hijo_derecho != NULL) {
		y->hijo_derecho->padre = nodo;

	}
	y->padre = nodo->padre;
	if (nodo->padre == NULL) {
		raiz = y;
	}
	else if (nodo== nodo->padre->hijo_izquierdo) {
		nodo->padre->hijo_izquierdo = y;
	}
	else {
		nodo->padre->hijo_derecho = y;
	}
	y->hijo_derecho = nodo;
	nodo->padre = y;

}

arbol_binario* arbol_rojo_negro:: insertar_AB(int data_1) {

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
void arbol_rojo_negro::insertar_RN(int data) {
	
	arbol_binario * nodo= insertar_AB(data);
	insertar_1(nodo);
}

void arbol_rojo_negro::insertar_1(arbol_binario* p) {
	if (p->padre == NULL) {
		p->color = negro;
		return;
	}
	else
		insertar_2(p);
}

void arbol_rojo_negro::insertar_2(arbol_binario* p) {
	if (p->padre->color == negro) 
		return;
	else
		insertar_3(p);
}

void arbol_rojo_negro::insertar_3(arbol_binario* p) {

	arbol_binario* tio_1 = tio(p);
	if ((tio_1 != NULL && tio_1->color == rojo) && p->padre->color == rojo) {
		
		arbol_binario* abuelo_1 = abuelo(p);
		p->padre->color = negro;
		tio_1->color = negro;
		abuelo_1->color = rojo;

		insertar_1(abuelo_1);
	}
	else insertar_4(p);

}
void arbol_rojo_negro::insertar_4(arbol_binario* p) {

	arbol_binario* tio_1 = tio(p);

	arbol_binario* abuelo_1 = abuelo(p);
	
	if (p->padre->color == rojo) {
		if (tio_1 == NULL) {
			
			if (abuelo_1->hijo_izquierdo == p->padre) {  
				
				if (p->padre->hijo_izquierdo == p) 
					cambiarColores(p->padre, abuelo_1);
				else {
					Rotacion_izquierda(p->padre);
					cambiarColores(p, abuelo_1);
					}
				Rotacion_derecha(abuelo_1);
				
				
			}
			else {
				if (p->padre->hijo_izquierdo == p) {
					cout << abuelo_1->data << endl;
					Rotacion_derecha(p->padre);
					cambiarColores(p, abuelo_1);
				}
				else {
					cambiarColores(p->padre, abuelo_1);
				}
				Rotacion_izquierda(abuelo_1);
			}
			
			
		}
		else if (tio_1->color == negro) {
			
			if (abuelo_1->hijo_izquierdo == p->padre) {
				if (p->padre->hijo_izquierdo == p)
					cambiarColores(p->padre, abuelo_1);
				else {
					Rotacion_izquierda(p->padre);
					cambiarColores(p, abuelo_1);
				}
				Rotacion_izquierda(abuelo_1);

			}
			else {
				if (p->padre->hijo_izquierdo == p) {

					Rotacion_derecha(p->padre);
					cambiarColores(p, abuelo_1);
				}
				else
					cambiarColores(p->padre, abuelo_1);
			}

			Rotacion_izquierda(abuelo_1);
		}
	}
}


void arbol_rojo_negro::borrar_RN(arbol_binario* v, int data) {

	v = Buscar_RN(v, data);
	//cout << v->data << endl;
	arbol_binario* u = reemplazar(v);
	
	
	
	bool uvBlack = ((u == NULL || u->color == negro) && (v->color == negro));
	arbol_binario* padre_1 = v->padre;

	if (u == NULL) {
	
		if (v == raiz) {
			raiz = NULL;
		}
		else {
			if (uvBlack) {
				fixDoubleBlack(v);
				
			}
			else {
				arbol_binario* hermano_1 = hermano(v);
				if (hermano_1 != NULL)
					hermano_1->color = rojo;
			}
			if (v->padre->hijo_izquierdo == v) 
				v->padre->hijo_izquierdo = NULL;
			else 
				v->padre->hijo_derecho = NULL;
		}
		delete v;
		return;
	}

	if (v->hijo_izquierdo == NULL || v->hijo_derecho == NULL) {
	
		if (v == raiz) {
			v->data = u->data;
			v->hijo_izquierdo = v->hijo_derecho = NULL;
			delete u;
		}
		else {

			if (v->padre->hijo_izquierdo == v) {
				v->padre->hijo_izquierdo = u;
			}
			else {
				v->padre->hijo_derecho = u;
			}

			delete v;

			u->padre = padre_1;
			if (uvBlack) {
				fixDoubleBlack(u);
			}
			else {
				u->color = negro;
			}
		}
		return;
	}


	int temp_1;
	temp_1 = u->data;
	u->data = v->data;
	v->data = temp_1;

	borrar_RN(u, u->data);
}



void arbol_rojo_negro::fixDoubleBlack(arbol_binario* x) {
	if (x == raiz)
		return;

	arbol_binario* hermano_1 = hermano(x), * padre_1 = x->padre;
	if (hermano_1 == NULL) {
		fixDoubleBlack(padre_1);
	}
	else {
		if (hermano_1->color == rojo) {

			padre_1->color = rojo;
			hermano_1->color = negro;
			if (hermano_1->padre->hijo_izquierdo == hermano_1) {

				Rotacion_derecha(padre_1);
			}
			else {

				Rotacion_izquierda(padre_1);
			}
			fixDoubleBlack(x);
		}
		else if (hermano_1->hijo_derecho != NULL || hermano_1->hijo_izquierdo != NULL) {

			if (hermano_1->hijo_derecho->color == rojo || hermano_1->hijo_izquierdo->color == rojo) {

				if (hermano_1->hijo_izquierdo != NULL && hermano_1->hijo_izquierdo->color == rojo) {
					if (hermano_1->padre->hijo_izquierdo == hermano_1) {

						hermano_1->hijo_izquierdo->color = hermano_1->color;
						hermano_1->color = padre_1->color;
						Rotacion_derecha(padre_1);
					}
					else {

						hermano_1->hijo_izquierdo->color = padre_1->color;
						Rotacion_derecha(hermano_1);
						Rotacion_izquierda(padre_1);
					}
				}
				else {
					if (hermano_1->padre->hijo_izquierdo == hermano_1) {

						hermano_1->hijo_derecho->color = padre_1->color;
						Rotacion_izquierda(hermano_1);
						Rotacion_derecha(padre_1);
					}
					else {

						hermano_1->hijo_derecho->color = hermano_1->color;
						hermano_1->color = padre_1->color;
						Rotacion_izquierda(padre_1);
					}
				}
				padre_1->color = negro;
			}
		}
			else {

				hermano_1->color = rojo;
				if (padre_1->color == negro)
					fixDoubleBlack(padre_1);
				else
					padre_1->color = negro;
			}
		}
	}




int main() {
	
	arbol_rojo_negro  raiz_cabeza_1 = { 2};


	raiz_cabeza_1.insertar_RN(3);
	raiz_cabeza_1.insertar_RN(69);
	raiz_cabeza_1.insertar_RN(12);
	raiz_cabeza_1.insertar_RN(57);
	raiz_cabeza_1.insertar_RN(43);
	raiz_cabeza_1.insertar_RN(100);
	

	/*raiz_cabeza_1.borrar_RN(raiz_cabeza_1.raiz, 20);
	raiz_cabeza_1.borrar_RN(raiz_cabeza_1.raiz, 10);
	raiz_cabeza_1.borrar_RN(raiz_cabeza_1.raiz, 5);*/


	raiz_cabeza_1.inorder_RN(raiz_cabeza_1.raiz);


}