//La cola de prioridad se impleto con una lista simplemente ligada, y un monticulo, por lo tanto
//hay dos clases, heap y cola. 
#include<iostream>
#include<climits> 
#include<stdlib.h>
using namespace std;
void swap(int *x, int *y); 

class cola{
	public:
		cola* next;
		int data;
		int prioridad;
};
cola* nuevo_nodo(int data, int prioridad){
	

	cola* nodo= new cola();
	nodo->data=data;
	nodo->prioridad=prioridad;
	nodo->next=NULL;
	return nodo; 
}	

int empty(cola *cabeza){
	return !cabeza;
}

class Heap 
{ 
    int *harr; 
    int capacity; 
    
    int heap_size; 
public: 
   
    Heap(int capacity); 
 
    void MaxHeapify(int i, int n ); 
    int parent(int i) { return (i-1)/2; } 
    int left(int i) { return (2*i + 1); } 
    int right(int i) { return (2*i + 2); } 
    int extractMax(cola** cabeza); 
    void increaseKey(int i, int new_val); 
    int getMax() { return harr[0]; } 
    void deleteKey(int i, cola** cabeza); 
    void insertKey(cola** k, int o, int i); 
 
    
 
    void Elemento_mayor(cola*, int );
}; 
void Encontrar_data(cola** cabeza, int prioridad){
	  cola * temp = *cabeza, *prev; 
  
  
    if (temp != NULL && temp->prioridad == prioridad) 
    { 
        *cabeza = temp->next;  
		cout<<"Se extrajo el elemento "<<temp->data<<endl; 
        free(temp);               
        return; 
    } 
  
   
    while (temp != NULL && temp->prioridad != prioridad) 
    { 
        prev = temp; 
        temp = temp->next; 
    } 
  
   
    if (temp == NULL) {
    	cout<<"La lista esta vacia"<<endl;
    	return;
	}
   
    prev->next = temp->next; 
   free(temp); 
}
void push(cola **cabeza, int data, int prioridad){


	cola* nodo=nuevo_nodo(data, prioridad);
	nodo->next=*cabeza;
	*cabeza= nodo;	
}
Heap::Heap(int cap) 
{ 	
	
    heap_size = 0; 
    capacity = cap; 
  
    harr = new int[cap]; 
} 
void Heap::insertKey(cola** k, int prioridad, int data) 
{ 
    if (heap_size == capacity) 
    { 
        cout << "\nLa cola esta llena\n"; 
        return ; 
    } 
  push(k,prioridad, data);
 
    heap_size++; 
    int i = heap_size - 1; 
    
    harr[i] = (*k)->prioridad; 
    
   
     
    while (i != 0 && harr[parent(i)] < harr[i]) 
    { 
       swap(&harr[i], &harr[parent(i)]); 
       i = parent(i); 
    } 
	cout<<"Se ha agregado  "<<(*k)->data<<endl;
	cout<<"con prioridad "<<(*k)->prioridad<<endl;
} 
void Heap::increaseKey(int i, int new_val) 
{ 
    harr[i] = new_val; 
    while (i != 0 && harr[parent(i)] > harr[i]) 
    { 
       swap(&harr[i], &harr[parent(i)]); 
       i = parent(i); 
    } 
} 
int Heap::extractMax(cola ** cabeza) 
{ 
    if (heap_size <= 0) 
        return INT_MIN; 
    if (heap_size == 1) 
    { 
        heap_size--; 
        Encontrar_data(cabeza,harr[0] );
        return harr[0]; 
    } 
  
  
    int root = harr[0]; 
    //cout<<harr[0]<<endl;
    harr[0] = harr[heap_size-1]; 
    heap_size--; 
    MaxHeapify(0, heap_size); 
  	
  	Encontrar_data(cabeza,root );
  
    return root; 
} 
void Heap::deleteKey(int i, cola** cabeza) 
{ 

   increaseKey(i, INT_MAX); 
    extractMax(cabeza); 
} 
void Heap::MaxHeapify(int i, int n) 
{ 	
	int largest= i; 
    int l = left(i); 
    int r = right(i); 
    
    if (l < n && harr[l] > harr[largest]) 
        largest = l; 
    if (r < n && harr[r] > harr[largest]) 
       largest = r; 
    if (largest != i) 
    { 
        swap(&harr[i], &harr[largest]); 
        MaxHeapify(largest, n); 
    } 
} 

void swap(int *x, int *y) 
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
} 
void Heap::Elemento_mayor(cola* cabeza, int prioridad){
while(cabeza!=NULL && cabeza->prioridad!=prioridad){
	cabeza=cabeza->next;
}
	cout<<"El elemento con mayor prioridad es : "<<cabeza->data<<endl;
}

  int main(){
  	

  	int capacidad=10, i, elemento, max_prioridad ;

  	Heap hola(capacidad);

  	cola* cabeza=NULL;
  	
	hola.insertKey(&cabeza,9,45 );
	max_prioridad=hola.getMax();
	cout<<"La mayor prioridad es"<<hola.getMax()<<endl;
	hola.Elemento_mayor(cabeza,max_prioridad);
	hola.extractMax(&cabeza);

  	return 0;
  }
