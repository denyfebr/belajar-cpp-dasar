//preprocessing directive

#include<iostream>

//macro merubah nilai dengan name
#define PI 3.14159265359
#define BAHASA "indonesia"

//macro untuk fungsi
#define KUADRAT(X) (X*X)
#define MAX(A,B) ((A > B) ? A:B)


//akhir dari preprocessing directive

using namespace std;

int main() {
	cout << "nilai PI: " << PI << endl;
	cout << "nilai Bahasa: " << BAHASA << endl;
	cout << "kuadrat:" << KUADRAT(5) << endl;
	int a, b;
	cout << "masukkan nilai A: ";
	cin >> a;
	cout << "masukkan nilai B: ";
	cin >> b;
	cout << "max: " << MAX(a, b) << endl;

	#undef BAHASA
	#define BAHASA "inggris"

	cout << "nilai Bahasa: " << BAHASA << endl;

}