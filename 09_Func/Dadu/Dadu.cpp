#include<iostream>
#include<cstdlib>//randon fuct
using namespace std;

int main() {

	while(true) {
		char lanjut;
		cout << "Lempar dadu (y/n)";
		cin >> lanjut;
		if (lanjut == 'y') {
			cout << 1 + (rand() % 6) << endl;
		}
		else if (lanjut == 'n') {
			break;
		}
		else
		{
			cout << "Ketik y/n!\n";
		}
		
	}

	return 0;
}