#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void Input(int[], int&);
void Search(int[], int);
void Standardize(int[], int);
int BinarySearch(int[], int, int, int);
int ExponentialSearch(int[], int, int);

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
		cout << ExponentialSearch(a, n, b[i]);
		cout << endl;
	}

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

int ExponentialSearch(int a[], int n, int x)
{ 
	if (a[0] == x)
		return 0;
	int i = 1;
	while (i < n && a[i] <= x)
		i = i * 2;
	return BinarySearch(a, i / 2, min(i, n), x);
}

int BinarySearch(int a[], int l, int r, int x)
{
	if (r >= l)
	{
		int mid = l + (r - l) / 2;
		if (a[mid] == x)
			return mid;
		if (a[mid] > x)
			return BinarySearch(a, l, mid - 1, x);
		return BinarySearch(a, mid + 1, r, x);
	}
	return -1;
}