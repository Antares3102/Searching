#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void Input(int[], int&);
void BinarySearch(int[], int);
int BinarySearch(int[], int, int);
void Standardize(int[], int);

int main()
{
	int a[100];
	int n;
	Input(a, n);
	Standardize(a, n);
	BinarySearch(a, n);
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

void BinarySearch(int a[], int n)
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
		cout << BinarySearch(a, n, b[i]);
		cout << endl;
	}

}

int BinarySearch(int a[], int n, int x)
{
	int middle;
	int left = 0; 
	int right = n - 1;
	while (left <= right)
	{
		middle = (left + right) / 2;
		if (a[middle] == x)
			return middle;
		if (x > a[middle])
			left = middle + 1;
		else
			right = middle - 1;

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