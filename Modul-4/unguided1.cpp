#include <iostream>
#include <string>

using namespace std;

bool binarySearch(string kalimat, char target, int left, int right) {
  if (right < left) {
    return false;
  }

  int mid = left + (right - left) / 2;
  char midChar = kalimat[mid];

  if (midChar == target) {
    return true;
  } else if (midChar < target) {
    return binarySearch(kalimat, target, mid + 1, right);
  } else {
    return binarySearch(kalimat, target, left, mid - 1);
  }
}

int main() {
  string kalimat;
  char target;

  cout << "Masukkan kalimat: ";
  getline(cin, kalimat);

  cout << "Masukkan huruf yang ingin dicari: ";
  cin >> target;

  bool found = binarySearch(kalimat, target, 0, kalimat.length() - 1);

  if (found) {
    cout << "Huruf '" << target << "' ditemukan dalam kalimat." << endl;
  } else {
    cout << "Huruf '" << target << "' tidak ditemukan dalam kalimat." << endl;
  }

  return 0;
}
