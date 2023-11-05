#include "Polynom.h"
#include<fstream>
#include <string>
Polynom::Polynom()
{

}

int Polynom::get_count()
{
	return this->counts;
}

Polynom::Polynom(const Polynom& a) // copy
{
	counts = a.counts;
	polynoms = new double[counts];
	for (int i = 0; i < counts; ++i)
	{
		this->polynoms[i] = a.polynoms[i];
	}
	
}

void Polynom::set_count(int c)
{
	counts = c;
	polynoms = new double[counts];
}

Polynom::~Polynom()
{
	delete[] polynoms;
}

double& Polynom::operator[](const int index)
{
	if (counts < index || 0 > index)
	{
		throw "Error";
	}
	else
	{
		for (int i = 0; i < counts; ++i)
		{
			if (i == index) { return polynoms[index]; }
		}
	}
}

Polynom& Polynom::operator=(const Polynom& h)
{
	if (this == &h)
	{
		return *this;
	}
	delete[] polynoms;

	counts = h.counts;
	polynoms = new double[counts];
	for (int i = 0; i < counts; ++i)
	{
		this->polynoms[i] = h.polynoms[i];
	}

	return *this;

}

void Polynom::add(Polynom& a)
{
	for (int i = 0; i < this->counts && a.counts; ++i)
	{
		polynoms[i] += a.polynoms[i];
	}
	
}

void Polynom::divide(Polynom& a)
{
	for (int i = 0; i < this->counts && a.counts; ++i)
	{
		polynoms[i] /= a.polynoms[i];
	}
}

void Polynom::multiply(Polynom& a)
{
	
	for (int i = 0; i < this->counts && a.counts; ++i)
	{
		polynoms[i] *= a.polynoms[i];
	}
}

void Polynom::minus(Polynom& a)
{
	for (int i = 0; i < this->counts && a.counts; ++i)
	{
		polynoms[i] -= a.polynoms[i];
	}
}

void Polynom::multi_const(const int co)
{
	for (int i = 0; i < this->counts; ++i)
	{
		polynoms[i] *= co;
	}
}


ostream& operator<<(ostream& out, Polynom& a)
{
	string op = "+";

	string xxx = "x";
	for (int i = 0; i < a.counts; ++i)
	{
		if (a.polynoms[i] < 0) { op = ""; }
		else if (a.polynoms[i] > 0) { op = "+"; }

		if (i >= 2) 
		{	
			xxx = "x^" + to_string(i);
		}

		if (i == 0)
		{
			out << a.polynoms[i];
			
		}
		else
		{
			out << op << a.polynoms[i] << xxx;
		}
	}


	return out;
	// TODO: вставьте здесь оператор return
}



istream& operator>>(istream& in, Polynom& a)
{	
	if (a.counts == 0)
	{
		cout << "How many elements you need? " << endl;
		int answ;
		in >> answ;
		a.set_count(answ);
		
	}
	
	double answ2;
	for (int i = 0; i < a.counts; ++i)
	{
		cout << "Enter number for " << i << " element:" << endl;

		in >> answ2;
		a.polynoms[i] = answ2;
	}

	return in;
}

ofstream& operator<<(ofstream& fileout, Polynom& a)
{
	fileout << a.counts << ':' << " ";
	
	for (int i = 0; i < a.counts; ++i)
	{
		fileout << a.polynoms[i] << " ";
	}

	return fileout;
}


ifstream& operator>>(ifstream& filein, Polynom& a)
{	
	string help;

	getline(filein, help, ':');

	a.set_count(stoi(help));
	
	for (int j = 0; j < a.counts; j++)
	{
		filein >> a.polynoms[j];
	}

	return filein;
}
