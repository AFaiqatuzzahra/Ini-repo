# <h1 align="center">Laporan Praktikum Modul Struct</h1>
<p align="center">Afifah Faiqatuzzahra</p>

## Dasar Teori
Variabel pada bahasa c++ adalah bagian dari memori yang hanya dapat menampung satu data/informasi pada satu waktu, dimana data/informasi tersebut dapat berubah setelah dideklarasikan selama pengeksekusian program. Variabel dilambangkan dengan simbol yang didefinisikan oleh pemrogram dan variabel harus dideklarasikan terlebih dahulu sebelum dapat digunakan. Pendeklarasian variabel pada bahasa C++ adalah sebagai berikut 'tipe_data nama_variabel;'. Variabel dapat langsung diberi nilai awal pada saat pendeklarasiannya. Pendeklarasian variabel pada bahasa C++ adalah sebagai berikut 'tipe_data nama_variabel=nilai_awal;' [1]. Pada C++, kita dapat mendeklarasikan variabel dibagian mana saja dari program, bahkan diantara 2 kalimat oerintah. Variabel global dapat digunakan untuk setiap bagian dari program, maupun fungsi, walaupun dideklarasikan diakhir program. Lingkup dari variabel lokal terbatas. Hanya berlaku dimana varibel tersebut dideklarasikan. Jika dideklarasikan diawal fungsi (seperti dalam main) maka lingkup dari variabel tersebut adalah untuk seluruh fungsi main [3].

Structure/struktur adalah kumpulan elemen-elemen data yang digabungkan menjadi satu kesatuan. Masing-masing elemen data dikenal dengan sebutan field/kolom. Field data tersebut dapat memiliki tipe data yang sama ataupun berbeda. Walaupun field-field tersebut berada dalam satu kesatuan, masing-masing field tersebut dapat diakses secara individual. Field-field tersebut digabungkan menjadi satu dengan tujuan untuk kemudahan dalam operasinya [1]. Structure atau struct juga dapat diartikan kumpulan dari beberapa variabel dengan beragam tipe data yang dibungkus dalam satu variabel. Ada dua cara untuk mengakses member yang ada di dalam struct. Cara pertama adalah dengan cara mendeklarasikan object-nya terlebih dahulu di dalam struct-nya kemudian untuk mengaksesnya bisa menggunakan object yang telah dideklarasikan tadi. Kemudian cara kedua adalah dengan mendeklarasikan object-nya di dalam 'int main()' dengan cara memanggil nama struct-nya dan diikuti dengan nama object-nya [2].

## Guided 

### 1. Guided 1: Buatlah sebuah struktur dengan nama buku yang berisi judul_buku, pengarang, penerbit, tebal_halaman, harga_buku. Isi dengan nilai kemudian tampilkan.

```C++
#include <iostream>

using namespace std;

// Mendefinisikan struktur buku
struct buku {
    string judulBuku;
    string pengarang;
    string penerbit;
    int tebalHalaman;
    int hargaBuku;
};

int main() {
    // Mendeklarasikan variabel favorit dengan tipe buku
    buku favorit;

    // Mengisi data ke dalam variabel favorit
    favorit.judulBuku = "The Alpha Girl's Guide";
    favorit.pengarang = "Henry Manampiring";
    favorit.penerbit = "Gagas Media";
    favorit.tebalHalaman = 253;
    favorit.hargaBuku = 79000;

    // Menampilkan informasi buku favorit
    cout << "\tBuku Favorit Saya" << endl;
    cout << "\tJudul Buku : " << favorit.judulBuku << endl;
    cout << "\tPengarang : " << favorit.pengarang << endl;
    cout << "\tPenerbit : " << favorit.penerbit << endl;
    cout << "\tTebal Halaman: " << favorit.tebalHalaman << " halaman" << endl;
    cout << "\tHarga Buku : Rp " << favorit.hargaBuku << endl;
 
    return 0;
}
```
Program di atas merupakan sebuah struktur dengan nama buku yang datanya berisi judul_buku, pengarang, penerbit, tebal_halaman, dan harga_buku dengan data yang di isi manual kemudian ditampilkan. Berikut adalah penjelasannya.

Pertama, program di atas mendefinisikan sebuah struktur yang bernama 'buku', dimana struktur 'buku' tersebut memiliki lima anggota, yaitu 'judulBuku', 'pengarang', 'penerbit', 'tebalHalaman', dan 'hargaBuku'. Tipe data untuk setiap anggota juga disesuaikan, seperti string untuk 'judulBuku', 'pengarang', dan 'penerbit', lalu int untuk 'tebalHalaman' dan 'hargaBuku'. Kemudian terdapat fungsi main() untuk mengeksekusi program saat dijalankan. Untuk yang pertama yaitu mendeklarasikan variabel 'favorit' dengan tipe 'buku'. Ini adalah variabel yang akan digunakan untuk menyimpan data tentang buku favorit. Yang kedua yaitu mengisi data ke dalam variabel favorit. Data buku favorit diisi ke dalam variabel favorit menggunakan operator titik. Kemudian setiap anggota dari variabel favorit diisi dengan nilai yang sudah ditentukan. Yang ketiga yaitu menampilkan informasi buku favorit. Informasi tentang buku favorit ditampilkan ke layar menggunakan perintah 'cout'. Lalu diberikan kode '\t' yang berfungsi untuk membuat tab (kalimat menjorok ke depan) pada tampilan outputnya. Dan yang terakhir 'return 0' yang berfungsi untuk mengembalikan nilai 0 dan menandakan bahwa program telah berakhir.

#### Output:


Dari output tersebut dapat kita ketahui data mengenai Buku Favorit Saya. Dimana, Judul Bukunya adalah 'The Alpha Girl's Guide, Pengarangnya adalah 'Henry Manampiring', Penerbitnya adalah 'Gagas Media', Tebal Halamannya adalah '253 halaman', dan Harga Bukunya adalah 'Rp 79000'.

#### Full code Screenshot:


### 2. Guided 2: Buatlah sebuah struktur dengan skema seperti dibawah, isi dengan nilai kemudian jalankan

![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/12f96230-5238-4e8d-9b0e-15975e420ddf)

```C++
#include <iostream>
using namespace std;

struct hewan {
    string namaHewan;
    string jenisKelamin;
    string caraBerkembangbiak;
    string alatPernafasan;
    string tempatHidup;
    bool Karnivora;
};

struct hewanDarat {
    int jumlahKaki;
    bool menyusui;
    string suara;
};

struct hewanLaut {
    string bentukSirip;
    string bentukPertahananDiri;
};

int main() {
    hewanDarat kelinci; // Menggunakan tipe data hewanDarat untuk kelinci
    kelinci.jumlahKaki = 4;
    kelinci.menyusui = true;
    kelinci.suara = "Citcit";

    hewanLaut ikan; // Menggunakan tipe data hewanLaut untuk ikan
    ikan.bentukSirip = "Sirip ekor";
    ikan.bentukPertahananDiri = "Sisik";

    hewan serigala; // Tetap menggunakan tipe data hewan untuk serigala
    serigala.namaHewan = "Serigala";
    serigala.jenisKelamin = "Jantan";
    serigala.caraBerkembangbiak = "Melahirkan";
    serigala.alatPernafasan = "Paru-paru";
    serigala.tempatHidup = "Hutan terbuka";
    serigala.Karnivora = true;

    cout << "\t\tHewan" << endl;
    cout << "\t" << serigala.namaHewan << endl;
    cout << "\tJenis kelamin : " << serigala.jenisKelamin << endl;
    cout << "\tCara berkembangbiak : " << serigala.caraBerkembangbiak << endl;
    cout << "\tAlat pernafasan : " << serigala.alatPernafasan << endl;
    cout << "\tTempat hidup : " << serigala.tempatHidup << endl;
    cout << "\tKarnivora : " << (serigala.Karnivora ? "Yes" : "No") << endl << endl;

    cout << "\t\tHewan Darat" << endl;
    cout << "\tKelinci" << endl;
    cout << "\tJumlah kaki : " << kelinci.jumlahKaki << endl;
    cout << "\tMenyusui : " << (kelinci.menyusui ? "Yes" : "No") << endl;
    cout << "\tSuara : " << kelinci.suara << endl << endl;

    cout << "\t\tHewan Laut" << endl;
    cout << "\tIkan" << endl;
    cout << "\tBentuk sirip : " << ikan.bentukSirip << endl;
    cout << "\tBentuk pertahanan diri: " << ikan.bentukPertahananDiri << endl;

    return 0;
}
```
Program di atas merupakan program yang menampilkan tiga struktur dengan nama Hewan, Hewan Darat, dan Hewan Laut. Berikut adalah penjelasannya.

Seperti yang sudah diketahui di atas, program tersebut memiliki tiga struktur data yang didefinisikan. Pertama adalah struktur 'hewan'. Struktur ini memiliki lima anggota yang dimana menggambarkan karakteristik umum dari hewan sendiri. Lima anggota tersebut adalah 'namaHewan', 'jenisKelamin', 'caraBerkembangbiak', 'alatPernafasan', 'tempatHidup', dan 'Karnovira'. Untuk tipe data semuanya bertipe string, kecuali untuk 'Karnivora' bertipe data bool yang berarti true atau false. Kedua adalah struktur 'hewanDarat'. Struktur ini memiliki tiga anggota yang menggambarkan karakteristik dari hewan darat sendiri. Tiga anggota tersebut adalah 'jumlahKaki', 'menyusui', dan 'suara'. Untuk tipe datanya juga disesuaikan, 'jumlahKaki' bertipe data int, 'menyusui' bertipe data bool, dan 'suara' bertipe data string. Ketiga adalah struktur 'hewanLaut'. Struktur ini memiliki dua anggota yang menggambarkan karakteristik dari hewan laut sendiri. Dua anggota tersebut adalah 'bentukSirip' dan 'bentukPertahananDiri'. Tipe data yang digunakan keduanya juga sama, yaitu menggunakan string. Selanjutnya fungsi 'main()'. Dalam fungsi 'main()' program melakukan beberapa hal, diantaranya menginisialisasi objek hewan, dimana kelinci untuk hewanDarat, ikan untuk hewanLaut, dan serigala untuk hewan, dan kemudian mengisi data-datanya. Setelah itu, program menggunakan objek hewan tersebut untuk menampilkan informasi dari ketiga struktur yang sudah di isi data-datanya, lalu informasi dicetak ke layar menggunakan fungsi 'cout'. 

#### Output:


Dari output tersebut dapat kita ketahui data mengenai karakteristik hewan, yang mana dibagi menjadi 3 kelompok. Kelompok pertama adalah Hewan yang di isi oleh Serigala. Serigala berjenis kelamin jantan, cara berkembang biaknya dengan melahirkan, alat pernafasannya menggunakan paru-paru, tempat hidupnya di hutan terbuka, dan tergolong ke dalam jenis hewan karnivora.
Kelompok kedua adalah Hewan Darat yang di isi oleh Kelinci. Kelinci memiliki jumlah kaki 4, termasuk hewan yang menyusui, dan memiliki suara citcit. Kelompok ketiga dan yang terakhir adalah Hewan Laut yang di isi oleh Ikan. Bentuk sirip ikan yaitu sirip ekor, dan ventuk pertahanan dirinya yaitu sisik.

#### Full code Screenshot:


## Unguided 

### 1. Modifikasi tugas guided pertama, sehingga setiap item yang terdapat pada struct buku berupa array yang berukuran 5, isi dengan data kemudian tampilkan.

```C++
#include <iostream>

using namespace std;

// Mendefinisikan struktur film
struct film {
    string judulfilm;
    string produser;
    string bioskop;
    int durasi;
    int hargatiket;
};

int main() {
    // Mendeklarasikan variabel favorit dengan tipe film
    film favorit;

    // Mengisi data ke dalam variabel favorit
    favorit.judulfilm = "Terbulan dibenam malam";
    favorit.produser = "Latulipa";
    favorit.bioskop = "CGV";
    favorit.durasi = 120;
    favorit.hargatiket = 120000;

    // Menampilkan informasi film favorit
    cout << "\tRekomendasi film " << endl;
    cout << "\tJudul film  : " << favorit.judulfilm << endl;
    cout << "\tProduser    : " << favorit.produser<< endl;
    cout << "\tBioskop     : " << favorit.bioskop << endl;
    cout << "\tDurasi      : " << favorit.durasi << " menit " << endl;
    cout << "\tHarga tiket : Rp " << favorit.hargatiket << endl;
 
    return 0;
}
```
## Interpretasi 

Program ini membantu kamu untuk menyimpan dan menampilkan informasi film favorit dengan mudah.

1. **Membuat Struktur `film`:**
   - Mendefinisikan struktur `film` untuk menyimpan data film seperti judul, produser, bioskop, durasi, dan harga tiket.
2. **Menyimpan Data Film Favorit:**
   - Membuat variabel `favorit` dengan tipe `film`.
   - Mengisi data `favorit` dengan informasi film favoritmu.
3. **Menampilkan Informasi Film:**
   - Menggunakan objek `cout` untuk menampilkan informasi film favorit ke layar, 
      termasuk judul, produser, bioskop, durasi, dan harga tiket.

#### Output:

Dari output tersebut dapat kita ketahui data mengenai Buku Favorit Saya yang berjumlah lima. Setiap buku menampilkan informasi judul, pengarang, penerbit, tebal halaman, dan harga buku. 

#### Full code Screenshot:


Dengan demikian, dapat disimpulkan bahwa program di atas adalah bentuk modifikasi dari program guided 1. Pada program ini kita mengunakan array yang berjumlah 5 dan juga kita diminta untuk memasukkan data setiap bukunya.

### 2. Apa yang terjadi jika deklarasi variabel struct yang dibuat pada tugas guided I, berjenis Array. Bagaimana cara mengisi data dan menampilkannya?

Jika kita ingin menggunakan array dari struktur buku pada guided 1 untuk menyimpan beberapa buku, kita bisa mendeklarasikan array dari struktur buku tersebut kemudian mengisi setiap elemen array dengan data buku yang sudah ditentukan. 

```C++
#include <iostream>
using namespace std;

// Mendefinisikan struktur film
struct film {
    string judulfilm;
    string produser;
    string bioskop;
    int durasi;
    int hargatiket;
};

int main() {
    // Mendeklarasikan array film dengan panjang 3
    film favorit[3];

    // Mengisi data ke dalam array film
    favorit[0] = {"Terbulan dibenam malam", "Latulipa", "CGV", 120, 120000};
    favorit[1] = {"The Godfather", "Francis Ford ", "XXI", 175, 150000};
    favorit[2] = {"Inception", "Christopher Nolan", "Cinepolis", 148, 130000};

    // Menampilkan informasi film-film favorit
    cout << "\tRekomendasi film " << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "\tFilm ke-" << i + 1 << endl;
        cout << "\tJudul film  : " << favorit[i].judulfilm << endl;
        cout << "\tProduser    : " << favorit[i].produser << endl;
        cout << "\tBioskop     : " << favorit[i].bioskop << endl;
        cout << "\tDurasi      : " << favorit[i].durasi << " menit " << endl;
        cout << "\tHarga tiket : Rp " << favorit[i].hargatiket << endl;
        cout << endl;
    }

    return 0;
}
```
Berikut adalah penjelasan program di atas.

Sama seperti program pada guided 1, program di atas dimulai dengan mendefinisikan sebuah struktur yang diberi nama buku dan struktur buku ini memiliki lima anggota diantaranya: 'judulBuku', 'pengarang', 'penerbit', 'tebalHalaman', dan 'hargaBuku'. Selanjutnya fungsi main(). Untuk yang pertama, array buku dengan ukuran 3 dideklarasikan sebagai daftarBuku. Kemudian data untuk setiap buku diisi ke dalam array daftarBuku. Setiap elemen array diisi dengan informasi karakteristik buku yang sudah ditentukan. Setelah array daftarBuku diisi, program mencetak informasi dalam array tersebut. Selanjutnya Loop for. Loop for digunakan untuk melintasi setiap elemen array daftarBuku, dan kemudian mencetak anggota-anggota buku tersebut satu per satu. Informasi setiap buku ditampilkan secara terformat ke layar.

#### Output:


Dari output tersebut dapat kita ketahui data mengenai tiga Daftar Buku. Dimana untuk buku ke-1 berjudul The Alpha Girl's Guide, lalu buku ke-2 berjudul Sapiens di Ujung Tanduk, dan buku ke-3 berjudul Almond, dengan masing-masing karakteristik buku dapat dilihat pada gambar di atas.  

#### Full code Screenshot:


Dengan demikian, dapat disimpulkan bahwa program di atas mendeklarasikan array dari struktur buku dan berhasil memasukkan serta menampilkan data buku-buku dalam array. Setiap elemen dari array daftarBuku mewakili satu buku dengan anggota judul, pengarang, penerbit, tebal halaman, dan harga buku yang sesuai. 

## Kesimpulan
Ringkasan dan interpretasi pandangan saya dari hasil praktikum dan pembelajaran yang didapat yaitu:
- Hasil Praktikum

Hasil dari praktikum kelima ini, saya menjadi tahu mengenai konsep dasar struct dan implementasinya. Ternyata dalam penulisan struct tidak berpatokan pada 1 format penulisan, melainkan terdapat banyak format dalam penulisannya. Bukan hanya itu, saya juga menjadi tahu mengenai dasar variabel, jenis variabel yang dimana dibagi menjadi 2 yaitu variabel lokal dan variabel global, serta format penulisan variabel. 

- Pembelajaran yang didapat

Pada praktikum kelima ini, saya mendapat pembelajaran yang banyak dan berarti. Saya banyak belajar mengenai implementasi struct pada program c++ dan juga menerapkan array pada struct. Semua itu adalah pembelajaran baru dan tentunya bermanfaat untuk saya kedepannya. Kemudian saya juga tetap banyak belajar dari evaluasi praktikum sebelumnya agar lebih baik lagi.

## Referensi
[1] R. Firliana, M.Kom, dan P. Kasih, M.Kom, Algoritma & Pemrograman C++. Nganjuk: Adjie Media Nusantara, Januari 2018.

[2] M. Nugraha, Dasar Pemrograman Dengan C++ Materi Paling Dasar Untuk Menjadi Programmer Berbagai Platform. Deepublish, 2021.

[3] A. Huda, N. Ardi, A. Muabi, PENGANTAR CODING BERBASIS C/C++. Padang: UNP PRESS, 2021