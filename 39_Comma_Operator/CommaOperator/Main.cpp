#include<iostream>
#include<string>

using namespace std;

int main() {
	int a;
	int b;
	int c;

	/*
		b = 1;
		c = 2;
		a = (b + c);
	*/
	
	a = (b = 1, cout << b << endl, c = 5, cout << c << endl, (b+c));

	cout << a << endl;
}