#include <iostream>
#include <string>
#include <vector>

using namespace std;

void hitungJarakAntarKota() {
    int jumlahKota;
    cout << "Masukkan jumlah kota: ";
    cin >> jumlahKota;
    cin.ignore(); // Untuk mengabaikan karakter newline setelah input jumlahKota

    vector<string> namaKota(jumlahKota); // Vector untuk nama kota
    vector<vector<int>> jarak(jumlahKota, vector<int>(jumlahKota)); // Matriks jarak

    // Input nama kota
    for (int i = 0; i < jumlahKota; ++i) {
        cout << "Masukkan nama kota ke-" << i + 1 << ": ";
        getline(cin, namaKota[i]); // Menggunakan getline untuk membaca nama kota yang bisa mengandung spasi
    }

    // Input jarak antar kota
    cout << "\nMasukkan jarak antar kota (0 jika tidak ada jalur langsung):\n";
    for (int i = 0; i < jumlahKota; ++i) {
        for (int j = 0; j < jumlahKota; ++j) {
            if (i == j) {
                jarak[i][j] = 0; // Jarak ke kota sendiri adalah 0
            } else {
                cout << namaKota[i] << " --> " << namaKota[j] << " = ";
                cin >> jarak[i][j];
            }
        }
    }

    // Tampilkan matriks jarak
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

    // Contoh penggunaan: Mencari jarak dari kota awal ke kota tujuan
    string kotaAwal, kotaTujuan;
    cout << "\nMasukkan kota awal: ";
    cin.ignore(); // Untuk mengabaikan karakter newline setelah input jarak
    getline(cin, kotaAwal);
    cout << "Masukkan kota tujuan: ";
    getline(cin, kotaTujuan);

    // Cari indeks kota
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
    getline(cin, nama); // Membaca input nama yang bisa berisi spasi

    cout << "Masukkan NIM Anda: ";
    cin >> nim; // Membaca input NIM

    cout << "\nNama: " << nama << endl;
    cout << "NIM: " << nim << endl;

    hitungJarakAntarKota();
    return 0;
}
