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
    // Mendeklarasikan variabel favorit dengan tipe film
    film favorit;

    // Mengisi data ke dalam variabel favorit
    favorit.judulfilm = "Terbulan dibenam malam";
    favorit.produser = "Latulipa";
    favorit.bioskop = "CGV";
    favorit.durasi = 120;
    favorit.hargatiket = 120000;

    // Menampilkan informasi film favorit
    cout << "\tRekomendasi film " << endl;
    cout << "\tJudul film  : " << favorit.judulfilm << endl;
    cout << "\tProduser    : " << favorit.produser<< endl;
    cout << "\tBioskop     : " << favorit.bioskop << endl;
    cout << "\tDurasi      : " << favorit.durasi << " menit " << endl;
    cout << "\tHarga tiket : Rp " << favorit.hargatiket << endl;
 
    return 0;
}