#include <iostream>
#include <map>
#include <string>

int main() {
    // Membuat map untuk menyimpan nama dan umur
    std::map<std::string, int> ageMap;

    // Menambahkan beberapa entri ke dalam map
    ageMap["John"] = 30;
    ageMap["Ali"] = 25;
    ageMap["Ben"] = 35;

    // Menampilkan umur seseorang
    std::cout << "Umur John: " << ageMap["John"] << std::endl;
    std::cout << "Umur Ali: " << ageMap["Ali"] << std::endl;

    // Mengubah umur seseorang
    ageMap["John"] = 40;

    // Menampilkan umur setelah diubah
    std::cout << "Umur John setelah diubah: " << ageMap["John"] << std::endl;

    return 0;
}

