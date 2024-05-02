#include <iostream>
using namespace std;

char array[5 * 26]; // Assuming maximum sentence length is 26 characters
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
    // Convert sentence to lowercase and remove non-alphanumeric characters
    string processedSentence;
    for (char c : sentence) {
        if (isalnum(c)) {
            processedSentence += tolower(c);
        }
    }

    // Push characters into the stack
    for (char c : processedSentence) {
        pushArray(c);
    }

    // Check if characters are the same when popped from both ends
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
    // ... (rest of the code remains the same)

    string sentence;
    cout << "Masukkan kalimat: ";
    getline(cin, sentence);

    if (isPalindrome(sentence)) {
        cout << sentence << " adalah palindrom" << endl;
    } else {
        cout << sentence << " bukan palindrom" << endl;
    }

    // ... (rest of the code remains the same)

    return 0;
}
