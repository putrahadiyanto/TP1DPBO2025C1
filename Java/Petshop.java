class Petshop{
    private String id;
    private String nama_produk;
    private String kategori;
    private int harga;

    Petshop(){
        this.id = "";
        this.nama_produk = "";
        this.kategori = "";
        this.harga = 0;
    }

    Petshop(String id, String nama_produk, String kategori, int harga){
        this.id = id;
        this.nama_produk = nama_produk;
        this.kategori = kategori;
        this.harga = harga;
    }

    public void setID(String id){ this.id = id; }
    public void setNamaProduk(String nama_produk){ this.nama_produk = nama_produk; }
    public void setKategori(String kategori){ this.kategori = kategori; }
    public void setHarga(int harga){ this.harga = harga; }

    public String getID(){ return this.id; }
    public String getNamaProduk(){ return this.nama_produk; }
    public String getKategori(){ return this.kategori; }
    public int getHarga(){ return this.harga; }

    public int IDLength(){ return this.id.length(); }
    public int NamaProdukLength(){ return this.nama_produk.length(); }
    public int KategoriLength(){ return this.kategori.length(); }
    public int HargaLength(){ return String.valueOf(this.harga).length(); }
    
    public void editData(String id, String nama_produk, String kategori, int harga)
    {
        this.id = id;
        this.nama_produk = nama_produk;
        this.kategori = kategori;
        this.harga = harga;
    }

    public void printPetshop()
    {
        System.out.println("ID: " + this.id);
        System.out.println("Nama Produk: " + this.nama_produk);
        System.out.println("Kategori: " + this.kategori);
        System.out.println("Harga: " + this.harga);
    }

    public Petshop findPetshop(String id)
    {
        if(this.id.equals(id))
        {
            return this;
        }
        return null;
    }

    
}