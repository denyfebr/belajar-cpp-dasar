#include <iostream>

using namespace std;

union nama {
	int int_value;
	char char_value[4];
};

int main() {

	nama data_nama;

	data_nama.int_value = 12345642;
	
	cout << "data int_value: " << data_nama.int_value << endl;
	cout << "data char_value: " << data_nama.char_value << endl;

	data_nama.char_value[0] = 'a';
	data_nama.char_value[1] = 'b';
	data_nama.char_value[2] = 'c';
	data_nama.char_value[3] = 'd';

	cout << "data int_value: " << data_nama.int_value << endl;
	cout << "data char_value: " << data_nama.char_value << endl;
}