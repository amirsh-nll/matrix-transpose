#include "stdafx.h"
#include "iostream"
#include "conio.h"
using namespace std;

// Matrix Class
class matrix
{
public:
	matrix(int n, string shape);
	~matrix();
	void transpose();
	void print();

private:
	double *mymatrix;
	string matrixshape;
	int matrixsize;
	int newlinenumber;
};

matrix::matrix(int n, string shape = "square")
{
	matrixshape = shape;

	if(!matrixshape.compare("square"))
	{
		matrixsize = n * n;
		newlinenumber = n;
	}
	else
	{
		matrixsize = n * 2;
		newlinenumber = 2;
	}

	mymatrix = new (nothrow) double[matrixsize];
	if (mymatrix == nullptr)
		cout << "Memory not Allocated";
	else
	{
		for (int i = 0; i < matrixsize; i++)
		{
			mymatrix[i] = i;
		}
	}
}

matrix::~matrix()
{
}

void matrix::print()
{
	int tempcounter = 0;

	for (int i = 0; i < matrixsize; i++)
	{
		cout << mymatrix[i] << '\t';
		tempcounter ++;
		if(tempcounter == newlinenumber)
		{
			tempcounter = 0;
			cout << endl;
		}
	}
}

void matrix::transpose()
{
	for(int i = 0; i < newlinenumber; ++i)
    for(int j = i+1; j < newlinenumber; ++j)
        swap(mymatrix[newlinenumber*i + j], mymatrix[newlinenumber*j + i]);

	if(matrixshape.compare("square"))
		newlinenumber = matrixsize / 2;
}



// Main Program
void main()
{
	// Test Rectangle Matrix 
	matrix m1 = matrix(5,"rect");
	cout << "First Matrix : " << endl;
	m1.print();
	cout << endl << "Transposed Matrix : " << endl;
	m1.transpose();
	m1.print();

	// Test square Matrix 
	matrix m1 = matrix(4,"square");
	cout << "First Matrix : " << endl;
	m1.print();
	cout << endl << "Transposed Matrix : " << endl;
	m1.transpose();
	m1.print();

	// stay in console
	int stay;
	cin >> stay;
	return;
}