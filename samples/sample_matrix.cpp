// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
// Тестирование матриц

#include <iostream>
#include <ctime>
#include "tmatrix.h"
//---------------------------------------------------------------------------
template<class T>
void random_matrix(TDynamicMatrix<T>& temp)
{
    srand(time(NULL) + rand());
    for (int i = 0; i < temp.size(); i++)
        for (int j = 0; j < temp.size(); j++)
            temp[i][j] = static_cast<T>(-14.532132) + static_cast<T> (rand()) / (static_cast <T> (RAND_MAX / static_cast<T>(54.05489 + 14.532132)));
}

template<class T>
void random_vector(TDynamicVector<T>& temp)
{
    srand(time(NULL) + rand());
    for (int i = 0; i < temp.size(); i++)
        temp[i] = static_cast<T>(-124.532132) + static_cast<T> (rand()) / (static_cast <T> (RAND_MAX / static_cast<T>(154.05489 + 124.532132)));
}
void ready_test(int type_gen)
{
    int st1 = 1, choice = 0, size;
    double scalar = 0.0;
    while (st1)
    {
        int st2 = 1;

        if (type_gen == 1)
            cout << endl << "//ВЫБРАНА СЛУЧАЙНАЯ ГЕНЕРАЦИЯ\\\\" << endl;
        else
            cout << endl << "//ВЫБРАН РУЧНОЙ ВВОД\\\\" << endl;

        cout << "Чтобы выйти - введите отрицательное число " << endl;
        cout << "Введите размер матриц: ";
        cin >> size;
        cout << endl << endl;

        if (size < 1)
        {
            st1 = 0;
            continue;
        }

        TDynamicMatrix<double> a(size);
        TDynamicMatrix<double> b(size);
        TDynamicMatrix<double> c(size);
        TDynamicVector<double> v(size);
        TDynamicVector<double> tmp(size);

        if (type_gen == 1)
        {
            random_matrix<double>(a);
            random_matrix<double>(b);
            random_vector<double>(tmp);
            cout << endl << endl;
        }

        else
        {
            cout << "Введите матрицу а:" << endl;
            cin >> a;
            cout << endl << "Введите матрицу b:" << endl;
            cin >> b;
            cout << endl << "Введите вектор tmp:" << endl;
            cin >> tmp;
            cout << endl;
        }

        while (st2)
        {
            cout << "Выберите операцию над матрицами:\n";
            cout << "1) Сложение\n2) Разность\n3) Умножение\n4) Умножение на скаляр\n5) Умножение на вектор" << endl;
            cout << "Чтобы выйти - нажмите любую другую клавишу." << endl;
            cout << "Ваш выбор: ";
            cin >> choice;

            string operation = "";

            switch (choice)
            {
            case 1:
            {
                c = a + b;
                operation = "c = a + b";
                break;
            }   
            case 2:
            {    
                c = a - b;
                operation = "c = a - b";
                break;
            }
            case 3:
            {    
                c = a * b;
                operation = "c = a * b";
                break;
            }
            case 4:
            {    
                cout << endl << "Введите скаляр: ";
                cin >> scalar;
                c = a * scalar;
                operation = "c = a * scalar";
                break;
            }
            case 5:
            {
                v = a * tmp;
                operation = "v = a * tmp";
                break;
            }
            default:
            {
                st2 = 0;
                break;
            }
            }

            if (st2 == 0)
                continue;

            cout << endl << "Матрица а:\n" << a << endl;
            if ((choice != 4) && (choice != 5))
                cout << "Матрица b:\n" << b << endl;
            if (choice != 5)
                cout << "Матрица " << operation << ":\n" << c << endl;
            if (choice == 5)
            {
                cout << "Вектор tmp:\n" << tmp << endl;
                cout << endl << "Вектор " << operation << ":\n" << v << endl;
            }

            cout << endl << endl;

        }
    }
}

void main()
{
    setlocale(LC_ALL, "Russian");
    cout << "ТЕСТИРОВАНИЕ РАБОТЫ МАТРИЦ" << endl << endl;
    int st = 1, choice = 0;

    while (st)
    {
        cout << "Выберите способ тестирования: 1) Случайные значения 2) Свой пример" << endl;
        cout << "Чтобы закончить - нажмите любую другую клавишу" << endl;
        cout << "Ваш выбор: ";
        cin >> choice;
        cout << endl;
        
        if ((choice == 1) || (choice == 2))
            ready_test(choice);
        else
            st = 0;
    }

}

//-------------------------------------------------------------------------
