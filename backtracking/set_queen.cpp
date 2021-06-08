#include<iostream>
#include<vector>

using namespace std;

int Count = 0;

bool checkSetQueen(vector<int>queen, int pos, int k)
{
	for (size_t i = 0; i < k; i++)
	{
		if (pos == queen[i] || abs(pos - queen[i]) == k - i) {
			return false;
		}
	}
	return true;
}

void Cout(vector<int>queen) {
	for (size_t i = 0; i < queen.size(); i++)
	{
		for (size_t j = 0; j < queen.size(); j++)
		{
			if (j == queen[i])
				cout << "1" << " ";
			else
				cout << "0" << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void setQueen(vector<int>queen, int k) {
	for (size_t i = 0; i < queen.size(); i++)
	{
		if (checkSetQueen(queen, i, k))
		{
			queen[k] = i;
			if (k == queen.size() - 1)
			{
				//Cout(queen);
				Count++;
			}
			else
				setQueen(queen, k + 1);
		}
	}
}

int main() {
	vector<int>queen;
	int n;
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		queen.push_back(-1);
	}
	setQueen(queen, 0);
	cout << Count;
	return 0;
}