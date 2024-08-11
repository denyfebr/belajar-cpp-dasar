#include <iostream>
#include <string>
using namespace std;

int main() {
	string kalimat_input;

	//getline(cin,variabel)
	std::cout << "masukkan kalimat: " << endl;
	std::getline(std::cin, kalimat_input);

	std::cout <<"hasil kalimat:" << kalimat_input << std::endl;

	//jumlah kata dari input
	int posisi = 0;
	int jumlah = 0;

	while (true) {
		posisi = kalimat_input.find(" ", posisi+1);
		jumlah++;
		//cout << "posisi: " << posisi << " jumlah: " << endl;
		if (posisi < 0) {
			break;
		}
	}
	cout << "jumlah kata :" << jumlah << endl;
}