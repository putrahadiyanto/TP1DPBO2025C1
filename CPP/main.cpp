/*Saya Putra Hadiyanto Nugroho dengan NIM 2308163 mengerjakan
 soal Latihan Modul 1 dalam mata kuliah Desain Pemrograman Berbasis Objek
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
#include "Petshop.cpp"
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int choice;
    list<Petshop> listPetshop;
    
    while(choice != 6)
    {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        cout << "List Menu Petshop : " << endl;
        cout << "1. View Data Petshop" << endl;
        cout << "2. Add Data Petshop" << endl;
        cout << "3. Edit Data Petshop" << endl;
        cout << "4. Delete Data Petshop" << endl;
        cout << "5. Find Data Petshop" << endl;
        cout << "6. Exit" << endl;
        cin >> choice;
        if(choice == 1)
        {
            if(listPetshop.empty())
            {
                cout << "Data Petshop masih kosong" << endl;
            }else{
                
                int idLen = 2, namaLen = 4, kategoriLen = 8, hargaLen = 5;
                for(Petshop petshop : listPetshop)
                {
                    if(petshop.IDLength() > idLen)
                    {
                        idLen = petshop.IDLength();
                    }
                    if(petshop.NamaLength() > namaLen)
                    {
                        namaLen = petshop.NamaLength(); 
                    }
                    if(petshop.KategoriLength() > kategoriLen)
                    {
                        kategoriLen = petshop.KategoriLength();
                    }
                    if(petshop.HargaLength() > hargaLen)
                    {
                        hargaLen = petshop.HargaLength();
                    }
                }
                cout << "Data Petshop" << endl;
                cout << "+" << string (idLen, '-')
                    << "+" << string (namaLen, '-')
                    << "+" << string (kategoriLen, '-')
                    << "+" << string (hargaLen, '-')
                    << "+" << endl;

                cout << "|" << "ID" << string (idLen - 2, ' ')
                    << "|" << "Nama" << string (namaLen - 4, ' ')
                    << "|" << "Kategori" << string (kategoriLen - 8, ' ')
                    << "|" << "Harga" << string (hargaLen - 5, ' ')
                    << "|" << endl;
                
                cout << "+" << string (idLen, '-')
                    << "+" << string (namaLen, '-')
                    << "+" << string (kategoriLen, '-')
                    << "+" << string (hargaLen, '-')
                    << "+" << endl;
                for(Petshop petshop : listPetshop)
                {
                    cout << "|" << petshop.getID() << string (idLen - petshop.getID().length(), ' ')
                        << "|" << petshop.getNama() << string (namaLen - petshop.getNama().length(), ' ')
                        << "|" << petshop.getKategori() << string (kategoriLen - petshop.getKategori().length(), ' ')
                        << "|" << petshop.getHarga() << string (hargaLen - to_string(petshop.getHarga()).length(), ' ')
                        << "|" << endl;
                }
                cout << "+" << string (idLen, '-')
                    << "+" << string (namaLen, '-')
                    << "+" << string (kategoriLen, '-')
                    << "+" << string (hargaLen, '-')
                    << "+" << endl;
            }
        }
        else if(choice == 2)
        {
            Petshop petshop;
            string id, nama, kategori;
            int harga;
            cout << "Input ID: ";
            cin >> id;
            cout << "Input Nama: ";
            cin >> nama;
            cout << "Input Kategori: ";
            cin >> kategori;
            cout << "Input Harga: ";
            cin >> harga;
            petshop = Petshop(id, nama, kategori, harga);
            listPetshop.push_back(petshop);
            cout << "Data berhasil ditambahkan" << endl;
        }
        else if(choice == 3)
        {
            string id;
            cout << "Input ID yang mau diedit: ";
            cin >> id;

            Petshop* dataEdit = NULL;
            auto it = listPetshop.begin();
            while (it != listPetshop.end() && dataEdit == NULL) {
                dataEdit = it->cekID(id);
                ++it;
            }
            
            if(dataEdit != NULL)
            {
                cout << "Data dengan ID" << id << " ditemukan" << endl;
                dataEdit->printPetshop();

                int choiceEdit;
                cout << "Pilih data yang ingin diedit: " << endl;
                cout << "1. Edit ID" << endl;
                cout << "2. Edit Nama" << endl;
                cout << "3. Edit Kategori" << endl;
                cout << "4. Edit Harga" << endl;
                cout << "5. Edit Semua" << endl;
                cin >> choiceEdit;
                
                if(choiceEdit == 1)
                {
                    string newID;
                    cout << "Input ID baru: ";
                    cin >> newID;
                    dataEdit->setID(newID);
                }
                else if(choiceEdit == 2)
                {
                    string newNama;
                    cout << "Input Nama baru: ";
                    cin >> newNama;
                    dataEdit->setNama(newNama);
                }
                else if(choiceEdit == 3)
                {
                    string newKategori;
                    cout << "Input Kategori baru: ";
                    cin >> newKategori;
                    dataEdit->setKategori(newKategori);
                }
                else if(choiceEdit == 4)
                {
                    int newHarga;
                    cout << "Input Harga baru: ";
                    cin >> newHarga;
                    dataEdit->setHarga(newHarga);
                }
                else if(choiceEdit == 5)
                {
                    string newID, newNama, newKategori;
                    int newHarga;
                    cout << "Input ID baru: ";
                    cin >> newID;
                    cout << "Input Nama baru: ";
                    cin >> newNama;
                    cout << "Input Kategori baru: ";
                    cin >> newKategori;
                    cout << "Input Harga baru: ";
                    cin >> newHarga;
                    dataEdit->editPetshop(newID, newNama, newKategori, newHarga);
                }
                cout << "Data berhasil diedit" << endl;
            }
            else
            {
                cout << "Data dengan ID " << id << " tidak ditemukan" << endl;
            }
        }
        else if(choice ==4)
        {
            string id;
            cout << "Input ID yang mau dihapus: ";
            cin >> id;

            auto it = listPetshop.begin();
            int found = 0;
            while (it != listPetshop.end() && found == 0) {
                if (it->getID() == id) {
                    it = listPetshop.erase(it);
                    cout << "Data dengan ID " << id << " berhasil dihapus" << endl;
                    found = 1;
                } else {
                    ++it;
                }
            }
            if(found == 0)
            {
                cout << "Data dengan ID " << id << " tidak ditemukan" << endl;
            }
        }
        else if(choice == 5)
        {
            string id;
            cout << "Input ID yang mau dicari: ";
            cin >> id;

            Petshop* dataFind = NULL;
            auto it = listPetshop.begin();
            while (it != listPetshop.end() && dataFind == NULL) {
                dataFind = it->cekID(id);
                ++it;
            }
            if(dataFind != NULL)
            {
                cout << "Data dengan ID " << id << " ditemukan" << endl;
                dataFind->printPetshop();
            }
            else
            {
                cout << "Data dengan ID " << id << " tidak ditemukan" << endl;
            }
        }
        if(choice != 6)
        {
            cout << "Press Enter to Continue...";
            cin.ignore();
            cin.get();
        }
    }
}