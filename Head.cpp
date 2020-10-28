#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include"Prism.h"
using namespace std;

void input(vector<Figure*>& l) {
	ifstream in("input.txt");
	int code;
	double a, b, al, h;
	string str;
	if (!in) cout << "File not found" << endl;
	else {
		while (!in.eof()) {
			in >> code;
			if (code == 1) {
				try {
					in >> a >> b >> al;
					if (a <= 0 || b <= 0 || al <= 0 || al >= 180) throw "Incorrect input triangle";
				}
				catch (const char* a) {
					cout << a << endl;
					continue;
				}
				CommonTriangle* t1 = new CommonTriangle(a, b ,al);
				l.push_back(t1);
			}
			if (code == 2) {
				try {
					in >> a >> b >> al >> h;
					if (a <= 0 || b <= 0 || h <= 0 || al <= 0 || al >= 180) throw "Incorrect input prism";
				}
				catch (const char* a) {
					cout << a << endl;
					continue;
				}
				Prism* p1 = new Prism(a, b, al, h);
				l.push_back(p1);
			}
		}
	}
}

void output(vector<Figure*>& l) {
	CommonTriangle* triangle;
	Prism* prism;
	for (auto i : l) {
		prism = dynamic_cast<Prism*>(i);
		if (prism) cout << "Prism:" << endl;
		else {
			triangle = dynamic_cast<CommonTriangle*>(i);
			if (triangle) cout << "Triangle:" << endl;
		}
		i->print();
		cout << endl;
	}
}

bool function3(const vector<Figure*>& v, CommonTriangle& t, double& d) {
	CommonTriangle* tr;
	Prism* pr;
	vector<Prism*> vp;
	double s = 0;
	bool flag = false;
	for (int i = 0; i < v.size(); i++) {
		pr = dynamic_cast<Prism*>(v[i]);
		if (pr) {
			if (pr->Diagonal() > d) d = pr->Diagonal();
		}
		else {
			tr = dynamic_cast<CommonTriangle*>(v[i]);
			if (tr) {
				if (tr->Area() > s) {
					s = tr->Area();
					t = *tr;
					flag = true;
				}
			}
		}
	}
	return flag;
}

int main() {
	vector<Figure*> l;
	input(l);
	output(l);
	double d = 0;
	CommonTriangle t;
	cout << endl << "Informatoin about triangle with tre biggest square: " << endl << endl;
	if (function3(l, t, d)) t.print();
	else cout << "Our vector is empty or we haven't type <triangle>" << endl;
	cout << endl << "The biggest diagonal in the prismes: " << endl << endl;
	if(d!=0) cout << d << endl;
	else cout << "Our vector is empty or we haven't type <prism>" << endl;
	system("pause");
	return 0;
}
