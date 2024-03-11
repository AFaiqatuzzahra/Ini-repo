#include <iostream>
#include <string>

// Definisi class Person
class Person {
private: // Bagian private, hanya dapat diakses dari dalam class
    std::string name;
    int age;

public: // Bagian public, dapat diakses dari luar class
    // Constructor
    Person(std::string n, int a) {
        name = n;
        age = a;
    }

    // Method untuk menampilkan informasi
    void displayInfo() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
    }

    // Method untuk mengatur usia
    void setAge(int newAge) {
        age = newAge;
    }
};

int main() {
    // Membuat objek dari class Person
    Person person1("Afifah", 18);

    // Memanggil method untuk menampilkan informasi
    person1.displayInfo(); // Output: Name: Afifah, Age: 18

    // Mengatur usia baru
    person1.setAge(19);

    // Menampilkan informasi setelah mengatur usia
    person1.displayInfo(); // Output: Name: Afifah, Age: 19

    return 0;
}

