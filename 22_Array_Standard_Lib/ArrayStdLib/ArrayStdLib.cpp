#include <iostream>
#include <array>
#include <stdio.h>

using namespace std;

int main() {
    // membuat array dengan menggunakan standard library
    // array<int, jumlah array> nama array

    array<int, 5> nilai;

    for (int i = 0; i <= 4; i++) {
        nilai[i] = i;
        cout << "nilai [" << i << "] = " << nilai[i];
        cout << " address " << &nilai[i] << endl;
    }

    cout << endl;
    // ukuran array
    cout << "ukuran: " << nilai.size() << endl;

    // address awal dari array
    printf("address awal : %p\n", (void*)&nilai[0]);

    // address akhir dari array
    printf("address akhir: %p\n", (void*)&nilai[nilai.size() - 1]);

    // nilai ke-2 dari array
    cout << "nilai ke-2 : " << nilai.at(2) << endl;

    return 0;
}
