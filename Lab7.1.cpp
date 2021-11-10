// Lab_7_1.cpp
// <Добош Юлія  >
// Лабораторна робота № 7.1.
// Пошук заданих елементів та впорядкування рядків / стовпчиків матриці.
// Варіант 7

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low,
    const int High);
void Print(int** a, const int rowCount, const int colCount);
void Sort(int** a, const int rowCount, const int colCount);
void Change(int** a, const int row1, const int row2, const int colCount);
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k);

int main()
{
    srand((unsigned)time(NULL));

    int Low = 4;
    int High = 51;

    int rowCount = 8;
    int colCount = 5;

    int** R = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        R[i] = new int[colCount];

    Create(R, rowCount, colCount, Low, High);
    Print(R, rowCount, colCount);
    Sort(R, rowCount, colCount);
    Print(R, rowCount, colCount);

    int S = 0;
    int k = 0;
    Calc(R, rowCount, colCount, S, k);
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;
    Print(R, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] R[i];
    delete[] R;

    return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low,
    const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

void Sort(int** a, const int rowCount, const int colCount)
{
    for (int i0 = 0; i0 < rowCount - 1; i0++)
        for (int i1 = 0; i1 < rowCount - i0 - 1; i1++)
            if ((a[i1][0] > a[i1 + 1][0])
                ||
                (a[i1][0] == a[i1 + 1][0] &&
                    a[i1][1] < a[i1 + 1][1])
                ||
                (a[i1][0] == a[i1 + 1][0] &&
                    a[i1][1] == a[i1 + 1][1] &&
                    a[i1][4] < a[i1 + 1][4]))
                Change(a, i1, i1 + 1, colCount);
}

void Change(int** a, const int row1, const int row2, const int colCount)
{
    int tmp;
    for (int j = 0; j < colCount; j++)
    {
        tmp = a[row1][j];
        a[row1][j] = a[row2][j];
        a[row2][j] = tmp;
    }
}

void Calc(int** R, const int rowCount, const int colCount, int& S, int& k)
{
    S = 0;
    k = 0;
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            if (!(R[i][j] % 2 != 0 ||( i % 3 == 0 && j % 3 == 0)))//всі, крім: непарних, або з двома індексами, кратними 3.
            {
                S +=  R[i][j];
                k++;
                R[i][j] = 0;
            }
}
