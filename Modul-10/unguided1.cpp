#include <iostream>

using namespace std;

// Fungsi rekursif untuk menghitung faktorial
unsigned long long factorial(int n) {
    // Kasus dasar: faktorial dari 0 adalah 1
    if (n == 0) {
        return 1;
    } else {
        // Kasus rekursif: n! = n * (n-1)!
        return n * factorial(n - 1);
    }
}

int main() {
    int n;
    
    cout << "Masukkan bilangan bulat positif: ";
    cin >> n;

    // Memastikan input valid
    if (n < 0) {
        cout << "Input tidak valid. Masukkan bilangan bulat positif." << endl;
    } else {
        unsigned long long result = factorial(n);
        cout << "Faktorial dari " << n << " adalah: " << result << endl;
    }

    return 0;
}
