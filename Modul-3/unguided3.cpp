#include <iostream>
using namespace std;

// Fungsi untuk melakukan insertion sort secara descending
void insertion_sort(char arr[], int length) {
    int i, j;
    char tmp;
    for (i = 1; i < length; i++) {
        j = i;
        while (j > 0 && arr[j - 1] < arr[j]) {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        }
    }
}

// Fungsi untuk mencetak isi array
void print_array(char a[], int length) {
    for(int i = 0; i < length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Masukkan jumlah karakter (n): ";
    cin >> n;

    char a[n];
    cout << "Masukkan " << n << " karakter: ";
    for(int i = 0; i < n; i++) { 
        cin >> a[i];
    }

    cout << "Urutan karakter sebelum sorting: " << endl;
    print_array(a, n);

    insertion_sort(a, n);

    cout << "\nUrutan karakter setelah sorting: " << endl;
    print_array(a, n);

    return 0;
}
