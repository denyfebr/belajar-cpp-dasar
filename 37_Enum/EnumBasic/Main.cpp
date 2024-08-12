#include <iostream>
using namespace std;

enum warna {
	merah, putih, hitam, coklat = 5, kuning, biru
};

int main() {
	warna kain;
	kain = coklat;

	if (kain == coklat) {
		cout << "warna kain coklat : " << endl;
	}

	cout << kain << endl;
}