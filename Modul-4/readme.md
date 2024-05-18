# <h1 align="center">Laporan Praktikum Modul Struct</h1>
<p align="center">Afifah Faiqatuzzahra</p>

## Dasar Teori



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

## Implementasi Kode Sequential Search

Berikut adalah implementasi kode Sequential Search yang Anda berikan:

```c++
#include <iostream>

using namespace std;

int main() {
  int n = 10; // Jumlah elemen array
  int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}; // Array data
  int cari = 10; // Nilai yang dicari
  int ketemu = false; // Flag untuk menandakan apakah nilai ditemukan
  int i;

  // Algoritma Sequential Search
  for (i = 0; i < n; i++) {
    if (data[i] == cari) {
      ketemu = true; // Nilai ditemukan
      break; // Keluar dari loop jika nilai ditemukan
    }
  }

  cout << "\t Program Sequential Search Sederhana\n" << endl;
  cout << " data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;

  if (ketemu) {
    cout << "\n angka " << cari << " ditemukan pada indeks ke-" << i << endl;
  } else {
    cout << cari << " tidak dapat ditemukan pada data." << endl;
  }

  return 0;
}
```

**Penjelasan kode:**

1. **Baris 1-3:** Memuat pustaka `iostream` dan namespace `std`.
2. **Baris 5-6:** Mendeklarasikan variabel `n` untuk menyimpan jumlah elemen array, dan `data` sebagai array integer berukuran `n`. Array diinisialisasi dengan nilai-nilai yang diberikan.
3. **Baris 7:** Mendeklarasikan variabel `cari` untuk menyimpan nilai yang ingin dicari.
4. **Baris 8:** Mendeklarasikan variabel `ketemu` sebagai flag boolean untuk menandakan apakah nilai yang dicari ditemukan. Diinisialisasi dengan `false`.
5. **Baris 9:** Mendeklarasikan variabel `i` sebagai counter untuk iterasi loop.
6. **Baris 11-17:** Loop `for` yang iterasi dari elemen pertama array hingga elemen terakhir. Di dalam loop:
    * Kondisi `if` memeriksa apakah elemen array saat ini (`data[i]`) sama dengan nilai yang dicari (`cari`).
      * Jika sama, flag `ketemu` diubah menjadi `true` dan loop dihentikan menggunakan `break`.
7. **Baris 20-24:** Menampilkan pesan "Program Sequential Search Sederhana" dan array `data`.
8. **Baris 26-31:** Kondisi `if` untuk memeriksa flag `ketemu`.
    * Jika `ketemu` adalah `true`, pesan "Nilai ditemukan" ditampilkan beserta indeks di mana nilai tersebut ditemukan.
    * Jika `ketemu` adalah `false`, pesan "Nilai tidak ditemukan" ditampilkan.
9. **Baris 32:** Mengembalikan nilai 0 dari fungsi `main`.

**Analisis Algoritma:**

* Algoritma ini menggunakan pendekatan pencarian **berurutan** untuk menemukan nilai yang dicari dalam array.
* Kompleksitas waktu algoritma ini adalah **O(n)**, di mana `n` adalah jumlah elemen dalam array.
* Algoritma ini **tidak memerlukan** array yang terurut untuk bekerja.
* Algoritma ini **mudah dipahami** dan **diimplementasikan**.

### Output


## Kesimpulan


### Full code screenshot


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

**Penjelasan kode:**

**Fungsi `selection_sort()`:**

* Fungsi ini mengimplementasikan algoritma **Selection Sort** untuk mengurutkan array `Data`.
* Algoritma ini bekerja dengan cara menemukan elemen terkecil dalam array dan menukarnya dengan elemen pertama, kemudian mencari elemen terkecil kedua dan menukarnya dengan elemen kedua, dan seterusnya.
* Algoritma ini memiliki kompleksitas waktu **O(n^2)**, di mana `n` adalah jumlah elemen dalam array.

**Fungsi `binarysearch()`:**

* Fungsi ini mengimplementasikan algoritma **Binary Search** untuk mencari nilai `cari` dalam array `Data` yang telah diurutkan.
* Algoritma ini bekerja dengan cara membagi array menjadi dua bagian secara berulang, dan memeriksa di bagian mana nilai `cari` berada.
* Algoritma ini memiliki kompleksitas waktu **O(log n)**, di mana `n` adalah jumlah elemen dalam array.

**Fungsi `main()`:**

* Fungsi ini adalah fungsi utama program.
* Fungsi ini menampilkan judul program, menampilkan data awal, meminta pengguna untuk memasukkan nilai yang ingin dicari, mengurutkan data dengan menggunakan fungsi `selection_sort()`, menampilkan data yang telah diurutkan, dan mencari nilai yang dicari dengan menggunakan fungsi `binarysearch()`.

### Output
![Screenshot (165)]

da

## Unguided1
```c++

```

## Implementasi



### Full Screenshot
![Screenshot (165)](https://github.com/AFaiqatuzzahra/Praktikum-Algoritma-Pemrograman-dan-Struktur-Data/assets/152428747/fcd31570-adfe-4aa3-9f88-0f88827c70d7)

[1]. GeeksforGeeks, “Priority queue in C++,” GeeksforGeeks. Dec. 12, 2019. [Online]. Available: https://www.geeksforgeeks.org/videos/priority-queue-in-c/.
[2] D. W. Jjones, "Concurrent operations on priority queues," Commun. ACM, vol. 32, no. Jan. 1989, pp. 132-137, 1989. DOI https://doi.org/10.1145/63238.63249.
[3]. “Heap Data Structure,” GeeksforGeeks. https://www.geeksforgeeks.org/heap-data-structure/.
‌[4]. E. Q. a. Z. P. a. H. J. Vintila, "MESH: A Memory-Efficient Safe HEap for C/C++," Association for Computing Macinery, p. 10, 2021. https://doi.org/10.1145/3465481.3465760.