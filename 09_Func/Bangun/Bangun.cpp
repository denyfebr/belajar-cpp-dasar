#include<iostream>
using namespace std;

double hitung_luas(double p, double l) {
	double luas = p * l;
	return luas;
}

double hitung_keliling(double p, double l) {
	double keliling = 2 * (p + l);
	return keliling;
}

void tampilkan_luas(double p, double l) {
	cout << "Menggunakan void: \n";
	cout << "Luasnya adalah: ";
	cout << hitung_luas(p, l);
}

int main() {

	double panjang, lebar;
	cout << "Panjang : ";
	cin >> panjang;
	cout << "Lebar : ";
	cin >> lebar;

	cout << "Luasnya adalah: ";
	cout << hitung_luas(panjang, lebar) << endl;
	cout << "Kelilingnya adalah: ";
	cout << hitung_keliling(panjang, lebar) << endl;
	return 0;
}