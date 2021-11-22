#include <iostream>
#include <cmath>
#include <iso646.h>


using namespace std;

int Factr(int N)
{
    int fac = 1;
    for (int i = 2; i <= N; fac *= i++);   //Факториал
    return fac;
}

float nElement(int N, float x)
{
    return pow(-1, N) * pow(x, 2 * N) /Factr(N);   //N-элемент последовательности
}



float Xtake()
{
    float x;
    cout << "Введите x: ";  //Перем. x
    cin >> x;
    return x;
}

int Ntake()
{
    int N;
    while (true)
    {
        cout << "Введите N: ";
        cin >> N;
        if (N >= 0) break;
        else cout << "Введите натуральное N";
    }
    return abs(N);
}

int Ntake(float x, float E)
{
    int N = 0;
    int i = 0;
    while (abs(nElement(i++, x)) > E) N++;
    return N;
}

float Etake()
{
    float E;
    cout << "Введите E: ";
        cin >> E;
    return E;
}



float SumTake(int N, float x, float E)
{
    float sum = 0;
    for (int i = 0; i <= N; i++)
    {
        if (abs(nElement(i, x)) > E)    //Частичная сумма ряда
        {
            sum += nElement(i, x);
        }
    }
    return sum;
    
}

float CountTake(int N, float x, float E)
{
    int count = 0;
    for (int i = 0; i <= N; i++)
    {
        if (abs(nElement(i, x)) > E)    //Кол-во элементов ряда
        {
            count +=1;
        }
    }
    return count;
}

float RasnostType(int N, float x, float E)
{
    return abs(SumTake(N, x, E) - pow(2.72, pow(-x, 2))); //Абсолютная погрешность
}


void firstObjective()   // Задание 1
{
    float x;
    int N;
    x = Xtake();
    N = Ntake();

    cout << "Частичная сумма ряда:  " << SumTake(N, x, 0) << endl;
    cout << "Абсолютная погрешность функции и частичной суммы ряда (разность между функцией и частичной суммой ряда):  " << RasnostType(N, x, 0) << endl;
    cout << "Разность между N элементом и подсчитаной разностью:  " << RasnostType(N, x, 0) - nElement(N, x) << endl;
}

void secondObjective()   // Задание 2
{
    float x,E; int count;
    
    E = Etake();
    x = Xtake();

    cout << "Частичная сумма ряда членов больше E:  " << SumTake(Ntake(), x, E) << endl;
    cout << "Кол-во слагаемых: " << CountTake(Ntake(), x, E) << endl;
    
}

void menyushka()
{
    while (true)
    {
        float menuu;
        cout << "Нажмите 1 - для решения задания №1, 2 - для задания №2, 0 - для выхода: ";
        cin >> menuu;
    
        if (menuu == 0) break;
        else if (menuu == 1) firstObjective();
        else if (menuu == 2) secondObjective();
    }
}
int main()
{
    setlocale(0,"");
    menyushka();
}


