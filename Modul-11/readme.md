# <h1 align="center">Laporan Praktikum Modul Hash Tabel</h1>
<p align="center">Afifah Faiqatuzzahra</p>

## Dasar Teori
Hash tabel adalah suatu struktur data yang memungkinkan penyimpanan dan pengambilan data dengan sangat efisien, terutama untuk pencarian, penyisipan, dan penghapusan. Efisiensi ini diperoleh melalui penggunaan fungsi hash, yang mengubah kunci (seperti string atau angka) menjadi indeks dalam array. Dengan demikian, operasi dasar pada hash tabel sering kali dapat dilakukan dalam waktu konstan rata-rata, 𝑂(1).[1]
Komponen Utama Hash Tabel:
1. Kunci (Key): Identifikasi unik untuk setiap item data.
2. Nilai (Value): Data yang terkait dengan kunci.
3. Fungsi Hash: Fungsi yang mengubah kunci menjadi indeks array.
4. Bucket: Tempat penyimpanan di dalam array, bisa menyimpan satu atau lebih pasangan kunci-nilai jika terjadi tabrakan (collision).[2]
Hash tabel adalah struktur data yang mendukung berbagai operasi dasar yang penting untuk banyak aplikasi komputasi. Berikut adalah operasi utama yang dapat dilakukan pada hash tabel:
1. Penyisipan (Insertion): Menambahkan pasangan kunci-nilai ke dalam hash tabel. Jika kunci sudah ada, nilainya dapat diperbarui.
2. Pencarian (Search): Mencari nilai yang terkait dengan kunci tertentu. Ini biasanya dilakukan dalam waktu konstan O(1) rata-rata.
3. Penghapusan (Deletion): Menghapus pasangan kunci-nilai dari hash tabel berdasarkan kunci.
4. Pemutakhiran (Update): Memperbarui nilai yang terkait dengan kunci yang sudah ada di dalam tabel.
5. Penanganan Tabrakan (Collision Handling): Teknik yang digunakan untuk menangani kasus ketika dua kunci berbeda menghasilkan nilai hash yang sama. Teknik umum meliputi chaining (menggunakan linked list) dan open addressing (mencari slot kosong berikutnya).[3]


## Guided1
```C++
#include <iostream>
using namespace std;
const int MAX_SIZE = 10;

// Fungsi hash sederhana
int hash_func(int key) {
    return key % MAX_SIZE;
}

// Struktur data untuk setiap node
struct Node {
    int key;
    int value;
    Node* next;
    Node(int key, int value) : key(key), value(value), next(nullptr) {}
};

// Class hash table
class HashTable {
private:
    Node** table;
public:
    HashTable() {
        table = new Node*[MAX_SIZE]();
    }
    ~HashTable() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    // Insertion
    void insert(int key, int value) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                current->value = value;
                return;
            }
            current = current->next;
        }
        Node* node = new Node(key, value);
        node->next = table[index];
        table[index] = node;
    }

    // Searching
    int get(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }

    // Deletion
    void remove(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->key == key) {
                if (prev == nullptr) {
                    table[index] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    // Traversal
    void traverse() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                cout << current->key << ": " << current->value << endl;
                current = current->next;
            }
        }
    }
};

int main() {
    HashTable ht;
    // Insertion
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);

    // Searching
    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;
   
    // Deletion
    ht.remove(4);
   
    // Traversal
    ht.traverse();
   
    return 0;
}
```
## Implementasi 
1. **Header dan Namespace:**
   - `#include <iostream>`: Mengimpor pustaka untuk operasi input/output (misalnya `cout`).
   - `using namespace std;`: Mengizinkan penggunaan nama-nama dari namespace standar tanpa kualifikasi (misalnya `cout` bukan `std::cout`).
   - `const int MAX_SIZE = 10;`: Menetapkan ukuran maksimum hash table menjadi 10 elemen.

2. **Fungsi Hash:**
   - `int hash_func(int key)`: Fungsi hash sederhana yang menghitung indeks dalam hash table berdasarkan kunci. Modulo `MAX_SIZE` digunakan untuk memastikan indeks selalu berada dalam rentang array.

3. **Struktur Node:**
   - `struct Node`: Mewakili setiap node dalam hash table. Setiap node menyimpan:
     - `key`: Kunci integer.
     - `value`: Nilai integer terkait dengan kunci.
     - `next`: Pointer ke node berikutnya dalam rantai (jika terjadi kolisi).

4. **Class HashTable:**
   - `Node** table`: Array pointer yang menyimpan kepala setiap rantai di hash table.
   - `HashTable()`: Konstruktor yang mengalokasikan memori untuk array `table`.
   - `~HashTable()`: Destruktor yang membebaskan memori yang dialokasikan untuk hash table (termasuk node-node dalam rantai).
   - `insert(int key, int value)`: Menyisipkan pasangan kunci-nilai ke dalam hash table.
   - `get(int key)`: Mencari nilai berdasarkan kunci. Mengembalikan -1 jika kunci tidak ditemukan.
   - `remove(int key)`: Menghapus pasangan kunci-nilai berdasarkan kunci.
   - `traverse()`: Mencetak semua pasangan kunci-nilai yang ada di hash table.
### Output
![Screenshot (234)](https://github.com/AFaiqatuzzahra/Praktikum-Algoritma-Pemrograman-dan-Struktur-Data/assets/152428747/e459340f-e846-4ee2-8ac8-1abf31224b64)
### Kesimpulan
Dari output yang diberikan dan kode yang ditampilkan, kita dapat menyimpulkan beberapa hal tentang implementasi hash table ini:
1. **Hash Table Bekerja dengan Baik:** Output menunjukkan bahwa operasi penyisipan (insert) untuk kunci 1, 2, dan 3 berhasil. Ini terlihat dari hasil traversal yang menampilkan pasangan kunci-nilai yang sesuai (1:10, 2:20, 3:30).
2. **Pencarian Berfungsi:**  Output dari `Get key 1: 10` menunjukkan bahwa fungsi pencarian (`get`) dapat menemukan nilai yang terkait dengan kunci 1.
3. **Pencarian Kunci yang Tidak Ada:** Output `Get key 4: -1` menunjukkan bahwa fungsi pencarian mengembalikan nilai -1 ketika kunci yang dicari (dalam hal ini kunci 4) tidak ada dalam hash table.
4. **Penghapusan Tidak Berpengaruh (Kunci Tidak Ditemukan):** Meskipun ada perintah `ht.remove(4);`, tidak ada perubahan pada hasil traversal. Ini karena kunci 4 tidak ada dalam hash table, sehingga operasi penghapusan tidak memiliki efek.
5. **Implementasi Chaining:** Kode menunjukkan bahwa implementasi hash table ini menggunakan chaining untuk menangani kolisi. Ini terlihat dari penggunaan struktur `Node` yang memiliki pointer `next` untuk membentuk linked list pada setiap slot tabel.
6. **Fungsi Hash Sederhana:** Fungsi hash yang digunakan (`key % MAX_SIZE`) adalah fungsi hash yang sangat sederhana. Dalam aplikasi yang lebih kompleks, mungkin perlu menggunakan fungsi hash yang lebih canggih untuk mengurangi risiko kolisi.  
### Full code screenshot
![Screenshot (234)](https://github.com/AFaiqatuzzahra/Praktikum-Algoritma-Pemrograman-dan-Struktur-Data/assets/152428747/e459340f-e846-4ee2-8ac8-1abf31224b64)

## Guided2
```C++
#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int TABLE_SIZE = 11;

string name;
string phone_number;

class HashNode {
public:
    string name;
    string phone_number;

    HashNode(string name, string phone_number) {
        this->name = name;
        this->phone_number = phone_number;
    }
};

class HashMap {
private:
    vector<HashNode*> table[TABLE_SIZE];
public:
    int hashFunc(string key) {
        int hash_val = 0;
        for (char c : key) {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }

    void insert(string name, string phone_number) {
        int hash_val = hashFunc(name);

        for (auto node : table[hash_val]) {
            if (node->name == name) {
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name, phone_number));
    }

    void remove(string name) {
        int hash_val = hashFunc(name);

        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++) {
            if ((*it)->name == name) {
                table[hash_val].erase(it);
                return;
            }
        }
    }

    string searchByName(string name) {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val]) {
            if (node->name == name) {
                return node->phone_number;
            }
        }
        return "";
    }

    void print() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
            for (auto pair : table[i]) {
                if (pair != nullptr) {
                    cout << "[" << pair->name << ", " << pair->phone_number << "]";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    HashMap employee_map;

    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");

    cout << "Nomer Hp Mistah : " << employee_map.searchByName("Mistah") << endl;
    cout << "Phone Hp Pastah : " << employee_map.searchByName("Pastah") << endl;

    employee_map.remove("Mistah");

    cout << "Nomer Hp Mistah setelah dihapus : " << employee_map.searchByName("Mistah") << endl << endl;

    cout << "Hash Table : " << endl;

    employee_map.print();

    return 0;
}
```
## Implementasi 
**Penjelasan Kode**
1. **Header dan Namespace:** Sama seperti sebelumnya, mengimpor pustaka `iostream`, `string`, dan `vector`, dan menggunakan namespace `std`.
2. **Variabel Global:**
   - `TABLE_SIZE = 11`: Mendefinisikan ukuran tabel hash sebagai 11. Ukuran prima seringkali digunakan dalam hash table untuk distribusi yang lebih baik.
3. **Kelas `HashNode`:**
   - Merepresentasikan sebuah node dalam hash map, yang menyimpan:
     - `name`: Nama karyawan (kunci)
     - `phone_number`: Nomor telepon karyawan (nilai)
4. **Kelas `HashMap`:**
   - `vector<HashNode*> table[TABLE_SIZE]`: Array dari vektor pointer ke `HashNode`. Ini adalah tabel hash, di mana setiap indeks mewakili bucket (slot) dalam tabel, dan vektor di setiap bucket menyimpan node-node yang memiliki nilai hash yang sama (jika terjadi kolisi).
   - `hashFunc(string key)`: Fungsi hash sederhana yang menjumlahkan nilai ASCII setiap karakter dalam kunci (`name`) dan menghitung modulo `TABLE_SIZE` untuk mendapatkan indeks bucket.
   - `insert(string name, string phone_number)`: Menyisipkan pasangan nama-nomor telepon ke dalam hash map.
   - `remove(string name)`: Menghapus pasangan nama-nomor telepon berdasarkan nama.
   - `searchByName(string name)`: Mencari nomor telepon berdasarkan nama.
   - `print()`: Mencetak seluruh isi hash map.
### Output
![Screenshot (235)](https://github.com/AFaiqatuzzahra/Praktikum-Algoritma-Pemrograman-dan-Struktur-Data/assets/152428747/91a100e4-acc8-421d-b600-a917c001bf62)
### Kesimpulan
1. **Hash Map Bekerja dengan Baik:** Output menunjukkan operasi penyisipan (insert) untuk kunci "Mistah", "Pastah", dan "Ghana" berhasil. Ini terlihat dari hasil cetak hash table yang menampilkan pasangan kunci-nilai yang sesuai.
2. **Pencarian Berfungsi:** Output dari "Nomer Hp Mistah : 1234" dan "Phone Hp Pastah : 5678" menunjukkan bahwa fungsi pencarian (`searchByName`) dapat menemukan nilai (nomor telepon) yang terkait dengan kunci (nama).
3. **Penghapusan Berfungsi:** Setelah "Mistah" dihapus, pencariannya menghasilkan output kosong, menunjukkan bahwa data telah berhasil dihapus dari hash map.
4. **Penanganan Kolisi dengan Chaining:** Kode menggunakan chaining untuk menangani kolisi. Ini terlihat dari penggunaan `vector<HashNode*>` untuk menyimpan beberapa node dalam satu bucket (slot) tabel hash jika terjadi kolisi.
5. **Fungsi Hash Sederhana:** Fungsi hash yang digunakan (`hashFunc`) adalah fungsi hash yang sangat sederhana, hanya menjumlahkan nilai ASCII setiap karakter dalam kunci. Dalam aplikasi yang lebih kompleks, mungkin perlu menggunakan fungsi hash yang lebih canggih untuk distribusi data yang lebih merata dan mengurangi risiko kolisi.
6. **Ukuran Tabel Hash:** Ukuran tabel hash (11) adalah bilangan prima, yang merupakan praktik umum dalam hash table untuk membantu distribusi data yang lebih merata.
7. **Output Tabel Hash:** Output tabel hash menunjukkan bagaimana data didistribusikan di seluruh bucket. Dalam contoh ini, beberapa bucket kosong, sementara bucket lain berisi satu atau dua node.
### Full Screenshot
![Screenshot (235)](https://github.com/AFaiqatuzzahra/Praktikum-Algoritma-Pemrograman-dan-Struktur-Data/assets/152428747/91a100e4-acc8-421d-b600-a917c001bf62)

## Unguided1
```C++
#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

struct Mahasiswa {
    int nim;
    int nilai;
};

class HashTable {
private:
    unordered_map<int, list<Mahasiswa>> table;

    int hashFunction(int nim) {
        return nim % 10; 
    }

public:
    void tambahMahasiswa(int nim, int nilai) {
        int index = hashFunction(nim);
        table[index].push_back({nim, nilai});
    }

    void hapusMahasiswa(int nim) {
        int index = hashFunction(nim);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->nim == nim) {
                table[index].erase(it);
                return;
            }
        }
        cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
    }

    void cariMahasiswaByNIM(int nim) {
        int index = hashFunction(nim);
        for (const auto& mahasiswa : table[index]) {
            if (mahasiswa.nim == nim) {
                cout << "NIM: " << mahasiswa.nim << ", Nilai: " << mahasiswa.nilai << endl;
                return;
            }
        }
        cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
    }

    void cariMahasiswaByNilai(int nilaiMin, int nilaiMax) {
        cout << "Mahasiswa dengan nilai antara " << nilaiMin << " dan " << nilaiMax << ":" << endl;
        for (const auto& bucket : table) {
            for (const auto& mahasiswa : bucket.second) {
                if (mahasiswa.nilai >= nilaiMin && mahasiswa.nilai <= nilaiMax) {
                    cout << "NIM: " << mahasiswa.nim << ", Nilai: " << mahasiswa.nilai << endl;
                }
            }
        }
    }
};
int main() {
    HashTable hashTable;
    int pilihan;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Tambah Mahasiswa" << endl;
        cout << "2. Hapus Mahasiswa" << endl;
        cout << "3. Cari Mahasiswa (NIM)" << endl;
        cout << "4. Cari Mahasiswa (Rentang Nilai)" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                int nim, nilai;
                cout << "NIM: ";
                cin >> nim;
                cout << "Nilai: ";
                cin >> nilai;
                hashTable.tambahMahasiswa(nim, nilai);
                break;
            }
            case 2: {
                int nim;
                cout << "NIM: ";
                cin >> nim;
                hashTable.hapusMahasiswa(nim);
                break;
            }
            case 3: {
                int nim;
                cout << "NIM: ";
                cin >> nim;
                hashTable.cariMahasiswaByNIM(nim);
                break;
            }
            case 4: {
                int nilaiMin, nilaiMax;
                cout << "Rentang Nilai (min-max): ";
                cin >> nilaiMin >> nilaiMax;
                hashTable.cariMahasiswaByNilai(nilaiMin, nilaiMax);
                break;
            }
            case 0:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 0);

    return 0;
}
```
## Implementasi
1. **Header dan Namespace:**
   - `#include <iostream>`: Mengimpor pustaka untuk input/output standar (misalnya, `cout`, `cin`).
   - `#include <list>`: Mengimpor pustaka untuk menggunakan linked list (`std::list`).
   - `#include <unordered_map>`: Mengimpor pustaka untuk menggunakan hash table (`std::unordered_map`).
   - `using namespace std;`: Mengizinkan penggunaan nama-nama dari namespace standar tanpa kualifikasi (misalnya, `cout` bukan `std::cout`).
2. **Struktur `Mahasiswa`:**
   - Struktur sederhana untuk menyimpan data mahasiswa:
     - `nim`: Nomor Induk Mahasiswa (NIM).
     - `nilai`: Nilai mahasiswa.
3. **Kelas `HashTable`:**
   - `unordered_map<int, list<Mahasiswa>> table`: Hash table yang memetakan NIM (kunci) ke daftar mahasiswa (nilai).
   - `hashFunction(int nim)`: Fungsi hash sederhana yang menghitung indeks bucket (slot) dalam hash table berdasarkan NIM.
   - `tambahMahasiswa(int nim, int nilai)`: Menambahkan mahasiswa baru ke hash table.
   - `hapusMahasiswa(int nim)`: Menghapus mahasiswa berdasarkan NIM.
   - `cariMahasiswaByNIM(int nim)`: Mencari mahasiswa berdasarkan NIM dan mencetak informasi jika ditemukan.
   - `cariMahasiswaByNilai(int nilaiMin, int nilaiMax)`: Mencari mahasiswa dengan nilai dalam rentang tertentu dan mencetak informasi mereka.
4. **Fungsi `main`:**
   - Membuat objek `HashTable`.
   - Menampilkan menu interaktif kepada pengguna:
     - Menambahkan mahasiswa.
     - Menghapus mahasiswa.
     - Mencari mahasiswa berdasarkan NIM.
     - Mencari mahasiswa berdasarkan rentang nilai.
     - Keluar dari program.
   - Memproses pilihan pengguna dan memanggil fungsi yang sesuai dari objek `HashTable`.
**Cara Menggunakan Program**
1. **Kompilasi:** Kompilasi kode menggunakan kompiler C++ (misalnya, g++):
   ```bash
   g++ -o hash_table hash_table.cpp
   ```
2. **Jalankan:** Jalankan program yang dihasilkan:
   ```bash
   ./hash_table
   ```
3. **Ikuti Menu:** Program akan menampilkan menu. Pilih opsi yang diinginkan dan ikuti petunjuk untuk memasukkan data mahasiswa atau melakukan pencarian.

### Output
![Screenshot (236)](https://github.com/AFaiqatuzzahra/Praktikum-Algoritma-Pemrograman-dan-Struktur-Data/assets/152428747/c04d4a9b-54b7-4956-9866-b9f5dde15d5b)
### Kesimpulan
1. **Fungsionalitas Dasar Berjalan Baik:**
   * Program berhasil **menyisipkan** data mahasiswa dengan NIM dan nilai yang berbeda (231, 232, 234).
   * Program mampu melakukan **pencarian** berdasarkan rentang nilai. Output menunjukkan tiga mahasiswa ditemukan dalam rentang nilai 80-90.
2. **Penggunaan Hash Table:**
Kode menggunakan `unordered_map` untuk mengimplementasikan hash table, yang memberikan **akses cepat** (rata-rata O(1)) ke data mahasiswa berdasarkan NIM mereka.
Setiap entri dalam hash table adalah sebuah `list` yang memungkinkan **penanganan kolisi** (ketika dua atau lebih NIM memiliki nilai hash yang sama).
3. **Fungsi Hash Sederhana:**
Fungsi hash yang digunakan (`nim % 10`) adalah fungsi hash yang sangat sederhana dan mungkin **tidak ideal** untuk distribusi data yang merata dalam tabel hash. Ini dapat menyebabkan beberapa bucket (slot) tabel menjadi lebih penuh daripada yang lain, yang berpotensi mempengaruhi kinerja.
4. **Penanganan Input Pengguna:**
Program memiliki **antarmuka pengguna berbasis teks sederhana** yang memungkinkan pengguna untuk berinteraksi dengan hash table (menambah, menghapus, dan mencari data mahasiswa).

## Full Screenshot
![Screenshot (236)](https://github.com/AFaiqatuzzahra/Praktikum-Algoritma-Pemrograman-dan-Struktur-Data/assets/152428747/c04d4a9b-54b7-4956-9866-b9f5dde15d5b)

[1]. T. H. Cormen, C. E. Leiserson, R. L. Rivest, and C. Stein, Introduction To Algorithms. MIT Press, 2001. Accessed: Jun. 02, 2024. [Online]. Available: https://books.google.co.id/books?id=NLngYyWFl_YC&lpg=PP1&hl=id&pg=PA221#v=onepage&q=hash%20table&f=false
‌[2]. [1]C. A. Shaffer, Data Structures and Algorithm Analysis in C++, Third Edition. Courier Corporation, 2012. Accessed: Jun. 02, 2024. [Online]. Available: https://books.google.co.id/books?id=AijEAgAAQBAJ&lpg=PP1&hl=id&pg=PP1#v=onepage&q&f=false
‌[3]. [1]R. Sedgewick and K. Wayne, Algorithms, Part II. Addison-Wesley Professional, 2014. Accessed: Jun. 02, 2024. [Online]. Available: https://books.google.co.id/books?id=a9HYAgAAQBAJ&lpg=PA1&hl=id&pg=PA1#v=onepage&q&f=false
‌
