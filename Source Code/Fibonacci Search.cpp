#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void Input(int[], int&);
void Search(int[], int);
int FibonacciSearch(int[], int, int);
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
		cout << FibonacciSearch(a, n, b[i]);
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
int FibonacciSearch(int a[], int n, int x)
{
    int fibMMm2 = 0; 
    int fibMMm1 = 1; 
    int fibM = fibMMm2 + fibMMm1; 

    while (fibM < n) 
	{
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    int offset = -1;

    while (fibM > 1) {
        int i = min(offset + fibMMm2, n - 1);
        if (a[i] < x) 
        {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
        else if (a[i] > x) 
        {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
        else
            return i;
    }
    if (fibMMm1 && a[offset + 1] == x)
        return offset + 1;
    return -1;
}
