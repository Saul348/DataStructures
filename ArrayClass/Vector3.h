#pragma once
class Vector3 {
public:
	float x = 0.0f, y = 0.0f, z = 0.0f;
public:
	Vector3() {};
	Vector3(float escalar)
		:x(escalar), y(escalar), z(escalar) {};
	Vector3(float x, float y, float z)
		:x(x), y(y), z(z) {};
	//Copy Constructor
	Vector3(const Vector3& something)
		: x(something.x), y(something.y), z(something.z) {
		std::cout << "copy\n";
	}
	//Move constructor
	Vector3(Vector3&& something)
		: x(something.x), y(something.y), z(something.z) {
		std::cout << "Move\n";
	}
	~Vector3() { std::cout << "Destroy\n"; }
	//sobrecargar los operadores de asignacion
	Vector3& operator=(const Vector3& something) {
		std::cout << "copy\n";	
		x = something.x;
		y = something.y;
		z = something.z;
		return *this;
	}
	Vector3& operator=(Vector3&& something) {
		std::cout << "move\n";
		x = something.x;
		y = something.y;
		z = something.z;
		return *this;
	}
};