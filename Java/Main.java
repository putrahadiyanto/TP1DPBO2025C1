import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        
        ArrayList<Petshop> listPetshop = new ArrayList<Petshop>();

        int choice = 0;
        Scanner input = new Scanner(System.in);
        while(choice != 6)
        {
            System.out.println("\nList Menu Petshop");
            System.out.println("1. View Data Petshop");
            System.out.println("2. Add Data Petshop");
            System.out.println("3. Edit Data Petshop");
            System.out.println("4. Delete Data Petshop");
            System.out.println("5. Find Data Petshop");
            System.out.println("6. Exit");

            try{
                choice = input.nextInt();
                input.nextLine();
            }catch(Exception e){
                System.out.println("Inputan harus berupa angka");
                input.nextLine();
                continue;
            }

            if(choice == 1)
            {
                if(listPetshop.size() == 0){
                    System.out.println("Data Petshop masih kosong");
                }
                else{
                    int idLen = 2, namaProdukLen = 4, kategoriLen = 8, hargaLen = 5;
                    for(int i = 0; i < listPetshop.size(); i++)
                    {
                        if(listPetshop.get(i).IDLength() > idLen)
                        {
                            idLen = listPetshop.get(i).IDLength();
                        }
                        if(listPetshop.get(i).NamaProdukLength() > namaProdukLen)
                        {
                            namaProdukLen = listPetshop.get(i).NamaProdukLength();
                        }
                        if(listPetshop.get(i).KategoriLength() > kategoriLen)
                        {
                            kategoriLen = listPetshop.get(i).KategoriLength();
                        }
                        if(listPetshop.get(i).HargaLength() > hargaLen)
                        {
                            hargaLen = listPetshop.get(i).HargaLength();
                        }
                    }
                    System.out.printf("%-" + idLen + "s %-" + namaProdukLen + "s %-" + kategoriLen + "s %-" + hargaLen + "s\n", "ID", "Nama", "Kategori", "Harga");
                    for(Petshop petshop : listPetshop) {
                        System.out.printf("%-" + idLen + "s %-" + namaProdukLen + "s %-" + kategoriLen + "s %-" + hargaLen + "d\n", petshop.getID(), petshop.getNamaProduk(), petshop.getKategori(), petshop.getHarga());
                    }
                }
            }else if(choice == 2)
            {
                String id, nama_produk, kategori;
                int harga;
                System.out.print("Masukkan ID: ");
                id = input.nextLine();

                System.out.print("Masukkan Nama Produk: ");
                nama_produk = input.nextLine();

                System.out.print("Masukkan Kategori: ");
                kategori = input.nextLine();

                System.out.print("Masukkan Harga: ");
                harga = input.nextInt();

                input.nextLine();
                listPetshop.add(new Petshop(id, nama_produk, kategori, harga));
            }else if(choice == 3){
                if(listPetshop.size() == 0){
                    System.out.println("Data Petshop masih kosong");
                }else{
                    String id;
                    System.out.print("Masukkan ID yang ingin di edit: ");
                    id = input.nextLine();
                    Petshop temp = null;
                    int it = 0;
                    while(it < listPetshop.size() && temp == null)
                    {
                        temp = listPetshop.get(it).findPetshop(id);  
                        it++;
                    }
                    if(temp == null)
                    {
                        System.out.println("Data dengan ID " + id + " tidak ditemukan");
                    }else{
                        int choiceEdit = 0;
                        System.out.println("Data yang ingin di edit: ");
                        System.out.println("1. ID");
                        System.out.println("2. Nama Produk");
                        System.out.println("3. Kategori");
                        System.out.println("4. Harga");
                        System.out.println("5. Semua Data");

                        try{
                            choiceEdit = input.nextInt();
                            input.nextLine();
                        }catch(Exception e){
                            System.out.println("Inputan harus berupa angka");
                            input.nextLine();
                            continue;
                        }

                        if(choiceEdit == 1)
                        {
                            String newID;
                            System.out.print("Masukkan ID baru: ");
                            newID = input.nextLine();
                            temp.setID(newID);
                        }else if(choiceEdit == 2){
                            String newNamaProduk;
                            System.out.print("Masukkan Nama Produk baru: ");
                            newNamaProduk = input.nextLine();
                            temp.setNamaProduk(newNamaProduk);
                        }else if(choiceEdit == 3){
                            String newKategori;
                            System.out.print("Masukkan Kategori baru: ");
                            newKategori = input.nextLine();
                            temp.setKategori(newKategori);
                        }else if(choiceEdit == 4){
                            int newHarga;
                            System.out.print("Masukkan Harga baru: ");
                            newHarga = input.nextInt();
                            temp.setHarga(newHarga);
                        }else if(choiceEdit == 5){
                            String newID, newNamaProduk, newKategori;
                            int newHarga;
                            System.out.print("Masukkan ID baru: ");
                            newID = input.nextLine();

                            System.out.print("Masukkan Nama Produk baru: ");
                            newNamaProduk = input.nextLine();

                            System.out.print("Masukkan Kategori baru: ");
                            newKategori = input.nextLine();

                            System.out.print("Masukkan Harga baru: ");
                            newHarga = input.nextInt();

                            input.nextLine();
                            temp.editData(newID, newNamaProduk, newKategori, newHarga);
                        }
                    }
                }  
            }else if(choice == 4){
                if(listPetshop.size() == 0)
                {
                    System.out.println("Data Petshop masih kosong");
                }
                else
                {
                    String id;
                    System.out.print("Masukkan ID yang ingin dihapus: ");
                    id = input.nextLine();
                    Petshop temp = null;
                    int it = 0;
                    while(it < listPetshop.size() && temp == null)
                    {
                        temp = listPetshop.get(it).findPetshop(id);  
                        it++;
                    }
                    if(temp == null)
                    {
                        System.out.println("Data dengan ID " + id + " tidak ditemukan");
                    }else{
                        listPetshop.remove(temp);
                        System.out.println("Data dengan ID " + id + " berhasil dihapus");
                    }
                }
            }else if(choice == 5){
                if(listPetshop.size() == 0)
                {
                    System.out.println("Data Petshop masih kosong");
                }
                else
                {
                    String id;
                    System.out.print("Masukkan ID yang ingin dicari: ");
                    id = input.nextLine();
                    Petshop temp = null;
                    int it = 0;
                    while(it < listPetshop.size() && temp == null)
                    {
                        temp = listPetshop.get(it).findPetshop(id);  
                        it++;
                    }
                    if(temp == null)
                    {
                        System.out.println("Data dengan ID " + id + " tidak ditemukan");
                    }else{
                        temp.printPetshop();
                    }
                }
            }
        }
        
        input.close();
    }
}
