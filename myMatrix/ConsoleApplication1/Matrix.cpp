
#include "stdafx.h"

using namespace std;

#include "matrix.h"

	Matrix::Matrix(){}									// ����������� �� ���������, ������� 10 � 10

	Matrix::Matrix(long _row, long _col){				// ����������� � �����������, ������ _row x _col
		myInit(_row, _col);
	}

	Matrix::Matrix(const Matrix &B){					// ����������� � ������������
		myInit(B.myRow, B.myCol);
		memcpy(_myMatrix, B._myMatrix, sizeof(double) *B.myRow *B.myCol);
	}

	void Matrix::myInit(long _row, long _col){			// �������� ����� ������
		myRow =_row;									// �������������� ���������� ����������
		myCol =_col;
		mySize =myRow *myCol;
		long k =sizeof(double) *mySize;
		_myMatrix =(double *) malloc(k);			    // �������� ������
		ZeroMemory(_myMatrix, k);
	}

	long Matrix::rows(){
		return myRow;
	}

	long Matrix::columns(){
		return myCol;
	}

	long Matrix::fstream(char *fullName){
		ifstream myFile;
		myFile.open(fullName);
			
		if (!myFile) return -1;                         // cout << "�� ������� ������� ���� \n\n"; 

		double *a =_myMatrix;							// ��������� �� ������ �����
		long _count =0;
		for(long k =0; k <mySize; k++){
			if(myFile.eof()) return _count;
			myFile >>*a;							    // �������, ��� �������� � ����� ��������� ��������
			_count +=1;
			a++;
		}
		return _count;
	}

	void Matrix::cout(){
		double *a =_myMatrix;							// ��������� �� ������ �����
		std::cout << endl << "����� ������ �������� " << myRow << " �� " << myCol << endl;

		for(long k =0; k <myRow; k++){
			for(long n =0; n <myCol; n++){
				std::cout.width(6);
				std::cout << *a << " ";
				a++;
			}
			std::cout <<endl;
		}
		std::cout << endl;
	}

	bool Matrix::fill(char *nameFile =NULL){            // ���������� � ���������� ������� � ����

		srand((unsigned int) time(NULL) );

		double *a =_myMatrix;

		for(long k =0; k <mySize; k++){
			*a =(double)rand();
			a++;
		}

		if(*nameFile !=NULL){
			ofstream myFile(nameFile);

			if(!myFile){
				std::cout << endl << "�� ������� ������� ���� ������" << endl;
				return false;
			}else{
				a =_myMatrix;
				for(long k =0; k <mySize; k++){
					myFile << *a << " ";
					a++;
				}
				myFile.close();
			}
		}
		return true;
	}

	Matrix Matrix::mlt(const double kof){
		double *a =_myMatrix;
		for(long n =0; n <mySize; n++){
			*a *= kof;
			a++;
		}
		return *this;
	}

	Matrix Matrix::operator + (const Matrix &B){
		Matrix *C =NULL;
		if( (myRow !=B.myRow) || (myCol !=B.myCol)) return *C;

		C =new Matrix(myRow, myCol);

		double *a =_myMatrix;
		double *b =B._myMatrix;
		double *c =C->_myMatrix;

		for(long k =0; k <mySize; k++){
			*c =(*a) +(*b);
			a++;
			b++;
			c++;
		}
		return *C;	
	}

	bool Matrix::operator == (const Matrix &B){
		if( (myRow !=B.myRow) || (myCol !=B.myCol)) return false;
		return memcmp((double *)_myMatrix, (double *)B._myMatrix, mySize) ==0;
	}

	Matrix Matrix::operator = (const Matrix &B){
		myInit(B.myRow, B.myCol);
		memcpy(_myMatrix, B._myMatrix, sizeof(double) *B.myRow *B.myCol);
		return *this;
	}

	Matrix Matrix::operator * (const Matrix &B){
		Matrix *C =NULL;
		if(myCol !=B.myRow) return *C;

		C =new Matrix(myRow, B.myCol);

		double *a =_myMatrix;
		double *b =B._myMatrix;
		double *c =C->_myMatrix;

		for(long k =0; k <myRow; k++)
			for(long n =0; n <B.myCol; n++){
				*c =0;
				for (long m =0; m <myCol; m++) *c += (a[k *myCol +m] * b[m *B.myCol +n]); // ������������ �������
				c++;
			}
		return *C;	
	}

	ostream & operator << (ostream &os, const Matrix &A){
		os << endl << "����� ������ �������� " << A.myRow << " �� " << A.myCol << endl;
		double *a =A._myMatrix;
		for (long k =0; k <A.myRow; k++){
			for (long n =0; n <A.myCol; n++){
				os.width(6);
				os << *a << ' ';
				a++;
			}
			os << endl;
		}
		return os;   
	}

	istream & operator >> (istream &is, Matrix &A){
		std::cout << endl << "���������� ������� �������� " << A.myRow << "x" << A.myCol << endl;
		double *a =A._myMatrix;
		for (long k =0; k <A.myRow; k++)
			for (long n =0; n <A.myCol; n++){
				std::cout << "[" << k+1 << n+1 << "] <- ";
				is >> *a;
				a++;
			}
		return is;   
	}

	Matrix::~Matrix(){									// ���������� �� ���������
		free(_myMatrix);								// ���������� ������ (�� ������, � ��������� �� �����)
	}