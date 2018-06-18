// ConsoleApplication1.cpp: ������� ���� �������.

#include "stdafx.h"
#include "Matrix.h"
#include <stdlib.h>

using namespace System;
using namespace std;

int main(array<System::String ^> ^args)
{
	setlocale(LC_ALL, "rus");

    Matrix *a =new Matrix(3, 3);          // ������� ���������� ������� 3�3

	cout << endl << "���������� ����� " << a->rows();
    cout << endl << "���������� �������� " << a->columns() << endl;

    a->fill("c:\\temp\\myMatrix.dat");    // ��������� � �������� �������
    a->cout();                            // ������ ������� � ����������� ����� � �������������� ������ cout()

    Matrix *c =new Matrix(3, 3);
    c->fstream("c:\\temp\\myMatrix.dat"); // ��������� � ��������� �������
    cout << *c;                           // ������ ������� � ����������� ����� � ������������� �������������� ��������� <<

    Matrix d;
    d = *c;                               // ��������������� �������� "="
    cout << d;

    Matrix f(*c);                         // ����������� � ������������
    cout << f;
                                         // �������� ��������, ��������� � ���������������
    if( (*c+d) == f.mlt(2)) cout << endl << "������� ������������ !!!" <<endl << endl;

    Matrix *g =new Matrix(2, 3);         // ���������� ���� 
    cin >> *g;
    cout << endl << *g << endl;
      
    Matrix *h =new Matrix(3, 1);        // ������� ������� ������� 3�1
    cin >> *h;							// ���������� ���� 
    cout << endl << *h << endl;

/*            ����������� ������ ������������ ������

			| 1 2 3 |	| 1 |	| 14 |
			|		| * | 2 | = |	 |
			| 2 4 6	|	| 3 |	| 28 |
*/

    Matrix e;
    e = *g * (*h);
    cout << e;

//    Console::WriteLine(L"����������, ���!");

    system("pause");
    return 0;
}
