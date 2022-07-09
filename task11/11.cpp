#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;

int IterationCount = 0;

int main()
{
	setlocale(LC_ALL, "Russian");
	
	int n, m;
	cout << "Введите количество камней N = ";
	cin >> n;

	int* weight = new int[n];
	int* id = new int[n];
	cout << "Введите веса соответствующие камням\n";
	for (int i = 0; i < n; i++)
	{
		cin >> weight[i];
		id[i] = 0;
	}

	cout << "\nВведите количество куч M = ";
	cin >> m;

	
	int MinSum = 0; //минимальный вес самой тяжелой кучи
	for (int i = 0; i < n; i++)
	{
		MinSum += weight[i];//изначально присвоим значение суммы весов всех камней
	}

	cout << "\nВсевозможные комбинации размещения камней в кучах\nпервый столбец: позиция соответствует камню, а число куче\nвторой столбец: веса квмней распределенные по кучам\n";
	while (id[0] == 0)
	{
		//выводим комбинацию
		for (int i = 0; i < n; i++)
		{
			cout << id[i] << " ";
		}
		

		int MaxSum = 0; //вес самой тяжелой кучи 
		
		for (int mi = 0; mi < m; mi++)
		{
			cout << " (";
			int sum = 0;
			for (int i = 0; i < n; i++)
			{
				IterationCount++;

				if (id[i] == mi)
				{
					sum += weight[i];
					cout<< weight[i] << " ";
				}
			}

			if (sum == 0)
				cout << ")";
			else
				cout << "\b)";

			if (sum > MaxSum)
			{
				MaxSum = sum;
			}
		}

		cout << " наибольший вес кучи = " << MaxSum << endl;

		if (MinSum > MaxSum)
		{
			MinSum = MaxSum;
		}


		id[n - 1]++;

		int i = n - 1;
		while (id[i] >= m)
		{
			IterationCount++;

			int temp = id[i];
			id[i] = temp % m;
			id[i - 1] += temp / m;

			i--;
		}
	}

	cout << "минимальный вес самой тяжелой кучи = " << MinSum << endl;

	cout << "Количество итераций " << IterationCount << endl;

	return 0;

}