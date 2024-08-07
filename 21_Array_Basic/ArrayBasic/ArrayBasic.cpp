#include <iostream>
using namespace std;

int main() {

	// membuat array
	int nilai[5];
	
	cout << nilai << endl << endl;

	nilai[0] = 0;
	nilai[1] = 1;
	nilai[2] = 2;
	nilai[3] = 3;
	nilai[4] = 4;

	cout << &nilai[0] << " nilainya adalah: " << nilai[0] << endl;
	cout << &nilai[1] << " nilainya adalah: " << nilai[1] << endl;
	cout << &nilai[2] << " nilainya adalah: " << nilai[2] << endl;
	cout << &nilai[3] << " nilainya adalah: " << nilai[3] << endl;
	cout << &nilai[4] << " nilainya adalah: " << nilai[4] << endl;

	//memodifikasi nilai array menggunakan pointernya
	int* ptr = nilai;
	*(ptr + 2) = 6;

	//memodifikasi nilai array dengan assignment ke index nya
	nilai[3] = 7;
	
	cout << endl;
	cout << &nilai[0] << " nilainya adalah: " << nilai[0] << endl;
	cout << &nilai[1] << " nilainya adalah: " << nilai[1] << endl;
	cout << &nilai[2] << " nilainya adalah: " << nilai[2] << endl;
	cout << &nilai[3] << " nilainya adalah: " << nilai[3] << endl;
	cout << &nilai[4] << " nilainya adalah: " << nilai[4] << endl;
	cout << endl;

	//mencari ukuran array
	cout << "ukuran array = " << sizeof(nilai) << " byte" << endl;
	cout << "jumlah member array = " << sizeof(nilai) / sizeof(int) << endl;
}