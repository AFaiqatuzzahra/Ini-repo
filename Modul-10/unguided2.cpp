#include <iostream>

using namespace std;

// Fungsi pembantu (helper): Dipanggil oleh factorial(), dan memanggil factorial() secara rekursif
int factorialHelper(int n, int result) {
    if (n == 0) {
        return result; // Kasus dasar: Jika n mencapai 0, kembalikan hasil akhir
    } else {
        return factorialHelper(n - 1, n * result); // Kasus rekursif: Panggil factorialHelper dengan n-1 dan hasil yang diperbarui
    }
}

// Fungsi utama untuk menghitung faktorial
int factorial(int n) {
    return factorialHelper(n, 1); // Memulai rekursi dengan nilai awal result = 1
}

int main() {
    int num;

    cout << "Masukkan bilangan bulat positif: ";
    cin >> num;

    // Memastikan input valid
    if (num < 0) {
        cout << "Input tidak valid. Masukkan bilangan bulat positif." << endl;
    } else {
        int result = factorial(num);
        cout << "Faktorial dari " << num << " adalah: " << result << endl;
    }

    return 0;
}
