#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void Input(int[], int&);
void Search(int[], int);
int InterPolationSearch(int[], int, int);
void Standardize(int[], int);

int main()
{
	int a[100];
	int n;
	Input(a, n);
	Standardize(a, n);
	Search(a, n);
	system("pause");
	return 0;
}

void Input(int a[], int& n)
{
	cout << "Nhap so phan tu mang: ";
	cin >> n;
	if (n <= 0)
	{
		do
		{
			cout << "\nGia tri nhap vao khong hop le! \nNhap so lon hon 0: ";
			cin >> n;
		} while (n <= 0);
	}
	cout << "\nNhap cac phan tu cua mang: ";
	for (int i = 0; i < n; i++)
	{
		cout << "\na[" << i << "] = ";
		cin >> a[i];
	}
}

void Search(int a[], int n)
{
	int Q;
	cout << "Nhap so luong phan tu can tim: ";
	cin >> Q;
	if (Q <= 0)
	{
		do
		{
			cout << "\nGia tri nhap vao khong hop le! \nNhap so lon hon 0: ";
			cin >> Q;
		} while (Q <= 0);
	}
	int b[100];
	cout << "\nNhap cac gia tri can tim: ";
	for (int i = 0; i < Q; i++)
	{
		cout << "\nGia tri thu " << i + 1 << " : ";
		cin >> b[i];
	}

	cout << "\n\nVi tri gia tri can tim lan luot la: \n";
	for (int i = 0; i < Q; i++)
	{
		cout << InterPolationSearch(a, n, b[i]);
		cout << endl;
	}

}

int InterPolationSearch(int a[], int n, int x)
{
	int left = 0;
	int right = n - 1;
	while (left <= right && x >= a[left] && x <= a[right])
	{
		double val1 = (double)(x - a[left]) / (a[right] - a[left]);
		int val2 = (right - left);
		int pos = left + val1 * val2;

		if (a[pos] == x)
			return pos;

		if (a[pos] < x)
			left = pos + 1;
		else
			right = pos - 1;
	}
	return -1;
}

void Standardize(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				swap(a[i], a[j]);
			}
		}
	}
	cout << "\nDay sau khi chuan hoa:  ";
	for (int i = 0; i < n; i++)
		cout << a[i] << "   ";
	cout << endl;
}

