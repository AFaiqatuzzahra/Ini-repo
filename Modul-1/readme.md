# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Afifah Faiqatuzzahra</p>

## Dasar Teori
Tipe data adalah cara untuk mengelompokkan dan mengklasifikasikan data berdasarkan sifat dan karakteristiknya. Pengklasifikasian ini penting agar kompiler atau program komputer dapat memahami bagaimana data akan digunakan dan diperlakukan. Terdapat beberapa jenis tipe data yang umum dipelajari, yaitu:
1. Tipe data Primitif: Merupakan tipe data dasar yang tersedia dalam bahasa pemrograman dan biasanya langsung didukung oleh perangkat keras komputer. Contohnya, seperti integer, float, karakter, dan boolean.
2. Tipe data Abstrak: Merupakan tipe data yang tidak secara langsung diimplementasikan dalam bahasa pemrograman, tetapi biasanya didefinisikan oleh pengguna atau menggunakan struktur data yang kompleks. Contoh tipe data abstrak termasuk tipe data seperti queue, stack, tree, dan graph.
3. Tipe data Koleksi: Merupakan tipe data yang memungkinkan untuk menyimpan beberapa nilai dalam satu variabel. Tipe data koleksi ini bisa berupa array, list, set, map, dan lain sebagainya. Tipe data koleksi memungkinkan untuk mengelola kumpulan data dengan lebih efisien.

## Guided 

### 1. Tipe Data Primitif

```C++
using namespace std ;
//main program
main()
{
    char op;
    float num1, num2;
    //It allows user to enter operator i.e. +, -, *, /
    cout << "masukkan opeartor:";
    cin >> op ;
    //It allows user to enter operands
    cout << "masukkan angka 1 & 2";
    cin >>  num1 >> num2;
    //Switch statement begins
    switch(op)
    {
    // If user enter +
    case '+':
        cout << num1 + num2;
        break;
    // If user enter -
    case '-':
        cout << num1 - num2;
        break;
    // If user enter *
    case '*':
        cout << num1 * num2;
        break;
    // If user enter /
    case '/':
        cout << num1/num2;
        break;
    // If the operator is other than +, -, *, /,
    //error message will display
    default:
        cout << "Error! operator is not correct";
    }// Switch statement ends
    return 0;
}

```
Kode di atas digunakan untuk sebuah kalkulator sederhana yang meminta pengguna memasukkan operator (+, -, *, atau /) dan dua bilangan. 

### 2. Tipe Data Abstrak
```C++
#include <stdio.h>

//Struct
struct Mahasiswa
{
    const char *name;
    const char *address;
    int age;
};

int main()
{
    //menggunakan struct
    struct Mahasiswa mhs1, mhs2;
    // mengisi nilai ke struct
    mhs1.name = "Dian";
    mhs1.address = "Mataram";
    mhs1.age = 22;
    mhs2.name = "Bambang";
    mhs2.address = "Surabaya";
    mhs2.age = 23;
    
    // mencetak isi struct
    printf("## Mahasiswa 1 ##\n");
    printf("Nama: %s\n", mhs1.name);
    printf("Alamat: %s\n", mhs1.address);
    printf("Umur: %d\n", mhs1.age);
    printf("## Mahasiswa 2 ##\n");
    printf("Nama: %s\n", mhs2.name);
    printf("Alamat: %s\n", mhs2.address);
    printf("Umur: %d\n", mhs2.age);
    return 0;   
}
```
Kode di atas merupakan contoh penggunaan struct untuk merepresentasikan informasi tentang mahasiswa.
Kode ini akan menampilkan informasi dua mahasiswa, yaitu mhs1 dan mhs2, yang telah diisi sebelumnya.

### 3. Tipe Data Koleksi
```C++
#include <iostream>
using namespace std;
int main()
{
    //deklarasi dan inisialisasi array
    int nilai[5];
    nilai[0] = 23;
    nilai[1] = 50;
    nilai[2] = 34;
    nilai[3] = 78;
    nilai[4] = 90;
    
    //mencetak array
    cout << "Isi array pertama :" << nilai[0] << endl;
    cout << "Isi array kedua :" << nilai[1] << endl;
    cout << "Isi array ketiga :" << nilai[2] << endl;
    cout << "Isi array keempat :" << nilai[3] << endl;
    cout << "Isi array kelima :" << nilai[4] << endl;
    return 0;
}
```
Kode di atas mendemonstrasikan cara mendeklarasikan, menginisialisasi, dan mencetak isi array
## Unguided 

### 1. Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!

```C++
#include <iostream>

using namespace std;

int main() {
  // Deklarasi variabel
  int panjang, lebar;
  float luas, keliling;

  // Memasukkan nilai panjang dan lebar
  cout << "Masukkan nilai panjang: ";
  cin >> panjang;
  cout << "Masukkan nilai lebar: ";
  cin >> lebar;

  // Menghitung luas dan keliling
  luas = panjang * lebar;
  keliling = 2 * (panjang + lebar);

  // Menampilkan hasil
  cout << "Luas persegi panjang: " << luas << endl;
  cout << "Keliling persegi panjang: " << keliling << endl;

  return 0;
}
```
kode diatas digunakan untuk menghitung luas dan keliling persegi panjang berdasarkan nilai panjang dan lebar yang dimasukkan oleh pengguna. Hasil perhitungan kemudian ditampilkan ke layar

#### Output:
![Screenshot (27)](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/f4a6d1dd-c183-4c43-aa1d-0f3dc6e29da5)


#### Full code Screenshot:
![Screenshot (28)](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/098bb294-b923-44b9-b044-40f843acb67c)

### 2. Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya
Class dan struct adalah dua struktur bahasa pemrograman C++ yang digunakan untuk mendefinisikan tipe data baru. Keduanya memungkinkan Anda untuk mengelompokkan data dan fungsi terkait bersama-sama, dan membuat objek dari tipe data tersebut.
Class adalah  blue print atau serangkaian instruksi untuk membangun jenis objek tertentu. Ini adalah konsep dasar Pemrograman Berorientasi Objek yang berkisar pada entitas kehidupan nyata. Kelas di a bahasa pemrograman menentukan bagaimana suatu objek akan berperilaku dan apa isi objek tersebut.
structure adalah  tipe data yang ditentukan pengguna yang menggabungkan item data yang terkait secara logis dari tipe data berbeda seperti float, char, int, dll., secara bersamaan.
```C++
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
```
Kode ini menunjukkan cara membuat class dengan anggota data, constructor, dan method. Class untuk mengelompokkan data dan fungsionalitas terkait, dan membuat objek dengan data dan perilaku yang spesifik.
### Output:
![Screenshot (29)](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/d88cd53b-c546-44d8-88fe-2b80725cc59d)

### Full code screenshot:
![Screenshot (30)](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/b3d627f8-eb0d-48c9-b026-8d18f9d7fcf2)

### 3. Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map.
Perbedaan Array dan Map adalah
Array
- Akses berdasarkan indeks
- Elemen dalam array memiliki urutan yang tetao sesuai dengan indeksnya
- Tipe data yang Homogen
Map
- Akses berdasarkan Key
- Elemen dalam map tidak memiliki urutan tetap
- Tipe data Heterogen
```C++

```


## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
