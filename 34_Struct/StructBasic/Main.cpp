#include <iostream>
#include <string>

using namespace std;

//Struct: data yang dibentuk oleh beberapa data
struct buah
{
	string warna;
	float berat;
	int harga;
	string rasa;
};

int main() {

	buah apel;

	apel.warna = "Merah";
	apel.berat = 250.76f;
	apel.harga = 45000;
	apel.rasa = "Asem ketek";
	cout << "Apel" << endl;
	cout << "Warna : " << apel.warna << endl;
	cout << "Berat : " << apel.berat << endl;
	cout << "Harga : " << apel.harga << endl;
	cout << "Rasa : " << apel.rasa << endl;

	cout << endl;
	buah jeruk;

	jeruk.warna = "Orange";
	jeruk.berat = 135.88f;
	jeruk.harga = 35700;
	jeruk.rasa = "Manis legit";
	cout << "Jeruk" << endl;
	cout << "Warna : " << jeruk.warna << endl;
	cout << "Berat : " << jeruk.berat << endl;
	cout << "Harga : " << jeruk.harga << endl;
	cout << "Rasa : " << jeruk.rasa << endl;

}