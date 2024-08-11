#include <iostream>
#include <string>

using namespace std;

struct aktor
{
	string nama;
	int tahun_lahir;
};

struct film
{
	string judul;
	string genre;
	int tahun;
	//struct aktor
	aktor pemeran_1;
	aktor pemeran_2;
	aktor pemeran_3;
};

int main() {
	aktor aktor1, aktor2, aktor3;
	film film1,film2;

	//buat aktor 1
	aktor1.nama = "Michael Otong";
	aktor1.tahun_lahir = 1992;

	//buat aktor 2
	aktor2.nama = "Sandra Bulog";
	aktor2.tahun_lahir = 1995;

	//buat aktor 3
	aktor3.nama = "Tom Hanks";
	aktor3.tahun_lahir = 1995;

	//buat film
	film1.judul = "Pengabdi wakanda";
	film1.genre = "Documenter";
	film1.tahun = 2018;
	film1.pemeran_1 = aktor1;
	film1.pemeran_2 = aktor2;

	film2.judul = "Saving Private Ryan";
	film2.genre = "Action";
	film2.tahun = 1998;
	film2.pemeran_1 = aktor1;
	film2.pemeran_3 = aktor3;

	cout << "Judul: " << film1.judul << endl;
	cout << "Genre: " << film1.genre << endl;
	cout << "Tahun: " << film1.tahun << endl;
	cout << "Nama Pemeran 1: " << film1.pemeran_1.nama << endl;
	cout << "Nama Pemeran 2: " << film1.pemeran_2.nama << endl;

	cout << endl;
	cout << "Judul: " << film2.judul << endl;
	cout << "Genre: " << film2.genre << endl;
	cout << "Tahun: " << film2.tahun << endl;
	cout << "Nama Pemeran 1: " << film2.pemeran_1.nama << endl;
	cout << "Nama Pemeran 2: " << film2.pemeran_3.nama << endl;
}