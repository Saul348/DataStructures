#pragma once
enum COLOR : int
{
	rojo, negro
};

class arbol_binario {
public:
	arbol_binario* hijo_derecho;
	arbol_binario* hijo_izquierdo;
	arbol_binario* padre;
	int data;
	COLOR color;
};
arbol_binario* insertar_nodo(int data_1) {

	arbol_binario* nuevo_nodo = new arbol_binario();
	nuevo_nodo->data = data_1;
	nuevo_nodo->hijo_derecho = NULL;
	nuevo_nodo->hijo_izquierdo = NULL;
	nuevo_nodo->padre = NULL;
	nuevo_nodo->color = COLOR::rojo;
	return (nuevo_nodo);
}
arbol_binario* abuelo(arbol_binario* nodo) {
	if ((nodo != NULL) && (nodo->padre != NULL))
		return nodo->padre->padre;
	else
		return NULL;
}


arbol_binario* tio(arbol_binario* nodo) {
	arbol_binario* nodo_1 = abuelo(nodo);
	if (nodo_1 != NULL && nodo->padre == nodo_1->hijo_izquierdo)
		return nodo_1->hijo_derecho;
	else if (nodo_1 != NULL && nodo->padre == nodo_1->hijo_derecho)
		return nodo_1->hijo_izquierdo;
	else {
		std::cout << "No existe abuelo" << std::endl;
		return NULL;
	}

}

arbol_binario* hermano(arbol_binario* nodo)
{
	if (nodo == nodo->padre->hijo_izquierdo)
		return nodo->padre->hijo_derecho;
	else
		return nodo->padre->hijo_izquierdo;
}


void cambiarColores(arbol_binario* x_1, arbol_binario* x_2) {
	COLOR temp;
	temp = x_1->color;
	x_1->color = x_2->color;
	x_2->color = temp;
}

arbol_binario* sucesor(arbol_binario* x) {
	

	arbol_binario* sucesor_1 = x->hijo_izquierdo;

	while (sucesor_1->hijo_derecho != NULL)
	{
		sucesor_1 = sucesor_1->hijo_derecho;
	}
	return sucesor_1;
}
arbol_binario* reemplazar(arbol_binario* x) {

	if (x->hijo_izquierdo != NULL && x->hijo_derecho != NULL)
		return sucesor(x);


	if (x->hijo_izquierdo == NULL && x->hijo_derecho == NULL)
		return NULL;
	
	if (x->hijo_izquierdo != NULL)
		return x->hijo_izquierdo;
	else
		return x->hijo_derecho;
}

arbol_binario* Buscar_RN(arbol_binario* raiz_1, int data) {
	arbol_binario* tem = raiz_1;
	if (tem == NULL || tem->data == data) {
		return tem;
	}
	if (data < tem->data) {
		return Buscar_RN(tem->hijo_izquierdo, data);
	}
	else
		return Buscar_RN(tem->hijo_derecho, data);

}