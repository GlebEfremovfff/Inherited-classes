#include "CommonTriangle.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#define pi 3.14159265
using namespace std;

CommonTriangle::CommonTriangle() {}
CommonTriangle::~CommonTriangle() {}
CommonTriangle::CommonTriangle(double a, double b, double al) : a(a), b(b), alpha(al) {}
double CommonTriangle::Area() {
	double c = sqrt(a * a + b * b - 2 * a * b * cos(alpha));
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}
double CommonTriangle::Perimetr() {
	double c = sqrt(a * a + b * b - 2 * a * b * cos(alpha / 57.2958));
	return a + b + c;
}
double CommonTriangle::MaxSide() {
	double c = sqrt(a * a + b * b - 2 * a * b * cos(alpha / 57.2958));
	double sd = max(a, max(b, c));
	return sd;
}
void CommonTriangle::print() {
	double c = sqrt(a * a + b * b - 2 * a * b * cos(alpha / 57.2958));
	int beta = acos(((a * a) - (b * b + c * c)) / (-2 * b * c)) * 57.2958;
	if (beta > 180) beta = 360 - beta;
	int gamma = acos(((b * b) - (a * a + c * c)) / (-2 * a * c)) * 57.2958;
	if (gamma > 180) gamma = 360 - gamma;
	cout << "Sides of triangle: " << a << " " << b << " " << c << endl;
	cout << "Angles of triangle: " << alpha << " ~" << beta
		<< " ~" << gamma << endl;
	cout << "Perimetr of triangle: " << CommonTriangle::Perimetr() << endl;
	cout << "Area of triangle: " << CommonTriangle::Area() << endl;
}
