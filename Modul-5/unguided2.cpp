#include <iostream>
using namespace std;

// Mendefinisikan struktur film
struct film {
    string judulfilm;
    string produser;
    string bioskop;
    int durasi;
    int hargatiket;
};

int main() {
    // Mendeklarasikan array film dengan panjang 3
    film favorit[3];

    // Mengisi data ke dalam array film
    favorit[0] = {"Terbulan dibenam malam", "Latulipa", "CGV", 120, 120000};
    favorit[1] = {"The Godfather", "Francis Ford ", "XXI", 175, 150000};
    favorit[2] = {"Inception", "Christopher Nolan", "Cinepolis", 148, 130000};

    // Menampilkan informasi film-film favorit
    cout << "\tRekomendasi film " << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "\tFilm ke-" << i + 1 << endl;
        cout << "\tJudul film  : " << favorit[i].judulfilm << endl;
        cout << "\tProduser    : " << favorit[i].produser << endl;
        cout << "\tBioskop     : " << favorit[i].bioskop << endl;
        cout << "\tDurasi      : " << favorit[i].durasi << " menit " << endl;
        cout << "\tHarga tiket : Rp " << favorit[i].hargatiket << endl;
        cout << endl;
    }

    return 0;
}
