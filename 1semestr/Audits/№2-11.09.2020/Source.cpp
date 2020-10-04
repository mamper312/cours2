/*Сгенерировать рандомно 1 000 000 целых чисел.
Посчитать частоту появления чисел кратных 2, 3, ... 9. Вывести гистограмму.

Попробовать srand + rand, а также :
класс std::random_device
класс std::mt19937
класс std::uniform_int_distribution

Провести 10 экспериментов.
В чём отличия ?*/
#include <cstdlib>
#include <ctime>
#include<iostream>
#include <random>  
#include<string>
using namespace std;

void Histogram_Output(int mass[8], string function)
{
    int x = 0;
    cout << "function: " << function << endl;
    for (int i = 0; i < 8; i++)
    {
        x = mass[i] / 10000;
        cout << (i + 2) << " : ";
        for (int k = 0; k < x; k++)
            cout << "|";
        mass[i] = 0;
        cout << endl;
    }
}

void Rand_Srand(int mass[8])
{
    string function = "srand + rand";
    int count = 0;
    for (int i = 0; i < 1000000; i++)
    {
        count = 1 + rand();
        for (int j = 2; j < 10; j++)
        {
            if (count % j == 0)
            {
                j = j - 2;
                mass[j]++;
                j = j + 2;
            }
        }
    }
    Histogram_Output(mass, function);
}

void Rand_Device(int mass[8])
{
    random_device count;
    string function = " Random_device";
    for (int i = 0; i < 1000000; i++)
    {   
        for (int j = 2; j < 10; j++)
        {
            if (count() % j == 0)
            {
                j = j - 2;
                mass[j]++;
                j = j + 2;
            }
        }
    }
    Histogram_Output(mass, function);
}

void Mt19937(int mass[8])
{
    mt19937 count;
    //count.seed(time(0));
    string function = " mt19937";
    for (int i = 0; i < 1000000; i++)
    {
        for (int j = 2; j < 10; j++)
        {
            if (count() % j == 0)
            {
                j = j - 2;
                mass[j]++;
                j = j + 2;
            }
        }
    }
    Histogram_Output(mass, function);
}

void Uniform_Int_Distribution(int mass[8])
{
    random_device rand;
    uniform_int_distribution<> count;
    string function = " uniform_int_distribution";
    for (int i = 0; i < 1000000; i++)
    {
        for (int j = 2; j < 10; j++)
        {
            if (count(rand) % j == 0)
            {
                j = j - 2;
                mass[j]++;
                j = j + 2;
            }
        }
    }
    Histogram_Output(mass, function); 
}

int main()
{
    srand(time(NULL));
    int mass[8] = { NULL };
    for (int i = 0; i < 10; i++)
    {
        cout << ( i + 1 ) << "  : \n";
        Rand_Srand(mass);
        Mt19937(mass);
        Rand_Device(mass);
        Uniform_Int_Distribution(mass);
        cout << endl;
    }
    system("pause");
    return 0;
}