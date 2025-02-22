class Petshop:
    __id = ""
    __nama = ""
    __kategori = ""
    __harga = 0

    def __init__(self, id, nama, kategori, harga):
        self.__id = id
        self.__nama = nama
        self.__kategori = kategori
        self.__harga = harga
    
    def getId(self):
        return self.__id
    def getNama(self):
        return self.__nama
    def getKategori(self):
        return self.__kategori
    def getHarga(self):
        return self.__harga

    def setId(self, id):
        self.__id = id
    def setNama(self, nama):
        self.__nama = nama
    def setKategori(self, kategori):
        self.__kategori = kategori
    def setHarga(self, harga):
        self.__harga = harga
    
    def editPetshop(self, id, nama, kategori, harga):
        self.__id = id
        self.__nama = nama
        self.__kategori = kategori
        self.__harga = harga

    def printPetshop(self):
        print("ID: ", self.__id)
        print("Nama: ", self.__nama)
        print("Kategori: ", self.__kategori)
        print("Harga: ", self.__harga)

    def cekId(self, id):
        if self.__id == id:
            return self
        else:
            return None