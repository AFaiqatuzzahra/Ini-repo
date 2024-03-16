#include <iostream>

using namespace std;

int main() {
  // Deklarasi variabel
  int panjang, lebar;
  float luas, keliling;

  // Memasukkan nilai panjang dan lebar
  cout << "Masukkan nilai panjang: ";
  cin >> panjang;
  cout << "Masukkan nilai lebar: ";
  cin >> lebar;

  // Menghitung luas dan keliling
  luas = panjang * lebar;
  keliling = 2 * (panjang + lebar);

  // Menampilkan hasil
  cout << "Luas persegi panjang: " << luas << endl;
  cout << "Keliling persegi panjang: " << keliling << endl;
  return 0;
}
