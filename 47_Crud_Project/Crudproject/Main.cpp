#include <iostream>
#include <string>
#include <fstream>
#include <limits>

using namespace std;

struct Mahasiswa {
    int pk;
    string NIM;
    string nama;
    string jurusan;
};

int getOption();
void checkDatabase(fstream& data);
void displayDataMahasiswa(fstream& data);
void updateDataMahasiswa(fstream& data);
void deleteDataMahasiswa(fstream& data);

void writeString(fstream& data, const string& str) {
    size_t length = str.size();
    data.write(reinterpret_cast<const char*>(&length), sizeof(length));
    if (length > 0) {
        data.write(str.c_str(), length);
    }
}

void readString(fstream& data, string& str) {
    size_t length;
    data.read(reinterpret_cast<char*>(&length), sizeof(length));

    // Check if length is too large, to prevent allocation errors
    if (length > 1000000) { // Adjust the maximum allowable length as needed
        throw std::runtime_error("String length too large, possible corruption.");
    }

    str.resize(length);
    if (length > 0) {
        data.read(&str[0], length);
    }
}


void writeData(fstream& data, int posisi, Mahasiswa& inputMahasiswa) {
    data.seekp(posisi, ios::beg);
    data.write(reinterpret_cast<char*>(&inputMahasiswa.pk), sizeof(inputMahasiswa.pk));
    writeString(data, inputMahasiswa.NIM);
    writeString(data, inputMahasiswa.nama);
    writeString(data, inputMahasiswa.jurusan);
}

int getDataSize(fstream& data) {
    data.seekg(0, ios::end);
    return data.tellg();
}

Mahasiswa readData(fstream& data, int posisi) {
    Mahasiswa readMahasiswa;
    data.seekg(posisi, ios::beg);
    data.read(reinterpret_cast<char*>(&readMahasiswa.pk), sizeof(readMahasiswa.pk));
    readString(data, readMahasiswa.NIM);
    readString(data, readMahasiswa.nama);
    readString(data, readMahasiswa.jurusan);
    return readMahasiswa;
}

void addDataMahasiswa(fstream& data) {
    Mahasiswa inputMahasiswa, lastMahasiswa;
    int size = getDataSize(data);

    if (size == 0) {
        inputMahasiswa.pk = 1;
    }
    else {
        data.seekg(-1 * (sizeof(int) + sizeof(size_t) * 3), ios::end);
        lastMahasiswa = readData(data, data.tellg());
        inputMahasiswa.pk = lastMahasiswa.pk + 1;
    }

    cout << "Nama: ";
    getline(cin, inputMahasiswa.nama);
    cout << "Jurusan: ";
    getline(cin, inputMahasiswa.jurusan);
    cout << "NIM: ";
    getline(cin, inputMahasiswa.NIM);

    writeData(data, data.tellp(), inputMahasiswa);
}

void displayDataMahasiswa(fstream& data) {
    Mahasiswa tampilMahasiswa;
    int size = getDataSize(data);
    int posisi = 0;

    data.seekg(0, ios::beg);  // Move to the beginning of the file

    cout << "\nData Mahasiswa:\n";
    while (posisi < size) {
        tampilMahasiswa = readData(data, posisi);
        cout << "PK       : " << tampilMahasiswa.pk << endl;
        cout << "NIM      : " << tampilMahasiswa.NIM << endl;
        cout << "Nama     : " << tampilMahasiswa.nama << endl;
        cout << "Jurusan  : " << tampilMahasiswa.jurusan << endl;
        cout << "=============================\n";
        posisi = data.tellg();
    }
}

void updateDataMahasiswa(fstream& data) {
    int pkToUpdate;
    Mahasiswa updatedMahasiswa;
    int posisi = 0;

    cout << "Masukkan PK yang ingin diubah: ";
    cin >> pkToUpdate;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    data.seekg(0, ios::beg);
    while (data.tellg() < getDataSize(data)) {
        int currentPos = data.tellg();
        Mahasiswa mhs = readData(data, currentPos);

        if (mhs.pk == pkToUpdate) {
            cout << "Data ditemukan:\n";
            cout << "PK       : " << mhs.pk << endl;
            cout << "NIM      : " << mhs.NIM << endl;
            cout << "Nama     : " << mhs.nama << endl;
            cout << "Jurusan  : " << mhs.jurusan << endl;

            cout << "\nMasukkan data baru:\n";
            updatedMahasiswa.pk = mhs.pk; // Keep the same PK
            cout << "Nama: ";
            getline(cin, updatedMahasiswa.nama);
            cout << "Jurusan: ";
            getline(cin, updatedMahasiswa.jurusan);
            cout << "NIM: ";
            getline(cin, updatedMahasiswa.NIM);

            writeData(data, currentPos, updatedMahasiswa);
            cout << "Data berhasil diubah.\n";
            return;
        }
        posisi = data.tellg();
    }
    cout << "Data dengan PK " << pkToUpdate << " tidak ditemukan.\n";
}

void deleteDataMahasiswa(fstream& data) {
    int pkToDelete;
    Mahasiswa mhs;
    fstream tempData;
    bool found = false;

    cout << "Masukkan PK yang ingin dihapus: ";
    cin >> pkToDelete;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    tempData.open("temp.bin", ios::out | ios::binary);
    data.seekg(0, ios::beg);

    while (data.tellg() < getDataSize(data)) {
        int currentPos = data.tellg();
        mhs = readData(data, currentPos);

        if (mhs.pk == pkToDelete) {
            cout << "Data dengan PK " << pkToDelete << " berhasil dihapus.\n";
            found = true;
        }
        else {
            writeData(tempData, tempData.tellp(), mhs);
        }
    }

    data.close();
    tempData.close();

    remove("data.bin");
    rename("temp.bin", "data.bin");

    if (!found) {
        cout << "Data dengan PK " << pkToDelete << " tidak ditemukan.\n";
    }
}

int main() {
    fstream data;
    checkDatabase(data);
    int pilihan = getOption();
    char is_continue;

    enum option { CREATE = 1, READ, UPDATE, DELETE, FINISH };

    while (pilihan != FINISH) {
        switch (pilihan) {
        case CREATE:
            cout << "Menambah data mahasiswa" << endl;
            addDataMahasiswa(data);
            break;
        case READ:
            cout << "Menampilkan data mahasiswa" << endl;
            displayDataMahasiswa(data);
            break;
        case UPDATE:
            cout << "Ubah data mahasiswa" << endl;
            updateDataMahasiswa(data);
            break;
        case DELETE:
            cout << "Hapus data mahasiswa" << endl;
            deleteDataMahasiswa(data);
            break;
        default:
            cout << "Pilihan tidak ditemukan" << endl;
            break;
        }

    label_continue:
        cout << "Lanjutkan?(y/n) : ";
        cin >> is_continue;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if ((is_continue == 'y') || (is_continue == 'Y')) {
            pilihan = getOption();
        }
        else if ((is_continue == 'n') || (is_continue == 'N')) {
            break;
        }
        else {
            goto label_continue;
        }
    }

    cout << "akhir dari program" << endl;
    cin.get();
    return 0;
}

int getOption() {
    int input;
    cout << "\nProgram CRUD data mahasiswa" << endl;
    cout << "=============================" << endl;
    cout << "1. Tambah" << endl;
    cout << "2. Tampilkan" << endl;
    cout << "3. Ubah" << endl;
    cout << "4. Hapus" << endl;
    cout << "5. Selesai" << endl;
    cout << "=============================" << endl;
    cout << "pilih [1-5]? : ";
    cin >> input;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return input;
}

void checkDatabase(fstream& data) {
    data.open("data.bin", ios::out | ios::in | ios::binary);

    if (!data) {
        // File not found, create a new one
        data.clear();
        data.open("data.bin", ios::trunc | ios::out | ios::in | ios::binary);
        if (!data) {
            throw std::runtime_error("Failed to create the database file.");
        }
        cout << "Database baru dibuat.\n";
    }
    else {
        cout << "Database ditemukan.\n";
    }
}


/*
To display data from the binary file, you need to read each `Mahasiswa` record sequentially and then print it to the console. The code below adds a function to display all the `Mahasiswa` data in the file:

### Explanation:
1. **displayDataMahasiswa Function**: This function reads each `Mahasiswa` record from the file and prints the contents to the console. It iterates through the file until all records are read.
2. **File Pointer Management**: The `data.seekg(0, ios::beg);` resets the file pointer to the beginning of the file, ensuring that all records are read sequentially.
3. **Loop Through Records**: The loop reads data from the file until the end of the file is reached. The position in the file is updated with each read operation using `data.tellg()`.

### Usage:
1. **Compile and Run**: After compiling, you can add multiple `Mahasiswa` entries using the "Tambah" option.
2. **Display Data**: Select the "Tampilkan" option to see all the stored `Mahasiswa` records printed on the console.

This approach correctly reads and displays all the student records stored in the binary file.
*/

/*
To implement an update function for modifying an existing `Mahasiswa` record in the binary file, you'll need to:

1. **Search for the record**: Find the record based on the primary key (`pk`) or another unique identifier.
2. **Update the fields**: Modify the relevant fields in the record.
3. **Rewrite the record**: Write the updated record back to the same position in the file.

### Explanation of the `updateDataMahasiswa` Function:

1. **Search for the Record**:
   - The function starts by prompting the user for the primary key (`pk`) of the record they want to update.
   - It iterates through the file, reading each record until it finds the one with the matching `pk`.

2. **Display the Current Record**:
   - If a matching record is found, its current values are displayed to the user.

3. **Update the Record**:
   - The user is prompted to enter new values for the `NIM`, `nama`, and `jurusan` fields. The `pk` remains unchanged.
   - The updated record is then written back to the same position in the file.

4. **Error Handling**:
   - If no record with the provided `pk` is found, a message is displayed indicating that the record was not found.

### Usage:

1. **Run the Program**: Compile and run the program as usual.
2. **Update Record**: Select the "Ubah" (Update) option, enter the `pk` of the record you want to update, and provide the new data.
3. **View Changes**: Use the "Tampilkan" (Display) option to verify that the record has been updated correctly.

This update method ensures that the correct record is modified without affecting other data in the file.
*/

/*
To implement a delete function for removing a `Mahasiswa` record from the binary file, you'll need to:

1. **Search for the record**: Identify the record you want to delete based on its primary key (`pk`).
2. **Rewrite the file**: Copy all records except the one to be deleted into a temporary file, then replace the original file with the temporary one.

### Implementation Steps

Here's how you can implement the `deleteDataMahasiswa` function and integrate it with your existing code:


### Explanation of the `deleteDataMahasiswa` Function:

1. **Search for the Record**:
   - The function starts by prompting the user for the primary key (`pk`) of the record they want to delete.
   - It then iterates through the file, reading each record.

2. **Create a Temporary File**:
   - As the function reads through the
*/