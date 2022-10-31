// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
// Тестирование матриц

#include <iostream>
#include "tmatrix.h"
//---------------------------------------------------------------------------

void ready_test()
{
    TDynamicMatrix<int> a(5), b(5), c(5);
    int i, j;
    for (i = 0; i < 5; i++)
        for (j = i; j < 5; j++)
        {
            a[i][j] = i * 10 + j;
            b[i][j] = (i * 10 + j) * 100;
        }

    cout << "Matrix a = " << endl << a << endl;
    cout << "Matrix b = " << endl << b << endl;

    c = a + b;
    cout << "Matrix c = a + b" << endl << c << endl;
    c = a - b;
    cout << "Matrix c = a - b" << endl << c << endl;
    c = a * b;
    cout << "Matrix c = a * b" << endl << c << endl;
}

template<class T>
void input(TDynamicMatrix<T> a)
{
    TDynamicMatrix<T> b(a.size());
    TDynamicMatrix<T> c(a.size());

    cout << "Введите матрицу а:" << endl;
    cin >> a;
    cout << "Введите матрицу b:" << endl;
    cin >> b;

    cout << "Matrix a = " << endl << a << endl;
    cout << "Matrix b = " << endl << b << endl;

    c = a + b;
    cout << "Matrix c = a + b" << endl << c << endl;
    c = a - b;
    cout << "Matrix c = a - b" << endl << c << endl;
    c = a * b;
    cout << "Matrix c = a * b" << endl << c << endl;
}

void test()
{
    while (1)
    {
        size_t size;
        int choice;
        cout << "Чтобы выйти - нажмите любую клавишу" << endl;
        cout << "Введите размер матрицы: ";
        cin >> size;
        cout << endl << "Выберите тип данных шаблона: 1) int, 2) long int 3) long long int 4) float 5) double 6) long double" << endl;
        cout << "Чтобы выйти - нажмите любую клавишу" << endl;
        cout << "Ваш выбор: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
        {   
            TDynamicMatrix<int> a(size);
            input<int>(a);
            break;
        }
        case 2:
        {
            TDynamicMatrix<long int> a(size);
            input<long int>(a);
            break;
        }
        case 3:
        {
            TDynamicMatrix<long long int> a(size);
            input<long long int>(a);
            break;
        }
        case 4:
        {
            TDynamicMatrix<float> a(size);
            input<float>(a);
            break;
        }
        case 5:
        {
            TDynamicMatrix<double> a(size);
            input<double>(a);
            break;
        }
        case 6:
        {
            TDynamicMatrix<long double> a(size);
            input<long double>(a);
            break; 
        }
        default:
            break;
        }
    }
}

void main()
{
  setlocale(LC_ALL, "Russian");
  cout << "ТЕСТИРОВАНИЕ РАБОТЫ С МАТРИЦАМИ" << endl << endl;
  int choice, st = 1;

  while (st)
  {
      cout << "Выберите способ тестирования: 1) Готовый тест 2) Свой пример" << endl;
      cout << "Чтобы закончить - нажмите любую другую клавишу" << endl;
      cout << "Ваш выбор: ";
      cin >> choice;
      cout << endl;

      switch (choice)
      {
      case 1:
          ready_test();
          break;
      case 2:
          test();
          break;
      default:
          st = 0;
          break;
      }
  }
}
//---------------------------------------------------------------------------
