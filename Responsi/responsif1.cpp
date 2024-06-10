#include <iostream>

using namespace std;

int main() {
    int n = 6;
    int data[n] = {1, 2, 3, 4, 5, 5};
    int cari = 5;
    int ketemu = false;
    int i;

    for (i = 0; i < n; i++) {
        if(data[i] == cari) {
            ketemu = true;
            break;
        }
    }
        cout << " Program Sequential Search " << endl;
        cout << " data: {1, 2, 3, 4, 5, 5}"<< endl;

    if (ketemu){
        cout << "\n angka "<< cari << " ditemukan pada indeks ke-" << i << endl;
    } else {
        cout << cari << " tidak dapat ditemukan pada data." << endl;
    }
    return 0;
}