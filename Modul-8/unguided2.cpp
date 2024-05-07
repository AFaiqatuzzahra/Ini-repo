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
