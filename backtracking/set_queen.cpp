#include<iostream>

using namespace std;

int number_queen;
int** chessboad = NULL;
bool* check = NULL;
int cOunt = 0;

void initData();
void Cout();
bool check_set_queen(int row, int col);
void setQueen(int k);

int main()
{
	cin >> number_queen;
	check = new bool[number_queen];

	chessboad = new int* [number_queen];
	for (size_t i = 0; i < number_queen; i++)
	{
		check[i] = true;
		chessboad[i] = new int[number_queen];
	}

	initData();
	setQueen(0);
	cout << cOunt;
	return 0;
}

void initData()
{
	for (size_t i = 0; i < number_queen; i++)
	{
		for (size_t j = 0; j < number_queen; j++)
		{
			chessboad[i][j] = 0;
		}
	}
}

void Cout()
{
	for (size_t i = 0; i < number_queen; i++)
	{
		for (size_t j = 0; j < number_queen; j++)
		{
			cout << chessboad[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

bool check_set_queen(int row, int col)
{
	//check diagonal top
	int count1 = 0;
	while (col - count1 >= 0 && row - count1 >= 0)
	{
		if (chessboad[row - count1][col - count1] == 1)
			return false;
		count1++;
	}
	//check diagonal bottom
	int count2 = 0;
	while (col - count2 >= 0 && row + count2 < number_queen)
	{
		if (chessboad[row + count2][col - count2] == 1)
			return false;
		count2++;
	}

	// if check all true ->return true
	return true;
}

void setQueen(int k)
{
	for (size_t i = 0; i < number_queen; i++)
	{
		if (check[i] == true)
		{
			if (check_set_queen(i, k) == true)
			{
				check[i] = false;

				chessboad[i][k] = 1;

				if (k == number_queen - 1)
				{
					Cout();
					cOunt++;
				}
				else
					setQueen(k + 1);

				chessboad[i][k] = 0;
			}
			check[i] = true;
		}
	}
}