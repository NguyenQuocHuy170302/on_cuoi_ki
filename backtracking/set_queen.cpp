#include<iostream>

using namespace std;

int number_queen;
int** chessboad = NULL;

void initData();
void Cout();
bool check_set_queen(int row,int col);
void setQueen(int k);

int main()
{
	cin >> number_queen;

	chessboad = new int* [number_queen];
	for (size_t i = 0; i < number_queen; i++)
	{
		chessboad[i] = new int[number_queen];
	}

	initData();
	setQueen(0);
	return 0;
}

void initData()
{
	for (size_t i = 0; i <number_queen; i++)
	{
		for (size_t j = 0; j <number_queen ; j++)
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
	// check row
	for (size_t i = 0; i <col ; i++)
	{
		if (chessboad[row][i] == 1)
			return false;
	}
	//check col
	for (size_t i = 0; i < row; i++)
	{
		if (chessboad[i][col] == 1)
			return false;
	}
	//check diagonal top
	int count1 = 0;
	while (col-count1>=0&&row-count1>=0)
	{
		if (chessboad[row - count1][col - count1] == 1)
			return false;
		count1++;
	}
	//check diagonal bottom
	int count2 = 0;
	while (col-count2>=0&&row+count2<number_queen)
	{
		if (chessboad[col - count2][row + count2] == 1)
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
		if (check_set_queen(i, k) == true)
		{
			chessboad[i][k] = 1;

			if (k == number_queen - 1)
				Cout();
			else
				setQueen(k + 1);

		}
		chessboad[i][k] = 0;
	}
}