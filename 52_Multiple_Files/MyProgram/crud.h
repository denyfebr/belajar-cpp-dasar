#include <iostream>
#include <fstream>
#include <string>

namespace crud
{
    struct Data
    {
        int id;
        char name[50]; // Array fixed size untuk nama
    };

    void createData();
    void readData();
    void updateData();
    void deleteData();
}
