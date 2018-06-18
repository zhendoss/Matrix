
#include "stdafx.h"

#include <fstream>
#include <iostream>
#include <time.h>
#include <stdlib.h>

#include <Windows.h>

using namespace std;

class Matrix{

private:
	double *_myMatrix;
	long myRow, myCol, mySize;

	void myInit(long, long);

public:
	Matrix();
	Matrix(long, long);
	Matrix(const Matrix &);
	~Matrix();

	long rows();
	long columns();

	long fstream(char *);
	void cout();
	bool fill(char *);

    Matrix mlt(const double);

	Matrix operator + (const Matrix &);
	Matrix operator * (const Matrix &);
	Matrix operator = (const Matrix &);
	bool operator == (const Matrix &);

    friend ostream & operator << (ostream &, const Matrix &);
    friend istream & operator >> (istream &, Matrix &);
};