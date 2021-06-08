#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void Input(int[], int&);
void JumpSearch(int[], int);
int JumpSearch(int[], int, int);
void Standardize(int[], int);

int main()
{
	int a[100];
	int n;
	Input(a, n);
	Standardize(a, n);
	JumpSearch(a, n);
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

void JumpSearch(int a[], int n)
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
		cout << JumpSearch(a, n, b[i]);
		cout << endl;
	}

}

int JumpSearch(int a[], int n, int x)
{
	int step = sqrt(n);
	int prev = 0;
	while (a[min(step, n) - 1] < x)
	{
		prev = step;
		step += sqrt(n);
		if (prev >= n)
			return -1;
	}

	while (a[prev] < x)
	{
		prev++; 
		if (prev == min(step, n))
			return -1;
	}

	if (a[prev] == x)
		return prev;

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