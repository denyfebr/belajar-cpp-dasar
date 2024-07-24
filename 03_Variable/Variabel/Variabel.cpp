#include <iostream>

using namespace std;

int main()
{
    
    int b;
    cout << "Masukkan nilai : ";
    cin >> b;
    cout << "Nilai yang Anda masukkan : ";
    cout << b << endl;
    cout << "Besar angka b adalah : " << sizeof(b) << " byte"<< endl;
    cout << "Maximum bit : " << numeric_limits<int>::max() << endl;

}