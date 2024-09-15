#include <iostream>
#include <fstream>
#include <string>
#include "crud.h"

void crud::createData()
{
    crud::Data data;
    std::ofstream file("data.bin", std::ios::binary | std::ios::app);

    std::cout << "Masukkan ID: ";
    std::cin >> data.id;
    std::cin.ignore(); // Mengabaikan karakter newline setelah ID
    std::cout << "Masukkan Nama: ";
    std::cin.getline(data.name, 50);

    file.write(reinterpret_cast<char *>(&data), sizeof(Data));
    file.close();
    std::cout << "Data berhasil ditambahkan!\n";
}

void crud::readData()
{
    crud::Data data;
    std::ifstream file("data.bin", std::ios::binary);

    if (file.is_open())
    {
        std::cout << "Data yang tersimpan:\n";
        while (file.read(reinterpret_cast<char *>(&data), sizeof(Data)))
        {
            std::cout << "ID: " << data.id << ", Nama: " << data.name << std::endl;
        }
        file.close();
    }
    else
    {
        std::cout << "Tidak ada data yang tersedia.\n";
    }
}

void crud::updateData()
{
    crud::Data data;
    std::fstream file("data.bin", std::ios::binary | std::ios::in | std::ios::out);
    int idUpdate;
    bool found = false;

    std::cout << "Masukkan ID yang akan diupdate: ";
    std::cin >> idUpdate;
    std::cin.ignore(); // Mengabaikan karakter newline

    while (file.read(reinterpret_cast<char *>(&data), sizeof(Data)))
    {
        if (data.id == idUpdate)
        {
            found = true;
            std::cout << "Masukkan Nama baru: ";
            std::cin.getline(data.name, 50);
            file.seekp(-static_cast<int>(sizeof(Data)), std::ios::cur);
            file.write(reinterpret_cast<char *>(&data), sizeof(Data));
            break;
        }
    }

    file.close();

    if (found)
    {
        std::cout << "Data berhasil diupdate!\n";
    }
    else
    {
        std::cout << "ID tidak ditemukan.\n";
    }
}

void crud::deleteData()
{
    crud::Data data;
    std::ifstream file("data.bin", std::ios::binary);
    std::ofstream temp("temp.bin", std::ios::binary);
    int idDelete;
    bool found = false;

    std::cout << "Masukkan ID yang akan dihapus: ";
    std::cin >> idDelete;

    while (file.read(reinterpret_cast<char *>(&data), sizeof(Data)))
    {
        if (data.id != idDelete)
        {
            temp.write(reinterpret_cast<char *>(&data), sizeof(Data));
        }
        else
        {
            found = true;
        }
    }

    file.close();
    temp.close();

    remove("data.bin");
    rename("temp.bin", "data.bin");

    if (found)
    {
        std::cout << "Data berhasil dihapus!\n";
    }
    else
    {
        std::cout << "ID tidak ditemukan.\n";
    }
}