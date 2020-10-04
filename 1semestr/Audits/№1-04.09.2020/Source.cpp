/*Считать из файла input.txt(подготовить самостоятельно) массив строк.
Удалить дубликаты, вывести в консоль.
Отсортировать по алфавиту, вывести в консоль.*/
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	string* mass;
	int size = 0;
	string buf;
	ifstream input;
	input.open("input.txt");
	if (!input.is_open())
		return 3;
	while (!input.eof())
	{
		getline(input, buf, '\n');
		size++;
	}
	mass = new string[size];
	input.close();
	input.open("input.txt");
	while (!input.eof())
	{
		for (int i = 0; i < size; i++) 
		{
			getline(input, buf);
			mass[i] = buf;
			for (int j = 0; j < i; j++) 
			{
				if (mass[j] == buf) 
				{
					size--;
					i--;
					break;
				}
			}
		}
	}
	for (int i = 0; i < size; i++)
		cout << mass[i] << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
		{
			if (mass[i] < mass[j])
			{
				buf = mass[i];
				mass[i] = mass[j];
				mass[j] = buf;
			}
		}
	}
	for (int i = 0; i < size; i++)
		cout << mass[i] << endl;
	input.close();
	system("pause");
	return 0;
}