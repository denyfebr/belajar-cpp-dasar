#include <iostream>
using namespace std;

/*Prototype function*/
//Default argument atau nilai standard nya
double volume_kubus(double p = 1, double l = 1, double t = 1);

int main()
{
    cout << "Volume kubus 1: " << volume_kubus(3, 4, 5) << endl;
    cout << "Volume kubus 2: " << volume_kubus(3, 4) << endl;
    cout << "Volume kubus 3: " << volume_kubus(3) << endl;
    cout << "Volume kubus 4: " << volume_kubus() << endl;
}


double volume_kubus(double p, double l, double t) {
    return p * l * t;
}
