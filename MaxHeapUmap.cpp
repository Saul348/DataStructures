#include <iostream>
#include <vector>
#include <unordered_map>

class Max_heap{
public:
int p= 0;
std::unordered_map<int, int> umap;
std::vector<int> heap;
//Constructor. 
Max_heap(int root){
        heap.push_back(root);
    umap[root]= 0;
}
        
void print(){
    for(int i= 0; i< heap.size(); i++){
        std::cout<< heap[i]<< std::endl; 
    }
}
void print_umap(int numero){
        std::cout<< umap[numero]<< std::endl; 
}
void intercambiar(int i, int j){
    int tem= 0;
    tem= heap[i];
    heap[i]= heap[j];
    heap[j]= tem;
    umap[heap[i]]= i;
    umap[heap[j]]= j;
}
int padre(int i){
    if(i==0){
        return i;
    }
    if(i % 2!= 0){
        return (i-1)/2;
    }
    else return (i/2-1);
}
int hijo_z(int i){
    if (2*i+1 <= heap.size()-1){
    return 2*i+1;}
    else return -1;
}

int hijo_d(int i){
    if(2*i+2<= heap.size()-1){
    return 2*i+2;}
    else return -1;
}

void heapfy(int indice){
    p= padre(indice);
     if(heap[indice]> heap[p]){
        intercambiar(indice, p);
        heapfy(p);
    }
}
void heapfynt(int indice){
    if(heap[hijo_z(indice)]>= heap[hijo_d(indice)]){
        if (heap[indice]< heap[hijo_z(indice)]){
        intercambiar(indice, hijo_z(indice));
        heapfynt(hijo_z(indice));}
    }else if (heap[indice]< heap[hijo_d(indice)]){
        intercambiar(indice, hijo_d(indice));
        heapfynt(hijo_d(indice));}
}
void insertar(int elemento){
    heap.push_back(elemento);
    umap[elemento]= heap.size()-1;
    heapfy(heap.size()-1);
}
void borrar(int indice){
    intercambiar(indice, heap.size()-1);
    heap.pop_back();
      if (heap[indice]> padre(indice)){
        heapfy(indice);
    }
    heapfynt(indice);
}
};
int main() {
    return 0;
}
