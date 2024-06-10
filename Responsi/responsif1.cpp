#include <iostream>

int main() {
    int data[] = {1, 2, 3, 4, 5, 5};
    int n = sizeof(data) / sizeof(data[0]);
    int cari = 5;

    std::cout << "Angka " << cari << " ditemukan pada indeks: ";
    for (int i = 0; i < n; ++i) {
        if (data[i] == cari) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
