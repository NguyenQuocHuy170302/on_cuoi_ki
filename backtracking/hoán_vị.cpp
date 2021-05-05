#include<iostream>

using namespace std;

int n;
int* arr = NULL;
bool* check = NULL;

void Cout();
void set(int k);

int main()
{
	cin >> n;

	arr = new int[n];
	check = new bool[n];

	for (size_t i = 0; i < n; i++)
	{
		check[i] = true;
	}

	set(0);
	return 0;
}

void Cout()
{
	for (size_t i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void set(int k)
{
	for (size_t i = 0; i < n; i++)
	{
		if (check[i] == true)
		{
			arr[k] = i+1;
			check[i] = false;
			if (k == n - 1)
				Cout();
			else
				set(k + 1);

			check[i] = true;
		}
	}
}
