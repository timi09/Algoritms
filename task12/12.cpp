#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;


int IterationCount = 0;

int getMinStack(int* stack_weight, int stack_count)
{
	int min_stack = 0;
	for (int i = 0; i < stack_count; i++)
	{
		IterationCount++;
		if (stack_weight[min_stack] > stack_weight[i])//находим минимальную кучу
		{
			min_stack = i;
		}
	}

	return min_stack;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int n, m;
	cout << "Введите количество камней N = ";
	cin >> n;
	int* stone_weight = new int[n];
	int* stone_id = new int[n];

	cout << "Введите веса соответствующие камням\n"; //Веса должны быть расположены по убыванию либо нужно применить сортировку
	for (int i = 0; i < n; i++)
	{
		cin >> stone_weight[i];
		stone_id[i] = 0;
	}

	cout << "\nВведите количество куч M = ";
	cin >> m;
	int* stack_weight = new int[m];
	for (int i = 0; i < m; i++)
	{
		stack_weight[i] = 0;
	}

	for (int i = 0; i < n; i++)
	{
		IterationCount++;

		int min_stack = 0;

		if (i < m)
		{
			min_stack = i;
		}
		else if(i == m)
		{
			min_stack = i-1;
		}
		else
		{
			min_stack = getMinStack(stack_weight, m);
		}

		stone_id[i] = min_stack;
		stack_weight[min_stack] += stone_weight[i];
	}

	int MaxSum = 0;
	for (int i = 0; i < m; i++)
	{
		IterationCount++;

		if (stack_weight[i] > MaxSum)
		{
			MaxSum = stack_weight[i];
		}
	}

	cout << "минимальный вес самой тяжелой кучи = " << MaxSum << endl;

	cout << "Количество итераций " << IterationCount << endl;

	return 0;

}
