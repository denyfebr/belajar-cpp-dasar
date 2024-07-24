#include<iostream>
using namespace std;

int main() {

	int n;
	cout << "Masukkan jumlah pola: " <<endl;
	cin >> n;

	cout << "===Pola I=== \n";
	for (int i = 0;i < n;i++) {		
		for (int j = 0;j <= i;j++) {
			cout << "*";
		}
		cout<<endl;
	}

	cout << "===Pola II=== \n";
	for (int i = 0;i < n;i++) {
		for (int j = n;j > i;j--) {
			cout << "*";
		}
		cout << endl;
	}

	cout << "===Pola III=== \n";
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < i;j++) {
			cout << " ";
		}
		for (int k = n;k > i;k--) {
			cout << "*";
		}
		cout << endl;
	}

	cout << "===Pola IV=== \n";
	for (int i = 0;i < n;i++) {

		for (int k = n-1;k > i;k--) {
			cout << " ";
		}

		for (int j = 0;j <= i;j++) {			
			cout << "*";
		}
		
		cout << endl;
	}

	cout << "===Pola V=== \n";
	for (int i = 0;i < n;i++) {

		for (int k = n - 1;k > i;k--) {
			cout << " ";
		}

		for (int j = 0;j <= i;j++) {
			cout << "*";
		}

		cout << endl;
	}

	cout << "===Pola VI=== \n";
	for (int i = 1;i <= n;i++) {

		for (int k = n;k > i;k--) {
			cout << " ";
		}

		for (int j = 1;j <= (2*i-1);j++) {
			cout << "*";
		}

		cout << endl;
	}

	cout << "===Pola VII=== \n";
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j < i;j++) {
			cout << " ";
		}
		for (int k = n;k >= (2*i-n);k--) {
			cout << "*";
		}
		cout << endl;
	}

	cout << "===Pola VIII=== \n";
	for (int i = 1;i <= n;i++) {

		for (int k = n;k > i;k--) {
			cout << " ";
		}

		for (int j = 1;j <= (2 * i - 1);j++) {
			cout << "*";
		}

		cout << endl;
	}
	for (int i = 2;i <= n;i++) {
		for (int j = 1;j < i;j++) {
			cout << " ";
		}
		for (int k = n;k >= (2 * i - n);k--) {
			cout << "*";
		}
		cout << endl;
	}

	return 0;
}