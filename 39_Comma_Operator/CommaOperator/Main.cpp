#include<iostream>
#include<string>

using namespace std;

void printData(int val) {
	cout << val << endl;
}

int main() {
	int a;
	int b;
	int c;

	/*
		b = 1;
		c = 2;
		a = (b + c);
	*/
	
	a = (b = 1, printData(b), c = 5, printData(c), (b+c));

	cout << a << endl;
}