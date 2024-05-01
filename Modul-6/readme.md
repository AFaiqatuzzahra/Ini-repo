# <h1 align="center">Laporan Praktikum Modul Linked List</h1>
<p align="center">Afifah Faiqatuzzahra</p>

## Dasar Teori
LinkedList adalah struktur data linier yang menyimpan elemen di lokasi yang tidak berdekatan. Elemen-elemen dalam daftar tertaut dihubungkan satu sama lain menggunakan pointer. Atau dengan kata lain, LinkedList terdiri dari node dimana setiap node berisi field data dan referensi (link) ke node berikutnya dalam daftar. Di C#, LinkedList adalah jenis koleksi generik yang didefinisikan dalam System.Collections.Generic namespace. Ini adalah daftar yang terhubung ganda, oleh karena itu, setiap node menunjuk ke depan ke node Berikutnya dan mundur ke node Sebelumnya. Ini adalah koleksi dinamis yang tumbuh, sesuai dengan kebutuhan program Anda. Ini juga menyediakan elemen penyisipan dan penghapusan cepat.[1]

- 1. Single Linked List

Single Linked List merupakan suatu linked list yang hanya memiliki satu variabel pointer saja. Dimana pointer tersebut menunjuk ke node selanjutnya. Biasanya field
pada tail menunjuk ke NULL. Terdapat dua Single Linked List, yaitu Circular dan Non Circular.

Single Linked List Circular adalah Single Linked List yang pointer nextnya menunjuk pada dirinya sendiri. Jika Single Linked List tersebut terdiri dari beberapa node, maka pointer next pada node terakhir akan menunjuk ke node terdepannya. Single artinya field pointer-nya hanya satu buah saja dan satu arah. Circular artinya pointer next-nya akan menunjuk pada dirinya sendiri sehingga berputar. Ilustrasi Single Linked List Circular: Setiap node pada linked list mempunyai field yang berisi pointer ke node berikutnya, dan juga memiliki field yang berisi data. Pada akhir linked list, node terakhir akan menunjuk ke node terdepan sehingga linked list tersebut berputar. Node terakhir akan menunjuk lagi ke head. 

Single Linked List Non Circular. Single artinya field pointer-nya hanya satu buah saja dan satu arah. Linked List artinya node-node tersebut saling terhubung satu sama lain. Ilustrasi Single Linked List Non Circular: Setiap node pada linked list mempunyai field yang berisi pointer ke node berikutnya, dan juga memiliki field yang berisi data. Pada akhir linked list, node terakhir akan menunjuk ke NULL yang akan digunakan sebagai kondisi berhenti pada saat pembacaan isi linked list.

- 2. Double Linked List

Elemen-elemen dihubungkan dengan dua pointer dalam satu elemen. Struktur ini menyebabkan list melintas baik ke depan maupun ke belakang. Masing-masing elemen pada double linked list terdiri dari tiga bagian, disamping data dan pointer next, masing-masing dilengkapi dengan pointer prev yang menunjuk ke elemen sebelumnya. Double linked list dibentuk dengan menyusun sejumlah elemen sehingga pointer next menujuk ke elemen yang mengikutinya dan pointer prev menujuk ke elemen yang mendahuluinya. Untuk menunjukkan head dari double linked list, maka pointer prev dari elemen pertama menujuk NULL. Untuk menunjukkan tail dari double linked list tersebut, maka pointer next dari elemen terakhir menunjuk NULL [2].

## Guided 

### 1. Guided 1: Latihan Single Linked List

```C++
#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node {
    int data;
    Node *next;
};

Node *head;
Node *tail;

// Inisialisasi Node
void init() {
    head = NULL;
    tail = NULL;
}

// Pengecekan apakah list kosong
bool isEmpty() {
    return (head == NULL);
}

// Tambah Data di Depan
void insertDepan(int nilai) {
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        baru->next = head;
        head = baru;
    }
}

// Tambah Data di Belakang
void insertBelakang(int nilai) {
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

// Hitung Jumlah Node
int hitungList() {
    Node *hitung = head;
    int jumlah = 0;
    while (hitung != NULL) {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

// Tambah Data di Tengah
void insertTengah(int data, int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi diluar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        Node *baru = new Node();
        baru->data = data;
        Node *bantu = head;
        for (int nomor = 1; nomor < posisi - 1; nomor++) {
            bantu = bantu->next;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Node di Depan
void hapusDepan() {
    if (!isEmpty()) {
        Node *hapus = head;
        if (head->next != NULL) {
            head = head->next;
        } else {
            head = tail = NULL;
        }
        delete hapus;
    } else {
        cout << "List kosong!" << endl;
    }
}

// Hapus Node di Belakang
void hapusBelakang() {
    if (!isEmpty()) {
        Node *hapus = tail;
        if (head != tail) {
            Node *bantu = head;
            while (bantu->next != tail) {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        } else {
            head = tail = NULL;
        }
        delete hapus;
    } else {
        cout << "List kosong!" << endl;
    }
}

// Hapus Node di Tengah
void hapusTengah(int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi di luar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        Node *hapus;
        Node *bantu = head;
        for (int nomor = 1; nomor < posisi - 1; nomor++) {
            bantu = bantu->next;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    }
}

// Ubah Data di Depan
void ubahDepan(int data) {
    if (!isEmpty()) {
        head->data = data;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah Data di Tengah
void ubahTengah(int data, int posisi) {
    if (!isEmpty()) {
        if (posisi < 1 || posisi > hitungList()) {
            cout << "Posisi di luar jangkauan" << endl;
        } else if (posisi == 1) {
            cout << "Posisi bukan posisi tengah" << endl;
        } else {
            Node *bantu = head;
            for (int nomor = 1; nomor < posisi; nomor++) {
                bantu = bantu->next;
            }
            bantu->data = data;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah Data di Belakang
void ubahBelakang(int data) {
    if (!isEmpty()) {
        tail->data = data;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Semua Node
void clearList() {
    Node *hapus;
    while (head != NULL) {
        hapus = head;
        head = head->next;
        delete hapus;
    }
    tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan List
void tampil() {
    Node *bantu = head;
    if (!isEmpty()) {
        while (bantu != NULL) {
            cout << bantu->data << " ";
            bantu = bantu->next;
        }
        cout << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

int main() {
    init();
    insertDepan(3); tampil();
    insertBelakang(5); tampil();
    insertDepan(2); tampil();
    insertDepan(1); tampil();
    hapusDepan(); tampil();
    hapusBelakang(); tampil();
    insertTengah(7, 2); tampil();
    hapusTengah(2); tampil();
    ubahDepan(1); tampil();
    ubahBelakang(8); tampil();
    ubahTengah(11, 2); tampil();
    clearList();
    return 0;
}
```
Program ini adalah contoh implementasi Single Linked List. Setiap node memiliki dua elemen: data dan pointer ke node berikutnya. Program ini memiliki beberapa fungsi:

* `init()`: Inisialisasi pointer head dan tail ke NULL (list kosong).
* `isEmpty()`: Mengembalikan true jika list kosong (head = NULL).
* `insertDepan(int nilai)`: Menambahkan data baru di awal list.
* `insertBelakang(int nilai)`: Menambahkan data baru di akhir list.
* `hitungList()`: Menghitung jumlah node dalam list dengan iterasi.
* `insertTengah(int data, int posisi)`: Menambahkan data baru di posisi tertentu dalam list.
* `hapusDepan()`: Menghapus node pertama dalam list.
* `hapusBelakang()`: Menghapus node terakhir dalam list.
* `hapusTengah(int posisi)`: Menghapus node pada posisi tertentu dalam list.
* `ubahDepan(int data)`: Mengubah nilai data node pertama dalam list.
* `ubahTengah(int data, int posisi)`: Mengubah nilai data node pada posisi tertentu dalam list.
* `ubahBelakang(int data)`: Mengubah nilai data node terakhir dalam list.
* `clearList()`: Menghapus semua node dalam list.
* `tampil()`: Menampilkan semua nilai data dalam list.

Fungsi-fungsi ini dipanggil dalam fungsi main() untuk mendemonstrasikan operasi dasar pada Single Linked List.

#### Output:
![Screenshot (108)](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/49174279-ebcb-4f60-a641-148b53f51485)

Maka, dari hasil diatas dapat diketahui bahwa:
1. **Memasukkan Data:**
    * Menambahkan angka 3 di depan list (**insertDepan(3)**).
    * Menambahkan angka 5 di belakang list (**insertBelakang(5)**).
    * Menambahkan angka 2 di depan list, sehingga angka 3 bergeser (**insertDepan(2)**).
    * Menambahkan angka 1 di depan list, sehingga angka 2 bergeser (**insertDepan(1)**).
2. **Menghapus Data:**
    * Menghapus angka 1 di depan list (**hapusDepan()**).
    * Menghapus angka 5 di belakang list (**hapusBelakang()**).
3. **Memasukkan Data di Tengah:**
    * Menambahkan angka 7 di posisi kedua (**insertTengah(7, 2)**).
4. **Menghapus Data di Tengah:**
    * Menghapus angka 7 di posisi kedua (**hapusTengah(2)**).
5. **Mengubah Data:**
    * Mengubah angka di depan list menjadi 1 (**ubahDepan(1)**).
    * Mengubah angka di belakang list menjadi 8 (**ubahBelakang(8)**).
    * Mengubah angka di posisi kedua menjadi 11 (**ubahTengah(11, 2)**).
6. **Membersihkan List:**
    * Menghapus semua data dalam list (**clearList()**).

**Kesimpulan:**
Kode tersebut menunjukkan operasi dasar pada Single Linked List Non-Circular, seperti memasukkan, menghapus, dan mengubah data di berbagai posisi dalam list. Operasi-operasi tersebut dilakukan dengan menggunakan fungsi-fungsi yang telah didefinisikan dalam kode.
 

#### Full code Screenshot:
![Screenshot (109)](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/352216b6-27ab-4145-8e86-afd677f96233)


### 2. Guided 2: Latihan Double Linked List

```C++
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }
        head = newNode;
    }

    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }

    bool update(int oldData, int newData) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}
```
Program ini mengimplementasikan struktur data Double Linked List dan menawarkan berbagai operasi untuk mengelola isi list. Program ini memungkinkan pengguna untuk berinteraksi dengan list melalui antarmuka berbasis menu.

**Struktur Data:**

* **Double Linked List :** Setiap node dalam list berisi tiga anggota:
    * `data`: Nilai integer yang disimpan dalam node.
    * `prev`: Pointer ke node sebelumnya di dalam list.
    * `next`: Pointer ke node selanjutnya di dalam list.
* **Kelas DoublyLinkedList:** Kelas ini mengkapsulkan fungsi doubly linked list. Ia memiliki anggota untuk node head dan tail (`head` dan `tail`) dan menyediakan metode untuk melakukan operasi pada list.

**Operasi:**

* **push(int data):** Menambahkan node baru yang berisi `data` yang diberikan ke depan (head) list.
* **pop():** Menghapus node pertama (head) dari list dan menghapusnya.
* **update(int oldData, int newData):** Mencari node yang berisi `oldData` dan memperbarui datanya menjadi `newData`. Mengembalikan `true` jika data ditemukan dan diperbarui, `false` jika tidak.
* **deleteAll():** Iterasi melalui list, menghapus setiap node dan menyetel `head` dan `tail` ke `nullptr`. Secara efektif membersihkan list.
* **display():** Iterasi melalui list, mencetak data dari setiap node.

**Antarmuka Berbasis Menu:**

* Fungsi `main` menampilkan menu dengan opsi untuk menambah, menghapus, memperbarui, membersihkan, dan menampilkan isi list.
* Pengguna dapat memilih opsi dengan memasukkan angka.
* Berdasarkan opsi yang dipilih, program memanggil metode yang sesuai dari kelas `DoublyLinkedList` untuk melakukan operasi yang diinginkan.
* Penanganan kesalahan disertakan untuk input pengguna yang tidak valid (pilihan) dan pembaruan data yang gagal.

**Rincian Kode:**

**1. Penyertaan Header dan Namespace:**

* `#include <iostream>`: Menyertakan library iostream untuk operasi input/output (seperti `cout` dan `cin`).
* `using namespace std;`: Menghindari penggunaan `std::` yang berulang sebelum elemen library standar.

**2. Definisi Kelas Node:**

* `class Node` mendefinisikan struktur node dalam doubly linked list.
* `public:` membuat anggota dapat diakses di luar kelas.
* `int data`: Menyimpan nilai integer dari node.
* `Node* prev`: Pointer ke node sebelumnya di dalam list.
* `Node* next`: Pointer ke node selanjutnya di dalam list.

**3. Definisi Kelas DoublyLinkedList:**

* `class DoublyLinkedList` mengkapsulkan operasi doubly linked list.
* `public:` membuat anggota dapat diakses di luar kelas.
* `Node* head`: Pointer ke node pertama (head) di dalam list.
* `Node* tail`: Pointer ke node terakhir (tail) di dalam list.
* `DoublyLinkedList()`: Konstruktor menginisialisasi `head` dan `tail` ke `nullptr` (list kosong).

**4. Operasi List (Fungsi Anggota):**

* `push(int data)`:
    * Membuat node baru `newNode` dengan `data` yang diberikan.
    * Mengatur `newNode->prev` ke `nullptr` (node head).
    * Mengatur `newNode->next` ke `head` saat ini.
    * Memperbarui `head->prev` ke `newNode` jika list tidak kosong.
    * Memperbarui `head` ke `newNode` dalam kedua kasus.
* `pop()`:
    * Memeriksa apakah list kosong (jika `head` adalah `nullptr`).
    * Jika tidak kosong, menyimpan `head` saat ini dalam node sementara `temp`.
    * Memperbarui `head` ke `head->next` (head baru).
    * Jika list menjadi kosong setelah penghapusan (`head` adalah `nullptr`), setel `tail` ke `nullptr` juga.
    * Menghapus node sementara `temp`.
* `update(int oldData, int newData)`:
    * Iterasi melalui list dimulai dari `head`.
    * Untuk setiap node:
        * Memeriksa apakah `data` node cocok dengan `oldData`.
        * Jika ditemukan kecocokan, perbarui `data` node ke `newData`.
        * Mengembalikan `true` untuk menunjukkan pembaruan berhasil.
    * Jika loop selesai tanpa menemukan kecocokan, kembalikan `false`.
* `deleteAll()`:
    * Iterasi melalui list sementara `head` tidak `nullptr`.
    * Untuk setiap node:
        * Menyimpan node saat ini dalam node sementara `

#### Output:
![Screenshot (110)](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/fcb228f3-8c0b-4900-a7cc-ce53ca1ddb8c)

Gambar tersebut menunjukkan cara penggunaan program Single Linked List Non-Circular C++ untuk mengelola data dalam list. Pengguna dapat memilih operasi yang diinginkan dari menu dan program akan melakukan operasi tersebut dengan menampilkan hasil yang sesuai.

#### Full code Screenshot:
![Screenshot (111)](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/c66485ed-9f7a-4347-8d62-756596e206b4)


### 3. Guided 3: Linked List Circular 

```C++
#include <iostream>
using namespace std;

/// Program Single Linked List Circular

// Deklarasi Struct Node
struct Node {
    string data;
    Node *next;
};

Node *head, *tail, *baru, *bantu, *hapus;

void init() {
    head = NULL;
    tail = head;
}

// Pengecekan
int isEmpty() {
    if (head == NULL)
        return 1; // true
    else
        return 0; // false
}

// Buat Node Baru 
void buatNode(string data) {
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}

// Hitung List
int hitungList() {
    bantu = head;
    int jumlah = 0;
    
    while (bantu != NULL) {
        jumlah++;
        bantu = bantu->next;
    }

    return jumlah;
}

// Tambah Depan
void insertDepan(string data) {
    // Buat Node Baru
    buatNode(data);

    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        while (tail->next != head) {
            tail = tail->next;
        }

        baru->next = head;
        head = baru;
        tail->next = head;
    }
}

// Tambah Belakang
void insertBelakang(string data) {
    // Buat Node baru
    buatNode(data);

    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        while (tail->next != head) {
            tail = tail->next;
        }

        tail->next = baru;
        baru->next = head;
    }
}

// Tambah Tengah
void insertTengah(string data, int posisi) {
    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        baru->data = data;

        // Transversing
        int nomor = 1;
        bantu = head;

        while (nomor < posisi - 1) {
            bantu = bantu->next;
            nomor++;
        }

        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Depan
void hapusDepan() {
    if (isEmpty() == 0) {
        hapus = head;
        tail = head;

        if (hapus->next == head) {
            head = NULL;
            tail = NULL;
            delete hapus;
        } else {
            while (tail->next != hapus) {
                tail = tail->next;
            }

            head = head->next;
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Belakang
void hapusBelakang() {
    if (isEmpty() == 0) {
        hapus = head;
        tail = head;

        if (hapus->next == head) {
            head = NULL;
            tail = NULL;
            delete hapus;
        } else {
            while (hapus->next != head) {
                hapus = hapus->next;
            }

            while (tail->next != hapus) {
                tail = tail->next;
            }
            
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Tengah
void hapusTengah(int posisi) {
    if (isEmpty() == 0) {
        // Transversing
        int nomor = 1;
        bantu = head;

        while (nomor < posisi - 1) {
            bantu = bantu->next;
            nomor++;
        }

        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus List
void clearlist() {
    if (head != NULL) {
        hapus = head->next;

        while (hapus != head) {
            bantu = hapus->next;
            delete hapus;
            hapus = bantu;
        }

        delete head;
        head = NULL;
    }

    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan List
void tampil() {
    if (isEmpty() == 0) {
        tail = head;

        do {
            cout << tail->data << ends;
            tail = tail->next;
        } while (tail != head) ;

        cout << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

int main() {
    init();
    insertDepan("Ayam");
    tampil();
    insertDepan("Bebek");
    tampil();
    insertBelakang("Cicak");
    tampil();
    insertBelakang("Domba");
    tampil();
    hapusBelakang();
    tampil();
    hapusDepan();
    tampil();
    insertTengah("Sapi", 2);
    tampil();
    hapusTengah(2);
    tampil();
    return 0;
}
```
Program Single Linked List Circular C++ ini menyediakan berbagai fungsi untuk mengelola data dalam struktur data linked list melingkar. Pengguna dapat memilih operasi yang diinginkan dan program akan melakukannya dengan menampilkan hasil yang sesuai.

**Fungsi Inisialisasi (init())**

Fungsi ini menginisialisasi list tertaut melingkar (circular linked list) dengan menyetel pointer `head` dan `tail` ke `NULL`, menandakan list kosong. Hal ini dilakukan di awal program atau saat ingin memulai dengan list baru.

**Fungsi Pemeriksaan List Kosong (isEmpty())**

Fungsi ini memeriksa apakah list tertaut melingkar kosong atau tidak. Ia mengembalikan 1 (true) jika `head` adalah `NULL` dan 0 (false) jika tidak. Fungsi ini berguna untuk mengecek kondisi list sebelum melakukan operasi lain, seperti penyisipan atau penghapusan data.

**Fungsi Pembuatan Node Baru (buatNode(string data))**

Fungsi ini membuat node baru untuk menyimpan data dalam list tertaut melingkar. Ia mengalokasikan memori baru untuk node menggunakan operator `new` dan menetapkan nilai `data` yang diberikan ke bidang `data` node. Pointer `next` node baru disetel ke `NULL` karena belum terhubung ke node lain dalam list. Node yang dibuat disimpan dalam variabel global `baru` untuk digunakan dalam operasi berikutnya.

**Fungsi Penghitungan List (hitungList())**

Fungsi ini menghitung jumlah node yang ada dalam list tertaut melingkar. Ia memulai iterasi dari node `head` dan terus mengikuti pointer `next` setiap node hingga kembali ke node `head` (lingkaran). Sebuah variabel `jumlah` diinisialisasi ke 0 dan diincrement setiap kali node baru dijumpai. Nilai `jumlah` yang dihasilkan menunjukkan total node dalam list.

**Fungsi Penyisipan Depan (insertDepan(string data))**

Fungsi ini menyisipkan node baru yang berisi `data` yang diberikan di bagian depan (awal) list tertaut melingkar. Ia menangani dua kasus:

* **List Kosong:** Jika list kosong (`head` adalah `NULL`), node baru menjadi `head` dan `tail` sekaligus, dan pointer `next`-nya disetel ke node `head` (membentuk lingkaran).
* **List Tidak Kosong:** Jika list tidak kosong, node baru disisipkan sebelum node `head` saat ini. Pointer `next` dari node baru disetel ke `head` saat ini, dan pointer `next` dari `tail` diubah untuk menunjuk ke node baru. Node `head` diperbarui ke node baru.

**Fungsi Penyisipan Belakang (insertBelakang(string data))**

Fungsi ini menyisipkan node baru yang berisi `data` yang diberikan di bagian belakang (akhir) list tertaut melingkar. Ia menangani dua kasus:

* **List Kosong:** Jika list kosong (`head` adalah `NULL`), node baru menjadi `head` dan `tail` sekaligus, dan pointer `next`-nya disetel ke node `head` (membentuk lingkaran).
* **List Tidak Kosong:** Jika list tidak kosong, node baru disisipkan setelah node `tail` saat ini. Pointer `next` dari node baru disetel ke `head`, dan pointer `next` dari node `tail` diubah untuk menunjuk ke node baru. 

**Fungsi Penyisipan Tengah (insertTengah(string data, int posisi))**

Fungsi ini menyisipkan node baru yang berisi `data` yang diberikan pada posisi tertentu dalam list tertaut melingkar. Ia memeriksa apakah list kosong dan mengembalikan pesan jika demikian. Jika tidak, fungsi ini melakukan iterasi melalui list hingga mencapai node sebelum posisi yang diinginkan. Node baru disisipkan di antara node tersebut dan node berikutnya. Pointer `next` dari node baru, node sebelum, dan node berikutnya diperbarui sesuai dengannya.

**Fungsi Penghapusan Depan (hapusDepan())**

Fungsi ini menghapus node pertama (awal) dari list tertaut melingkar. Ia menangani dua kasus:

* **List Kosong:** Jika list kosong (`head` adalah `NULL`), pesan "List masih kosong!" ditampilkan.
* **List Tidak Kosong:** Jika list tidak kosong, node `head` dan `tail` diubah untuk menunjuk ke node berikutnya. Node yang dihapus (`hapus`) dibebaskan dari memori menggunakan operator `delete`.

**Fungsi Penghapusan Belakang (hapusBelakang())**

Fungsi ini menghapus node terakhir (akhir) dari list tertaut melingkar. Ia menangani dua kasus:

* **List Kosong:** Jika list kosong (`head` adalah `NULL`), pesan "List masih kosong!" ditampilkan.
* **List Tidak Kosong:** Jika list tidak kosong, node `tail` diubah untuk menunjuk ke node sebelum node terakhir. Node terakhir (`hapus`) dibebaskan dari memori menggunakan operator `delete`.


### Output:
![Screenshot (112)a](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/aea81b2c-b81b-4b69-95ff-e201fb845f6d)

Berdasarkan hasil output tersebut, dapat diamati urutan operasi yang dilakukan sebagai berikut:

1. **Menambahkan "Ayam" di Depan:** Operasi ini menyisipkan data "Ayam" pada posisi paling awal di dalam list. Hal ini mengakibatkan perubahan struktur list dan pergeseran posisi elemen-elemen di belakangnya. Daftar ditampilkan setelah operasi ini.

2. **Menambahkan "Bebek" di Depan:** Operasi ini menyisipkan data "Bebek" pada posisi paling awal, yang berarti menggeser "Ayam" ke posisi kedua. Daftar ditampilkan kembali setelah operasi ini.

3. **Menambahkan "Cicak" di Belakang:** Operasi ini menyisipkan data "Cicak" pada posisi paling akhir di dalam list. Daftar ditampilkan setelah operasi ini.

4. **Menambahkan "Domba" di Belakang:** Operasi ini menyisipkan data "Domba" pada posisi paling akhir, yang berarti menggeser "Cicak" ke posisi kedua dari belakang. Daftar ditampilkan kembali setelah operasi ini.

5. **Menghapus Elemen di Belakang:** Operasi ini menghapus elemen terakhir (saat ini "Domba") dari dalam list. Daftar ditampilkan setelah operasi ini.

6. **Menghapus Elemen di Depan:** Operasi ini menghapus elemen pertama (saat ini "Bebek") dari dalam list. Daftar ditampilkan setelah operasi ini.

7. **Menambahkan "Sapi" di Tengah (Posisi 2):** Operasi ini menyisipkan data "Sapi" pada posisi kedua di dalam list, yang berarti menggeser elemen-elemen di belakangnya. Daftar ditampilkan setelah operasi ini.

8. **Menghapus Elemen di Tengah (Posisi 2):** Operasi ini menghapus elemen pada posisi kedua (saat ini "Sapi") dari dalam list. Daftar ditampilkan setelah operasi ini.

### Full code Screenshot:
![Screenshot (112)](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/76973c81-8b6b-4f7d-95fd-d886d445ebc2)

## Unguided 
Buatlah program menu Linked List Non Circular untuk menyimpan Nama dan NIM mahasiswa, dengan menggunakan input dari user. 

- Program
```C++
#include <iostream>
#include <string>
#include <iomanip> // Library untuk setw
using namespace std;

// Deklarasi Struct Node
struct Node {
    string nama;
    string nim;
    Node *next;
};

Node *head = NULL;

// Inisialisasi Node
void init() {
    head = NULL;
}

// Mengecek apakah list kosong
bool isEmpty() {
    return (head == NULL);
}

// Menambah Data di Depan
void insertDepan(string nama, string nim) {
    Node *baru = new Node;
    baru->nama = nama;
    baru->nim = nim;
    baru->next = head;
    head = baru;
    cout << "Data telah ditambahkan" << endl;
}

// Menambah Data di Belakang
void insertBelakang(string nama, string nim) {
    Node *baru = new Node;
    baru->nama = nama;
    baru->nim = nim;
    baru->next = NULL;
    if (isEmpty()) {
        head = baru;
    } else {
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = baru;
    }
    cout << "Data telah ditambahkan" << endl;
}

// Menambah Data di Tengah
void insertTengah(string nama, string nim, int posisi) {
    Node *baru = new Node;
    baru->nama = nama;
    baru->nim = nim;
    if (posisi == 1 || isEmpty()) {
        insertDepan(nama, nim);
    } else {
        Node *temp = head;
        for (int i = 1; i < posisi - 1 && temp->next != NULL; i++) {
            temp = temp->next;
        }
        baru->next = temp->next;
        temp->next = baru;
        cout << "Data telah ditambahkan" << endl;
    }
}

// Menghapus Node di Depan
void hapusDepan() {
    if (!isEmpty()) {
        Node *hapus = head;
        head = head->next;
        delete hapus;
        cout << "Data posisi mahasiswa yang dipilih berhasil dihapus" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

// Menghapus Node di Belakang
void hapusBelakang() {
    if (!isEmpty()) {
        if (head->next == NULL) {
            hapusDepan();
        } else {
            Node *hapus = head;
            Node *sebelumHapus = NULL;
            while (hapus->next != NULL) {
                sebelumHapus = hapus;
                hapus = hapus->next;
            }
            sebelumHapus->next = NULL;
            delete hapus;
            cout << "Data posisi mahasiswa yang dipilih berhasil dihapus" << endl;
        }
    } else {
        cout << "List kosong!" << endl;
    }
}

// Menghapus Node di Tengah
void hapusTengah(int posisi) {
    if (!isEmpty()) {
        if (posisi == 1) {
            hapusDepan();
        } else {
            Node *hapus = head;
            Node *sebelumHapus = NULL;
            for (int i = 1; i < posisi && hapus->next != NULL; i++) {
                sebelumHapus = hapus;
                hapus = hapus->next;
            }
            if (hapus != NULL) {
                sebelumHapus->next = hapus->next;
                delete hapus;
                cout << "Data posisi mahasiswa yang dipilih berhasil dihapus" << endl;
            } else {
                cout << "Posisi tidak valid" << endl;
            }
        }
    } else {
        cout << "List kosong!" << endl;
    }
}

// Mengubah Data di Depan
void ubahDepan(string namaBaru, string nimBaru) {
    if (!isEmpty()) {
        string namaLama = head->nama;
        string nimLama = head->nim;
        head->nama = namaBaru;
        head->nim = nimBaru;
        cout << "Data (" << namaLama << ", " << nimLama << ") telah diubah menjadi (" << namaBaru << ", " << nimBaru << ")" << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Mengubah Data di Belakang
void ubahBelakang(string namaBaru, string nimBaru) {
    if (!isEmpty()) {
        Node *temp = head;
        string namaLama, nimLama;
        while (temp->next != NULL) {
            namaLama = temp->nama;
            nimLama = temp->nim;
            temp = temp->next;
        }
        namaLama = temp->nama;
        nimLama = temp->nim;
        temp->nama = namaBaru;
        temp->nim = nimBaru;
        cout << "Data (" << namaLama << ", " << nimLama << ") telah diubah menjadi (" << namaBaru << ", " << nimBaru << ")" << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Mengubah Data di Tengah
void ubahTengah(string namaBaru, string nimBaru, int posisi) {
    if (!isEmpty()) {
        Node *temp = head;
        string namaLama, nimLama;
        for (int i = 1; i < posisi && temp != NULL; i++) {
            namaLama = temp->nama;
            nimLama = temp->nim;
            temp = temp->next;
        }
        if (temp != NULL) {
            namaLama = temp->nama;
            nimLama = temp->nim;
            temp->nama = namaBaru;
            temp->nim = nimBaru;
            cout << "Data (" << namaLama << ", " << nimLama << ") pada posisi " << posisi << " telah diubah menjadi (" << namaBaru << ", " << nimBaru << ")" << endl;
        } else {
            cout << "Posisi tidak valid" << endl;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Menghapus Semua Node
void hapusList() {
    Node *hapus;
    while (head != NULL) {
        hapus = head;
        head = head->next;
        delete hapus;
    }
    cout << "List berhasil terhapus!" << endl;
}

void tampilkan() {
    if (!isEmpty()) {
        cout << "=============================================================" << endl;
        cout << "DATA MAHASISWA" << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << "| No.\t| NAMA\t\t\t  | NIM\t\t\t    |" << endl;
        cout << "-------------------------------------------------------------" << endl;
        int counter = 1;
        Node *temp = head;
        while (temp != NULL) {
            cout << "| " << counter << "\t| " << left << setw(24) << temp->nama << "| " << setw(24) << temp->nim << "|" << endl;
            temp = temp->next;
            counter++;
        }
        cout << "-------------------------------------------------------------" << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

int main() {
    int pilihan;
    string nama, nim;
    int posisi;

    do {
        cout << "=============================================================" << endl;
        cout << "PROGRAM SINGLE LINKED LIST NON-CIRCULAR" << endl;
        cout << "=============================================================" << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Tambah Tengah" << endl;
        cout << "4. Ubah Depan" << endl;
        cout << "5. Ubah Belakang" << endl;
        cout << "6. Ubah Tengah" << endl;
        cout << "7. Hapus Depan" << endl;
        cout << "8. Hapus Belakang" << endl;
        cout << "9. Hapus Tengah" << endl;
        cout << "10. Hapus List" << endl;
        cout << "11. Tampilkan" << endl;
        cout << "0. Keluar" << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << "Pilih Operasi : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                insertDepan(nama, nim);
                break;
            case 2:
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                insertBelakang(nama, nim);
                break;
            case 3:
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                cout << "Masukkan Posisi : ";
                cin >> posisi;
                insertTengah(nama, nim, posisi);
                break;
            case 4:
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                ubahDepan(nama, nim);
                break;
            case 5:
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                ubahBelakang(nama, nim);
                break;
            case 6:
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                cout << "Masukkan Posisi : ";
                cin >> posisi;
                ubahTengah(nama, nim, posisi);
                break;
            case 7:
                hapusDepan();
                break;
            case 8:
                hapusBelakang();
                break;
            case 9:
                cout << "Masukkan posisi : ";
                cin >> posisi;
                hapusTengah(posisi);
                break;
            case 10:
                hapusList();
                break;
            case 11:
                tampilkan();
                break;
            case 0:
                cout << "Terima kasih, program selesai" << endl;
                break;
            default:
                cout << "Pilihan tidak valid" << endl;
                break;
        }
    } while (pilihan != 0);

    return 0;
}
```
- Interpretasi
**Program Linked List Non-Circular untuk Manajemen Data Mahasiswa**
Program ini menggunakan struktur data Single Linked List Non-Circular untuk mengelola data mahasiswa, termasuk nama dan NIM mereka. Program ini memungkinkan pengguna untuk menambah, mengubah, menghapus, dan menampilkan data mahasiswa melalui input yang diberikan.

* **Deklarasi Struct Node:** Mendefinisikan struktur data untuk node dalam linked list. Setiap node memiliki dua string untuk menyimpan nama dan NIM mahasiswa, serta pointer `next` yang menunjuk ke node berikutnya di dalam list.

* **Fungsi:**

    * `init()`: Meminisiasi pointer `head` menjadi `NULL`, menunjukkan linked list kosong.

    * `isEmpty()`: Memeriksa apakah linked list kosong.

    * `insertDepan(string nama, string nim)`: Memasukkan node baru di depan linked list. Fungsi ini membuat node baru dengan nama dan NIM yang diberikan, kemudian menghubungkannya ke node pertama yang ada saat ini. Selanjutnya, pointer `head` diperbarui untuk menunjuk ke node baru dan menampilkan pesan konfirmasi.

    * `insertBelakang(string nama, string nim)`: Memasukkan node baru di belakang linked list. Jika linked list kosong, node baru langsung menjadi node pertama (`head`). Namun, jika tidak kosong, fungsi ini mencari node terakhir dengan iterasi melalui semua node menggunakan pointer sementara `temp`, lalu menghubungkan node baru di belakang node terakhir.

    * `insertTengah(string nama, string nim, int posisi)`: Memasukkan node baru pada posisi tertentu di tengah linked list. Jika posisi adalah 1 atau linked list kosong, fungsi ini akan memanggil `insertDepan()` untuk menambahkan node di depan. Jika tidak, fungsi ini mencari node pada posisi sebelumnya (`posisi - 1`) dan menghubungkan node baru di antara node tersebut dan node setelahnya.

    * `hapusDepan()`: Menghapus node di depan linked list.

    * `hapusBelakang()`: Menghapus node terakhir di linked list.

    * `hapusTengah(int posisi)`: Menghapus node pada posisi tertentu di linked list.

    * `ubahDepan(string namaBaru, string nimBaru)`: Mengubah data (nama dan NIM) pada node di depan linked list.

    * `ubahBelakang(string namaBaru, string nimBaru)`: Mengubah data (nama dan NIM) pada node terakhir di linked list.

    * `ubahTengah(string namaBaru, string nimBaru, int posisi)`: Mengubah data (nama dan NIM) pada node pada posisi tertentu di linked list.

    * `hapusList()`: Menghapus semua node dari linked list, sehingga linked list menjadi kosong.

    * `tampilkan()`: Menampilkan semua data mahasiswa yang tersimpan di dalam linked list. Fungsi ini menampilkan nomor urut, nama, dan NIM setiap mahasiswa dalam format tabel.

* **Fungsi Utama:**
    * Merupakan titik masuk program.
    * Menampilkan menu dengan 12 pilihan, termasuk keluar.
    * Meminta pengguna untuk memilih operasi yang diinginkan.
    * Menjalankan operasi yang dipilih berdasarkan pilihan pengguna.
    * Terus menawarkan pilihan operasi sampai pengguna memilih keluar.

**Kesimpulan:**
Program ini menyediakan serangkaian fungsi yang lengkap untuk mengelola data mahasiswa menggunakan Single Linked List Non-Circular. Pengguna dapat dengan mudah menambah, mengubah, menghapus, dan menampilkan data mahasiswa.

### 1. Buatlah menu untuk menambahkan, mengubah, menghapus, dan melihat Nama dan  NIM mahasiswa!

#### Output:
-Tampilan Menu
![Screenshot (113)](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/0ded5a33-01f8-486e-8a6d-34b598c1fb70)

- Tampilan Operasi Tambah:

-Tambah Depan

![Screenshot (114)](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/f99f3b3a-2f08-4676-b6e0-360c0cd52d29)

-Tambah Belakang

![Screenshot (115)](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/65b9cb10-50f9-4632-939e-75dd58d53c2b)


-Tambah Tengah

![Screenshot (116)](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/c5f85907-153b-413d-a0b7-0b0c35fd3522)


- Tampilan Operasi Ubah:

-Ubah Depan

![Screenshot (117)](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/85d2c121-69bf-4b10-8bab-66923e44c953)

-Ubah Belakang

![Screenshot (118)](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/16cb74fc-a7cc-4afe-8bff-2d2c83965732)


-Ubah Tengah

![Screenshot (119)](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/5a033e77-58ee-42ac-b2ca-224f2befdc54)

- Tampilan Operasi Tampilkan:

![Screenshot (121)](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/2df537f9-81d4-4c23-b40c-8502e6247dfc)

- Tampilan Operasi Hapus:
  
-Hapus Belakang

![Screenshot (121)](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/62a81e2f-a143-44ad-89d4-43edcb48bb5d)

-Hapus Tengah
![Screenshot (129)1](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/a464e198-cab8-44ea-9f47-846e142b3034)

- Menampilkan Operasi Hapus List:
![Screenshot (130)1](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/144e7180-51d1-41cc-b4b8-27ddcb4d3207)

- Menampilkan Operator Keluar
![Screenshot (130)2](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/c420034a-f19e-499e-ac32-b749c045418a)


#### Full code Screenshot:
![Screenshot (122)](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/2991e44c-cc3c-433f-8278-6f8bb817b724)


### 2. Setelah membuat menu tersebut, masukkan data sesuai urutan berikut, lalu  tampilkan data yang telah dimasukkan. (Gunakan insert depan, belakang atau tengah) 

#### Output:
- Menggunakan operator 'Tambah Depan' untuk data ke-1
![Screenshot (128)1](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/b0838810-19b5-4569-bbd9-1d7616b3d296)

- Menggunakan operator 'Tambah Belakang'' untuk data ke-10 atau data akhir
![Screenshot (128)2](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/3fd8ac4c-73ba-4aa2-bc8e-0e377c8e93de)

- Menggunakan operator 'Tambah Tengah' untuk data selain ke-1 dan ke-10
![Screenshot (128)](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/2751e9a8-df21-45a0-86ea-19b346a4924c)
![Screenshot (127)](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/60353298-5df2-4548-b8b0-58fb54e41d69)
![Screenshot (126)](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/2842a4f7-551f-44f6-a6bb-bc4e96dd5b21)
![Screenshot (125)](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/67ae39dd-3890-4c8b-b622-4106f5ee5a13)
![Screenshot (124)](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/4dfc597a-a47a-4dda-9596-807c1641dd07)

- Menampilkan data
![Screenshot (123)](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/aa0f42d4-afd1-44fc-95e2-6e18be34135f)

  
#### Full code Screenshot:
![Screenshot (122)](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/a999cead-8ac8-4d47-9922-8a65187a6d3c)

### 3. Lakukan perintah berikut:  

#### Output:
- a. Tambahkan data berikut diantara Farrel dan Denis: Wati 2330004 
![Screenshot (132)](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/91931304-261a-4ae1-aa90-e55acbd18692)

- b. Hapus data Denis 
![Screenshot (133)](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/568426df-6e01-4009-8396-37618d46c2f0)

- c. Tambahkan data berikut di awal: Owi 2330000 
![Screenshot (134)](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/d7b4f9b9-e9f7-40c1-bcc9-101edcc3e1d6)

- d. Tambahkan data berikut di akhir: David 23300100 
![Screenshot (135)](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/fda5e2fa-8d52-44f7-ab6b-b541e91cccfc)

- e. Ubah data Udin menjadi data berikut: Idin 23300045
![Screenshot (136)](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/d6a87cce-3545-4f0c-ae6c-a8f1c22223fa)


- F. Ubah data terakhir menjadi berikut: Lucy 23300101
![Screenshot (137)](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/e10fc73c-bec8-4bfc-b4ea-15b8197986fb)


- g. Hapus data awal 
![Screenshot (138)](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/937e315a-ba20-4926-b349-e30c9391bea0)

Disini kita pilih operator 7 yaitu 'Hapus Depan' untuk menghapus data awal.

- h. Ubah data awal menjadi berikut: Bagas 2330002 
![Screenshot (139)](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/6858a307-ce69-47dc-a2c7-8167343db146)

- i. Hapus data akhir
![Screenshot (140)](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/0dec6115-b6dd-4d74-831e-2efb0957f858)

- j. Tampilkan seluruh data
![Screenshot (131)](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/d8c87603-27fb-4e5e-8383-a2f9490ffb6e)

#### Full code Screenshot:
![Screenshot (131)](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/d8c87603-27fb-4e5e-8383-a2f9490ffb6e)

## Kesimpulan
Kesimpulan pada materi kali ini adalah saya mengetahui bahwa Linked list merupakan struktur data yang fleksibel dan efisien untuk melakukan operasi insersi dan penghapusan. Memahami konsep linked list memberikan dasar yang kuat untuk mempelajari struktur data yang lebih kompleks.


## Referensi
[1] GeeksforGeeks, “Linked List Implementation in C,” GeeksforGeeks, Jan. 17, 2023. https://www.geeksforgeeks.org/linked-list-implementation-in-c-sharp/

[2] H. Sismoro, K. Iskandar, Struktur Data & Pemrograman Dengan Pascal. Indonesia: Penerbit Andi, 2004.
