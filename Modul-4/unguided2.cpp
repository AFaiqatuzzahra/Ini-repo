#include <iostream>
#include <string>

using namespace std;

int countVowels(string kalimat) {
  int count = 0;
  for (char c : kalimat) {
    switch (tolower(c)) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
        count++;
        break;
    }
  }
  return count;
}

int main() {
  string kalimat;

  cout << "Masukkan kalimat: ";
  getline(cin, kalimat);

  int vowelCount = countVowels(kalimat);

  cout << "Jumlah huruf vokal dalam kalimat: " << vowelCount << endl;

  return 0;
}
