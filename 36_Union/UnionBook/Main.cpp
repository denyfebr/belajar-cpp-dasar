#include <iostream>
using namespace std;
typedef union int_or_float {
	int n;
	float x;
} number;

int main() {
	number temp;
	temp.n = 4444;
	cout << "(a) temp.n = " << temp.n << " temp.x = " << temp.x << endl;
	temp.x = 4444.0;
	cout << "(b) temp.n = " << temp.n << " temp.x = " << temp.x << endl;
	temp.n = 4444;
	cout << "(b) temp.n = " << temp.n << " temp.x = " << temp.x << endl;
}