<?php
require('Petshop.php');

session_start();

// Initialize list_petshop from session or create a new list
if (!isset($_SESSION['list_petshop'])) {
    $_SESSION['list_petshop'] = [
        new Petshop(1, "Kucing", "Hewan", 100000, "images/cat.jpg"),
        new Petshop(2, "Anjing", "Hewan", 200000, "images/dog.jpg")
    ];
}

$list_petshop = $_SESSION['list_petshop'];

if (!is_dir("images")) {
    mkdir("images", 0777, true);
}


if (isset($_POST['submit'])) {
    $nama = $_POST['nama'];
    $kategori = $_POST['kategori'];
    $harga = $_POST['harga'];
    $photo = $_FILES['photo'];

    $photo_path = "images/" . basename($photo['name']);
    move_uploaded_file($photo['tmp_name'], $photo_path);

    $new_petshop = new Petshop(count($list_petshop) + 1, $nama, $kategori, $harga, $photo_path);
    $list_petshop[] = $new_petshop;

    $_SESSION['list_petshop'] = $list_petshop;
}

if (isset($_POST['delete'])) {
    $delete_id = $_POST['delete'];
    $it = 0;
    $found = false;
    while($it < count($list_petshop) && $found == false){
        if($list_petshop[$it]->getId() == $delete_id){
            $found = true;
            if(file_exists($list_petshop[$it]->getPhoto())){
                unlink($list_petshop[$it]->getPhoto());
            }
            unset($list_petshop[$it]);
            $list_petshop = array_values($list_petshop);
            $_SESSION['list_petshop'] = $list_petshop;
        }else{
            $it++;
        }
    }
}


if (isset($_POST['edit_submit'])) {
    $edit_id = $_POST['edit_id'];
    $edit_nama = $_POST['nama'];
    $edit_kategori = $_POST['kategori'];
    $edit_harga = $_POST['harga'];
    $edit_photo = $_FILES['photo'];

    $it = 0;
    $petshop = NULL;
    while($it < count($list_petshop) && $petshop == NULL){
        $petshop = $list_petshop[$it]->cekId($edit_id);
        $it++;
    }

    if ($edit_photo['error'] == 4) {
        $edit_photo_path = $petshop->getPhoto();
    } else {
        $edit_photo_path = "images/" . basename($edit_photo['name']);
        move_uploaded_file($edit_photo['tmp_name'], $edit_photo_path);
    }

    $petshop->editPetshop($edit_nama, $edit_kategori, $edit_harga, $edit_photo_path);
    $_SESSION['list_petshop'] = $list_petshop;
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>List Petshop</title>
    <style>
        html, body {
            margin: 0;
            padding: 0;
            font-family: Arial, Helvetica, sans-serif;
        }
        .header {
            background-color: #007BFF;
            color: white;
            font-size : 20px;
            padding: 20px;
            width: 100%;
            top: 0;
            margin-top: 0;
            margin-bottom: 10px;
        }
        .main-table{
            margin: 0 auto;
            border-radius: 10px;
            width: 80%;
            background-color: #F8F9FA;
        }
        .main-table th{
            background-color: #0056B3;
            color: white;
            border-color: #DEE2E6;
            padding: 10px;
        }
        .main-table td{
            color: #212529;
            padding: 10px;
            text-align: center;
        }   

        button{
            color: white;
            border: none;
            font-size: 15px;
            padding: 7px 20px;
            border-radius: 5px;
            margin-bottom: 5px;
            cursor: pointer;
        }
        button:hover{
            opacity: 0.6;
        }
        .delete-btn{
            background-color: #DC3545;
        }
        .edit{
            background-color: #FFC107;
        }
        .add {
            background-color: #28A745;
            display: block;
            margin: 10px auto;
        }
        form{
            display: none;
            margin: 0 auto;
            width: 50%;
            text-align: center;
            display: block;
        }
        input{
            margin: 5px;
            padding: 5px;
            border-radius: 5px;
            border: 1px solid #DEE2E6;
        }
        .submit-btn{
            background-color: #007BFF;
        }


    </style>
</head>
<body>
    <h1 class="header">List Petshop Putra</h1>
    <table class="main-table">
        <tr>
            <th>ID</th>
            <th>Nama</th>
            <th>Kategori</th>
            <th>Harga</th>
            <th>Foto</th>
            <th>Actions</th>
        </tr>
        <?php if(count($list_petshop) <= 0) {?>
            <tr>
                <td colspan="6" style="text-align: center;">No data</td>
            </tr>
        <?php }else{ ?>
        <?php foreach ($list_petshop as $petshop) { ?>
            <tr>
                <td><?= $petshop->getId(); ?></td>
                <td><?= $petshop->getNama(); ?></td>
                <td><?= $petshop->getKategori(); ?></td>
                <td><?= $petshop->getHarga(); ?></td>
                <td align = "center"><img src="<?= $petshop->getPhoto(); ?>" alt="<?= $petshop->getNama(); ?>" width="100"></td>
                <td align = "center">
                    <form action="" method="POST">
                        <input type="hidden" name="delete" value="<?= $petshop->getId(); ?>">
                        <button type="submit" class = "delete-btn">Delete</button>
                    </form>

                    <button class="edit" onclick="toggleEditForm(
                        <?= $petshop->getId(); ?>, 
                        '<?= $petshop->getNama(); ?>', 
                        '<?= $petshop->getKategori(); ?>', 
                        <?= $petshop->getHarga(); ?>
                    )">Edit</button>
                </td>
            </tr>
        <?php } }?>    
    </table>
    <button class="add" onclick="toggleAddForm()">Add</button>

    <form class = "form" action="" method="POST" id="addForm" style="display: none;" enctype="multipart/form-data">
        <div class="form-container">
            <input type="text" name="nama" placeholder="Nama"> <br>
            <input type="text" name="kategori" placeholder="Kategori"> <br>
            <input type="number" name="harga" placeholder="Harga"> <br>
            <input type="file" name="photo"> <br>
            <button class = "submit-btn" type="submit" name="submit">Submit</button>
        </div>
    </form>

    <form class = "form" action="" method="POST" id="editForm" style="display:none;" enctype="multipart/form-data">
        <div class="form-container">
            <input type="hidden" name="edit_id" id="edit_id">
            <input type="text" name="nama" id="edit_nama" placeholder="Nama"> <br>
            <input type="text" name="kategori" id="edit_kategori" placeholder="Kategori"> <br>
            <input type="number" name="harga" id="edit_harga" placeholder="Harga"> <br>
            <input type="file" name="photo"> <br>
            <button class = "submit-btn" type="submit" name="edit_submit">Update</button>
        </div>
    </form>

    <script>
        function toggleAddForm() {
            var addForm = document.getElementById("addForm");
            var editForm = document.getElementById("editForm");
            
            if (editForm.style.display === "block") {
                editForm.style.display = "none";
            }
            
            addForm.style.display = (addForm.style.display === "none") ? "block" : "none";
        }

        function toggleEditForm(id, nama, kategori, harga) {
            var addForm = document.getElementById("addForm");
            var editForm = document.getElementById("editForm");
            
            if (addForm.style.display === "block") {
                addForm.style.display = "none";
            }
            
            document.getElementById("edit_id").value = id;
            document.getElementById("edit_nama").value = nama;
            document.getElementById("edit_kategori").value = kategori;
            document.getElementById("edit_harga").value = harga;
            
            editForm.style.display = (editForm.style.display === "block") ? "none" : "block";
        }
    </script>
</body>
</html>