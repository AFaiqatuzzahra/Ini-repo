#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

string reverseWord(string word) {
    string reversedWord = "";
    // Memulai dari karakter terakhir dan menggabungkan setiap karakter ke string yang dibalik
    for (int i = word.length() - 1; i >= 0; i--) {
        reversedWord += word[i];
    }
    return reversedWord;
}

string reverseSentence(string sentence) {
    stack<string> words;
    stringstream ss(sentence);
    string word, reversedSentence;

    // Memisahkan kata-kata dalam kalimat menggunakan stringstream
    while (ss >> word) {
        words.push(reverseWord(word)); // Memasukkan kata yang sudah dibalik ke dalam stack
    }

    // Mengambil kata-kata dari tumpukan untuk membentuk kalimat yang terbalik
    while (!words.empty()) {
        reversedSentence += words.top() + " ";
        words.pop();
    }

    return reversedSentence;
}

int main() {
    string kalimat;

    cout << "Masukkan kalimat (minimal 3 kata): ";
    getline(cin, kalimat);

    // Mengecek apakah kalimat memiliki minimal 3 kata
    stringstream checkStream(kalimat);
    string temp;
    int countWords = 0;
    while (checkStream >> temp) {
        countWords++;
    }

    if (countWords >= 3) {
        string hasil_pembalikan = reverseSentence(kalimat);
        cout << "Kalimat asli: " << kalimat << endl;
        cout << "Hasil pembalikan: " << hasil_pembalikan << endl;
    } else {
        cout << "Mohon masukkan kalimat dengan minimal 3 kata." << endl;
    }

    return 0;
}
