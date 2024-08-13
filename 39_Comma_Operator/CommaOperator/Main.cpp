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
	
	a = (b = 1, c = 5, (b+c));

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;

}