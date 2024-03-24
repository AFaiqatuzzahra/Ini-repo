#include <iostream>
using namespace std;

int main() {
  int x, y, z;

  // Input dimensi array
  cout << "Masukkan jumlah layer: ";
  cin >> x;
  cout << "Masukkan jumlah baris per layer: ";
  cin >> y;
  cout << "Masukkan jumlah kolom per baris: ";
  cin >> z;

  // Deklarasi array 3 dimensi dengan ukuran dari user
  int arr[x][y][z];

  // Input elemen array
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      for (int k = 0; k < z; k++) {
        cout << "Input array[" << i << "][" << j << "][" << k << "] = ";
        cin >> arr[i][j][k];
      }
    }
  }

  // Output array
  cout << endl;
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      for (int k = 0; k < z; k++) {
        cout << arr[i][j][k] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }

  return 0;
}
