#include <iostream>
using namespace std;

int x = 10; //variable

int ambil_global() {
    return x; //mengambil variable global
}

int x_local() {
    int x = 5; //varibel local scopenya x_local()
    return x;
}

int main()
{
    cout << "1. variable global : " << x << endl;
    int x = 8; //variable local untuk main
    cout << "2. variable local main : " << x << endl;
    cout << "3. variable ambil_global : " << ambil_global() << endl;
    cout << "4. variable local main : " << x << endl;
    cout << "5. variable x_local : " << x_local() << endl;
    cout << "6. variable local main : " << x << endl;

    cout << "7. variable local main : " << x << endl;
    {
        cout << "8. variable local main : " << x << endl;
        //block scope
        int x = 1;
        cout << "9. variable local block : " << x << endl;
        cout << "10. variable global : " << ::x << endl;
    }
    cout << "10. variable local main : " << x << endl;
}