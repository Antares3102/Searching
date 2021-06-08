#include <iostream>
#include <cmath>
using namespace std;

void Input(int[], int&);
void LinearSearch(int[], int);
int LinearSearch(int[], int, int);

int main()
{
	int a[100];
	int n;
	Input(a, n);
	LinearSearch(a, n);
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

void LinearSearch(int a[], int n)
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
		cout << "\nGia tri thu " << i << " : ";
		cin >> b[i];
	}

	cout << "\n\nVi tri gia tri can tim lan luot la: \n";
	for (int i = 0; i < Q; i++)
	{
		cout << LinearSearch(a, n, b[i]);
		cout << endl;
	}

}

int LinearSearch(int a[], int n, int x)
{
	for (int i = 0; i < n; i++)
		if (a[i] == x)
			return i;
	return -1;
}