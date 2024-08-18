#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	fstream myFile;
	int number = 1;
	myFile.open("data.bin", ios::out, ios::binary);
	myFile.write(reinterpret_cast<char*>(&number), sizeof(number));
	myFile.close();
}