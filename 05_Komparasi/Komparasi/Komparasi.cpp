#include <iostream>
using namespace std;

int main()
{
	int a = 2;
	int b = 2;

	bool hasil1, hasil2;

	//komparasi, relation komparasion

	//sebanding
	hasil1 = (a == b);
	cout << hasil1 << endl;

	//tidak sebanding
	hasil2 = (a != b);
	cout << hasil2 << endl;

	//kurang dari
	hasil1 = (a < b);
	cout << hasil1 << endl;

	//lebih dari
	hasil2 = (a > b);
	cout << hasil2 << endl;

	//kurang dari sama dengan
	hasil1 = (a <= b);
	cout << hasil1 << endl;

	//lebih dari sama dengan
	hasil2 = (a >= b);
	cout << hasil2 << endl;

}
