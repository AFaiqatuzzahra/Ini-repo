#include <iostream>

using namespace std;

void bubble_sort(double arr [], int length){
    bool not_sorted = true;
    int j=0;
    double tmp;

    while (not_sorted){
        not_sorted = false;
        j++;
        for (int i = 0; i < length - j; i++){
            if (arr[i] > arr[i + 1]) {
                tmp = arr[i]; //
                arr[i] = arr [i + 1];
                arr[i + 1] = tmp; //
                not_sorted = true;
            }
        }
    }
}

void print_array(double a[], int length) { 
    for(int i=0; i<length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main() {
    int length = 5;
    double a[] = {3.8, 2.9, 3.3, 4.0, 2.4};

    cout << "IPS sebelum sorting:" << endl;
    print_array(a,length);

    bubble_sort(a, length);

    cout << "\nIPS setelah sorting:" << endl;
    print_array(a, length);
}
