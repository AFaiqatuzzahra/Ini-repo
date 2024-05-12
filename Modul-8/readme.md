# <h1 align="center">Laporan Praktikum Modul Queue</h1>
<p align="center">Afifah Faiqatuzzahra</p>

## Dasar Teori
Queue Struktur data yang mengikuti prinsip First In, First Out (FIFO). Elemen yang pertama masuk menjadi yang pertama keluar.
Priority Queue Merupakan pengembangan dari queue biasa dimana elemen memiliki nilai "prioritas". Elemen dengan prioritas lebih tinggi akan dikeluarkan terlebih dahulu, meskipun masuk antrian setelah elemen dengan prioritas rendah.[1]
ciri umum dari antrian (queue):
1. FIFO (First In, First Out): Antrian mengikuti prinsip FIFO di mana elemen yang pertama masuk ke dalam antrian akan menjadi yang pertama keluar saat proses penghapusan.
2. Kapasitas Terbatas: Antrian memiliki kapasitas maksimum yang dapat menampung sejumlah elemen. Jika antrian penuh dan ada upaya untuk menambahkan elemen baru, ini bisa menghasilkan kondisi overflow atau penolakan.
3. Operasi Penambahan dan Penghapusan: Elemen dapat ditambahkan ke antrian pada satu ujung (biasanya disebut "rear" atau "tail") dan dihapus dari ujung lain (biasanya disebut "front" atau "head").
4. Kesetimbangan: Antrian harus menjaga keseimbangan antara waktu pemasukan dan pengeluaran elemen untuk mencegah situasi di mana antrian kosong atau terlalu penuh.
5. Penggunaan dalam Penjadwalan: Antrian sering digunakan dalam algoritma penjadwalan untuk mengatur proses atau tugas yang akan dieksekusi oleh sistem komputer.
6. Struktur Data: Antrian merupakan salah satu struktur data dasar yang digunakan dalam pemrograman komputer untuk mengatur data dalam urutan tertentu.
Dapat Diimplementasikan dengan Berbagai Metode: Antrian dapat diimplementasikan menggunakan berbagai pendekatan, termasuk array, linked list, atau struktur data khusus seperti priority queue.
Penggunaan dalam Sistem Komputer: Antrian digunakan secara luas dalam berbagai aplikasi dan sistem komputer, termasuk sistem operasi, jaringan komputer, manajemen memori, dan antrian pelayanan pelanggan.[3]
Antrian (queue) memiliki banyak kegunaan dalam berbagai bidang, termasuk komputasi, manajemen sumber daya, transportasi, dan banyak lagi. Berikut adalah beberapa kegunaan utama dari antrian:
**Penjadwalan Proses**,**Buffering**,**Manajemen Memori**,**Pengurutan**,**Pengelolaan Sumber Daya**,**Pengelolaan Tugas**,**Jaringan Komputer**,**Transportasi**[2]]


## Guided

```C++
#include <iostream>

using namespace std;

const int maksimalQueue = 5;
int front = 0;
int back = 0;

string queueTeller[5];

bool isFull() {
    if (back == maksimalQueue) {
        return true;
    } else {
        return false;
    }
}

bool isEmpty() {
    if (back ==  0) {
        return true;
    } else {
        return false;
    }
}

void enqueueAntrian(string data) {
    if (isFull()) {
        cout << "Antrian Penuh" << endl;
    } else{
        if (isEmpty()) {
            queueTeller[0] = data;
            front++;
            back++;
        } else {
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for ( int i = 0; i < back; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        back --;
    }
}

int countQueue() {
    return back;
}

void clearQueue() {
    if (isEmpty()) {
        cout << "Antrian Kosong" << endl;
    } else {
        for ( int i = 0; i < back; i++) {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void viewQueue() {
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << "." << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" <<endl;
        }
    }
}

int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian =" << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian =" << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian =" << countQueue() << endl;
    return 0;
}
```
## Implementasi Antrian Teller Menggunakan Array di C++

Berikut adalah penjelasan implementasi antrian teller menggunakan array di C++:

**1. Header dan Namespace:**

```c++
#include <iostream>

using namespace std;
```

Baris pertama menyertakan pustaka `iostream` untuk operasi input/output. Baris kedua menggunakan namespace `std` untuk kenyamanan.

**2. Konstanta dan Variabel:**

```c++
const int maksimalQueue = 5;
int front = 0;
int back = 0;

string queueTeller[5];
```

* `maksimalQueue`: Menetapkan ukuran maksimum antrian (5 elemen dalam kasus ini).
* `front`: Menunjuk ke elemen depan antrian (awalnya 0).
* `back`: Menunjuk ke posisi di mana elemen berikutnya akan ditambahkan (awalnya 0).
* `queueTeller`: Array string dengan ukuran `maksimalQueue` untuk menyimpan nama pelanggan.

**3. Operasi Antrian:**

* **isFull():** Memeriksa apakah antrian penuh dengan membandingkan `back` dengan `maksimalQueue`.
* **isEmpty():** Memeriksa apakah antrian kosong dengan membandingkan `back` dengan 0.
* **enqueueAntrian(string data):** Menambahkan pelanggan baru (`data`) ke antrian.
    * Jika antrian penuh, menampilkan "Antrian Penuh".
    * Jika tidak, menambahkan data ke `queueTeller[back]`, meningkatkan `back`, dan jika antrian kosong, juga meningkatkan `front`.
* **dequeueAntrian():** Menghapus elemen depan dari antrian.
    * Jika antrian kosong, menampilkan "Antrian kosong".
    * Jika tidak, mengulangi elemen, menggesernya ke depan satu posisi untuk menghapus elemen depan. Kemudian mengurangi `back`.
* **countQueue():** Mengembalikan jumlah elemen saat ini dalam antrian menggunakan nilai `back`.
* **clearQueue():** Mengosongkan antrian dengan menyetel semua elemen dalam `queueTeller` ke string kosong dan menyetel ulang `back` dan `front` ke 0.
    * Jika antrian sudah kosong, menampilkan "Antrian Kosong".
* **viewQueue():** Mencetak isi antrian.
    * Mengulangi array `queueTeller`.
    * Jika elemen tidak kosong, menampilkan nomor elemen dan nama.
    * Jika elemen kosong, menampilkan nomor elemen dan "(kosong)".

**4. Fungsi Utama:**

```c++
int main() {
  enqueueAntrian("Andi");
  enqueueAntrian("Maya");
  viewQueue();
  cout << "Jumlah antrian =" << countQueue() << endl;
  dequeueAntrian();
  viewQueue();
  cout << "Jumlah antrian =" << countQueue() << endl;
  clearQueue();
  viewQueue();
  cout << "Jumlah antrian =" << countQueue() << endl;
  return 0;
}
```

Fungsi `main` menunjukkan cara menggunakan operasi antrian yang diimplementasikan:

* Menambahkan "Andi" dan "Maya" (menambahkannya ke antrian).
* Mencetak isi antrian menggunakan `viewQueue`.
* Menampilkan jumlah elemen menggunakan `countQueue`.
* Menghapus elemen (menghapus elemen depan).
* Mencetak isi antrian lagi.
* Menampilkan jumlah elemen lagi.
* Mengosongkan antrian.
* Mencetak isi antrian (seharusnya kosong).
* Menampilkan jumlah elemen (seharusnya 0).

Kode ini secara efektif mengimplementasikan antrian menggunakan array untuk simulasi antrian teller dasar.

### Output
![Screenshot (149)](https://github.com/AFaiqatuzzahra/Praktikum-Algoritma-Pemrograman-dan-Struktur-Data/assets/152428747/88b719af-ffcb-4688-a037-d13c429d35e7)

## Informasi yang Dapat Diketahui dari Output Kode

Berdasarkan output kode yang Anda berikan, berikut informasi yang dapat diketahui:

### 1. Operasi pada Antrian Teller

* **Penambahan Pelanggan:**
    * "Andi" ditambahkan ke antrian teller.
    * "Maya" ditambahkan ke antrian teller.

* **Penampilan Antrian:**
    * Setelah menambahkan "Andi" dan "Maya", antrian berisi:
        * 1. Andi
        * 2. Maya
        * 3. (kosong)
        * 4. (kosong)
        * 5. (kosong)
    * Jumlah antrian adalah 2.
    * Setelah dequeueing, antrian berisi:
        * 1. Maya
        * 2. (kosong)
        * 3. (kosong)
        * 4. (kosong)
        * 5. (kosong)
    * Jumlah antrian adalah 1.
    * Setelah clearQueue, antrian berisi:
        * 1. (kosong)
        * 2. (kosong)
        * 3. (kosong)
        * 4. (kosong)
        * 5. (kosong)
    * Jumlah antrian adalah 0.

### 2. Status Antrian

* **Antrian Penuh:**
    * Kode tidak menunjukkan pesan "Antrian Penuh" karena antrian tidak pernah mencapai kapasitas maksimum (5 elemen).

* **Antrian Kosong:**
    * Pesan "Antrian kosong" muncul ketika dequeueing dari antrian kosong dan ketika clearQueue dijalankan pada antrian kosong.

### 3. Jumlah Elemen

* Jumlah elemen dalam antrian ditampilkan setelah setiap operasi enqueue, dequeue, dan clearQueue.

### 4. Simulasi Antrian Teller

* Kode ini mensimulasikan antrian teller sederhana dengan menambahkan, menghapus, dan menampilkan nama pelanggan.

### Full code screenshot
![Screenshot (149)](https://github.com/AFaiqatuzzahra/Praktikum-Algoritma-Pemrograman-dan-Struktur-Data/assets/152428747/88b719af-ffcb-4688-a037-d13c429d35e7)


## Unguided1
```C++
#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;
public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty() {
        return (front == nullptr);
    }

    void enqueue(string data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        } else {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    void displayQueue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        } else {
            Node* current = front;
            cout << "Data antrian teller:" << endl;
            while (current != nullptr) {
                cout << current->data << endl;
                current = current->next;
            }
        }
    }
};

int main() {
    Queue antrian;

    antrian.enqueue("Andi");
    antrian.enqueue("Maya");
    antrian.displayQueue();

    antrian.dequeue();
    antrian.displayQueue();

    return 0;
}
```
## Implementasi Antrian Teller Menggunakan Linked List di C++

Kode yang diberikan sudah mengimplementasikan antrian menggunakan linked list untuk simulasi antrian teller. Berikut penjelasan rincinya:

**1. Struktur dan Definisi Kelas:**

* **Node (Simpul):**
    * `data`: Variabel string untuk menyimpan nama pelanggan.
    * `next`: Penunjuk ke simpul berikutnya di linked list.
* **Queue (Antrian):**
    * Anggota private:
        * `front`: Penunjuk ke simpul depan antrian (awalnya `nullptr`).
        * `rear`: Penunjuk ke simpul belakang antrian (awalnya `nullptr`).
    * Fungsi anggota publik:
        * **Konstruktor:** Meminisiasi `front` dan `rear` menjadi `nullptr`.
        * **isEmpty():** Memeriksa apakah antrian kosong dengan memeriksa apakah `front` adalah `nullptr`.
        * **enqueue(string data):** Menambahkan pelanggan baru (`data`) ke antrian.
            * Membuat `Node` baru dan menetapkan data.
            * Mengatur penunjuk `next` dari node baru ke `nullptr`.
            * Jika antrian kosong, atur `front` dan `rear` ke node baru.
            * Jika tidak, atur penunjuk `next` dari node `rear` saat ini ke node baru dan perbarui `rear` untuk menunjuk ke node baru.
        * **dequeue():** Menghapus elemen depan dari antrian.
            * Memeriksa apakah antrian kosong. Jika ya, tampilkan "Antrian kosong".
            * Jika tidak, simpan node depan dalam variabel sementara `temp`.
            * Perbarui `front` untuk menunjuk ke node kedua di antrian.
            * Hapus node sementara menggunakan `delete temp`.
        * **displayQueue():** Mencetak isi antrian.
            * Memeriksa apakah antrian kosong. Jika ya, tampilkan "Antrian kosong".
            * Jika tidak, iterasi melalui linked list dimulai dari `front`, cetak data dari setiap node hingga mencapai `nullptr`.

**2. Fungsi Utama:**

```c++
int main() {
  Queue antrian; // Objek Queue bernama antrian

  antrian.enqueue("Andi");
  antrian.enqueue("Maya");
  antrian.displayQueue();

  antrian.dequeue();
  antrian.displayQueue();

  return 0;
}
```

Fungsi `main` mendemonstrasikan cara menggunakan operasi antrian yang diimplementasikan:

* Membuat objek `Queue` bernama `antrian`.
* Menambahkan "Andi" dan "Maya" (menambahkannya ke antrian).
* Mencetak isi antrian menggunakan `displayQueue`.
* Menghapus elemen (menghapus elemen depan).
* Mencetak isi antrian lagi.

### Output
![image](https://github.com/AFaiqatuzzahra/Praktikum-Algoritma-Pemrograman-dan-Struktur-Data/assets/152428747/dcee88df-b09b-442e-84e6-3c3fee22a0fd)

daei output tersebut dapat diketahui bahwa data pada antrian tersebut adalah Andi dan Maya.

### Full Screenshot
![Screenshot (155)](https://github.com/AFaiqatuzzahra/Praktikum-Algoritma-Pemrograman-dan-Struktur-Data/assets/152428747/24ba6099-62b9-49c3-82de-b9c6df9adeb8)


## Unguided2
```C++
#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    Mahasiswa* next;
};

class AntrianMahasiswa {
private:
    Mahasiswa* front;
    Mahasiswa* rear;
public:
    AntrianMahasiswa() {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty() {
        return (front == nullptr);
    }

    void enqueue(string nama, string nim) {
        Mahasiswa* newNode = new Mahasiswa();
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->next = nullptr;
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        } else {
            Mahasiswa* temp = front;
            front = front->next;
            delete temp;
        }
    }

    void displayAntrian() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        } else {
            Mahasiswa* current = front;
            cout << "Data dalam antrian mahasiswa:" << endl;
            while (current != nullptr) {
                cout << "Nama: " << current->nama << ", NIM: " << current->nim << endl;
                current = current->next;
            }
        }
    }
};

int main() {
    AntrianMahasiswa antrian;

    // Menambahkan beberapa mahasiswa ke dalam antrian
    antrian.enqueue("Andi", "123456789");
    antrian.enqueue("Maya", "987654321");

    // Menampilkan isi antrian
    antrian.displayAntrian();

    // Menghapus mahasiswa pertama dari antrian
    antrian.dequeue();

    // Menampilkan isi antrian setelah penghapusan
    antrian.displayAntrian();

    return 0;
}
```
## Implementasi Antrian Mahasiswa Menggunakan Linked List di C++

Kode yang diberikan berhasil mengimplementasikan antrian untuk mengelola antrian mahasiswa menggunakan struktur data linked list. Berikut penjelasan rinciannya:

**1. Struktur dan Definisi Kelas:**

* **Mahasiswa (Student):**
    * `nama`: Variabel string untuk menyimpan nama mahasiswa.
    * `nim`: Variabel string untuk menyimpan NIM (Nomor Induk Mahasiswa).
    * `next`: Penunjuk ke node berikutnya di linked list.
* **AntrianMahasiswa (StudentQueue):**
    * Anggota private:
        * `front`: Penunjuk ke node depan antrian (awalnya `nullptr`).
        * `rear`: Penunjuk ke node belakang antrian (awalnya `nullptr`).
    * Fungsi anggota publik:
        * **Konstruktor:** Meminisiasi `front` dan `rear` menjadi `nullptr`.
        * **isEmpty():** Memeriksa apakah antrian kosong dengan memeriksa apakah `front` adalah `nullptr`.
        * **enqueue(string nama, string nim):** Menambahkan mahasiswa baru (`nama` dan `nim`) ke antrian.
            * Membuat node `Mahasiswa` baru dan menetapkan data.
            * Mengatur penunjuk `next` dari node baru ke `nullptr`.
            * Jika antrian kosong, atur `front` dan `rear` ke node baru.
            * Jika tidak, atur penunjuk `next` dari node `rear` saat ini ke node baru dan perbarui `rear` untuk menunjuk ke node baru.
        * **dequeue():** Menghapus elemen depan (mahasiswa pertama) dari antrian.
            * Memeriksa apakah antrian kosong. Jika ya, tampilkan "Antrian kosong".
            * Jika tidak, simpan node depan dalam variabel sementara `temp`.
            * Perbarui `front` untuk menunjuk ke node kedua di antrian.
            * Hapus node sementara menggunakan `delete temp`.
        * **displayAntrian():** Mencetak isi antrian.
            * Memeriksa apakah antrian kosong. Jika ya, tampilkan "Antrian kosong".
            * Jika tidak, iterasi melalui linked list dimulai dari `front`, mencetak data dari setiap node (nama dan NIM) hingga mencapai `nullptr`.

**2. Fungsi Utama:**

```c++
int main() {
  AntrianMahasiswa antrian; // Objek AntrianMahasiswa bernama antrian

  // Menambahkan beberapa mahasiswa ke dalam antrian (menambahkan mahasiswa)
  antrian.enqueue("Andi", "123456789");
  antrian.enqueue("Maya", "987654321");

  // Menampilkan isi antrian
  antrian.displayAntrian();

  // Menghapus mahasiswa pertama dari antrian (menghapus mahasiswa pertama)
  antrian.dequeue();

  // Menampilkan isi antrian setelah penghapusan
  antrian.displayAntrian();

  return 0;
}
```

Fungsi `main` mendemonstrasikan cara menggunakan operasi antrian yang diimplementasikan:

* Membuat objek `AntrianMahasiswa` bernama `antrian`.
* Menambahkan (enqueue) dua mahasiswa ke antrian: "Andi" dengan NIM "123456789" dan "Maya" dengan NIM "987654321".
* Memanggil `displayAntrian` untuk mencetak isi antrian.
* Menghapus (dequeue) mahasiswa pertama dari antrian.
* Memanggil `displayAntrian` lagi untuk mencetak isi antrian setelah dequeue.

**Ringkasan:**

Kode ini efektif mengimplementasikan antrian mahasiswa menggunakan linked list dan menyediakan operasi dasar enqueue, dequeue, dan display untuk mengelola antrian. Ini dapat digunakan untuk simulasi antrian mahasiswa yang menunggu layanan atau sumber daya.
### Output
![Screenshot (156)](https://github.com/AFaiqatuzzahra/Praktikum-Algoritma-Pemrograman-dan-Struktur-Data/assets/152428747/b5c9cfbf-f103-4e80-b767-480be784a448)

Dari output diatas dapat disimpulkan bahwa kode ini efektif mengimplementasikan antrian mahasiswa menggunakan linked list dan menyediakan operasi dasar enqueue, dequeue, dan display untuk mengelola antrian. Ini dapat digunakan untuk simulasi antrian mahasiswa yang menunggu layanan atau sumber daya.
### Full Screenshot
![Screenshot (156)](https://github.com/AFaiqatuzzahra/Praktikum-Algoritma-Pemrograman-dan-Struktur-Data/assets/152428747/b5c9cfbf-f103-4e80-b767-480be784a448)



[1]Goponenko, A., & Carroll, S. (2019). A C++ implementation of a lock-free priority queue based on Multi-Dimensional Linked List. Link: https://www. researchgate. net/publication/337020321_A_C_Implementation_of_a_Lock-Free _Priority_Queue_Based_on_Multi-Dimensional_Linked_List.
[2][1]GeeksforGeeks, “Queue Data Structure - GeeksforGeeks,” GeeksforGeeks, 2015. https://www.geeksforgeeks.org/queue-data-structure/
[3]K. Jagannathan and E. Modiano, "The Impact of Queue Length Information on Buffer Overflow in Parallel Queues," in IEEE Transactions on Information Theory, vol. 59, no. 10, pp. 6393-6404, Oct. 2013, doi: 10.1109/TIT.2013.2268926. keywords: {Queueing analysis;Servers;Indexes;Scheduling;Trajectory;Processor scheduling;Topology;Buffer overflow probability;large deviations;queue length-based scheduling},
