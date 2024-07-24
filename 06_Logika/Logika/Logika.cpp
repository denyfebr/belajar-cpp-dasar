#include <iostream>
using namespace std;
int main()
{
    int a = 3;
    int b = 2;

    bool hasil;

    //not
    hasil = !(a == 3);

    //And
    hasil = (a == 3) and (b == 2); //true and true
    cout << hasil << endl;
    hasil = (a == 4) and (b == 2); //false and true
    cout << hasil << endl;
    hasil = (a == 3) and (b == 3); //true and false
    cout << hasil << endl;
    hasil = (a == 4) and (b == 3); //false and false
    cout << hasil << endl;

    cout << hasil << endl;
}
