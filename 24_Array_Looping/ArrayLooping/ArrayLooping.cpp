#include <iostream>
#include <array>
using namespace std;

int main() {

	//int arrayNilai[10] = { 0,1,2,3,4,5,6,7,8,9 };

	array <int, 10> arrayNilai = { 0,1,2,3,4,5,6,7,8,9 };

	for (int nilai : arrayNilai) {
		cout << "address "<< &nilai <<" nilainya: "<< nilai << endl;

		nilai = 1; //tidak merubah apapun
	}

	cout << endl;
	// Memanipulasi array dengan menggunakan referensi
	for (int &nilaiRef : arrayNilai) {
		nilaiRef *= 2;
	}

	cout << endl;

	for (int& nilaiRef : arrayNilai) {
		cout << "address " << &nilaiRef << "nilainya: " << nilaiRef << endl;
	}

}
