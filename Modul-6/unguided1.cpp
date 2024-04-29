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
    cout << "Data telah ditambah" << endl;
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
    cout << "Data telah ditambah" << endl;
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
        cout << "Data telah ditambah" << endl;
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