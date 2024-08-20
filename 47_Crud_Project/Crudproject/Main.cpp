#include<iostream>
#include<string>
#include<fstream>

using namespace std;

struct Mahasiswa {
	int pk;
	string NIM;
	string nama;
	string jurusan;
};

int getOption();
void checkDatabase(fstream& data);

void addDataMahasiswa(fstream& data) {

	Mahasiswa inputMahasiswa;

	inputMahasiswa.pk = 1;

	cout << "Nama: ";
	getline(cin, inputMahasiswa.nama);
	cout << "Jurusan: ";
	getline(cin, inputMahasiswa.jurusan);
	cout << "NIM: ";
	getline(cin, inputMahasiswa.NIM);
}

int main() {

	fstream data;

	checkDatabase(data);

	int pilihan = getOption();
	char is_continue;

	enum option {CREATE=1,READ,UPDATE,DELETE,FINISH};

	while (pilihan != FINISH) {
		switch (pilihan)
		{
			case CREATE:
				cout << "Menambah data mahasiswa" << endl;
				addDataMahasiswa(data);
				break;
			case READ:
				cout << "Menampilkan data mahasiswa" << endl;
				break;
			case UPDATE:
				cout << "Ubah data mahasiswa" << endl;
				break;
			case DELETE:
				cout << "Hapus data mahasiswa" << endl;
				break;
			default:
				cout << "Pilihan tidak ditemukan" << endl;
				break;
		}

		label_continue:
			cout << "Lanjutkan?(y/n) : ";
			cin >> is_continue;
			if ((is_continue == 'y') | (is_continue == 'Y')) {
				pilihan = getOption();
			}
			else if ((is_continue == 'n') | (is_continue == 'N')) {
				break;
			}
			else {
				goto label_continue;
			}
	}

	cout << "akhir dari program" << endl;

	cin.get();
	return 0;
}

int getOption() {

	int input;
	//system("cls");

	cout << "\nProgram CRUD data mahasiswa" << endl;
	cout << "=============================" << endl;
	cout << "1. Tambah" << endl;
	cout << "2. Tampilkan" << endl;
	cout << "3. Ubah" << endl;
	cout << "4. Hapus" << endl;
	cout << "5. Selesai" << endl;
	cout << "=============================" << endl;
	cout << "pilih [1-5]? : ";
	cin >> input;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return input;
}

void checkDatabase(fstream& data) {
	data.open("data.bin", ios::out | ios::in | ios::binary);

	//Check file ada atau tidak
	if (data.is_open()) {
		cout << "Database ditemukan";
	}
	else {
		cout << "Database tidak ditemukan, buat database baru";
		data.close();
		data.open("data.bin", ios::trunc | ios::out | ios::in | ios::binary);
	}

}
