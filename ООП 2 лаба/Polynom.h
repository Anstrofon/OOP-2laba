#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Polynom
{
private:
	int counts;
	double* polynoms;
public:


	Polynom();

	int get_count();

	Polynom(const Polynom& a);

	Polynom(int counts, double* polynoms) : counts(counts), polynoms(polynoms)
	{};

	~Polynom();

	void set_count(int c);

	double& operator[](const int index);

	Polynom& operator=(const Polynom& h);

	friend istream& operator>>(istream& in, Polynom& a);

	friend ofstream& operator<<(ofstream& fileout, Polynom& a);
	friend ifstream& operator>>(ifstream& filein, Polynom& a);
	friend ostream& operator<<(ostream& out, Polynom& a);

	void add(Polynom& a);

	void divide(Polynom& a);

	void multiply(Polynom& a);
	void minus(Polynom& a);

	void multi_const(const int co);


};
