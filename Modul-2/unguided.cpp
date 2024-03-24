#include <iostream>
using namespace std;

int main() {
  int data[10]; // Array untuk menyimpan 10 data
  
  // Input data dari user
  cout << "Masukkan 10 data: ";
  for (int i = 0; i < 10; i++) {
    cin >> data[i];
  }

  // Menampilkan data array
  cout << "Data Array: ";
  for (int i = 0; i < 10; i++) {
    cout << data[i] << " ";
  }
  cout << endl;

  // Menampilkan nomor genap
  cout << "Nomor Genap: ";
  for (int i = 0; i < 10; i++) {
    if (data[i] % 2 == 0) {
      cout << data[i] << " ";
    }
  }
  cout << endl;

  // Menampilkan nomor ganjil
  cout << "Nomor Ganjil: ";
  for (int i = 0; i < 10; i++) {
    if (data[i] % 2 == 1) {
      cout << data[i] << " ";
    }
  }
  cout << endl;

  return 0;
}
