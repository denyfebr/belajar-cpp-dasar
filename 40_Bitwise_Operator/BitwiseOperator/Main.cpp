#include<iostream>
#include<stdio.h>
#include<string>
#include<bitset>

using namespace std;

void printBinary(unsigned short val, string nama) {
	cout << nama << " = " << bitset<8>(val) << endl;
}

int main()
{
	unsigned short a = 6;
	unsigned short b = 10;
	unsigned short c;

	cout << "& - Bitwise AND (c = a & b)" << endl;
	c = a & b;
	printBinary(a, "a");
	printBinary(b, "b");
	printBinary(c, "c");
	printf("c = %d\n",c);

	cout << endl;

	cout << "| - Bitwise OR (c = a | b)" << endl;
	c = a | b;
	printBinary(a, "a");
	printBinary(b, "b");
	printBinary(c, "c");
	printf("c = %d\n", c);

	cout << endl;

	cout << "^ - Bitwise XOR (c = a ^ b)" << endl;
	c = a ^ b;
	printBinary(a, "a");
	printBinary(b, "b");
	printBinary(c, "c");
	printf("c = %d\n", c);

	cout << endl;

	cout << "~ - Bitwise NOT (c = ~a)" << endl;
	c = ~a;
	printBinary(a, "a");
	printBinary(c, "c");
	printf("c = %d\n", c);

	cout << endl;

	cout << "<< - SHL Shift bits left (c = a << 2)" << endl;
	c = a << 2;
	printBinary(a, "a");
	printBinary(c, "c");
	printf("c = %d\n", c);

	cout << endl;

	cout << ">> - SHR Shift bits right (c = a >> 2)" << endl;
	c = a >> 2;
	printBinary(a, "a");
	printBinary(c, "c");
	printf("c = %d\n", c);

	cout << endl;
	// bitwise operator
	// &	AND	Bitwise AND
	// |	OR	Bitwise inclusive OR
	// ^	XOR	Bitwise exclusive OR
	// ~	NOT	
	// <<	SHL	Shift bits left
	// >>	SHR	Shift bits right	
}