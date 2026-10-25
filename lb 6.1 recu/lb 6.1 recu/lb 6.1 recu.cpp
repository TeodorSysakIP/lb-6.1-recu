// Лабораторна робота № 6.1, варіант 13
// Спосіб 2: рекурсивні функції
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;


void Create(int* p, const int size, const int Low, const int High, int i)
{
    if (i < size)
    {
        p[i] = Low + rand() % (High - Low + 1);
        Create(p, size, Low, High, i + 1);
    }
}


void Print(int* p, const int size, int i)
{
    if (i < size)
    {
        cout << setw(4) << p[i];
        Print(p, size, i + 1);
    }
    else
        cout << endl;
}


int Count(int* p, const int size, int i)
{
    if (i < size)
    {
        if (p[i] > 0 || i % 2 == 0)
            return 1 + Count(p, size, i + 1);
        else
            return Count(p, size, i + 1);
    }
    else
        return 0;
}


int Sum(int* p, const int size, int i)
{
    if (i < size)
    {
        if (p[i] > 0 || i % 2 == 0)
            return p[i] + Sum(p, size, i + 1);
        else
            return Sum(p, size, i + 1);
    }
    else
        return 0;
}


void ZeroOut(int* p, const int size, int i)
{
    if (i < size)
    {
        if (p[i] > 0 || i % 2 == 0)
            p[i] = 0;
        ZeroOut(p, size, i + 1);
    }
}

#ifndef UNIT_TEST   
int main()
{
    srand((unsigned)time(NULL));

    const int n = 24;
    int p[n];
    const int Low = -10;
    const int High = 14;

    Create(p, n, Low, High, 0);
    Print(p, n, 0);

    cout << "Count = " << Count(p, n, 0) << endl;
    cout << "Sum   = " << Sum(p, n, 0) << endl;

    ZeroOut(p, n, 0);
    Print(p, n, 0);

    return 0;
}
#endif