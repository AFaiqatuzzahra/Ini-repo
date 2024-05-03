# <h1 align="center">Laporan Praktikum Modul Stack</h1>
<p align="center">Afifah Faiqatuzzahra</p>

## Dasar Teori
Stack (tumpukan) adalah struktur data abstrak yang memiliki aturan "Last In, First Out" (LIFO). Artinya, elemen terakhir yang dimasukkan ke dalam stack adalah elemen pertama yang akan dikeluarkan. Stack sering digunakan dalam pemrograman komputer untuk menyimpan data sementara, seperti pembatalan (undo) dan redo, atau untuk mengevaluasi ekspresi matematika.[1]

Di C++, stack dapat diimplementasikan menggunakan array atau linked list. Implementasi stack menggunakan array lebih sederhana, namun memiliki batasan memori yang statis. Implementasi stack menggunakan linked list lebih fleksibel dalam hal memori, namun lebih kompleks dalam hal implementasi.[3]
Stack dapat diimplementasikan menggunakan berbagai struktur data, seperti array, daftar tertaut, atau pohon. Implementasi stack yang paling umum adalah dengan menggunakan array.[2]

## Guided

```C++
#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull() {
    return (top == maksimal);
}

bool isEmpty() {
    return (top == 0);
}

void pushArrayBuku(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    } else {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        arrayBuku[top - 1] = "";
        top--;
    }
}

void peekArrayBuku(int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}

int countStack() {
    return top;
}

void changeArrayBuku(int posisi, string data) {
    if (posisi > top) {
        cout << "Posisi melebihi data yang ada" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        arrayBuku[index] = data;
    }
}

void destroyArraybuku() {
    for (int i = top; i >= 0; i--) {
        arrayBuku[i] = "";
    }
    top = 0;
}

void cetakArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main() {
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();
    cout << "\n";

    cout << "Apakah data stack penuh? " << isFull() << endl;
    cout << "Apakah data stack kosong? " << isEmpty() << endl;

    peekArrayBuku(2);
    popArrayBuku();

    cout << "Banyaknya data = " << countStack() << endl;

    changeArrayBuku(2, "Bahasa Jerman");
    cetakArrayBuku();

    cout << "\n";

    destroyArraybuku();
    cout << "Jumlah data setelah dihapus: " << top << endl;

    cetakArrayBuku();

    return 0;
}
```
Penjelasan implementasi kode diatas adalah

1. Header dan Namespase:
#include <iostream>: Baris ini menyertakan pustaka iostream yang menyediakan fungsi-fungsi untuk input dan output data.
using namespace std;: Baris ini menggunakan namespace std yang berisi definisi objek dan fungsi standar C++. Ini dilakukan untuk memudahkan penulisan kode tanpa perlu menyertakan std:: di depan setiap objek atau fungsi standar.
2. Struktur Data:
string arrayBuku[5];: Baris ini mendeklarasikan array bernama arrayBuku yang dapat menyimpan hingga 5 string. Array ini digunakan untuk menyimpan data di dalam stack.
int maksimal = 5;: Baris ini mendefinisikan kapasitas maksimum dari arrayBuku, yaitu 5 elemen.
int top = 0;: Baris ini menginisialisasi variabel top untuk melacak elemen teratas (top) di dalam stack. Nilai awal top adalah 0 yang menandakan stack kosong.
3. Fungsi-fungsi Operasi Stack:
isFull(): Fungsi ini memeriksa apakah stack sudah penuh. Pemeriksaan dilakukan dengan membandingkan nilai top dengan maksimal. Jika top sama dengan maksimal, maka stack penuh.
isEmpty(): Fungsi ini memeriksa apakah stack kosong. Pemeriksaan dilakukan dengan mengecek apakah nilai top sama dengan 0. Jika top bernilai 0, maka stack kosong.
pushArrayBuku(string data): Fungsi ini digunakan untuk memasukkan elemen baru (data) ke dalam stack. Jika stack penuh, fungsi ini akan menampilkan pesan error.
popArrayBuku(): Fungsi ini digunakan untuk mengeluarkan elemen teratas dari stack. Jika stack kosong, fungsi ini akan menampilkan pesan error.
peekArrayBuku(int posisi): Fungsi ini digunakan untuk melihat elemen pada posisi tertentu (posisi) di dalam stack tanpa mengeluarkannya.

### Output
![Screenshot (142)1](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/275d0c4f-cf1c-4398-87a9-e7982e8f95f8)

Dari output diatas diketahui bahwa, awalnya dimulai dari stack kosong(array buku) kemudian memasukkan elemen-elemen kalkulus, bahasa inggris, dst. lalu menggunakan program memeriksa apakah stack penuh menggunakan fungsi isFull() dan mencetak false karena masih ada ruang untuk elemen lainnya. kemudian memeriksa apakah stack kosong menggunakan fungsi isEmpty() dan mencetak false karena stack memiliki elemen. dan dari yang awalnya berurut Inggris, Dasar Multimedia, Matematika Diskrit, Struktur Data, Kalkulus menjadi  Bahasa Jerman ,Dasar Multimedia, Matematika Diskrit, Struktur Data, Kalkulus.

### Full code screenshot
![Screenshot (142)](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/ca618bd0-c96b-493e-94f5-570db5213098)

## Unguided1
```C++
#include <iostream>
using namespace std;

char array[5 * 26]; // Assuming maximum sentence length is 26 characters
int maksimal = 5 * 26, top = 0;

bool isFull() {
    return (top == maksimal);
}

bool isEmpty() {
    return (top == 0);
}

void pushArray(char data) {
    if (isFull()) {
        cout << "Data stack telah penuh" << endl;
    } else {
        array[top] = data;
        top++;
    }
}

void popArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        top--;
    }
}

bool isPalindrome(string sentence) {
    // Convert sentence to lowercase and remove non-alphanumeric characters
    string processedSentence;
    for (char c : sentence) {
        if (isalnum(c)) {
            processedSentence += tolower(c);
        }
    }

    // Push characters into the stack
    for (char c : processedSentence) {
        pushArray(c);
    }

    // Check if characters are the same when popped from both ends
    int i = 0, j = top - 1;
    while (i <= j) {
        if (array[i] != array[j]) {
            return false;
        }
        i++;
        j--;
    }

    return true;
}

int main() {
    // ... (rest of the code remains the same)

    string sentence;
    cout << "Masukkan kalimat: ";
    getline(cin, sentence);

    if (isPalindrome(sentence)) {
        cout << sentence << " adalah palindrom" << endl;
    } else {
        cout << sentence << " bukan palindrom" << endl;
    }

    // ... (rest of the code remains the same)

    return 0;
}
```
Implementasi kode diatas adalah Kode ini berfungsi untuk memeriksa apakah sebuah kalimat merupakan palindrom atau bukan. Palindrom adalah kalimat atau frasa yang dibaca sama dari depan maupun belakang.
Penjelasan Baris per Baris:

1. Header dan Namespace:

#include `<iostream>`: Baris ini menyertakan pustaka iostream yang menyediakan fungsi-fungsi untuk input dan output data.
using namespace std;: Baris ini menggunakan namespace std yang berisi definisi objek dan fungsi standar C++. Ini dilakukan untuk memudahkan penulisan kode tanpa perlu menyertakan std:: di depan setiap objek atau fungsi standar.
Implementasi Stack:

char array[5 * 26]: Baris ini mendeklarasikan array bernama array untuk menyimpan karakter di dalam stack. Ukuran maksimum array adalah 5 * 26 (dengan asumsi panjang kalimat maksimum 26 karakter).
int maksimal = 5 * 26, top = 0;: Baris ini mendefinisikan kapasitas maksimum stack (maksimal) dan menginisialisasi indeks top ke 0 (stack kosong).
isFull(): Fungsi ini memeriksa apakah stack sudah penuh.
isEmpty(): Fungsi ini memeriksa apakah stack kosong.
pushArray(char data): Fungsi ini digunakan untuk memasukkan karakter baru (data) ke dalam stack.
popArray(): Fungsi ini digunakan untuk mengeluarkan karakter teratas dari stack.
Fungsi Pemeriksa Palindrom (isPalindrome)

Mendapat input berupa string sentence (kalimat).
Mengubah kalimat menjadi huruf kecil dan menghilangkan karakter selain huruf dan angka. Ini dilakukan untuk pemeriksaan palindrom tanpa memperhitungkan huruf besar/kecil.
Memasukkan setiap karakter dari kalimat yang sudah diproses ke dalam stack.
Membandingkan karakter dari awal dan akhir kalimat yang sudah diproses menggunakan stack. Jika ada ketidakcocokan karakter, maka kalimat tersebut bukan palindrom.
Mengembalikan nilai true jika kalimat tersebut palindrom, dan false jika bukan.
Fungsi Utama (main)
Meminta pengguna untuk memasukkan kalimat.
Memanggil fungsi isPalindrome untuk memeriksa apakah kalimat yang dimasukkan merupakan palindrom.
Mencetak pesan yang menunjukkan apakah kalimat tersebut palindrom atau bukan.

### Output
![Screenshot (143)](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/1d78a3b0-642b-4049-b87b-42bf5cc70489)

Dari output tersebut dapat diketahui bahwa kalimat apa apa adalah palindrom karena apa jika dibalik maka dibaca tetap apa, namun pada kalimat warung bahari bukanlah palindrom karena warung bahari jika dibalik maka dibaca irahab gnuraw.

### Full Screenshot
![Screenshot (143)1](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/7d2ca40c-403b-4a3b-a6d4-f9b2377a472f)

## Unguided2
```C++
#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

string reverseWord(string word) {
    string reversedWord = "";
    // Memulai dari karakter terakhir dan menggabungkan setiap karakter ke string yang dibalik
    for (int i = word.length() - 1; i >= 0; i--) {
        reversedWord += word[i];
    }
    return reversedWord;
}

string reverseSentence(string sentence) {
    stack<string> words;
    stringstream ss(sentence);
    string word, reversedSentence;

    // Memisahkan kata-kata dalam kalimat menggunakan stringstream
    while (ss >> word) {
        words.push(reverseWord(word)); // Memasukkan kata yang sudah dibalik ke dalam stack
    }

    // Mengambil kata-kata dari tumpukan untuk membentuk kalimat yang terbalik
    while (!words.empty()) {
        reversedSentence += words.top() + " ";
        words.pop();
    }

    return reversedSentence;
}

int main() {
    string kalimat;

    cout << "Masukkan kalimat (minimal 3 kata): ";
    getline(cin, kalimat);

    // Mengecek apakah kalimat memiliki minimal 3 kata
    stringstream checkStream(kalimat);
    string temp;
    int countWords = 0;
    while (checkStream >> temp) {
        countWords++;
    }

    if (countWords >= 3) {
        string hasil_pembalikan = reverseSentence(kalimat);
        cout << "Kalimat asli: " << kalimat << endl;
        cout << "Hasil pembalikan: " << hasil_pembalikan << endl;
    } else {
        cout << "Mohon masukkan kalimat dengan minimal 3 kata." << endl;
    }

    return 0;
}
```
Implementasi kode diatas adalah untuk membalikkan urutan kata-kata dan huruf dalam sebuah kalimat. 

1. **File Header:**
   - `#include <iostream>`: Baris ini menyertakan pustaka `iostream` yang menyediakan fungsi-fungsi untuk input dan output data.
   - `#include <stack>`: Baris ini menyertakan pustaka `stack` untuk menggunakan struktur data stack (tumpukan).
   - `#include <string>`: Baris ini menyertakan pustaka `string` untuk manipulasi string (teks).
   - `#include <sstream>`: Baris ini menyertakan pustaka `sstream` untuk menggunakan stringstream yang dapat memproses string seperti aliran data.
2. **Fungsi `reverseWord` (Membalikkan Kata):**
   - Mendapat input berupa string `word` (kata).
   - Membuat string kosong `reversedWord` untuk menyimpan kata yang sudah dibalik.
   - Melakukan iterasi melalui karakter-karakter dalam `word` secara terbalik, menambahkan setiap karakter ke `reversedWord`.
   - Mengembalikan kata yang sudah dibalik `reversedWord`.
3. **Fungsi `reverseSentence` (Membalikkan Kalimat):**
   - Mendapat input berupa string `sentence` (kalimat).
   - Membuat stack `words` untuk menyimpan sementara kata-kata yang sudah dibalik.
   - Membuat `stringstream` `ss` untuk memproses `sentence`.
   - Mendeklarasikan variabel `word` dan `reversedSentence` untuk menyimpan kata individu dan kalimat yang sudah dibalik.
   - Melakukan iterasi melalui kata-kata dalam kalimat menggunakan `stringstream`:
     - Untuk setiap kata:
       - Memanggil fungsi `reverseWord` untuk membalikkan kata tersebut.
       - Memasukkan kata yang sudah dibalik ke dalam stack `words`.
   - Melakukan iterasi melalui stack `words` untuk mengeluarkan kata dan membentuk kalimat yang dibalik:
     - Selama stack tidak kosong:
       - Mengeluarkan kata teratas dari stack dan menambahkannya ke `reversedSentence` dengan spasi.
   - Mengembalikan kalimat yang sudah dibalik `reversedSentence`.  
4. **Fungsi `main` (Fungsi Utama):**
   - Meminta pengguna untuk memasukkan kalimat.
   - Mendapatkan kalimat input menggunakan `getline(cin, sentence)`.
   - Membuat `stringstream` `checkStream` untuk mengecek jumlah kata dalam kalimat.
   - Mendeklarasikan variabel `temp` dan penghitung integer `countWords`.
   - Melakukan iterasi melalui kata-kata dalam kalimat menggunakan `stringstream`:
     - Untuk setiap kata:
       - Menambah `countWords`.
   - Memeriksa apakah kalimat memiliki minimal 3 kata (`countWords >= 3`).
     - Jika ya:
       - Memanggil fungsi `reverseSentence` untuk membalikkan kalimat dan menyimpan hasilnya di `reversedSentence`.
       - Mencetak kalimat asli dan bentuk terbaliknya.
     - Jika tidak:
       - Mencetak pesan error yang menyatakan bahwa kalimat minimal harus 3 kata.

### Output
![Screenshot (144)1](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/04000529-c92b-4d7d-b20a-76f71f7d3f4b)

Dari output yang dihasilkan kita bisa memasukkan kalimat yang kita maksud minimal 3 kata, kemudian kode akan memproses dan kalimat yang kita masukkan tersebut akan dibalikkan seperti output diatas.

### Full Screenshot
![Screenshot (144)](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/f9511e66-02fb-46be-95e6-866fc17f92bc)

### Daftar Pustaka
[1] I. Kandel, M. Castelli, and A. Popovič, “Comparing stacking ensemble techniques to improve musculoskeletal fracture image classification,” Journal of Imaging, vol. 7, no. 6, p. 100, Jun. 2021, doi: 10.3390/jimaging7060100.
[2] M. Verdi, A. Sami, J. Akhondali, F. Khomh, G. Uddin, and A. K. Motlagh, “An Empirical Study of C++ Vulnerabilities in Crowd-Sourced Code Examples,” IEEE Transactions on Software Engineering, pp. 1–1, 2020, doi: https://doi.org/10.1109/TSE.2020.3023664.
[3] Educative, “Stack (Implementation) - data structures for coding interviews in C++,” Educative. https://www.educative.io/courses/data-structures-coding-interviews-cpp/stack-implementation
