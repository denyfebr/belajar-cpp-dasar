#include <iostream>
#include <string>
using namespace std;

int main() {
	/*
	* char kata[4] = { 'u','c','u','p' };
	char kata_cmp[4] = { 'u','c','u','p' };

	if (kata == kata_cmp) {
		cout << "Sama" << endl;
	}
	TIDAK BISA
	*/

	string inputkata;
	string katarahasia("ucup");
	int pilih;

	while (true) {
		cout << "tebak nama : ";
		cin >> inputkata;

		if (inputkata == katarahasia) {
			cout << "tebakan anda benar!!" << endl;
			break;
		}

		cout << "tebakan anda salah!"<<endl;
		cout << "coba lagi ?" << endl;
		cout << "1. iya (ketik 1)" << endl;
		cout << "2. tidak (ketik 2)" << endl;
		cin >> pilih;

		if (pilih == 2) {
			break;
		}

	}
	cout << "program selesai" << endl;

}