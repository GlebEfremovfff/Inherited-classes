#pragma once
#include "CommonTriangle.h"
class Prism : public CommonTriangle {
	double height;
public:
	Prism(double a, double b, double al, double h);
	double Volume();
	double SurfaceArea();
	double Diagonal();
	void print();
	~Prism();
};
