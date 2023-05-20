//This algorithm was implemented with Maxheap, tt's practically the same code just add the sort function
#include<iostream>
#include<climits> 
using namespace std;
void swap(int *x, int *y); 
  

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
  
    
    int extractMax(); 
  
    
    void increaseKey(int i, int new_val); 
  
    
    int getMax() { return harr[0]; } 
  
    
    void deleteKey(int i); 
 
  	void insertKey(int k); 
 	void sort();
   
    void print();
}; 
  

Heap::Heap(int cap) 
{ 
    heap_size = 0; 
    capacity = cap; 
    harr = new int[cap]; 
} 
  

void Heap::insertKey(int k) 
{ 
    if (heap_size == capacity) 
    { 
        cout << "\nLa cola esta llena\n"; 
        return; 
    } 
  
   
    heap_size++; 
    
    int i = heap_size - 1; 
    harr[i] = k; 
 
     
    while (i != 0 && harr[parent(i)] < harr[i]) 
    { 
       swap(&harr[i], &harr[parent(i)]); 
       i = parent(i); 
    } 
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
  
 
int Heap::extractMax() 
{ 
    if (heap_size <= 0) 
        return INT_MIN; 
    if (heap_size == 1) 
    { 
        heap_size--; 
        return harr[0]; 
    } 
  
  
    int root = harr[0]; 
    harr[0] = harr[heap_size-1]; 
    heap_size--; 
    MaxHeapify(0, heap_size); 
  
    return root; 
} 
  
  

void Heap::deleteKey(int i) 
{ 

   increaseKey(i, INT_MAX); 
    extractMax(); 
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

void Heap::sort(){
	int i,n=heap_size;
	for ( i=n-1; i>0; i--) 
    { 
        
        swap(&harr[0], &harr[i]); 
  

        MaxHeapify(0, i); 
    } 
}


void swap(int *x, int *y) 
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
} 
void Heap::print(){
	int i;
	cout<<"El arreglo ordenado es :"<<endl;
for(i=0;i<capacity-1;i++)
	cout<<harr[i]<<endl;
}
  int main(){
  	cout<<"Ingrese la cantidad de elementos de su arreglo"<<endl;
  	int capacidad, i, elemento ;
  	cin>>capacidad;
  	Heap hola(capacidad);
  	for(i=0;i<capacidad;i++){
  		cout<<"Ingrese elemento:"<<endl;
  		cin>>elemento;
  		hola.insertKey(elemento);
	  }
  hola.sort();
  hola.print();
//	cout<<hola.extractMax()<<endl;
  
  	return 0;
  }
