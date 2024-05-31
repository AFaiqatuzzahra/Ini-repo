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
        return nim % 10; // Contoh fungsi hash sederhana
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
