# <h1 align="center">Laporan Praktikum Modul Hash Tabel</h1>
<p align="center">Afifah Faiqatuzzahra</p>

## Dasar Teori


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

### Output


### Kesimpulan


### Full code screenshot



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


### Output


### Kesimpulan

### Full Screenshot


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

[1]. GeeksforGeeks, “Priority queue in C++,” GeeksforGeeks. Dec. 12, 2019. [Online]. Available: https://www.geeksforgeeks.org/videos/priority-queue-in-c/.
[2] D. W. Jjones, "Concurrent operations on priority queues," Commun. ACM, vol. 32, no. Jan. 1989, pp. 132-137, 1989. DOI https://doi.org/10.1145/63238.63249.
[3]. “Heap Data Structure,” GeeksforGeeks. https://www.geeksforgeeks.org/heap-data-structure/.
‌[4]. E. Q. a. Z. P. a. H. J. Vintila, "MESH: A Memory-Efficient Safe HEap for C/C++," Association for Computing Macinery, p. 10, 2021. https://doi.org/10.1145/3465481.3465760.
