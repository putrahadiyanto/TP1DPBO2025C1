<?php

class Petshop{

    private $id = "";
    private $nama = "";
    private $kategori = "";
    private $harga = 0;
    private $photo = "";

    public function __construct($id, $nama, $kategori, $harga, $photo){
        $this->id = $id;
        $this->nama = $nama;
        $this->kategori = $kategori;
        $this->harga = $harga;
        $this->photo = $photo;
    }

    public function getId(){return $this->id;}
    public function getNama(){return $this->nama;}
    public function getKategori(){return $this->kategori;}
    public function getHarga(){return $this->harga;}
    public function getPhoto(){return $this->photo;}

    public function setId($id){$this->id = $id;}
    public function setNama($nama){$this->nama = $nama;}
    public function setKategori($kategori){$this->kategori = $kategori;}
    public function setHarga($harga){$this->harga = $harga;}
    public function setPhoto($photo){$this->photo = $photo;}

    public function editPetshop($nama, $kategori, $harga, $photo){
        $this->nama = $nama;
        $this->kategori = $kategori;
        $this->harga = $harga;
        $this->photo = $photo;
    }

    public function cekId($id){
        if($this->id == $id){
            return $this;
        }else{
            return NULL;
        }
    }

}

?>