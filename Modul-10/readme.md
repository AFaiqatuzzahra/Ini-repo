# <h1 align="center">Laporan Praktikum Modul Rekursif</h1>
<p align="center">Afifah Faiqatuzzahra</p>

## Dasar Teori


## Guided1

```C++
#include <iostream>

using namespace std;

void countdown(int n) {
    if (n == 0) {
        return;
    }

    cout << n << " ";
    countdown(n - 1);
}

int main() {
    cout << "Rekursi Langsung:";
    countdown(5);
    cout << endl;
    return 0;
}
```
## Implementasi 

1. **Fungsi `countdown(int n)`:**
   - Fungsi ini menerima argumen `n`, yang merupakan angka awal hitung mundur.
   - **Kondisi Dasar:** Jika `n` mencapai 0, fungsi ini tidak melakukan apa-apa (mengembalikan nilai `void`). Ini menghentikan proses rekursi.
   - **Langkah Rekursi:** Jika `n` lebih besar dari 0, fungsi ini melakukan dua hal:
      - Menampilkan nilai `n` saat ini ke konsol.
      - Memanggil dirinya sendiri (`countdown(n - 1)`) secara rekursif dengan nilai `n` dikurangi 1.

2. **Fungsi `main()`:**
   - Fungsi utama program.
   - Menampilkan teks "Rekursi Langsung: ".
   - Memanggil fungsi `countdown(5)`, memulai hitung mundur dari 5.
   - Menampilkan karakter baris baru (`endl`) untuk kerapian.

**Output:**
![Screenshot (210)](https://github.com/AFaiqatuzzahra/Praktikum-Algoritma-Pemrograman-dan-Struktur-Data/assets/152428747/488e70c2-f464-41de-96d2-ae4793df106a)

Ketika menjalankan program ini, outputnya akan menjadi:

```
Rekursi Langsung: 5 4 3 2 1 
```

Ini menunjukkan hitung mundur dari 5 hingga 1, seperti yang diinginkan.

**Cara Kerja Rekursi:**

1. Fungsi `countdown(5)` dipanggil.
2. Karena 5 bukan 0, angka 5 ditampilkan, dan fungsi `countdown(4)` dipanggil.
3. Langkah 2 berulang hingga fungsi `countdown(0)` dipanggil.
4. Karena 0 adalah kondisi dasar, rekursi berhenti dan fungsi-fungsi yang dipanggil sebelumnya kembali satu per satu.

Proses ini menghasilkan urutan tampilan angka dari 5 hingga 1.

## Kesimpulan
Kode ini adalah contoh sederhana dari penggunaan rekursi dalam C++. Rekursi adalah konsep pemrograman di mana suatu fungsi memanggil dirinya sendiri. Dalam contoh ini, rekursif digunakan untuk melakukan tugas berulang (menampilkan angka) hingga kondisi tertentu terpenuhi (n mencapai 0).

### Full code screenshot
![Screenshot (210)](https://github.com/AFaiqatuzzahra/Praktikum-Algoritma-Pemrograman-dan-Struktur-Data/assets/152428747/488e70c2-f464-41de-96d2-ae4793df106a)

## Guided2
```C++
#include <iostream>

using namespace std;

void functionB(int n);

void functionA(int n) {
    if (n > 0) {
        cout << n << " ";
        functionB(n - 1);
    }
}

void functionB(int n) {
    if (n > 0) {
        cout << n << " ";
        functionA(n / 2);
    }
}

int main() {
    int  num = 5;
    cout << " Rekursif tidak langsung:";
    functionA(num);
    return 0;
}
```
## Implementasi 

**Penjelasan:**

1. **Rekursi Tidak Langsung:**
   - Program ini menggunakan dua fungsi rekursif (`functionA` dan `functionB`) yang saling memanggil satu sama lain. Ini disebut rekursi tidak langsung.
   - Rekursi berhenti ketika `n` mencapai 0 pada salah satu fungsi.

2. **Pola Output:**
   - Program ini menghasilkan pola angka yang unik. 
   - `functionA` mencetak nilai `n`, kemudian memanggil `functionB` dengan `n - 1`.
   - `functionB` mencetak nilai `n`, kemudian memanggil `functionA` dengan `n / 2`.
   - Pola ini terus berlanjut hingga `n` mencapai 0 di salah satu fungsi.

3. **Output:**
   - Jika menjalankan kode ini dengan `num = 5`, maka akan mendapatkan output berikut:

   ```
   Rekursi Tidak Langsung: 5 4 2 1 0
   ```

**Cara Kerja Rekursi Tidak Langsung:**

1. `main()` memanggil `functionA(5)`.
2. `functionA(5)` mencetak 5, lalu memanggil `functionB(4)`.
3. `functionB(4)` mencetak 4, lalu memanggil `functionA(2)`.
4. `functionA(2)` mencetak 2, lalu memanggil `functionB(1)`.
5. `functionB(1)` mencetak 1, lalu memanggil `functionA(0)`.
6. `functionA(0)` tidak melakukan apa-apa (kasus dasar).
7. Rekursi berhenti dan fungsi-fungsi kembali satu per satu.

### Output
![Screenshot (211)](https://github.com/AFaiqatuzzahra/Praktikum-Algoritma-Pemrograman-dan-Struktur-Data/assets/152428747/283f1640-47b3-4382-ae4d-744c2d826f3c)

dari output tersebut dapat diketahui bahwa code tersebut mengimplementasikan rekursi tidak langsung. Ini terlihat dari adanya dua fungsi, functionA dan functionB, yang saling memanggil satu sama lain.
Outputnya adalah urutan angka 5, 4, 2, 1. Ini menunjukkan bahwa proses rekursi dimulai dari angka 5, kemudian menurun hingga mencapai base case (0), dan akhirnya kembali naik mencetak angka-angka yang tersisa.

### Full Screenshot
![Screenshot (211)](https://github.com/AFaiqatuzzahra/Praktikum-Algoritma-Pemrograman-dan-Struktur-Data/assets/152428747/283f1640-47b3-4382-ae4d-744c2d826f3c)

## Unguided1
```c++
#include <iostream>

using namespace std;

unsigned long long factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int n;
    
    cout << "Masukkan bilangan bulat positif: ";
    cin >> n;

    if (n < 0) {
        cout << "Input tidak valid. Masukkan bilangan bulat positif." << endl;
    } else {
        unsigned long long result = factorial(n);
        cout << "Faktorial dari " << n << " adalah: " << result << endl;
    }

    return 0;
}
```
## Implementasi

1. **Header `iostream`:**
   - Digunakan untuk operasi input/output (misalnya, `cout` untuk menampilkan teks di layar dan `cin` untuk menerima input dari pengguna).

2. **`using namespace std`:**
   - Untuk menghindari penulisan `std::` setiap kali kita menggunakan elemen dari pustaka standar (seperti `cout` dan `cin`).

3. **Fungsi `factorial(int n)`:**
   - Ini adalah fungsi rekursif yang menghitung faktorial.
   - **Base Case:** Jika `n` adalah 0, kembalikan 1 (faktorial dari 0 adalah 1).
   - **Recursive Case:** Jika tidak, kembalikan `n` dikalikan dengan hasil pemanggilan rekursif `factorial(n - 1)`.

4. **Fungsi `main()`:**
   - **Deklarasi Variabel:** Mendeklarasikan variabel `n` untuk menyimpan input pengguna.
   - **Input Pengguna:**
     - Menampilkan pesan kepada pengguna untuk memasukkan bilangan bulat positif.
     - Membaca input pengguna dan menyimpannya dalam variabel `n`.
   - **Validasi Input:**
     - Memeriksa apakah `n` kurang dari 0 (input tidak valid).
     - Jika tidak valid, tampilkan pesan kesalahan.
   - **Perhitungan Faktorial:**
     - Jika input valid, panggil fungsi `factorial(n)` untuk menghitung faktorial.
     - Simpan hasilnya dalam variabel `result`.
   - **Output:**
     - Tampilkan hasil faktorial kepada pengguna.
   - **Pengembalian Nilai:** Mengembalikan 0 untuk menunjukkan eksekusi program yang berhasil.

**Cara Menjalankan Kode:**

1. **Simpan:** Simpan kode ini dalam file dengan ekstensi `.cpp` (misalnya, `faktorial.cpp`).
2. **Kompilasi:** Gunakan kompiler C++ (seperti g++) untuk mengkompilasi kode:
   ```bash
   g++ -o faktorial faktorial.cpp
   ```
3. **Eksekusi:** Jalankan program yang dihasilkan:
   ```bash
   ./faktorial
   ```
### Output
![Screenshot (212)](https://github.com/AFaiqatuzzahra/Praktikum-Algoritma-Pemrograman-dan-Struktur-Data/assets/152428747/e9a56d81-301d-4a5c-88d0-5e44b25bc1f8)

Kode C++ yang diberikan berfungsi dengan baik untuk menghitung dan menampilkan faktorial dari bilangan bulat positif. Kode ini juga memiliki validasi input dasar dan menggunakan rekursi untuk perhitungan faktorial.

### Full code screenshot
![Screenshot (212)](https://github.com/AFaiqatuzzahra/Praktikum-Algoritma-Pemrograman-dan-Struktur-Data/assets/152428747/e9a56d81-301d-4a5c-88d0-5e44b25bc1f8)






[1]. GeeksforGeeks, “Priority queue in C++,” GeeksforGeeks. Dec. 12, 2019. [Online]. Available: https://www.geeksforgeeks.org/videos/priority-queue-in-c/.
[2] D. W. Jjones, "Concurrent operations on priority queues," Commun. ACM, vol. 32, no. Jan. 1989, pp. 132-137, 1989. DOI https://doi.org/10.1145/63238.63249.
[3]. “Heap Data Structure,” GeeksforGeeks. https://www.geeksforgeeks.org/heap-data-structure/.
‌[4]. E. Q. a. Z. P. a. H. J. Vintila, "MESH: A Memory-Efficient Safe HEap for C/C++," Association for Computing Macinery, p. 10, 2021. https://doi.org/10.1145/3465481.3465760.
