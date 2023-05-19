#include<iostream>
#include "Vector3.h"
template<typename T>
class Arreglo {
private:
	T* m_data = nullptr;
	size_t tamano=0;
	size_t capacidad=0;
private:
	void resize(size_t NCapacidad) {
		T* NArreglo = (T*)::operator new(NCapacidad * sizeof(T));
		if (NCapacidad < tamano)
			tamano = NCapacidad;
		for (size_t i = 0; i < tamano; i++) 
			NArreglo[i] = std::move(m_data[i]);
		::operator delete(m_data, capacidad * sizeof(T));
		m_data = NArreglo;
		capacidad = NCapacidad;
	}
public:
	Arreglo(){
		resize(2);
	}
	void PushBack(const T& valor) {
		if (tamano >= capacidad)
			resize(capacidad +  capacidad/2);
		m_data[tamano] = valor;
		tamano++;
	}
	void PushBack(T&& valor) {
		if (tamano >= capacidad)
			resize(capacidad + capacidad / 2);
		m_data[tamano] = std::move(valor);
		tamano++;
	}
	size_t size() const { return tamano; }
	const T& operator[] (size_t indice)const  { return m_data[indice]; }
};



template<typename T>
void PrintVector(const Arreglo<T> arreglo) {
	for (size_t i = 0; i < arreglo.size(); i++) {
		std::cout << arreglo[i]<<std::endl;
	}
	std::cout << "--------------------------------";
}
template<>
void PrintVector(const Arreglo<Vector3> arreglo) {
	for (size_t i = 0; i < arreglo.size(); i++) {
		std::cout << arreglo[i].x << " "<< arreglo[i].y << " "<< arreglo[i].z << " "<< std::endl;
	}
	std::cout << "--------------------------------";
}


int main() { 
	Arreglo<Vector3> Prueba;
	Prueba.PushBack(Vector3(3));	
	Prueba.PushBack(Vector3(3,3,2));
	Prueba.PushBack(Vector3());
	PrintVector(Prueba);
}