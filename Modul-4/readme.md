# <h1 align="center">Laporan Praktikum Modul Searching</h1>
<p align="center">Afifah Faiqatuzzahra</p>

## Dasar Teori
Binary search adalah algoritma pencarian yang efisien dan serbaguna yang banyak digunakan dalam berbagai aplikasi. Algoritma ini memiliki waktu rata-rata O(log n), yang menjadikannya salah satu algoritma pencarian tercepat yang tersedia. Implementasi algoritma ini relatif sederhana dan mudah dipahami, dan berbagai sumber daya tersedia untuk mempelajari lebih lanjut tentang algoritma ini.[1] Cara kerja Pencarian Binary didasarkan pada prinsip memecah belah (divide and conquer).  Algoritma ini berulang kali membagi array menjadi dua bagian kira-kira sama besarnya, kemudian membandingkan nilai target yang ingin dicari dengan elemen tengah dari array tersebut. [1]
Pencarian Sequential (Sequential Search), juga dikenal sebagai Pencarian Beruntun, adalah algoritma pencarian yang paling sederhana untuk menemukan elemen tertentu dalam suatu array.
Cara kerja Pencarian Sequential didasarkan pada pemeriksaan elemen array secara berurutan, mulai dari elemen pertama hingga elemen terakhir[2]


## Guided

```C++
#include <iostream>

using namespace std;

int main() {
    int n = 10;
    int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10};
    int cari = 10;
    int ketemu = false;
    int i;

    // Algoritma Sequential Search
    for (i = 0; i < n; i++) {
        if(data[i] == cari) {
            ketemu = true;
            break;
        }
    }
        cout << "\t Progran Sequential Search Sederhana\n" << endl;
        cout << " data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}"<< endl;

    if (ketemu){
        cout << "\n angka "<< cari << " ditemukan pada indeks ke-" << i << endl;
    } else {
        cout << cari << " tidak dapat ditemukan pada data." << endl;
    }
    return 0;
}
```
## Implementasi 
**1. Menyertakan Pustaka:**

```c++
#include <iostream>

using namespace std;
```

Baris ini menyertakan pustaka `iostream` yang diperlukan untuk operasi input dan output data, serta menggunakan namespace `std` untuk memudahkan penggunaan fungsi dan tipe data standar C++.

**2. Deklarasi Variabel:**

```c++
int n = 10; // Ukuran array
int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}; // Array data
int cari = 10; // Nilai yang ingin dicari
int ketemu = false; // Bendera untuk menunjukkan apakah nilai ditemukan
int i; // Penghitung loop
```

Baris-baris ini mendeklarasikan beberapa variabel:

* `n`: Ukuran array, dalam contoh ini bernilai 10.
* `data`: Array berisi 10 elemen integer yang menyimpan data yang akan dicari.
* `cari`: Nilai yang ingin dicari dalam array, nilainya 10.
* `ketemu`: Variabel boolean yang awalnya bernilai `false`, menandakan nilai belum ditemukan.
* `i`: Variabel penghitung untuk loop.

**3. Implementasi Algoritma Pencarian Sequential:**

```c++
// Algoritma Pencarian Sequential
for (i = 0; i < n; i++) {
  if (data[i] == cari) {
    ketemu = true;
    break;
  }
}
```

Loop ini menerapkan algoritma Pencarian Sequential. Loop ini mengiterasi melalui array `data` dari elemen pertama (indeks 0) hingga elemen terakhir (indeks `n - 1`). Di dalam loop:

* Kondisi `if (data[i] == cari)` memeriksa apakah elemen saat ini (`data[i]`) sama dengan nilai yang dicari (`cari`).
* Jika kondisi tersebut benar, maka nilai yang dicari telah ditemukan. Bendera `ketemu` diubah menjadi `true` dan loop dihentikan menggunakan `break`.

**4. Menampilkan Output:**

```c++
cout << "\t Program Pencarian Sequential Sederhana\n" << endl;
cout << " Data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}"<< endl;

if (ketemu){
  cout << "\n Angka "<< cari << " ditemukan pada indeks ke-" << i << endl;
} else {
  cout << cari << " tidak dapat ditemukan pada data." << endl;
}
```

Baris-baris ini menggunakan pernyataan `cout` untuk menampilkan output:

* Judul program: "Program Pencarian Sequential Sederhana"
* Data array: "{9, 4, 1, 7, 5, 12, 4, 13, 4, 10}"
* Jika nilai ditemukan:
    * Pesan yang menunjukkan bahwa nilai ditemukan: "Angka 10 ditemukan pada indeks ke-3" (dengan asumsi ditemukan pada indeks 3)
* Jika nilai tidak ditemukan:
    * Pesan yang menunjukkan bahwa nilai tidak ditemukan: "10 tidak dapat ditemukan pada data."

**Menjalankan Program:**

1. Simpan kode tersebut dalam file C++ (misalnya: `pencarian_sequential.cpp`).
2. Kompilasi kode menggunakan compiler C++: `g++ pencarian_sequential.cpp -o pencarian_sequential`
3. Jalankan program yang sudah dikompilasi: `./pencarian_sequential`
Program akan menampilkan output yang disebutkan di atas, menunjukkan apakah nilai `10` ditemukan dalam array data dan pada indeks berapa.

### Output
![Screenshot (172)](https://github.com/AFaiqatuzzahra/Praktikum-Algoritma-Pemrograman-dan-Struktur-Data/assets/152428747/876634f3-e37a-4272-a868-577b0a95da70)
berdasarkan informasi pada gambar:

* **Pencarian Sequential** adalah algoritma pencarian yang paling sederhana. 
* Program ini mencari nilai `cari` (yang bernilai 10) di dalam array `data`. 
* Array `data` berisi elemen-elemen integer yaitu {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}. 
* Variabel `ketemu` merupakan flag untuk pengecekan apakah nilai yang dicari sudah ditemukan. 
* Perulangan `for` digunakan untuk iterasi mencari nilai `cari` pada setiap elemen di dalam array `data`.

Program ini berhasil menemukan nilai `10` yang disimpan pada posisi indeks ke-9 di dalam array `data`. 

### Full code screenshot
![Screenshot (172)](https://github.com/AFaiqatuzzahra/Praktikum-Algoritma-Pemrograman-dan-Struktur-Data/assets/152428747/876634f3-e37a-4272-a868-577b0a95da70)


## Guided2
```C++
#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

int Data[7] = {1, 8, 2, 5, 4, 9, 7};
int cari;

void selection_sort() {
    int temp, min, i, j;
    for (i = 0; i < 7; i++) {
        min = i;
        for (j = i + 1; j < 7; j++) {
            if (Data[j] < Data[min]) {
                min = j;
            }
        }
        temp = Data[i];
        Data[i] = Data[min];
        Data[min] = temp;
    }
}

void binarysearch() {
    // searching
    int awal, akhir, tengah, b_flag = 0;
    awal = 0;
    akhir = 7;
    while (b_flag == 0 && awal <= akhir) {
        tengah = (awal + akhir) / 2;
        if (Data[tengah] == cari) {
            b_flag = 1;
            break;
        }
        else if (Data[tengah] < cari) {
            awal = tengah + 1;
        }
        else {
            akhir = tengah - 1;
        }
    }
    if(b_flag == 1) {
        cout << "\n Data ditemukan pada index ke- " << tengah << endl;
    }
    else {
        cout << "\n Data tidak ditemukan\n";
    }
}

int main () {
    cout << "\t BINARY SEARCH " << endl;
    cout << "\n Data : ";

    //tampilkan data awal
    for (int x = 0; x < 7; x++) {
        cout << setw(3) << Data[x];
    }
    cout << endl;

    cout << "\n Masukkan data yang ingin Anda cari : ";
    cin >> cari;
    cout << "\n Data diurutkan : ";

    // urutkan data dengan selection sort
    selection_sort();

    // tampilkan data setelah diurutkan
    for (int x = 0; x < 7; x++) {
        cout << setw(3) << Data[x];
    }
    cout << endl;

    binarysearch();

    _getche();
    return EXIT_SUCCESS;
}
```
## Implementasi 
**1. Menyertakan Pustaka:**
```c++
#include <iostream>
#include <conio.h> // Hanya digunakan untuk `_getche()` di Windows
#include <iomanip> // Digunakan untuk mengatur format output
using namespace std;
```
Baris-baris ini menyertakan pustaka:

* `<iostream>` untuk operasi input dan output data
* `<conio.h>` hanya digunakan untuk fungsi `_getche()` di Windows untuk menahan program hingga tombol ditekan
* `<iomanip>` untuk mengatur format output data

**2. Deklarasi Data dan Variabel:**

```c++
int Data[7] = {1, 8, 2, 5, 4, 9, 7}; // Array data berisi 7 elemen
int cari; // Nilai yang ingin dicari
```

Baris-baris ini mendeklarasikan:

* `Data`: Array integer berisi 7 elemen yang akan diurutkan dan dicari.
* `cari`: Variabel untuk menyimpan nilai yang ingin dicari dalam array.

**3. Fungsi `selection_sort`:**

```c++
void selection_sort() {
  int temp, min, i, j;
  for (i = 0; i < 7; i++) {
    min = i;
    for (j = i + 1; j < 7; j++) {
      if (Data[j] < Data[min]) {
        min = j;
      }
    }
    temp = Data[i];
    Data[i] = Data[min];
    Data[min] = temp;
  }
}
```

Fungsi ini mengimplementasikan algoritma **Selection Sort** untuk mengurutkan array `Data`. Algoritma ini bekerja dengan cara:

1. Mencari nilai minimum dalam array yang belum diurutkan.
2. Menukar nilai minimum dengan nilai pada elemen pertama yang belum diurutkan.
3. Mengulangi langkah 1 dan 2 hingga semua elemen diurutkan.

**4. Fungsi `binarysearch`:**

```c++
void binarysearch() {
  // searching
  int awal, akhir, tengah, b_flag = 0;
  awal = 0;
  akhir = 7;
  while (b_flag == 0 && awal <= akhir) {
    tengah = (awal + akhir) / 2;
    if (Data[tengah] == cari) {
      b_flag = 1;
      break;
    }
    else if (Data[tengah] < cari) {
      awal = tengah + 1;
    }
    else {
      akhir = tengah - 1;
    }
  }
  if(b_flag == 1) {
    cout << "\n Data ditemukan pada index ke- " << tengah << endl;
  }
  else {
    cout << "\n Data tidak ditemukan\n";
  }
}
```
Fungsi ini mengimplementasikan algoritma **Binary Search** untuk mencari nilai `cari` dalam array `Data` yang telah diurutkan. Algoritma ini bekerja dengan cara:

1. Membagi array menjadi dua bagian secara berulang.
2. Membandingkan nilai `cari` dengan nilai tengah array.
3. Jika nilai `cari` sama dengan nilai tengah, maka nilai ditemukan dan posisinya dikembalikan.
4. Jika nilai `cari` lebih kecil dari nilai tengah, maka pencarian dilanjutkan pada bagian kiri array.
5. Jika nilai `cari` lebih besar dari nilai tengah, maka pencarian dilanjutkan pada bagian kanan array.
6. Jika nilai `cari` tidak ditemukan di seluruh array, maka fungsi menandakan bahwa nilai tidak ditemukan.

**5. Fungsi `main`:**

```c++
int main () {
  // Menampilkan judul program
  cout << "\t BINARY SEARCH " << endl;

  // Menampilkan data awal
  cout << "\n Data : ";
  for (int x = 0; x < 7; x++) {
    cout << setw(3) << Data[x];
  }
  cout << endl;

  // Meminta nilai yang ingin dicari
  cout << "\n Masukkan data yang ingin Anda cari : ";
  cin >> cari;

  // Mengurutkan data dengan Selection Sort
  selection_sort();

  // Menampilkan data setelah diurutkan
```

## Implementasi Kode Binary Search dan Selection Sort

Berikut adalah implementasi kode Binary Search dan Selection Sort yang Anda berikan:

```c++
#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

int Data[7] = {1, 8, 2, 5, 4, 9, 7};
int cari;

void selection_sort() {
  int temp, min, i, j;
  for (i = 0; i < 7; i++) {
    min = i;
    for (j = i + 1; j < 7; j++) {
      if (Data[j] < Data[min]) {
        min = j;
      }
    }
    temp = Data[i];
    Data[i] = Data[min];
    Data[min] = temp;
  }
}

void binarysearch() {
  // searching
  int awal, akhir, tengah, b_flag = 0;
  awal = 0;
  akhir = 7;
  while (b_flag == 0 && awal <= akhir) {
    tengah = (awal + akhir) / 2;
    if (Data[tengah] == cari) {
      b_flag = 1;
      break;
    } else if (Data[tengah] < cari) {
      awal = tengah + 1;
    } else {
      akhir = tengah - 1;
    }
  }
  if (b_flag == 1) {
    cout << "\n Data ditemukan pada index ke- " << tengah << endl;
  } else {
    cout << "\n Data tidak ditemukan\n";
  }
}

int main() {
  cout << "\t BINARY SEARCH " << endl;
  cout << "\n Data : ";

  // tampilkan data awal
  for (int x = 0; x < 7; x++) {
    cout << setw(3) << Data[x];
  }
  cout << endl;

  cout << "\n Masukkan data yang ingin Anda cari : ";
  cin >> cari;
  cout << "\n Data diurutkan : ";

  // urutkan data dengan selection sort
  selection_sort();

  // tampilkan data setelah diurutkan
  for (int x = 0; x < 7; x++) {
    cout << setw(3) << Data[x];
  }
  cout << endl;

  binarysearch();

  _getche();
  return EXIT_SUCCESS;
}
```
### Output
![Screenshot (173)](https://github.com/AFaiqatuzzahra/Praktikum-Algoritma-Pemrograman-dan-Struktur-Data/assets/152428747/39275e33-98d9-4b6d-bf21-d1c543773520)
Dari output tersebut user mencari angka 2 dan setelah diurutkan, angka 2 ditemukan pada index ke-1

### Full Screenshoot
![Screenshot (173)](https://github.com/AFaiqatuzzahra/Praktikum-Algoritma-Pemrograman-dan-Struktur-Data/assets/152428747/39275e33-98d9-4b6d-bf21-d1c543773520)

## Unguided1
```c++
#include <iostream>
#include <string>

using namespace std;

bool binarySearch(string kalimat, char target, int left, int right) {
  if (right < left) {
    return false;
  }

  int mid = left + (right - left) / 2;
  char midChar = kalimat[mid];

  if (midChar == target) {
    return true;
  } else if (midChar < target) {
    return binarySearch(kalimat, target, mid + 1, right);
  } else {
    return binarySearch(kalimat, target, left, mid - 1);
  }
}

int main() {
  string kalimat;
  char target;

  cout << "Masukkan kalimat: ";
  getline(cin, kalimat);

  cout << "Masukkan huruf yang ingin dicari: ";
  cin >> target;

  bool found = binarySearch(kalimat, target, 0, kalimat.length() - 1);

  if (found) {
    cout << "Huruf '" << target << "' ditemukan dalam kalimat." << endl;
  } else {
    cout << "Huruf '" << target << "' tidak ditemukan dalam kalimat." << endl;
  }

  return 0;
}
```

## Implementasi
**1. Penyertaan Pustaka:**

```c++
#include <iostream>
#include <string>

using namespace std;
```

Baris-baris ini menyertakan pustaka yang diperlukan:

* `iostream`: untuk operasi input dan output data.
* `string`: untuk menangani manipulasi string (kalimat).
* `using namespace std;`: untuk memudahkan penggunaan fungsi dan tipe data standar C++.

**2. Fungsi Pencarian Binary:**

```c++
bool binarySearch(string kalimat, char target, int left, int right) {
  if (right < left) {
    return false; // Target tidak ditemukan jika penunjuk kiri melampaui penunjuk kanan
  }

  int mid = left + (right - left) / 2; // Cari indeks tengah
  char midChar = kalimat[mid]; // Dapatkan karakter pada indeks tengah

  if (midChar == target) {
    return true; // Target ditemukan jika cocok dengan karakter tengah
  } else if (midChar < target) {
    return binarySearch(kalimat, target, mid + 1, right); // Cari di separuh kanan jika target lebih besar dari karakter tengah
  } else {
    return binarySearch(kalimat, target, left, mid - 1); // Cari di separuh kiri jika target lebih kecil dari karakter tengah
  }
}
```

Fungsi ini mengimplementasikan algoritma Pencarian Binary:

* Fungsi ini menerima beberapa argumen:
    * `kalimat`: Kalimat yang akan dicari (berupa string).
    * `target`: Karakter yang ingin dicari (berupa char).
    * `left`: Indeks awal pencarian (integer).
    * `right`: Indeks akhir pencarian (integer).
* Fungsi ini memiliki kondisi dasar yang mengembalikan `false` jika `right` menjadi kurang dari `left`,  menandakan target tidak ditemukan.
* Fungsi ini menghitung indeks tengah (`mid`) dari area pencarian.
* Fungsi ini mengambil karakter pada indeks tengah (`midChar`).
* Jika `midChar` cocok dengan `target`, target ditemukan dan fungsi mengembalikan `true`.
* Jika `midChar` lebih kecil dari `target`, target hanya mungkin ada di separuh kanan kalimat. Fungsi memanggil dirinya sendiri secara rekursif dengan `left` yang diperbarui (`mid + 1`) dan `right` tetap sama.
* Jika `midChar` lebih besar dari `target`, target hanya mungkin ada di separuh kiri kalimat. Fungsi memanggil dirinya sendiri secara rekursif dengan `right` yang diperbarui (`mid - 1`) dan `left` tetap sama.

**3. Fungsi Utama:**

```c++
int main() {
  string kalimat;
  char target;

  cout << "Masukkan kalimat: ";
  getline(cin, kalimat); // Menggunakan getline untuk menangani spasi dalam kalimat

  cout << "Masukkan huruf yang ingin dicari: ";
  cin >> target;

  bool found = binarySearch(kalimat, target, 0, kalimat.length() - 1);

  if (found) {
    cout << "Huruf '" << target << "' ditemukan dalam kalimat." << endl;
  } else {
    cout << "Huruf '" << target << "' tidak ditemukan dalam kalimat." << endl;
  }

  return 0;
}
```
Fungsi ini menangani interaksi pengguna dan memanggil fungsi `binarySearch`:

* Ini mendeklarasikan variabel untuk kalimat (`kalimat`) dan karakter target (`target`).
* Ini meminta pengguna untuk memasukkan kalimat menggunakan `getline` (untuk menangani spasi) dan menyimpannya di `kalimat`.
* Ini meminta pengguna untuk memasukkan karakter target dan menyimpannya di `target`.
* Ini memanggil fungsi `binarySearch` dengan kalimat, karakter target, indeks awal (`0`), dan indeks akhir (`kalimat.length() - 1`).
* Fungsi ini menyimpan hasil pencarian (`true` jika ditemukan, `false` sebaliknya) dalam variabel `found`.
* Ini menampilkan pesan yang menunjukkan apakah karakter target ditemukan dalam kalimat atau tidak.

**Menjalankan Kode:**

1. Simpan kode tersebut dalam file C++ (misalnya: `pencarian_binary_kalimat.cpp`).
2. Kompilasi kode menggunakan compiler C++: `g++ pencarian_binary_kalimat.cpp -o pencarian_binary_kalimat`
3. Jalankan program yang sudah dikompilasi: `./pencarian_binary_kalimat`

Program akan meminta Anda untuk memasukkan kalimat dan karakter, kemudian memberi tahu Anda jika karakter tersebut ditemukan dalam kalimat.
### Output
![Screenshot (174)](https://github.com/AFaiqatuzzahra/Praktikum-Algoritma-Pemrograman-dan-Struktur-Data/assets/152428747/521b1dad-9fde-47c6-bbed-c6818152c49d)
Dari output yang diberikan dapat diketahui bahwa pada kata berbahasa terdapat huruf "a"

### Full Screenshot
![Screenshot (174)](https://github.com/AFaiqatuzzahra/Praktikum-Algoritma-Pemrograman-dan-Struktur-Data/assets/152428747/521b1dad-9fde-47c6-bbed-c6818152c49d)

## Unguided2
```c++
#include <iostream>
#include <string>

using namespace std;

int countVowels(string kalimat) {
  int count = 0;
  for (char c : kalimat) {
    switch (tolower(c)) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
        count++;
        break;
    }
  }
  return count;
}

int main() {
  string kalimat;

  cout << "Masukkan kalimat: ";
  getline(cin, kalimat);

  int vowelCount = countVowels(kalimat);

  cout << "Jumlah huruf vokal dalam kalimat: " << vowelCount << endl;

  return 0;
}
```
## Implementasi

1. **Selection Sort (Pengurutan Seleksi):** Algoritma ini mengurutkan elemen-elemen dalam array `Data` secara menaik. Cara kerjanya dengan iterasi melalui array, menemukan elemen minimum dalam bagian yang belum terurut, lalu menukarnya dengan elemen pada posisi indeks tersebut. Proses ini diulang hingga seluruh elemen terurut.

2. **Binary Search (Pencarian Binary):** Algoritma ini mencari nilai tertentu (`cari`) dalam array `Data` yang sudah terurut. Cara kerjanya dengan membagi array menjadi dua bagian, membandingkan nilai target dengan elemen tengah array, kemudian secara rekursif mencari di bagian kiri atau kanan array tergantung hasil perbandingan.

**Penjelasan Detail Implementasi:**

**Fungsi `selection_sort`:**

* Tidak menerima argumen.
* Mengurutkan elemen di dalam array `Data` secara langsung (modifikasi array `Data`).
* Menggunakan loop bersarang untuk iterasi melalui array dan menemukan elemen minimum di setiap iterasi.
* Menukar elemen minimum dengan elemen yang berada pada posisi indeks saat ini.

**Fungsi `binarysearch`:**

* Tidak menerima argumen.
* Mencari nilai `cari` dalam array `Data` yang sudah terurut.
* Menggunakan pendekatan rekursif untuk membagi array menjadi dua bagian dan mempersempit area pencarian.
* Mengembalikan nilai `true` jika nilai ditemukan dan `false` jika tidak ditemukan.

**Fungsi `main`:**

* Menampilkan judul program dan array awal yang belum terurut.
* Meminta pengguna untuk memasukkan nilai yang ingin dicari (`cari`).
* Mengurutkan array `Data` menggunakan fungsi `selection_sort`.
* Menampilkan array yang sudah terurut.
* Memanggil fungsi `binarysearch` untuk mencari nilai `cari` dalam array terurut.
* Menampilkan hasil pencarian (apakah nilai tersebut ditemukan atau tidak).

Program akan menampilkan array awal, meminta memasukkan nilai yang ingin dicari, mengurutkan array, menampilkan array terurut, dan kemudian memberi tahu apakah nilai yang dimasukkan ditemukan dalam array yang sudah terurut.

### Output
![Screenshot (175)](https://github.com/AFaiqatuzzahra/Praktikum-Algoritma-Pemrograman-dan-Struktur-Data/assets/152428747/3c888b01-50ed-4b64-84ba-90d9056dcb6e)
Diketahui dari output yang diberikan, pada kata berbahagia terdapat huruf vokal yang dicari yaitu "a"

### Full code screenshoot
![Screenshot (175)](https://github.com/AFaiqatuzzahra/Praktikum-Algoritma-Pemrograman-dan-Struktur-Data/assets/152428747/3c888b01-50ed-4b64-84ba-90d9056dcb6e)

## Unguided3
```c++
#include <iostream>

using namespace std;

int main() {
  // Data yang diberikan
  int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
  int n = sizeof(data) / sizeof(data[0]); // Ukuran data

  // Inisialisasi variabel untuk menghitung jumlah angka 4
  int count = 0;

  // Algoritma Sequential Search
  for (int i = 0; i < n; i++) {
    if (data[i] == 4) {
      count++; // Hitung setiap kali angka 4 ditemukan
    }
  }

  // Tampilkan jumlah angka 4
  cout << "Jumlah angka 4 dalam data: " << count << endl;

  return 0;
}
```
### Implementasi
**1. Penyertaan Pustaka:**

```c++
#include <iostream>

using namespace std;
```

Baris ini menyertakan pustaka `iostream` yang menyediakan fungsi untuk operasi input dan output data. Pernyataan `using namespace std;` memungkinkan penggunaan fungsi dan tipe data standar C++ dengan lebih mudah, tanpa perlu menyertakan awalan `std::` setiap saat.

**2. Definisi Data dan Variabel:**

```c++
int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
int n = sizeof(data) / sizeof(data[0]); // Ukuran data
int count = 0; // Variabel untuk menghitung jumlah angka 4
```

* `data[]`: Array integer yang berisi kumpulan data yang diberikan.
* `n`: Variabel integer yang dihitung menggunakan operator `sizeof` untuk menentukan jumlah elemen dalam array `data`.
* `count`: Variabel integer yang diinisialisasi menjadi 0 untuk melacak jumlah kemunculan angka 4.

**3. Algoritma Pencarian Sequential:**

```c++
for (int i = 0; i < n; i++) {
  if (data[i] == 4) {
    count++; // Hitung setiap kali angka 4 ditemukan
  }
}
```

Looping ini beriterasi melalui array `data` dari indeks 0 hingga `n-1`. Di dalam loop:

* Pernyataan `if` memeriksa apakah elemen saat ini (`data[i]`) sama dengan nilai target (4).
* Jika kondisi tersebut benar, variabel `count` ditambah 1, menandakan bahwa satu lagi kemunculan angka 4 telah ditemukan.

**4. Tampilkan Hasil:**

```c++
cout << "Jumlah angka 4 dalam data: " << count << endl;
```

Baris ini mencetak pesan "Jumlah angka 4 dalam data:"  diikuti dengan nilai variabel `count`, yang mewakili total berapa kali angka 4 ditemukan dalam kumpulan data.

**Menjalankan Kode:**

1. Simpan kode tersebut ke dalam file C++ (misalnya: `hitung_kemunculan.cpp`).
2. Kompilasi kode menggunakan compiler C++: `g++ hitung_kemunculan.cpp -o hitung_kemunculan`
3. Jalankan program yang sudah dikompilasi: `./hitung_kemunculan`
Program akan menampilkan berapa kali angka 4 muncul dalam kumpulan data yang diberikan.

### Output
![Screenshot (176)](https://github.com/AFaiqatuzzahra/Praktikum-Algoritma-Pemrograman-dan-Struktur-Data/assets/152428747/57fa0d5c-21e5-4b16-8d8d-9ac0b18af4f8)
Dapat diketahui dari output yang diberikan bahwa angka 4 dalam data berjumlah 4.

### Full Screenshoot
![Screenshot (176)](https://github.com/AFaiqatuzzahra/Praktikum-Algoritma-Pemrograman-dan-Struktur-Data/assets/152428747/57fa0d5c-21e5-4b16-8d8d-9ac0b18af4f8)

### Referensi
[1] R. Nowak, "Generalized binary search," 2008 46th Annual Allerton Conference on Communication, Control, and Computing, Monticello, IL, USA, 2008, pp. 568-574, doi: 10.1109/ALLERTON.2008.4797609.
keywords: {Search problems;Channel coding;Particle separators;Machine learning;Design for experiments;Probability distribution;Sampling methods;Feedback;Uncertainty},

[2] Yuxin Chen, Song Yao (2016) Sequential Search with Refinement: Model and Application with Click-Stream Data. Management Science 63(12):4345-4365.
https://doi.org/10.1287/mnsc.2016.2557

