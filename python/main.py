from Petshop import Petshop

choice = 0

petshop_list = []

while choice != 6:

    print("\nList Menu Petshop:")
    print("1. View Data Petshop")
    print("2. Tambah Data Petshop")
    print("3. Edit Data Petshop")
    print("4. Hapus Data Petshop")
    print("5. Cari Data Petshop")
    print("6. Keluar")
    choice = int(input(""))

    if choice == 1:
        if len(petshop_list) == 0:
            print("Data Petshop Kosong")
        else:
            lenId = 2
            lenNama = 5
            lenKategori = 9
            lenHarga = 6
            for petshop in petshop_list:
                if len(petshop.getId()) > lenId:
                    lenId = len(petshop.getId())
                if len(petshop.getNama()) > lenNama:
                    lenNama = len(petshop.getNama())
                if len(petshop.getKategori()) > lenKategori:
                    lenKategori = len(petshop.getKategori())
                if len(str(petshop.getHarga())) > lenHarga:
                    lenHarga = len(str(petshop.getHarga()))
            print("ID".ljust(lenId), "Nama".ljust(lenNama), "Kategori".ljust(lenKategori), "Harga".ljust(lenHarga))
            for petshop in petshop_list:
                print(petshop.getId().ljust(lenId), petshop.getNama().ljust(lenNama), petshop.getKategori().ljust(lenKategori), str(petshop.getHarga()).ljust(lenHarga))
    elif choice == 2:
        id = input("Masukkan ID: ")
        nama = input("Masukkan Nama: ")
        kategori = input("Masukkan Kategori: ")
        harga = int(input("Masukkan Harga: "))
        petshop = Petshop(id, nama, kategori, harga)
        petshop_list.append(petshop)
        print("Data Petshop Berhasil Ditambahkan")
    elif choice == 3:
        id = input("Masukkan ID yang ingin diubah: ")
        petshop = None
        iterator = 0
        while petshop == None and iterator < len(petshop_list):
            petshop = petshop_list[iterator].cekId(id)
            iterator += 1

        if petshop == None:
            print("Data petshop dengan ID ", id, " tidak ditemukan")
        else:
            print("Data Petshop Ditemukan")
            print("Pilih data yang ingin diubah:")
            print("1. ID")
            print("2. Nama")
            print("3. Kategori")
            print("4. Harga")
            print("5. Semua Data")
            choiceEdit = int(input())
            if choiceEdit == 1:
                id = input("Masukkan ID Baru: ")
                petshop.setId(id)
            elif choiceEdit == 2:
                nama = input("Masukkan Nama Baru: ")
                petshop.setNama(nama)
            elif choiceEdit == 3:
                kategori = input("Masukkan Kategori Baru: ")
                petshop.setKategori(kategori)
            elif choiceEdit == 4:
                harga = int(input("Masukkan Harga Baru: "))
                petshop.setHarga(harga)
            elif choiceEdit == 5:
                id = input("Masukkan ID Baru: ")
                nama = input("Masukkan Nama Baru: ")
                kategori = input("Masukkan Kategori Baru: ")
                harga = int(input("Masukkan Harga Baru: "))
                petshop.setId(id)
                petshop.setNama(nama)
                petshop.setKategori(kategori)
                petshop.setHarga(harga)
            
            print("Data Petshop Berhasil Diubah")
    elif choice == 4:
        id = input("Masukkan ID yang ingin dihapus: ")
        petshop = None
        iterator = 0
        while petshop == None and iterator < len(petshop_list):
            petshop = petshop_list[iterator].cekId(id)
            iterator += 1

        if petshop == None:
            print("Data petshop dengan ID ", id, " tidak ditemukan")
        else:
            petshop_list.remove(petshop)
            print("Data Petshop Berhasil Dihapus")
    elif choice == 5:
        id = input("Masukkan ID yang ingin dicari: ")
        petshop = None
        iterator = 0
        while petshop == None and iterator < len(petshop_list):
            petshop = petshop_list[iterator].cekId(id)
            iterator += 1

        if petshop == None:
            print("Data petshop dengan ID ", id, " tidak ditemukan")
        else:
            petshop.printPetshop()
