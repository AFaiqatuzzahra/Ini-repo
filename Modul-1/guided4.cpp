#include <iostream>
#include <map>
#include <string>

int main() {
    // Membuat map untuk menyimpan nama dan umur
    std::map<std::string, int> ageMap;

    // Menambahkan beberapa entri ke dalam map
    ageMap["John"] = 30;
    ageMap["Alice"] = 25;
    ageMap["Bob"] = 35;

    // Menampilkan umur seseorang
    std::cout << "Umur John: " << ageMap["John"] << std::endl;
    std::cout << "Umur Alice: " << ageMap["Alice"] << std::endl;

    // Mengubah umur seseorang
    ageMap["John"] = 40;

    // Menampilkan umur setelah diubah
    std::cout << "Umur John setelah diubah: " << ageMap["John"] << std::endl;

    return 0;
}

