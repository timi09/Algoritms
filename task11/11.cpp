#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;

int IterationCount = 0;

int main()
{
	setlocale(LC_ALL, "Russian");
	
	int n, m;
	cout << "������� ���������� ������ N = ";
	cin >> n;

	int* weight = new int[n];
	int* id = new int[n];
	cout << "������� ���� ��������������� ������\n";
	for (int i = 0; i < n; i++)
	{
		cin >> weight[i];
		id[i] = 0;
	}

	cout << "\n������� ���������� ��� M = ";
	cin >> m;

	
	int MinSum = 0; //����������� ��� ����� ������� ����
	for (int i = 0; i < n; i++)
	{
		MinSum += weight[i];//���������� �������� �������� ����� ����� ���� ������
	}

	cout << "\n������������ ���������� ���������� ������ � �����\n������ �������: ������� ������������� �����, � ����� ����\n������ �������: ���� ������ �������������� �� �����\n";
	while (id[0] == 0)
	{
		//������� ����������
		for (int i = 0; i < n; i++)
		{
			cout << id[i] << " ";
		}
		

		int MaxSum = 0; //��� ����� ������� ���� 
		
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

		cout << " ���������� ��� ���� = " << MaxSum << endl;

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

	cout << "����������� ��� ����� ������� ���� = " << MinSum << endl;

	cout << "���������� �������� " << IterationCount << endl;

	return 0;

}