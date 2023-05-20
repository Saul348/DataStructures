 #include<iostream>
 #include<math.h>
 using namespace std;
 class Forma{
 	public:
 	double area;
 	double perimetro;
 	double base;
 	double altura;
	Forma(double base_1,double altura_1){
		base=base_1;
		altura=altura_1;
	}
 	double area_1();
 	double perimetro_1();
 	
 };
 double Forma::area_1(){
 	 	area=base*altura;
 	return area;
 }
 double Forma::perimetro_1(){
 	return (2*altura+2*base);
 	
 }
 
 
 
 class Triangulo: public Forma{
 	public:
 		double lado_1,
 		lado_2,
 		lado_3;
 		
 		Triangulo(double base_1, double altura_1, double _lado_1,double _lado_2,double _lado_3):Forma(base_1,altura_1){
 			lado_1=_lado_1;
 			lado_2=_lado_2;
 			lado_3=_lado_3;
		 }
 	double area_2();
 	double perimetro_2();
 };
 double Triangulo::area_2(){
 	 area=	area_1()/2;
		
 		return area;
 }
 double Triangulo::perimetro_2(){
 	return (lado_1+lado_2+lado_3);
 	}




class Rectangulo: public Forma{
 	public:
 		double area;
 			Rectangulo(double base_1,double altura_1):Forma(base_1,altura_1){};
 		double area_2()
		 	{area_1();}
 		double perimetro_2()
		 	{perimetro_1();}
 };	



class Circulo: public Forma{
	public:
		double coordenada_x;
		double coordenada_y;
	Circulo(double radio_1, double _coordenada_x, double _coordenada_y):Forma(radio_1,radio_1){
		
		coordenada_x=_coordenada_x;
		coordenada_y=_coordenada_y;
	}
	double area_2(){
		return (area_1()*3.14);
	}
	double perimetro_2(){
		return (2*base*(3.14));
	}	
	bool dentro(double x, double y);
	
double interseccion(double radio);
	
};
 
 
bool Circulo::dentro(double x, double y){
 	double distancia;
 	distancia= sqrt(pow(coordenada_x-x,2)+pow(coordenada_y-y,2));
 	if(distancia>base){
 		return false;
	 }
	 else 
	 return true;
 } 	
 double Circulo::interseccion(double radio){
		Circulo circulo(radio, coordenada_x, coordenada_y);
		if(circulo.area_2()>this->area_2()){
			return (circulo.area_2()-this->area_2());
		}
		else 
			return (this->area_2()-circulo.area_2());
	}
 	
 int main(){
 	Triangulo triangulo(10,15,10,20,30);
 	Rectangulo rectangulo(20,40);
 	Circulo circulo(10,4,5);
 	cout<<triangulo.area_2()<<endl;
 	cout<<triangulo.perimetro_2()<<endl;
 	cout<<rectangulo.area_2()<<endl;
 	cout<<rectangulo.perimetro_2()<<endl;
 	cout<<circulo.area_2()<<endl;
 	cout<<circulo.perimetro_2()<<endl;
 	cout<<circulo.interseccion(30)<<endl;
	 return 0;
 }
