#include<iostream>
using namespace std;

int fibonacci(int n);

int main()
{
	int angka, hasil;
	cout << "Menghitung fibonacci ke : " << endl;
	cin >> angka;
	hasil = fibonacci(angka);

	cout << "Nilainya adalah: " << endl;
	cout << hasil << endl;

}

int fibonacci(int n) {
	if ((n == 1) || (n == 0)) {
		return n;
	}
	else {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}