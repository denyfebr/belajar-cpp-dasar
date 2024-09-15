#include <iostream>
#include <fstream>
#include <string>
#include "crud.h"

int main()
{
	int pilihan;

	do
	{
		std::cout << "\nSistem CRUD Sederhana (Biner)\n";
		std::cout << "1. Tambah Data\n";
		std::cout << "2. Tampilkan Data\n";
		std::cout << "3. Update Data\n";
		std::cout << "4. Hapus Data\n";
		std::cout << "0. Keluar\n";
		std::cout << "Pilih opsi: ";
		std::cin >> pilihan;

		switch (pilihan)
		{
		case 1:
			crud::createData();
			break;
		case 2:
			crud::readData();
			break;
		case 3:
			crud::updateData();
			break;
		case 4:
			crud::deleteData();
			break;
		case 0:
			std::cout << "Keluar dari program.\n";
			break;
		default:
			std::cout << "Opsi tidak valid.\n";
			break;
		}
	} while (pilihan != 0);

	return 0;
}
