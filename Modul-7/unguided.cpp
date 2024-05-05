#include <iostream>
using namespace std;

char array[5 * 26]; 
int maksimal = 5 * 26, top = 0;

bool isFull() {
    return (top == maksimal);
}

bool isEmpty() {
    return (top == 0);
}

void pushArray(char data) {
    if (isFull()) {
        cout << "Data stack telah penuh" << endl;
    } else {
        array[top] = data;
        top++;
    }
}

void popArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        top--;
    }
}

bool isPalindrome(string sentence) {
    for (char c : sentence) {
        if (isalnum(c)) {
            processedSentence += tolower(c);
        }
    }

    for (char c : processedSentence) {
        pushArray(c);
    }

    int i = 0, j = top - 1;
    while (i <= j) {
        if (array[i] != array[j]) {
            return false;
        }
        i++;
        j--;
    }

    return true;
}

int main() {

    string sentence;
    cout << "Masukkan kalimat: ";
    getline(cin, sentence);

    if (isPalindrome(sentence)) {
        cout << sentence << " adalah palindrom" << endl;
    } else {
        cout << sentence << " bukan palindrom" << endl;
    }

    return 0;
}
