# <h1 align="center">Laporan Praktikum Modul Graph and Tree</h1>
<p align="center">Afifah Faiqatuzzahra</p>

## Dasar Teori
Graph adalah struktur data yang digunakan untuk merepresentasikan hubungan atau koneksi antara sekelompok objek. Graph terdiri dari vertex (atau node) dan edge (atau arc). Vertex mewakili objek, dan edge mewakili koneksi atau hubungan antara objek-objek tersebut. Graph dapat bersifat berarah (directed) atau tidak berarah (undirected), dan juga bisa memiliki bobot (weighted) atau tidak berbobot (unweighted).[1]
Jenis-jenis Graph:
1. Graf Tak Berarah (Undirected Graph):
Graf di mana setiap sisi (edge) tidak memiliki arah. Artinya, jika ada sisi antara simpul A dan B, maka kita dapat bergerak dari A ke B dan sebaliknya.
2. Graf Berarah (Directed Graph atau Digraph):
Graf di mana setiap sisi memiliki arah, menunjukkan hubungan satu arah.
3. Graf Berbobot (Weighted Graph):
Graf di mana setiap sisi memiliki bobot atau biaya yang terkait.
4. Graf Tak Berbobot (Unweighted Graph):
Graf di mana semua sisi memiliki bobot yang sama.
5. Graf Terhubung (Connected Graph):
Graf di mana ada jalur antara setiap pasangan simpul.
6. Graf Tidak Terhubung (Disconnected Graph):
Graf di mana setidaknya ada dua simpul yang tidak memiliki jalur penghubung.
7. Graf Siklik (Cyclic Graph):
Graf yang mengandung setidaknya satu siklus (jalur yang dimulai dan berakhir pada simpul yang sama).
8. Graf Asiklik (Acyclic Graph):
Graf yang tidak memiliki siklus.
9. Pohon (Tree):
Graf terhubung yang tidak memiliki siklus.
10. Graf Lengkap (Complete Graph):
Graf di mana setiap pasangan simpul terhubung oleh sisi unik.
11. Graf Bipartit (Bipartite Graph):
Graf di mana simpul dapat dibagi menjadi dua set disjoint sedemikian rupa sehingga setiap sisi menghubungkan simpul di satu set dengan simpul di set lainnya.
12. Multigraf (Multigraph):
Graf yang dapat memiliki beberapa sisi antara sepasang simpul.
13. Subgraf (Subgraph):
Graf yang dibentuk dari subset simpul dan sisi dari graf lain.
14. Graf Planar (Planar Graph):
Graf yang dapat digambar di bidang tanpa ada sisi yang saling memotong.[2]

Tree adalah bentuk khusus dari graph yang tidak memiliki cycle dan memiliki struktur hierarkis. Tree memiliki satu root node dan setiap node (kecuali root) memiliki satu parent node dan nol atau lebih child node. Tree yang paling sederhana adalah binary tree, di mana setiap node memiliki paling banyak dua child.[4]
Beberapa jenis tree yang umum:
1. Binary Tree: Setiap node memiliki paling banyak dua anak.
2. Binary Search Tree (BST): Binary tree di mana nilai left child selalu lebih kecil daripada nilai parent dan nilai right child selalu lebih besar.
3. AVL Tree: Binary search tree yang seimbang.
4. Red-Black Tree: Binary search tree yang menggunakan warna untuk memastikan keseimbangan.[3]

## Guided1
```C++
#include<iostream>
#include<iomanip>

using namespace std;

string simpul[7] = {
    "Ciamis", "Bandung", "Tasikmalaya", "Cianjur", "Purwokerto", "Yogyakarta"
};

int busur[7][7] = {
    {0,7,8,0,0,0,0},
    {0,0,5,0,0,15,0},
    {0,6,0,0,5,0,0},
    {0,5,0,0,2,4,0},
    {23,0,0,10,0,0,8},
    {0,0,0,0,7,0,3},
    {0,0,0,0,9,4,0}
};

void tampilGraph() {
    for (int baris = 0; baris < 7; baris++) {
        cout << " " << setiosflags(ios::left) << setw(15) << simpul[baris] << " : ";
        for (int kolom = 0; kolom < 7; kolom++) {
            if (busur[baris][kolom] != 0) {
                cout << " " << simpul[kolom] << " (" << busur[baris][kolom] << ")";
            } 
        }
        cout << endl;
    }
}

int main() {
    tampilGraph();
    return 0;
}
```
## Implementasi 
Kode ini merepresentasikan graf sederhana yang menggambarkan rute perjalanan bus antar kota. Berikut adalah implementasinya:

1. **Header Files:**
   - `#include <iostream>`: Mengizinkan operasi input dan output standar (seperti `cout` dan `endl`).
   - `#include <iomanip>`: Menyediakan manipulasi output, seperti mengatur lebar kolom (`setw`) dan perataan teks (`setiosflags`).
2. **Namespace std:**
   - `using namespace std;`: Menghindari penulisan berulang `std::` sebelum elemen-elemen standar seperti `cout`.
3. **Array Simpul:**
   - `string simpul[7]`: Array untuk menyimpan nama-nama kota (simpul graf).
4. **Matriks Busur:**
   - `int busur[7][7]`: Matriks yang merepresentasikan hubungan (busur) antar kota. Nilai 0 berarti tidak ada rute langsung, sedangkan nilai lainnya menunjukkan jarak antara dua kota.
5. **Fungsi tampilGraph():**
   - Fungsi ini menampilkan representasi graf ke layar.
   - Loop pertama (`for (int baris = 0; baris < 7; baris++)`) mengiterasi setiap baris matriks `busur`.
   - `cout << " " << setiosflags(ios::left) << setw(15) << simpul[baris] << " : ";` menampilkan nama kota (simpul) dengan perataan kiri dan lebar 15 karakter.
   - Loop kedua (`for (int kolom = 0; kolom < 7; kolom++)`) mengiterasi setiap kolom dalam baris tersebut.
   - `if (busur[baris][kolom] != 0)` memeriksa apakah ada rute langsung antara kota pada baris dan kolom saat ini.
   - Jika ada rute, `cout << " " << simpul[kolom] << " (" << busur[baris][kolom] << ")";` menampilkan nama kota tujuan dan jaraknya.
6. **Fungsi main():**
   - Titik awal eksekusi program.
   - Memanggil fungsi `tampilGraph()` untuk menampilkan graf.
   - `return 0;` menunjukkan bahwa program berakhir dengan sukses.
### Output
![image](https://github.com/AFaiqatuzzahra/Praktikum-Algoritma-Pemrograman-dan-Struktur-Data/assets/152428747/accf0725-347d-4cda-bf80-a92a407f139a)

## Kesimpulan
Output tersebut menampilkan representasi graf dari rute bus antar kota, dengan format: "Kota Asal : Kota Tujuan (Jarak)". Ini menunjukkan hubungan langsung dan jarak antar kota yang terhubung dalam jaringan rute bus tersebut.

### Full code screenshot
![image](https://github.com/AFaiqatuzzahra/Praktikum-Algoritma-Pemrograman-dan-Struktur-Data/assets/152428747/accf0725-347d-4cda-bf80-a92a407f139a)

## Guided2
```C++
#include<iostream>
using namespace std;

struct TNode {
    int data;
    TNode *left;
    TNode *right;

    //constuctor
    TNode(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void preOrder(TNode *node) {
    if (node != NULL) {
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void inOrder(TNode *node) {
    if (node != NULL) {
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
}

void postOrder(TNode *node){
    if (node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data<< " ";
    }
}

int main() {
    TNode *zero = new TNode(0);
    // 0
    // /\
    // NULL NULL

    TNode *one = new TNode(1);
    TNode *five = new TNode(5);
    TNode *seven = new TNode(7);
    TNode *eight = new TNode(8);
    TNode *nine = new TNode(9);

    seven->left = one;
    // 7
    // /\
    // 1 NULL


    seven->right = nine;
    //7
    // /\
    // 1 9

    one->left=zero;
    // 7
    // /\
    // 1 9
    // /\
    // 0 NULL

    one->right = five;
    //7
    // /\
    // 1 9
    // /\
    
    nine->left = eight;
    // 7
    // /\
    // 1 9
    // / \ / \

    preOrder(seven);
    cout << endl;

    inOrder(seven);
    cout<< endl;

    postOrder(seven);
    cout << endl;

    return 0;
}
```
## Implementasi 
1. **Struktur `TNode`:**
   - `data`: Menyimpan nilai integer yang akan disimpan dalam node.
   - `left`: Pointer yang menunjuk ke node anak kiri.
   - `right`: Pointer yang menunjuk ke node anak kanan.
   - Konstruktor `TNode(int value)`: Inisialisasi data node dengan nilai yang diberikan dan mengatur pointer `left` dan `right` menjadi NULL.
2. **Fungsi Traversal:**
   - `preOrder(TNode *node)`: Traversal preorder (root, left, right) secara rekursif.
   - `inOrder(TNode *node)`: Traversal inorder (left, root, right) secara rekursif.
   - `postOrder(TNode *node)`: Traversal postorder (left, right, root) secara rekursif.
3. **Fungsi `main()`:**
   - Membuat node-node dengan nilai 0, 1, 5, 7, 8, dan 9.
   - Menghubungkan node-node tersebut untuk membentuk binary tree seperti yang diilustrasikan dalam komentar pada kode.
   - Memanggil fungsi traversal `preOrder`, `inOrder`, dan `postOrder` untuk mencetak hasil traversal ke konsol.

### Output
![image](https://github.com/AFaiqatuzzahra/Praktikum-Algoritma-Pemrograman-dan-Struktur-Data/assets/152428747/210e6b01-8708-441a-a922-de4a5b025ba1)

Output yang diberikan menunjukkan hasil dari tiga jenis traversal pada sebuah binary tree:
- **Preorder:** 7 1 0 5 9 8
- **Inorder:** 0 1 5 7 8 9
- **Postorder:** 0 5 1 8 9 7

Kesimpulannya, output ini adalah urutan node-node dalam binary tree tersebut saat dikunjungi menggunakan metode preorder, inorder, dan postorder.
**Penjelasan:**
- **Preorder:** Root dikunjungi pertama kali, lalu subtree kiri, kemudian subtree kanan.
- **Inorder:** Subtree kiri dikunjungi terlebih dahulu, lalu root, kemudian subtree kanan. Inorder traversal pada binary search tree akan menghasilkan urutan node terurut menaik.
- **Postorder:** Subtree kiri dikunjungi pertama, lalu subtree kanan, dan terakhir root.
**Binary Tree yang dihasilkan dari kode tersebut adalah sebagai berikut:**
```
      7
     / \
    1   9
   / \ / \
  0  5 8  NULL
```
### Full Screenshot
![image](https://github.com/AFaiqatuzzahra/Praktikum-Algoritma-Pemrograman-dan-Struktur-Data/assets/152428747/210e6b01-8708-441a-a922-de4a5b025ba1)

## Unguided1
```c++
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void hitungJarakAntarKota() {
    int jumlahKota;
    cout << "Masukkan jumlah kota: ";
    cin >> jumlahKota;
    cin.ignore(); 
    
    vector<string> namaKota(jumlahKota); 
    vector<vector<int>> jarak(jumlahKota, vector<int>(jumlahKota)); 

    for (int i = 0; i < jumlahKota; ++i) {
        cout << "Masukkan nama kota ke-" << i + 1 << ": ";
        getline(cin, namaKota[i]); 
    }

  
    cout << "\nMasukkan jarak antar kota (0 jika tidak ada jalur langsung):\n";
    for (int i = 0; i < jumlahKota; ++i) {
        for (int j = 0; j < jumlahKota; ++j) {
            if (i == j) {
                jarak[i][j] = 0; 
            } else {
                cout << namaKota[i] << " --> " << namaKota[j] << " = ";
                cin >> jarak[i][j];
            }
        }
    }

    cout << "\nMatriks Jarak:\n    ";
    for (const string& nama : namaKota) {
        cout << nama << "\t";
    }
    cout << endl;
    for (int i = 0; i < jumlahKota; ++i) {
        cout << namaKota[i] << "\t";
        for (int j = 0; j < jumlahKota; ++j) {
            cout << jarak[i][j] << "\t";
        }
        cout << endl;
    }

     string kotaAwal, kotaTujuan;
    cout << "\nMasukkan kota awal: ";
    cin.ignore();
    getline(cin, kotaAwal);
    cout << "Masukkan kota tujuan: ";
    getline(cin, kotaTujuan);

    int indeksAwal = -1, indeksTujuan = -1;
    for (int i = 0; i < jumlahKota; ++i) {
        if (namaKota[i] == kotaAwal) {
            indeksAwal = i;
        }
        if (namaKota[i] == kotaTujuan) {
            indeksTujuan = i;
        }
    }

    if (indeksAwal != -1 && indeksTujuan != -1) {
        if (jarak[indeksAwal][indeksTujuan] == 0) {
            cout << "Tidak ada jalur langsung dari " << kotaAwal << " ke " << kotaTujuan << endl;
        } else {
            cout << "Jarak dari " << kotaAwal << " ke " << kotaTujuan << " adalah " << jarak[indeksAwal][indeksTujuan] << endl;
        }
    } else {
        cout << "Kota tidak ditemukan." << endl;
    }
}

int main() {
    string nama;
    int nim;

    cout << "Masukkan nama Anda: ";
    getline(cin, nama); 

    cout << "Masukkan NIM Anda: ";
    cin >> nim; 
    cout << "\nNama: " << nama << endl;
    cout << "NIM: " << nim << endl;

    hitungJarakAntarKota();
    return 0;
}
```
### Implementasi
1. **Header Files:**
   - `#include <iostream>`: Untuk operasi input dan output standar (cout, cin).
   - `#include <string>`: Untuk bekerja dengan tipe data string (nama kota).
   - `#include <vector>`: Untuk menggunakan vector (array dinamis) untuk menyimpan nama kota dan jarak.
2. **Fungsi `hitungJarakAntarKota()`:**
   - **Input Jumlah Kota:** Meminta pengguna memasukkan jumlah kota.
   - **Input Nama Kota:** Meminta pengguna memasukkan nama kota satu per satu menggunakan `getline(cin, ...)` untuk membaca input termasuk spasi.
   - **Input Jarak Antar Kota:** Meminta pengguna memasukkan jarak antara setiap pasangan kota. Jarak 0 berarti tidak ada jalur langsung.
   - **Membuat Matriks Jarak:** Menyimpan jarak antar kota dalam bentuk matriks dua dimensi (`vector<vector<int>> jarak`).
   - **Menampilkan Matriks Jarak:** Mencetak matriks jarak dalam format tabel yang mudah dibaca.
   - **Input Kota Awal dan Tujuan:** Meminta pengguna memasukkan nama kota awal dan tujuan.
   - **Mencari Indeks Kota:** Mencari indeks kota awal dan tujuan dalam vector `namaKota`.
   - **Menampilkan Jarak:** Jika kedua kota ditemukan, menampilkan jaraknya. Jika tidak ada jalur langsung, mencetak pesan yang sesuai. Jika kota tidak ditemukan, mencetak pesan kesalahan.
3. **Fungsi `main()`:**
   - **Input Nama dan NIM:** Meminta pengguna memasukkan nama dan NIM.
   - **Menampilkan Nama dan NIM:** Mencetak nama dan NIM yang dimasukkan.
   - **Memanggil Fungsi `hitungJarakAntarKota()`:** Memulai proses menghitung jarak antar kota.

### Output
![image](https://github.com/AFaiqatuzzahra/Praktikum-Algoritma-Pemrograman-dan-Struktur-Data/assets/152428747/22577a6d-a95c-4885-b58b-b210040b20b0)
Output program menunjukkan bahwa program berhasil menghitung dan menampilkan jarak antara dua kota yang dimasukkan oleh pengguna.
1. **Input Data:** Pengguna memasukkan nama ("Afifah Faiqatuzzahra") dan NIM (23111143) sebagai informasi awal. Kemudian, pengguna memasukkan jumlah kota (2), nama kota-kota tersebut ("Batu" dan "Palu"), serta jarak antar kota (Batu ke Palu: 3, Palu ke Batu: 4).
2. **Matriks Jarak:** Program menghasilkan matriks jarak yang menunjukkan jarak antara setiap pasangan kota. Dalam contoh ini, matriks jarak adalah:
```
    Batu   Palu
Batu   0     3
Palu   4     0
```
3. **Perhitungan Jarak:** Pengguna memasukkan kota awal ("Batu") dan kota tujuan ("Palu"). Program berhasil mencari jarak antara kedua kota tersebut dalam matriks jarak dan menampilkan hasilnya:

```
Jarak dari Batu ke Palu adalah 3
```
### Full Screenshoot
![image](https://github.com/AFaiqatuzzahra/Praktikum-Algoritma-Pemrograman-dan-Struktur-Data/assets/152428747/22577a6d-a95c-4885-b58b-b210040b20b0)

## Unguided2
```C++
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct Node {
    string data;
    Node* left;
    Node* right;

    Node(string val) : data(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, string data) {
    if (root == nullptr) {
        return new Node(data);
    }
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (!temp->left) {
            temp->left = new Node(data);
            break;
        } else {
            q.push(temp->left);
        }

        if (!temp->right) {
            temp->right = new Node(data);
            break;
        } else {
            q.push(temp->right);
        }
    }
    return root;
}

Node* findNode(Node* root, const string& data) {
    if (!root) return nullptr;
    if (root->data == data) return root;

    Node* leftNode = findNode(root->left, data);
    if (leftNode) return leftNode;

    return findNode(root->right, data);
}

void displayChildren(Node* node) {
    if (!node) {
        cout << "Node tidak ditemukan." << endl;
        return;
    }
    cout << "Child dari node " << node->data << ": ";
    if (node->left) cout << node->left->data << " ";
    if (node->right) cout << node->right->data;
    cout << endl;
}

void displayDescendants(Node* node) {
    if (!node) {
        cout << "Node tidak ditemukan." << endl;
        return;
    }
    queue<Node*> q;
    q.push(node);
    cout << "Descendant dari node " << node->data << ": ";
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        if (temp != node) cout << temp->data << " ";

        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
    cout << endl;
}

int main() {
    Node* root = nullptr;
    int choice;
    string data;

    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah node ke tree\n";
        cout << "2. Tampilkan child dari node\n";
        cout << "3. Tampilkan descendant dari node\n";
        cout << "4. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
        case 1:
            cout << "Masukkan data node: ";
            getline(cin, data);
            root = insert(root, data);
            break;
        case 2:
            cout << "Masukkan data node yang ingin ditampilkan child-nya: ";
            getline(cin, data);
            displayChildren(findNode(root, data));
            break;
        case 3:
            cout << "Masukkan data node yang ingin ditampilkan descendant-nya: ";
            getline(cin, data);
            displayDescendants(findNode(root, data));
            break;
        case 4:
            cout << "Keluar dari program.\n";
            break;
        default:
            cout << "Opsi tidak valid. Silakan coba lagi.\n";
        }
    } while (choice != 4);

    return 0;
}
```
### Implementasi
1. **Struktur Node:**
   - `data`: Menyimpan data dalam node (tipe `string`).
   - `left`: Pointer ke node anak kiri.
   - `right`: Pointer ke node anak kanan.
2. **Fungsi `insert(Node* root, string data)`:**
   - Menyisipkan node baru ke dalam Binary Tree.
   - Menggunakan antrian (`queue`) untuk melakukan penyisipan secara level order (BFS).
3. **Fungsi `findNode(Node* root, const string& data)`:**
   - Mencari node dengan data tertentu dalam Binary Tree.
   - Menggunakan rekursi untuk mencari di kedua subtree.
4. **Fungsi `displayChildren(Node* node)`:**
   - Menampilkan anak (child) dari node tertentu.
   - Jika node tidak ada, mencetak pesan "Node tidak ditemukan."
   - Jika ada, menampilkan data dari anak kiri dan kanan (jika ada).
5. **Fungsi `displayDescendants(Node* node)`:**
   - Menampilkan semua keturunan (descendant) dari node tertentu.
   - Jika node tidak ada, mencetak pesan "Node tidak ditemukan."
   - Jika ada, melakukan BFS untuk menampilkan semua node keturunan.
6. **Fungsi `main()`:**
   - Membuat menu interaktif untuk pengguna:
     - Opsi 1: Menambahkan node baru.
     - Opsi 2: Menampilkan anak dari node tertentu.
     - Opsi 3: Menampilkan keturunan dari node tertentu.
     - Opsi 4: Keluar dari program.
   - Terus meminta pilihan dari pengguna sampai pengguna memilih untuk keluar.

### Output
![image](https://github.com/AFaiqatuzzahra/Praktikum-Algoritma-Pemrograman-dan-Struktur-Data/assets/152428747/51f7b24f-aad6-4474-b95c-01678bff487a)
Kesimpulan dari output contoh interaksi yang diberikan adalah:
1. **Program berhasil menambahkan node baru ke dalam tree:** Pengguna berhasil menambahkan node dengan data "A", "B", dan "C".
2. **Program berhasil menampilkan child dari suatu node:** Ketika pengguna meminta untuk menampilkan child dari node "A", program dengan benar menampilkan "B C", yang menunjukkan bahwa B dan C adalah anak dari node A.
3. **Program berhasil menampilkan descendant dari suatu node:** Ketika pengguna meminta untuk menampilkan descendant dari node "A", program menampilkan "B C", yang menunjukkan bahwa B dan C adalah keturunan dari node A.
4. **Node tidak ditemukan ditangani dengan baik:** Ketika pengguna mencoba menampilkan child dari node "15" yang tidak ada dalam tree, program dengan benar menampilkan pesan "Child dari node 15:". Hal yang sama terjadi ketika pengguna mencoba menampilkan descendant dari node "15".
5. **Penanganan input yang salah:** Ketika pengguna memasukkan opsi yang tidak valid (misalnya, angka 5), program memberikan pesan "Opsi tidak valid. Silakan coba lagi."
Secara keseluruhan, contoh interaksi ini menunjukkan bahwa program berfungsi dengan baik dalam menambahkan node, menampilkan child dan descendant, serta menangani input yang salah dan node yang tidak ditemukan.

### Full Screenshoot
![image](https://github.com/AFaiqatuzzahra/Praktikum-Algoritma-Pemrograman-dan-Struktur-Data/assets/152428747/51f7b24f-aad6-4474-b95c-01678bff487a)

[1]. A. Drozdek, Data Structures and Algorithms in C++. Cengage Learning, 2012.
[2]. W. Anggoro, C++ Data Structures and Algorithms : Learn how to write efficient code to build scalable and robust applications in C++. Birmingham: Packt Publishing, 2018.
‌[3]. D. S. Malik, Data Structures Using C++. South Western Educational Publishing, 2010.
[4]. T. Cormen, C. Leiserson, R. Rivest, and C. Stein, Introduction to Algorithms, Third. Cambridge, Mass.: Mit Press, 2009.
‌
‌
