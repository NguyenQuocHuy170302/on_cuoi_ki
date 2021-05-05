
/*"Viết chương trình trong tất cả mật khẩu từ một tập ký tự. Các ký tự trong tập có thể không được sử dụng bất kỳ lần nào hoặc nếu được sử dụng thì mỗi ký tự chỉ được sử dụng 1 lần.
Đầu vào :
-Dòng đầu chứa số nguyên n là tối đa độ dài của mật khẩu. (n <= 10)
- Dòng thứ 2 chứa một chuỗi ký tự có thể hiện các ký tự của tập hợp.Các ký tự trong s không trùng lặp và đã được sắp xếp xếp theo từ điển thứ tự.
Đầu tiên : Tất cả các xâu có độ dài tối đa là n từ các kí tự trong tập.Trong mỗi chuỗi trên một dòng, các chuỗi có độ dài ngắn trước, các chuỗi có độ dài bằng nhau trong từ điển thứ tự.*/


#include<iostream>
#include<string>

using namespace std;

int n;
string s;
bool* check;
int* arr;

void initData();
void Cout(int size);
void set_pos(int size, int k);


int main()
{
	cin >> n;
	cin.ignore();

	getline(cin, s);
	check = new bool[s.size()];
	arr = new int[s.size()];

	initData();
	for (size_t i = 1; i <= n; i++)
	{
		set_pos(i, 0);
	}


	return 0;
}

void initData()
{
	for (size_t i = 0; i < s.size(); i++)
	{
		check[i] = true;
		arr[i] = -1;
	}
}

void Cout(int size)
{
	string temp;

	for (size_t i = 0; i < size; i++)
	{
		temp += s[arr[i]];
	}
	cout << temp << endl;
}

void set_pos(int size, int k)
{
	for (size_t i = 0; i < s.size(); i++)
	{
		if (check[i] == true)
		{
			arr[k] = i;
			check[i] = false;

			if (k == size - 1)
			{
				Cout(size);
			}
			else
				set_pos(size, k + 1);

			check[i] = true;
		}
	}
}
