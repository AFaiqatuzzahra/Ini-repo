#include <iostream>

using namespace std;

int main() {
  // Data yang diberikan
  int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
  int n = sizeof(data) / sizeof(data[0]); // Ukuran data

  // Inisialisasi variabel untuk menghitung jumlah angka 4
  int count = 0;

  // Algoritma Sequential Search
  for (int i = 0; i < n; i++) {
    if (data[i] == 4) {
      count++; // Hitung setiap kali angka 4 ditemukan
    }
  }

  // Tampilkan jumlah angka 4
  cout << "Jumlah angka 4 dalam data: " << count << endl;

  return 0;
}
