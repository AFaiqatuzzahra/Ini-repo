# <h1 align="center">Laporan Praktikum Modul Priority Queue and Heaps</h1>
<p align="center">Afifah Faiqatuzzahra</p>

## Dasar Teori
Priority Queue (Antrian Prioritas) dalam C++ adalah struktur data yang menyimpan elemen berdasarkan prioritasnya. Elemen dengan prioritas tertinggi (nilai terbesar) selalu berada di posisi terdepan antrian. Hal ini memungkinkan akses cepat ke elemen dengan prioritas tinggi, yang membuatnya ideal untuk peng-aplikasi di mana waktu respons sangat penting[1], dalam priority queue operasi mendasar adalah enqueue dan dequeue, Keuntungan dalam implementasi ini memungkinkan beberapa proses untuk mengakses antrian prioritas secara bersamaan, berpotensi meningkatkan kinerja aplikasi yang menggunakannya, namun kekurangannya adalah implementasi ini lebih kompleks dibandingkan dengan implementasi antrian prioritas sekuensial. [2]
Heap (tumpukan) adalah struktur data berupa pohon biner lengkap yang memenuhi sifat heap: untuk setiap node (simpul), nilai dari anak-anaknya harus kurang dari atau sama dengan nilai node itu sendiri. Heap biasanya digunakan untuk mengimplementasikan antrian prioritas, di mana elemen terkecil (atau terbesar) selalu berada di akar pohon.[3] Karakteristik Utama Heaps:
Sifat Heap Max/Min: Dalam heap max, elemen di setiap sub-pohon selalu memiliki nilai lebih kecil atau sama dengan nilai akarnya. Sebaliknya, dalam heap min, elemen di setiap sub-pohon selalu memiliki nilai lebih besar atau sama dengan nilai akarnya.
Sifat Struktur: Heaps selalu terstruktur sebagai pohon biner lengkap, di mana setiap node memiliki maksimal dua anak.
Efisiensi Operasi: Heaps menawarkan operasi enqueue (memasukkan elemen) dan dequeue (menghapus elemen) yang efisien dengan kompleksitas waktu O(log n), di mana n adalah jumlah elemen dalam heap. [4]


## Guided

```C++
#include <iostream>
#include<algorithm>

int H[50];
int heapSize = -1;

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return ((2 * i)+ 1);
}

int rightChild(int i) {
    return((2 * i) + 2);
}

void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[1]) {
        std::swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapSize && H[1] > H[maxIndex]) {
        maxIndex = 1;
    }
    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        std::swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

int extractMax() {
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    return H[0];
}

void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

int main() {
    insert(45);
    insert(20);
    insert(14);
    insert(12);
    insert(31);
    insert(7);
    insert(11);
    insert(13);
    insert(7);

    std::cout << "Priority Queue : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Node with maximum priority :" << extractMax() << "\n";

    std::cout << "Priority queue after extracting maximum :";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    changePriority(2, 49);
    std::cout << "Priority queue adter priority change :";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    remove(3);
    std::cout << "Priority queue after removing the element :";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << "  ";
    }
    return 0;
}
```
## Implementasi 

**Header yang Digunakan:**

* `<iostream>`: Header untuk input dan output standar (misalnya, mencetak ke konsol).
* `<algorithm>`: Header yang menyediakan algoritma standar, seperti `std::swap` yang digunakan untuk menukar elemen array.

**Array dan Variabel Global:**

* `H[50]`: Array yang digunakan untuk menyimpan elemen-elemen heap. Ukuran maksimum heap adalah 50.
* `heapSize`: Variabel yang melacak jumlah elemen saat ini di dalam heap. Awalnya bernilai -1 karena heap masih kosong.

**Fungsi-fungsi yang Digunakan:**

* `parent(int i)`: Fungsi ini menghitung indeks parent dari elemen di indeks `i`.
* `leftChild(int i)`: Fungsi ini menghitung indeks anak kiri dari elemen di indeks `i`.
* `rightChild(int i)`: Fungsi ini menghitung indeks anak kanan dari elemen di indeks `i`.
* `shiftUp(int i)`: Fungsi ini melakukan perbaikan ke atas (shiftUp) pada elemen di indeks `i`. Digunakan untuk menjaga struktur heap maksimum, yaitu elemen parent harus lebih besar dari atau sama dengan anak-anaknya.
* `shiftDown(int i)`: Fungsi ini melakukan perbaikan ke bawah (shiftDown) pada elemen di indeks `i`. Digunakan untuk menjaga struktur heap maksimum setelah melakukan operasi seperti `extractMax` atau `changePriority`.
* `insert(int p)`: Fungsi ini memasukkan elemen baru `p` ke dalam heap. Elemen baru ditempatkan di posisi terakhir heap, kemudian dilakukan perbaikan ke atas untuk menjaga struktur heap.
* `extractMax()`: Fungsi ini mengekstrak elemen dengan prioritas tertinggi (nilai terbesar) dari heap. Elemen yang diekstrak dikembalikan oleh fungsi. Setelah ekstraksi, dilakukan perbaikan ke bawah untuk menjaga struktur heap.
* `changePriority(int i, int p)`: Fungsi ini mengubah prioritas elemen di indeks `i` menjadi nilai `p`. Fungsi ini kemudian melakukan perbaikan ke atas atau ke bawah tergantung apakah prioritas baru lebih besar atau lebih kecil dari prioritas sebelumnya.
* `getMax()`: Fungsi ini mengembalikan elemen dengan prioritas tertinggi (nilai terbesar) tanpa mengeluarkannya dari heap.
* `remove(int i)`: Fungsi ini menghapus elemen di indeks `i` dari heap. Elemen yang akan dihapus diganti terlebih dahulu dengan elemen yang memiliki prioritas tertinggi, kemudian dilakukan perbaikan ke bawah untuk menjaga struktur heap.

**Fungsi Utama (main):**

1. Memasukkan beberapa elemen ke dalam heap menggunakan fungsi `insert`.
2. Mencetak isi heap saat ini.
3. Mengekstrak elemen dengan prioritas tertinggi menggunakan `extractMax` dan mencetaknya.
4. Mencetak isi heap setelah ekstraksi.
5. Mengubah prioritas elemen di indeks 2 menjadi nilai yang lebih tinggi (49) menggunakan `changePriority`.
6. Mencetak isi heap setelah perubahan prioritas.
7. Menghapus elemen di indeks 3 menggunakan `remove`.
8. Mencetak isi heap setelah penghapusan.

### Output
![Screenshot (164)](https://github.com/AFaiqatuzzahra/Praktikum-Algoritma-Pemrograman-dan-Struktur-Data/assets/152428747/45defcf9-d608-4beb-bc0f-bc49dd97cfe0)

## Kesimpulan

Output kode program memberikan wawasan berharga tentang implementasi dan operasi struktur data Heap Maksimum. Ini menunjukkan pengelolaan elemen secara efisien berdasarkan prioritas, menjadikannya alat serbaguna untuk berbagai aplikasi, seperti Antrian Prioritas dan algoritma seperti Heap Sort.

### Full code screenshot
![Screenshot (164)](https://github.com/AFaiqatuzzahra/Praktikum-Algoritma-Pemrograman-dan-Struktur-Data/assets/152428747/45defcf9-d608-4beb-bc0f-bc49dd97cfe0)


## Unguided1
```C++
#include <iostream>
#include <algorithm>

int H[50];
int heapSize = -1;

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return ((2 * i) + 1);
}

int rightChild(int i) {
    return ((2 * i) + 2);
}

void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        std::swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = l;
    }
    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        std::swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

int extractMax() {
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    return H[0];
}

void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

int main() {
    int n, element;
    std::cout << "Enter the number of elements to insert: ";
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::cout << "Enter element " << i + 1 << ": ";
        std::cin >> element;
        insert(element);
    }

    std::cout << "Priority Queue: ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Node with maximum priority: " << extractMax() << "\n";

    std::cout << "Priority queue after extracting maximum: ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    int index, newPriority;
    std::cout << "Enter the index of the element to change priority: ";
    std::cin >> index;
    std::cout << "Enter the new priority value: ";
    std::cin >> newPriority;

    changePriority(index, newPriority);

    std::cout << "Priority queue after priority change: ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Enter the index of the element to remove: ";
    std::cin >> index;

    remove(index);

    std::cout << "Priority queue after removing the element: ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
```
## Implementasi 

Kode ini mengimplementasikan struktur data **Heap Maksimum** dalam bahasa pemrograman C++. Heap Maksimum adalah struktur data khusus yang efisien untuk menyimpan elemen berdasarkan prioritasnya. Elemen dengan prioritas tertinggi (nilai terbesar) selalu berada di posisi teratas (indeks 0) heap. 
**Header yang Digunakan:**

* `<iostream>`: Header ini menyediakan fungsi input dan output standar, seperti `std::cin` untuk membaca input dari pengguna dan `std::cout` untuk mencetak output ke konsol.
* `<algorithm>`: Header ini menyediakan algoritma standar, seperti `std::swap` yang digunakan untuk menukar elemen array.

**Array dan Variabel Global:**

* `H[50]`: Array yang digunakan untuk menyimpan elemen-elemen heap. Ukuran maksimum heap adalah 50 elemen.
* `heapSize`: Variabel yang melacak jumlah elemen saat ini di dalam heap. Awalnya bernilai -1 karena heap masih kosong.

**Fungsi-fungsi yang Digunakan:**

* `parent(int i)`: Fungsi ini menghitung indeks parent dari elemen di indeks `i`.
* `leftChild(int i)`: Fungsi ini menghitung indeks anak kiri dari elemen di indeks `i`.
* `rightChild(int i)`: Fungsi ini menghitung indeks anak kanan dari elemen di indeks `i`.
* `shiftUp(int i)`: Fungsi ini melakukan perbaikan ke atas (shiftUp) pada elemen di indeks `i`. Digunakan untuk menjaga struktur heap maksimum, yaitu elemen parent harus lebih besar dari atau sama dengan anak-anaknya.
* `shiftDown(int i)`: Fungsi ini melakukan perbaikan ke bawah (shiftDown) pada elemen di indeks `i`. Digunakan untuk menjaga struktur heap maksimum setelah melakukan operasi seperti `extractMax` atau `changePriority`.
* `insert(int p)`: Fungsi ini memasukkan elemen baru `p` ke dalam heap. Elemen baru ditempatkan di posisi terakhir heap, kemudian dilakukan perbaikan ke atas untuk menjaga struktur heap.
* `extractMax()`: Fungsi ini mengekstrak elemen dengan prioritas tertinggi (nilai terbesar) dari heap. Elemen yang diekstrak dikembalikan oleh fungsi. Setelah ekstraksi, dilakukan perbaikan ke bawah untuk menjaga struktur heap.
* `changePriority(int i, int p)`: Fungsi ini mengubah prioritas elemen di indeks `i` menjadi nilai `p`. Fungsi ini kemudian melakukan perbaikan ke atas atau ke bawah tergantung apakah prioritas baru lebih besar atau lebih kecil dari prioritas sebelumnya.
* `getMax()`: Fungsi ini mengembalikan elemen dengan prioritas tertinggi (nilai terbesar) tanpa mengeluarkannya dari heap.
* `remove(int i)`: Fungsi ini menghapus elemen di indeks `i` dari heap. Elemen yang akan dihapus diganti terlebih dahulu dengan elemen yang memiliki prioritas tertinggi, kemudian dilakukan perbaikan ke bawah untuk menjaga struktur heap.

**Fungsi Utama (main):**

1. **Meminta Input dari Pengguna:**
   - Program meminta pengguna untuk memasukkan jumlah elemen yang ingin dimasukkan ke dalam heap menggunakan `std::cin`.

2. **Memasukkan Elemen ke dalam Heap:**
   - Kode menggunakan loop `for` untuk membaca elemen dari pengguna (menggunakan `std::cin`) dan memasukkannya ke dalam heap menggunakan fungsi `insert`.

3. **Mencetak Heap Saat Ini:**
   - Program mencetak isi heap saat ini menggunakan loop `for` dan `std::cout`.

4. **Mengekstrak Elemen dengan Prioritas Tertinggi:**
   - Fungsi `extractMax` digunakan untuk mengekstrak elemen dengan prioritas tertinggi dari heap. Elemen yang diekstrak kemudian dicetak menggunakan `std::cout`.

5. **Mencetak Heap setelah Ekstraksi:**
   - Program mencetak isi heap setelah ekstraksi menggunakan loop `for` dan `std::cout`.

6. **Meminta Input untuk Mengubah Prioritas:**
   - Program meminta pengguna untuk memasukkan indeks elemen yang ingin diubah prioritasnya dan nilai prioritas baru menggunakan `std::cin`.

7. **Mengubah Prioritas Elemen:**
   - Fungsi `changePriority` digunakan untuk mengubah prioritas elemen di indeks yang ditentukan menjadi nilai prioritas baru.

8. **Mencetak Heap setelah Perubahan Prioritas:**
   - Program mencetak isi heap setelah perubahan prioritas menggunakan loop `for` dan `std::cout`.

9. **Meminta Input untuk Menghapus Elemen:**
   - Program meminta pengguna untuk memasukkan indeks elemen yang ingin dihapus dari heap menggunakan `std::cin`.

10. **Menghapus Elemen dari Heap:**
   - Fungsi `remove` digunakan untuk menghapus elemen di indeks yang ditentukan dari heap.

11. **Mencetak Heap setelah Penghapusan:**
   - Program mencetak isi heap setelah penghapusan menggunakan loop `for`
### Output
![Screenshot (165)](https://github.com/AFaiqatuzzahra/Praktikum-Algoritma-Pemrograman-dan-Struktur-Data/assets/152428747/fcd31570-adfe-4aa3-9f88-0f88827c70d7)

daei output tersebut dapat diketahui bahwa user memasukkan 5 elemen kemudian elemen 1 dengan nilai 23, kemudian 1,43,3,6. setelah di-enter code mengeluarkan maximum priority yakni 43, sehingga dihasilkan 23,6,3,1. kemudian code memberikan pertanyaan endex yang akan diganti di index keberapa, dan user memasukkan index ke-2 dengan nilai 13, maka dihasilkan 23,6,13,1 dan terakhir kode menanyakan index mana yang akan dihapus dan user memasukkan index ke 3 sehingga hasil akhihr menjadi 23,6,13.

### Full Screenshot
![Screenshot (165)](https://github.com/AFaiqatuzzahra/Praktikum-Algoritma-Pemrograman-dan-Struktur-Data/assets/152428747/fcd31570-adfe-4aa3-9f88-0f88827c70d7)

[1]. GeeksforGeeks, “Priority queue in C++,” GeeksforGeeks. Dec. 12, 2019. [Online]. Available: https://www.geeksforgeeks.org/videos/priority-queue-in-c/.
[2] D. W. Jjones, "Concurrent operations on priority queues," Commun. ACM, vol. 32, no. Jan. 1989, pp. 132-137, 1989. DOI https://doi.org/10.1145/63238.63249.
[3]. “Heap Data Structure,” GeeksforGeeks. https://www.geeksforgeeks.org/heap-data-structure/.
‌[4]. E. Q. a. Z. P. a. H. J. Vintila, "MESH: A Memory-Efficient Safe HEap for C/C++," Association for Computing Macinery, p. 10, 2021. https://doi.org/10.1145/3465481.3465760.
