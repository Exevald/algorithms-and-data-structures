#include <iostream>
#include <fstream>
#define ItemType int
#define ItemCount 1000

using namespace std;

void Surface(int array[], int i, int k)
{
	int j, m, copy;
	copy = array[i];
	m = 2 * i;
	while (m <= k)
	{
		if (m == k)
		{
			j = m;
		}
		else
		{
			if (array[m] > array[m + 1])
			{
				j = m;
			}
			else
			{
				j = m + 1;
			}
		}
		if (array[j] > copy)
		{
			array[i] = array[j];
			i = j;
			m = 2 * i;
		}
		else
		{
			break;
		}
	}
	array[i] = copy;
}

void Sort(int array[], int n)
{
	int i, k, w;
	for (int i = n / 2; i >= 1; i--)
	{
		Surface(array, i, n);
		for (int k = n; i >= 1; i--)
		{
			Surface(array, 0, k);
			w = array[k];
			array[k] = array[0];
			array[0] = w;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << endl;
	}
}

int main()
{
	ItemType item;
	ifstream inputFile("input.txt");

	int itemArray[ItemCount] = {};
	int i = 0;
	int count = 0;

	if (!inputFile.is_open())
	{
		puts("Error for opeing file input.txt");
		return 1;
	}
	else
	{
		if (!inputFile.eof())
		{
			inputFile >> count;
			do
			{
				inputFile >> item;
				itemArray[i] = item;
				i++;
			} while (!inputFile.eof());
		}
		Sort(itemArray, count - 1);
	}

	return 0;
}
