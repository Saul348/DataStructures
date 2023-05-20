#include<iostream>
#include<stdlib.h>
using namespace std;
class pila{
	public:
	int data;
	pila* siguiente;
};

pila* nuevo_nodo(int data){
	pila* nodo= new pila();
	nodo->data=data;
	nodo->siguiente=NULL;
	return nodo; 
}
int empty(pila *cabeza){
	return !cabeza;
}
void push(pila **cabeza, int data){
	pila* nodo=nuevo_nodo(data);
	nodo->siguiente=*cabeza;
	*cabeza= nodo;
	cout<<data<<"Se ha apildado "<<endl;
}
int pop(pila** cabeza){
	if(empty(*cabeza)){
		return INT_MIN;
	}
	pila *temporal= *cabeza;
	*cabeza=(*cabeza)->siguiente;
	int poped=temporal->data;
	free(temporal);
	return poped;
	
}
int peek(pila* cabeza){
	if(empty(cabeza)){
		return INT_MIN;
	}
	return cabeza->data;
}
int size(pila **cabeza,int contador){
	
	if(empty(*cabeza))
	return contador;
	*cabeza=(*cabeza)->siguiente;
	contador++;
	size(cabeza, contador);
	
}
int main(){
	int contador=0;
	pila* cabeza=NULL;
	push(&cabeza, 10);
	push(&cabeza, 20);
	cout<<pop(&cabeza)<<"se saco de la pila"<<endl;
	cout<<"el elemento de arriba es :"<<peek(cabeza)<<endl;
	cout<<"el tamaño es :"<<size(&cabeza, contador)<<endl;
	
}
