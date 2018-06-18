// ConsoleApplication1.cpp: главный файл проекта.

#include "stdafx.h"
#include "Matrix.h"
#include <stdlib.h>

using namespace System;
using namespace std;

int main(array<System::String ^> ^args)
{
	setlocale(LC_ALL, "rus");

    Matrix *a =new Matrix(3, 3);          // создали квадратную матрицу 3х3

	cout << endl << "количество строк " << a->rows();
    cout << endl << "количество столбцов " << a->columns() << endl;

    a->fill("c:\\temp\\myMatrix.dat");    // заполнили и записали матрицу
    a->cout();                            // вывели матрицу в стандартный поток с использованием метода cout()

    Matrix *c =new Matrix(3, 3);
    c->fstream("c:\\temp\\myMatrix.dat"); // прочитали и заполнили матрицу
    cout << *c;                           // вывели матрицу в стандартный поток с использование перегруженного оператора <<

    Matrix d;
    d = *c;                               // переопределЄнный оператор "="
    cout << d;

    Matrix f(*c);                         // конструктор с копированием
    cout << f;
                                         // проверка сложени€, умнодени€ и эквиваленьности
    if( (*c+d) == f.mlt(2)) cout << endl << "матрицы эквивалентны !!!" <<endl << endl;

    Matrix *g =new Matrix(2, 3);         // консольный ввод 
    cin >> *g;
    cout << endl << *g << endl;
      
    Matrix *h =new Matrix(3, 1);        // создали матрицу столбец 3х1
    cin >> *h;							// консольный ввод 
    cout << endl << *h << endl;

/*             онтрольный пример перемножени€ матриц

			| 1 2 3 |	| 1 |	| 14 |
			|		| * | 2 | = |	 |
			| 2 4 6	|	| 3 |	| 28 |
*/

    Matrix e;
    e = *g * (*h);
    cout << e;

//    Console::WriteLine(L"«дравствуй, мир!");

    system("pause");
    return 0;
}
