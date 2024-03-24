#include <iostream>
using namespace std;

int main() {
  int n;

  // Input jumlah elemen array
  cout << "Masukkan jumlah elemen array: ";
  cin >> n;

  // Deklarasi array
  int arr[n];

  // Input elemen array
  for (int i = 0; i < n; i++) {
    cout << "Masukkan elemen array[" << i << "] = ";
    cin >> arr[i];
  }

  // Mencari nilai maksimum
  int max = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }

  // Mencari nilai minimum
  int min = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] < min) {
      min = arr[i];
    }
  }

  // Menghitung nilai rata-rata
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }
  float average = (float)sum / n;

  // Menampilkan hasil
  cout << endl;
  cout << "Nilai maksimum: " << max << endl;
  cout << "Nilai minimum: " << min << endl;
  cout << "Nilai rata-rata: " << average << endl;

  return 0;
}
