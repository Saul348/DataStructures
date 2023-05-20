#include<iostream>
using namespace std;
class cola{
	public:
		cola* next;
		float data; 
};
cola* nuevo_nodo(float data){
	cola* nodo= new cola();
	nodo->data=data;
	nodo->next=NULL;
	return nodo; 
}
bool empty(cola *principio){
	return !principio;
}
void push(cola** primero, cola** ultimo, float data ){
	cola* nodo= nuevo_nodo(data); 
	if((*ultimo)==NULL){
		*ultimo=*primero=nodo;
		cout<<(*ultimo)->data<<"Se ha agregado"<<endl;
		return;
	}
	(*ultimo)->next=nodo;
	*ultimo=nodo;
	cout<<(*ultimo)->data<<"Se ha agregado"<<endl;
	
}

void pop(cola ** principio, cola** ultimo){
	if(*principio==NULL){
		return;
	}
	cola* nodo=*principio;
	*principio=(*principio)->next;
	
	if(*principio==NULL){
		*ultimo=NULL;
	}
	cout<<nodo->data<<"Se ha eliminado"<<endl;
	delete(nodo);
}


