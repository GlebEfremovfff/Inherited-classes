#pragma once
#include"Figure.h"
class CommonTriangle : public Figure {
	    double a;
	    double b;
	    double alpha;
	public:
		CommonTriangle();
		CommonTriangle(double a, double b, double al);
		virtual void print();
		double Area();
		double Perimetr();
		double MaxSide();
		/*CommonTriangle operator=(const CommonTriangle& i);*/
		~CommonTriangle();
};
