#include "Prism.h"
#include "CommonTriangle.h"
#include <iostream>
#include <cmath>
using namespace std;

Prism::Prism(double a, double b, double al, double h) : CommonTriangle(a, b, al), height(h) {}
double Prism::Volume() {
	return height * CommonTriangle::Area();
}
double Prism::SurfaceArea() {
	return CommonTriangle::Area() * 2.0 + CommonTriangle::Perimetr() * height;
}
double Prism::Diagonal() {
	return sqrt(height * height + CommonTriangle::MaxSide() * CommonTriangle::MaxSide());
}
void Prism::print() {
	CommonTriangle::print();
	cout << "Height of prism: " << height << endl;
	cout << "Volume of prism: " << Prism::Volume() << endl;
	cout << "Surface area of prism: " << Prism::SurfaceArea() << endl;
}
Prism::~Prism() {}
