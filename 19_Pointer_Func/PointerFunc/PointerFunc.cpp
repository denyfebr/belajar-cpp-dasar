#include <iostream>
using namespace std;

void fungsi(int*);
void kuadrat(int*);

int main() {

	int a = 5;
	cout << "address a " << &a << endl;
	cout << "  nilai a " << a << endl;

	fungsi(&a); //fungsi dengan input pointer
	cout << endl;
	kuadrat(&a);
	cout << "  nilai a " << a << endl;
}

void fungsi(int* b) {
	cout << "address b " << b << endl;
	cout << "  nilai b " << *b << endl; // deferencing
}

void kuadrat(int* valPtr) {
	*valPtr = (*valPtr) * (*valPtr);
}
