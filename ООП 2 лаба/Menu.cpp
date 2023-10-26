#include "Menu.h"

void menu()
{
	cout << "Welcome to polynomals" << endl;
	cout << "[1] Create polynomias" << endl;
	cout << "[2] Load polynom" << endl;
	cout << "[3] Exit" << endl;
	
	Polynom p;
	vector<Polynom> lp;
	int answer;
	cin >> answer;

	switch (answer)
	{
	case 1:
		polym(lp);
		break;
	case 2:
		load_p(lp);
		break;
	case 3:
		break;
	}
}

void polym(vector<Polynom>& lp)
{
	cout << "[1] Create one polynoum" << endl;
	
	cout << "[2] Show one polynoum" << endl;
	cout << "[3] Show polynoums" << endl;
	cout << "[4] Adding polynoms" << endl;
	cout << "[5] Multiple polynoms" << endl;
	cout << "[6] Multiple to polynome constant" << endl;
	cout << "[7] Save one polynoum" << endl;
	cout << "[8] Exit to menu" << endl;
	cout << "[9] (Checking) work operator = for one polynome" << endl;
	cout << "[10] (Checking) work copying constructor for one polynome" << endl;

	

	Polynom p;
	Polynom p_copy;

	int answer;

	cin >> answer;

	int index;
	int index2;
	ofstream file("source_file.txt");

	switch (answer) 
	{
	case 1:
		cin >> p;
		lp.push_back(p);

		polym(lp);
		break;
	case 2:
		if (lp.size() == 0)
		{	
			cout << "Theare is not any polynoumls" << endl;
			polym(lp);
			break;
		}
		cout << "Index of polynoum: ";
		cin >> index;
		cout << lp[index] << endl;
		
		polym(lp);
		break;
	case 3:
		if (lp.size() == 0)
		{
			cout << "Theare is not any polynoumls" << endl;
			polym(lp);
			break;
		}

		for (int i = 0; i < lp.size(); ++i)
		{
			cout<< i <<". " << lp[i] << endl;
		}
		polym(lp);
		break;
	case 4:
		if (lp.size() == 0)
		{
			cout << "Theare is not any polynoumls. You can use multiply to constant." << endl;
			polym(lp);
			break;
		}
		cout << "What index to add? ";
		cin >> index;
		
		cout << "Add to him: ";
		cin >> index2;

		lp[index].add(lp[index2]);

		cout << "Result:" << endl;
		cout << lp[index] << endl;

		polym(lp);
		break;
	case 5:
		if (lp.size() == 0)
		{
			cout << "Theare is not any polynoumls. You can use multiply to constant." << endl;
			polym(lp);
			break;
		}
		cout << "What index to multiply? ";
		cin >> index;

		cout << "Multiply to him: ";
		cin >> index2;

		lp[index].multiply(lp[index2]);

		cout << "Result:" << endl;
		cout << lp[index] << endl;

		polym(lp);
		break;
	case 6:
		cout << "What a polynom you want to multiply by constant? " << endl;
		cin >> index;
		cout << "Constanta: ";
		cin >> index2;

		lp[index].multi_const(index2);

		cout << "Result:" << endl;
		cout << lp[index] << endl;

		polym(lp);
		break;
	case 7:
		cout << "What an index of polynoum? " << endl;
		cin >> index;

		
		if (!file) 
		{ 
			cout << "Error while opening file" << endl;
			polym(lp);
			break;
		}
		try
		{
			file << lp[index];
		}
		catch (const char* error_message)
		{
			cout << error_message << endl;
		}
		
		
		//file.close();
		polym(lp);
		break;
	case 8:
		

		menu();
		break;
	case 9:
		
		cout << "What a polynoum you want to pass to anouther one?" << endl;
		cin >> index;

		p_copy = lp[index]; // operator=

		cout << "Polynom p_copy;" << endl;
		cout << "p_copy = lp[index]:" << endl;

		cout << p_copy << endl;

		polym(lp);
		break;
	case 10:
		cout << "Just testing Copy constructor" << endl;
		cin >> p;
		
		show_first_2elems(p); // copy constructor

		polym(lp);
		break;
	}
}

void load_p(vector<Polynom>& lp)
{
	Polynom p;

	ifstream file("source_file.txt");
	if (!file) { cout << "Error to open file" << endl; menu(); }
	try 
	{
		file >> p;
	}
	catch (const char* error_message)
	{
		cout << error_message << endl;
	}
	
	lp.push_back(p);
	file.close();

	polym(lp);
	
}

void show_first_2elems(Polynom p)
{
	cout << "first elemen: " << p[0] << endl;
	cout << "second elemen: " << p[1] << endl;

}
