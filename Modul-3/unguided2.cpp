#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bubbleSort(vector<string> &names) {
    int n = names.size();
    for (int i = 0; i < n-1; i++) { 
        for (int j = 0; j < n-i-1; j++) { 
            if (names[j] > names[j+1]) {
                swap(names[j], names[j+1]); 
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

    bubbleSort(names); 

    cout << "\nSetelah diurutkan:" << endl;
    for (const auto &name : names) {
        cout << name << " ";
    }
    cout << endl; 

    return 0; 
}
