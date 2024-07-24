#include <iostream>
using namespace std;

int main()
{
    int a = 6;
    int b = 4;
    int hasil;
    //operatornya +, -, *, /, %

    //penjumlahan
    cout << "== Penjumlahan ==" << endl;
    hasil = a + b;
    cout << a << " + "<< b <<" = " << hasil << endl;

    //pengurangan
    cout << "== Pengurangan ==" << endl;
    hasil = a - b;
    cout << a << " - " << b << " = " << hasil << endl;

    //perkalian
    cout << "== Perkalian ==" << endl;
    hasil = a * b;
    cout << a << " * " << b << " = " << hasil << endl;

    //division
    cout << "== Pembagian ==" << endl;
    hasil = a / b;
    cout << a << " / " << b << " = " << hasil << endl;

    //modulus
    cout << "== Modulo ==" << endl;
    hasil = a % b;
    cout << a << " % " << b << " = " << hasil << endl;
}