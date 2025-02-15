/*Saya Putra Hadiyanto Nugroho dengan NIM 2308163 mengerjakan
 soal Latihan Modul 1 dalam mata kuliah Desain Pemrograman Berbasis Objek
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
#include <bits/stdc++.h>

using namespace std;

class Petshop{

    private:
        string id;
        string nama;
        string kategori;
        int harga;

    public:
        Petshop(){
            id = "";
            nama = "";
            kategori = "";
        }

        Petshop(string id, string nama, string kategori, int harga){
            this->id = id;
            this->nama = nama;
            this->kategori = kategori;
            this->harga = harga;
        }

        void setID(string id) { this->id = id; }
        string getID(){ return id; }

        void setNama(string nama){ this->nama = nama; }
        string getNama(){ return nama; }

        void setKategori(string kategori){ this->kategori = kategori; }
        string getKategori(){ return kategori; }

        void setHarga(int harga){ this->harga = harga; }
        int getHarga(){ return harga; }

        int IDLength(){ return id.length(); }
        int NamaLength(){ return nama.length(); }
        int KategoriLength(){ return kategori.length(); }
        int HargaLength(){ return to_string(harga).length(); }

        void editPetshop(string id, string nama, string kategori, int harga){
            this->id = id;
            this->nama = nama;
            this->kategori = kategori;
            this->harga = harga;
        }

        void printPetshop(){
            cout << "ID: " << id << endl;
            cout << "Nama: " << nama << endl;
            cout << "Kategori: " << kategori << endl;
            cout << "Harga: " << harga << endl;
        }

        Petshop* cekID(string id){
            if (this->id == id) {
                return this;
            } else {
                return NULL;
            }
        }

    ~Petshop(){
    }
};
