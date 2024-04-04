#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//menerima sebuah vector yang berisi string yang akan diurutkan
void bubbleSort(vector<string> &names) {
    int n = names.size();
    for (int i = 0; i < n-1; i++) { //melintasi setiap elemen faktor
        for (int j = 0; j < n-i-1; j++) { //membandingkan dan menukar apabila tidak ssesuai
            if (names[j] > names[j+1]) {
                swap(names[j], names[j+1]); //menukar elemen
            }
        }
    }
}


int main() {
    vector<string> names = {"siti", "situ", "sana", "ana", 
    "ani", "caca", "cici", "dida", "dodo", "dadi"};

    cout << "Sebelum diurutkan:" << endl;
    for (const auto &name : names) {
        cout << name << " ";
    }
    cout << endl;

    bubbleSort(names); //mengurutkan nama-nama dalam vektor

    cout << "\nSetelah diurutkan:" << endl;
    for (const auto &name : names) {
        cout << name << " ";
    }
    cout << endl; 

    return 0; //apabila tidak ada kesalahan program
}
