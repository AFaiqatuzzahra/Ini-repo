#include <iostream>

using namespace std;

unsigned long long factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int n;
    
    cout << "Masukkan bilangan bulat: ";
    cin >> n;

    if (n < 0) {
        cout << "Input tidak valid. Masukkan bilangan bulat positif." << endl;
    } else {
        unsigned long long result = factorial(n);
        cout << "Faktorial dari " << n << " adalah: " << result << endl;
    }
    return 0;
}
