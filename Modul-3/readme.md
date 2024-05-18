# <h1 align="center">Laporan Praktikum Modul Sorting</h1>
<p align="center">Afifah Faiqatuzzahra</p>

## Dasar Teori
pengurutan (sorting) adalah proses mengatur ulang elemen-elemen dalam suatu kumpulan data (biasanya berupa array) menurut kriteria tertentu. Kriteria ini biasanya berupa urutan menaik (smallest to largest) atau menurun (largest to smallest).[1]
Dalam C++, ada beberapa ciri-ciri umum yang bisa digunakan untuk mengidentifikasi dan memahami algoritma sorting. Berikut adalah ciri-ciri umum dari berbagai algoritma sorting yang sering digunakan dalam C++:
Bubble Sort:
Sederhana: Algoritma ini sangat sederhana dan mudah diimplementasikan.
Kompleksitas Waktu: O(n^2) dalam kasus terburuk dan rata-rata, di mana n adalah jumlah elemen.
Stable: Mempertahankan urutan relatif elemen yang memiliki nilai sama.
In-place: Tidak membutuhkan ruang tambahan yang signifikan.
Selection Sort:
Sederhana: Algoritma ini mudah diimplementasikan dan dipahami.
Kompleksitas Waktu: O(n^2) dalam semua kasus.
Not Stable: Tidak selalu mempertahankan urutan relatif elemen yang memiliki nilai sama.
In-place: Tidak membutuhkan ruang tambahan yang signifikan.
Insertion Sort:
Efisien untuk Data Kecil: Sangat efisien untuk dataset yang kecil atau hampir terurut.
Kompleksitas Waktu: O(n^2) dalam kasus terburuk dan rata-rata, O(n) dalam kasus terbaik (ketika data sudah terurut).
Stable: Mempertahankan urutan relatif elemen yang memiliki nilai sama.
In-place: Tidak membutuhkan ruang tambahan yang signifikan.
Merge Sort:
Efisien: Menggunakan pendekatan divide-and-conquer.
Kompleksitas Waktu: O(n log n) dalam semua kasus.
Stable: Mempertahankan urutan relatif elemen yang memiliki nilai sama.
Not In-place: Membutuhkan ruang tambahan untuk array sementara.
Quick Sort:
Sangat Efisien untuk Data Besar: Menggunakan pendekatan divide-and-conquer.
Kompleksitas Waktu: O(n log n) rata-rata, tetapi O(n^2) dalam kasus terburuk.
Not Stable: Tidak selalu mempertahankan urutan relatif elemen yang memiliki nilai sama.
In-place: Tidak membutuhkan ruang tambahan yang signifikan.
Heap Sort:
Berbasis Heap: Menggunakan struktur data heap.
Kompleksitas Waktu: O(n log n) dalam semua kasus.
Not Stable: Tidak selalu mempertahankan urutan relatif elemen yang memiliki nilai sama.
In-place: Tidak membutuhkan ruang tambahan yang signifikan.
STL Sort (std::sort):
Optimized: Menggunakan kombinasi introspective sort (hybrid of quicksort, heapsort, and insertion sort).
Kompleksitas Waktu: O(n log n) dalam semua kasus.
Not Stable: Tidak selalu mempertahankan urutan relatif elemen yang memiliki nilai sama.
In-place: Tidak membutuhkan ruang tambahan yang signifikan.
Stable Sort (std::stable_sort):
Stable: Mempertahankan urutan relatif elemen yang memiliki nilai sama.
Kompleksitas Waktu: O(n log n) dalam semua kasus.
Not In-place: Membutuhkan ruang tambahan untuk array sementara.[2]
Kegunaan
Small Data Sets: Bubble Sort dan Insertion Sort cocok untuk dataset kecil atau yang hampir terurut.
Large Data Sets: Merge Sort, Quick Sort, dan std::sort lebih cocok untuk dataset besar karena efisiensi waktu yang lebih baik.
Stable Sorting Needs: Insertion Sort, Merge Sort, dan std::stable_sort digunakan ketika stabilitas diperlukan.[3]

## Guided 

### 1. Guided 1: Latihan Single Linked List

```C++
#include <iostream>
using namespace std;

void bubble_sort(double arr[], int length){
    bool not_sorted = true;
    int j=0;
    double tmp;

    while (not_sorted){
        not_sorted = false;
        j++;
        for (int i = 0; i < length - j; i++){
            if (arr[i] > arr[i + 1]) {
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                not_sorted = true;
            }//end of if
        }//end of for loop
    }//end of while loop
}//end of bubble_sort

void print_array(double a[], int length) {
    for(int i=0; i<length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main() {

    int length = 5;
    double a[] = {22.1, 15.3, 8.2, 33.21, 99.99};

    cout << "Urutan bilangan sebelum sorting: " << endl;
    print_array(a, length);

    bubble_sort(a, length);

    cout << "\nUrutan bilangan setelah sorting: " << endl;
    print_array(a, length);
}
```
### Implementasi
Kode ini mengurutkan array menggunakan bubble sort dan mencetak array sebelum dan sesudah pengurutan.
1. **bubble_sort**: Fungsi ini melakukan pengurutan array menggunakan algoritma bubble sort.
    - **not_sorted**: Sebuah bendera yang menunjukkan apakah array masih perlu diurutkan.
    - **j**: Menunjukkan jumlah elemen yang sudah diurutkan pada akhir array.
    - **tmp**: Variabel sementara untuk pertukaran nilai.

2. **print_array**: Fungsi ini mencetak elemen-elemen array yang diberikan.

3. **main**: Fungsi utama yang mendefinisikan array, mencetak array sebelum pengurutan, memanggil fungsi pengurutan, dan mencetak array setelah pengurutan.

#### Output:
![Screenshot (180)](https://github.com/AFaiqatuzzahra/Praktikum-Algoritma-Pemrograman-dan-Struktur-Data/assets/152428747/7717d041-efb5-4aed-af9b-3cfdd0a84cf0)

Maka, dari hasil diatas dapat diketahui bahwa:
urutan terkecil pada nilai tersebut adalah 8,2 sehingga nilai tersebut menjadi didepan, sedangkan nilai terbesar adalah 99,99 sehingga nilai tersebut diletakkan dibelakang sendiri.
 
#### Full code Screenshot:
![Screenshot (180)](https://github.com/AFaiqatuzzahra/Praktikum-Algoritma-Pemrograman-dan-Struktur-Data/assets/152428747/7717d041-efb5-4aed-af9b-3cfdd0a84cf0)


### 2. Guided 2

```C++
#include <iostream>

using namespace std;

void insertion_sort(char arr[], int length) {
    int i, j;
    char tmp;

    for (i = 1; i < length; i++) {
        j = i;

        while (j > 0 && arr[j - 1] < arr[j]) {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        }//end of while loop
    }//end of for loop
}

void print_array(char a[], int length) {

    for(int i=0; i<length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}
 int main() {
    int length = 6;
    char a[length] = {'c', 'f', 'a', 'z', 'd', 'p'};

    cout << "Urutan karakter sebelum sorting:" << endl;
    print_array(a, length);

    insertion_sort(a, length);

    cout << "\nUrutan karakter setelah sorting:" << endl;
    print_array(a, length);
 }
```
### Implementasi

1. **insertion_sort**: Fungsi ini melakukan pengurutan array menggunakan algoritma insertion sort dalam urutan menurun.
    - **i**: Indeks yang digunakan untuk iterasi pada array mulai dari elemen kedua.
    - **j**: Indeks yang digunakan untuk membandingkan dan menukar elemen.
    - **tmp**: Variabel sementara untuk pertukaran nilai.
    - **while (j > 0 && arr[j - 1] < arr[j])**: Membandingkan elemen saat ini dengan elemen sebelumnya dan menukar mereka jika elemen saat ini lebih besar.

2. **print_array**: Fungsi ini mencetak elemen-elemen array yang diberikan.

3. **main**: Fungsi utama yang mendefinisikan array karakter, mencetak array sebelum pengurutan, memanggil fungsi pengurutan, dan mencetak array setelah pengurutan.

#### Output:
![Screenshot (181)](https://github.com/AFaiqatuzzahra/Praktikum-Algoritma-Pemrograman-dan-Struktur-Data/assets/152428747/09855e77-2a09-46e9-a248-56e095ffb9e9)

PAda output yang diberikan dapat diketahui bahwa, setelah diurutkan dari belakang, huruf paling depan adalah z dan paling belakang adalah a.

#### Full code Screenshot:
![Screenshot (181)](https://github.com/AFaiqatuzzahra/Praktikum-Algoritma-Pemrograman-dan-Struktur-Data/assets/152428747/09855e77-2a09-46e9-a248-56e095ffb9e9)


### 3. Unguided1
```C++
#include <iostream>

using namespace std;

void bubble_sort(double arr [], int length){
    bool not_sorted = true;
    int j=0;
    double tmp;

    while (not_sorted){
        not_sorted = false;
        j++;
        for (int i = 0; i < length - j; i++){
            if (arr[i] > arr[i + 1]) {
                tmp = arr[i]; //
                arr[i] = arr [i + 1];
                arr[i + 1] = tmp; //
                not_sorted = true;
            }
        }
    }
}

void print_array(double a[], int length) { 
    for(int i=0; i<length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main() {
    int length = 5;
    double a[] = {3.8, 2.9, 3.3, 4.0, 2.4};

    cout << "IPS sebelum sorting:" << endl;
    print_array(a,length);

    bubble_sort(a, length);

    cout << "\nIPS setelah sorting:" << endl;
    print_array(a, length);
}
```
### Implementasi
1. **bubble_sort**: Fungsi ini melakukan pengurutan array menggunakan algoritma bubble sort.
    - **not_sorted**: Sebuah bendera yang menunjukkan apakah array masih perlu diurutkan.
    - **j**: Menunjukkan jumlah elemen yang sudah diurutkan pada akhir array.
    - **tmp**: Variabel sementara untuk pertukaran nilai.
    - **while (not_sorted)**: Melakukan iterasi hingga array sepenuhnya diurutkan.
    - **for (int i = 0; i < length - j; i++)**: Mengiterasi elemen-elemen yang belum diurutkan.
    - **if (arr[i] > arr[i + 1])**: Memeriksa apakah elemen saat ini lebih besar dari elemen berikutnya. Jika iya, elemen tersebut ditukar.

2. **print_array**: Fungsi ini mencetak elemen-elemen array yang diberikan.
    - **for (int i = 0; i < length; i++)**: Mengiterasi dan mencetak setiap elemen dari array.

3. **main**: Fungsi utama yang mendefinisikan array nilai IPS, mencetak array sebelum pengurutan, memanggil fungsi pengurutan, dan mencetak array setelah pengurutan.

### Output:
![Screenshot (177)](https://github.com/AFaiqatuzzahra/Praktikum-Algoritma-Pemrograman-dan-Struktur-Data/assets/152428747/f4e7e43d-60d0-4533-a2a3-39d7f3f8e20e)
Dari output yang diberikan dapat diketahui bahwa sebelum diurutkan data tidak terurut, namun setelah di sorting data yang paling kecil bernilai 2,4 dan terbesar adalah 4.

### Full screenshoot
![Screenshot (177)](https://github.com/AFaiqatuzzahra/Praktikum-Algoritma-Pemrograman-dan-Struktur-Data/assets/152428747/f4e7e43d-60d0-4533-a2a3-39d7f3f8e20e)

### 4. Unguided2
```c++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bubbleSort(vector<string> &names) {
    int n = names.size();
    for (int i = 0; i < n-1; i++) { 
        for (int j = 0; j < n-i-1; j++) { 
            if (names[j] > names[j+1]) {
                swap(names[j], names[j+1]); 
            }
        }
    }
}


int main() {
    vector<string> names = {"siti", "situ", "sana", "ana", 
    "ani", "caca", "cici", "dida", "dodo", "dadi"};

    cout << "Sebelum diurutkan:" << endl;
    for (const auto &name : names) {
        cout << name << " ";
    }
    cout << endl;

    bubbleSort(names); 

    cout << "\nSetelah diurutkan:" << endl;
    for (const auto &name : names) {
        cout << name << " ";
    }
    cout << endl; 

    return 0; 
}
```

### Implementasi

1. **bubbleSort**: Fungsi ini melakukan pengurutan vektor string menggunakan algoritma bubble sort.
    - **int n = names.size()**: Mendapatkan ukuran vektor.
    - **for (int i = 0; i < n - 1; i++)**: Mengiterasi elemen-elemen dari awal hingga elemen sebelum terakhir.
    - **for (int j = 0; j < n - i - 1; j++)**: Mengiterasi elemen-elemen yang belum diurutkan.
    - **if (names[j] > names[j + 1])**: Memeriksa apakah elemen saat ini lebih besar dari elemen berikutnya. Jika iya, elemen tersebut ditukar menggunakan fungsi `swap`.

2. **main**: Fungsi utama yang mendefinisikan vektor string, mencetak vektor sebelum pengurutan, memanggil fungsi pengurutan, dan mencetak vektor setelah pengurutan.
    - **vector<string> names**: Mendefinisikan dan menginisialisasi vektor string dengan beberapa nama.
    - **for (const auto &name : names)**: Mengiterasi dan mencetak setiap elemen dari vektor.

### Output
![Screenshot (178)](https://github.com/AFaiqatuzzahra/Praktikum-Algoritma-Pemrograman-dan-Struktur-Data/assets/152428747/18671538-4a34-4312-9c4b-041b7f62c275)
Dari output yang diberikan, setelah diurutkan nama paling depan adalah ana dan paling belakang adalah situ sehingga memudahkan pak RT untuk mencari data warga.

### Full code Screenshot:
![Screenshot (178)](https://github.com/AFaiqatuzzahra/Praktikum-Algoritma-Pemrograman-dan-Struktur-Data/assets/152428747/18671538-4a34-4312-9c4b-041b7f62c275)


##5. Unguided3 

```C++
#include <iostream>
using namespace std;

void insertion_sort(char arr[], int length) {
    int i, j;
    char tmp;
    for (i = 1; i < length; i++) {
        j = i;
        while (j > 0 && arr[j - 1] < arr[j]) {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        }
    }
}

void print_array(char a[], int length) {
    for(int i = 0; i < length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Masukkan jumlah karakter (n): ";
    cin >> n;

    char a[n];
    cout << "Masukkan " << n << " karakter: ";
    for(int i = 0; i < n; i++) { 
        cin >> a[i];
    }

    cout << "Urutan karakter sebelum sorting: " << endl;
    print_array(a, n);

    insertion_sort(a, n);

    cout << "\nUrutan karakter setelah sorting: " << endl;
    print_array(a, n);

    return 0;
}
```
### Implementasi
1. **insertion_sort**: Fungsi ini melakukan pengurutan array karakter menggunakan algoritma insertion sort dalam urutan menurun.
    - **for (i = 1; i < length; i++)**: Mengiterasi elemen-elemen mulai dari elemen kedua.
    - **while (j > 0 && arr[j - 1] < arr[j])**: Membandingkan elemen saat ini dengan elemen sebelumnya dan menukar mereka jika elemen saat ini lebih besar.

2. **print_array**: Fungsi ini mencetak elemen-elemen array yang diberikan.
    - **for (int i = 0; i < length; i++)**: Mengiterasi dan mencetak setiap elemen dari array.

3. **main**: Fungsi utama yang meminta pengguna untuk memasukkan jumlah karakter dan karakter itu sendiri, mencetak array sebelum pengurutan, memanggil fungsi pengurutan, dan mencetak array setelah pengurutan.
    - **cin >> n**: Meminta pengguna untuk memasukkan jumlah karakter.
    - **for (int i = 0; i < n; i++) { cin >> a[i]; }**: Meminta pengguna untuk memasukkan karakter.
    - **print_array(a, n)**: Mencetak array sebelum dan sesudah pengurutan.

### Output
![Screenshot (179)](https://github.com/AFaiqatuzzahra/Praktikum-Algoritma-Pemrograman-dan-Struktur-Data/assets/152428747/65bb72c8-ebcf-4ab1-aa00-6597ad776521)
Dari output yang diberikan, dapat diketahui bahwa user memasukkan kata beralas dan setelah disorting menjadi s r l b a a

### Full code screenshoot
![Screenshot (179)](https://github.com/AFaiqatuzzahra/Praktikum-Algoritma-Pemrograman-dan-Struktur-Data/assets/152428747/65bb72c8-ebcf-4ab1-aa00-6597ad776521)

## Referensi
[1] S. Sharma, ‘Performance comparison of Java and C++ when sorting integers and writing/reading files.’, Dissertation, 2019.

[2] O. K. Durrani, A. S. Farooqi, A. G. Chinmai and K. S. Prasad, "Performances of Sorting Algorithms in Popular Programming Languages," 2022 International Conference on Smart Generation Computing, Communication and Networking (SMART GENCON), Bangalore, India, 2022, pp. 1-7, doi: 10.1109/SMARTGENCON56628.2022.10084261. keywords: {Java;Machine learning algorithms;Data analysis;Program processors;Memory management;C++ languages;Machine learning;Popular Sorting Algorithms(PSAs);asymptotic;test bed;Python;Java;C++;implementation;observations;modern compiler design},

[3] https://www.researchgate.net/profile/Omar-Khan-Durrani-2/publication/369196272_ASYMPTOTIC_PERFORMANCES_OF_POPULAR_PROGRAMMING_LANGUAGES_FOR_POPULAR_SORTING_ALGORITHMS/links/6411ba4392cfd54f840152ac/ASYMPTOTIC-PERFORMANCES-OF-POPULAR-PROGRAMMING-LANGUAGES-FOR-POPULAR-SORTING-ALGORITHMS.pdf
