# <h1 align="center">Laporan Praktikum Modul Array</h1>
<p align="center">Afifah Faiqatuzzahra</p>

## Dasar Teori
**Struktur Data Array**
Array adalah struktur data fundamental yang digunakan untuk menyimpan kumpulan data dengan tipe yang sama. 
Array dapat dianalogikan sebagai rak penyimpanan yang memiliki kotak-kotak untuk menyimpan data.

**Jenis-Jenis Array:**
**1. Array Satu Dimensi:**
Array satu dimensi (1D) adalah tipe variabel yang terdiri dari kumpulan data dengan tipe sama yang disusun dalam satu baris. 
Setiap elemen dalam array 1D memiliki indeks (nomor) untuk mengaksesnya. Indeks dimulai dari 0 dan berakhir pada jumlah elemen dikurangi 1.
Contoh:
```c++
#include <iostream>
using namespace std;

int main() {
  int arr[5] = {9, 3, 5, 2, 1}; // deklarasi array
  cout << arr[1] << endl; // mencetak elemen ke-2 (indeks 1)
  cout << arr[4]; // mencetak elemen ke-5 (indeks 4)
}
```
Output:
```
3
1
```
**2. Array Dua Dimensi:**
Array dua dimensi (2D) adalah variabel yang terdiri dari kumpulan array 1D dengan tipe sama yang disusun dalam baris dan kolom.
Setiap elemen dalam array 2D memiliki dua indeks: indeks baris dan indeks kolom.
Contoh:
```c++
#include <iostream>
using namespace std;

int main() {
  int arr[2][2] = {{3, 2}, {2, 5}};
  for (int i = 0; i < 2; i++) { // perulangan baris
    for (int j = 0; j < 2; j++) { // perulangan kolom
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}
```
Output:

```
3 2
2 5
```
**3. Array Multidimensi:**
Array multidimensi memiliki kesamaan dengan array 1D dan 2D, namun memiliki kapasitas memori lebih besar. 
Array ini digunakan untuk merepresentasikan array dengan dimensi lebih dari dua, seperti array tiga dimensi (3D), empat dimensi (4D), dan seterusnya.
Contoh:
```c++
#include <iostream>
using namespace std;

int main() {
  int arr[2][2][3] = {{{2, 8, 7}, {6, 5, 1}}, {{8, 5, 2}, {9, 2, 7}}};
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 3; k++) {
        cout << arr[i][j][k] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }
}
```
Output:
```
2 8 7
6 5 1
8 5 2
9 2 7
```
**4. Array Empat Dimensi:**
Contoh deklarasi array 4D:
```c++
int arr[3][2][4][4];
```
**5. Array Lima Dimensi:**
Contoh deklarasi array 5D:
```c++
int arr[5][4][3][2][1];
```

## Guided 

### 1. Program Input Array 3 Dimensi

```C++
#include <iostream>
using namespace std;
//PROGRAM INPUT ARRAY 3 DIMENSI
int main()
{
     //Deklarasi array
     int arr[2][3][3];
     //Input elemen
    for (int x=0; x<2; x++)
     {
         for (int y = 0; y < 3; y++)
         {
             for (int y =0; y < 3; y++)
             { 
                 for ( int z = 0; z<3; z++)
                 {
                     cout<< "Input array" << x << "][" << y << "][" << z << "] =";
                     cin >> arr[x][y][z];
                 }
             }
        
         }
     }
    cout << endl;
 //Output Array
 for (int x = 0; x < 2; x++)
 {
     for(int y=0; y < 3; y++)
     {
         for(int z = 0; z <3; z++)
         {
             cout << "Data Array" << x << "][" << y << "][" << z << "]=" << arr[x][y][z] << endl;
         }
     }
 }
  cout << endl;
 //Tampilan Array
 for (int x = 0; x < 2; x++)
 {
    for (int y =0; y < 3; y++)
    {
        for(int z = 0; z < 3; z++)
        {
            cout << arr[x][y][z] << ends;
        }
        cout << endl;
    }
    cout << endl;
 }
}
```
Kode di atas digunakan untuk  membantu mengilustrasikan bagaimana cara menggunakan 
array 3 dimensi dalam C++ untuk input, output, dan menampilkan nilai-nilai yang disimpan di dalamnya.

### 2. Program Mencari Nilai Maksimal pada Array
```C++
#include <iostream>
using namespace std;
int main()
{
    int maks, a, i = 1, lokasi = 0;
    //masukkan data
    cout << "Masukkan panjang array:";
    cin >> a;
    int *array = new int[a];
    cout << "Masukkan " << a << " angka\n";
    for (i=0; i < a; i++)
    {
        cout << "Array ke-" << (i) << ": ";
        cin >> array[i];
    }
    maks = array[0];
    for (i = 0; i < a; i++)
    {
        if(array[i]> maks)
        {
            maks = array[i];
            lokasi = i;
        }
    }
    cout << "Nilai maksimum adalah " << maks << " berada di Array ke " << lokasi << endl;
}
```
Kode diatas digunakan untuk menemukan nilai maksimum dari sebuah array yang diinputkan oleh pengguna,
dan menampilkan nilai mmaksimum beserta indeksnya.

## Unguided 

### 1. Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user!
Data Array: 1 2 3 4 5 6 7 8 9 10
Nomor Genap : 2, 3, 6, 8, 10,
Nomor Ganjil: 1, 3, 5, 7, 9,

```C++
#include <iostream>
using namespace std;

int main() {
  int data[10]; // Array untuk menyimpan 10 data
  
  // Input data dari user
  cout << "Masukkan 10 data: ";
  for (int i = 0; i < 10; i++) {
    cin >> data[i];
  }

  // Menampilkan data array
  cout << "Data Array: ";
  for (int i = 0; i < 10; i++) {
    cout << data[i] << " ";
  }
  cout << endl;

  // Menampilkan nomor genap
  cout << "Nomor Genap: ";
  for (int i = 0; i < 10; i++) {
    if (data[i] % 2 == 0) {
      cout << data[i] << " ";
    }
  }
  cout << endl;

  // Menampilkan nomor ganjil
  cout << "Nomor Ganjil: ";
  for (int i = 0; i < 10; i++) {
    if (data[i] % 2 == 1) {
      cout << data[i] << " ";
    }
  }
  cout << endl;

  return 0;
}
```
#### Output:
![10 data](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/10b8553f-6757-4bd9-a286-2686427b0bfe)

Kode di atas digunakan untuk mengetahui data nomor genap dan nomor ganjil dari data array yang diinputkan.

#### Full code Screenshot:
![Screenshot (41)](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/b61d1c76-ef91-46e8-8aca-493feeef9519)

#### 2. Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!
```C++
#include <iostream>
using namespace std;

int main() {
  int x, y, z;

  // Input dimensi array
  cout << "Masukkan jumlah layer: ";
  cin >> x;
  cout << "Masukkan jumlah baris per layer: ";
  cin >> y;
  cout << "Masukkan jumlah kolom per baris: ";
  cin >> z;

  // Deklarasi array 3 dimensi dengan ukuran dari user
  int arr[x][y][z];

  // Input elemen array
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      for (int k = 0; k < z; k++) {
        cout << "Input array[" << i << "][" << j << "][" << k << "] = ";
        cin >> arr[i][j][k];
      }
    }
  }

  // Output array
  cout << endl;
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      for (int k = 0; k < z; k++) {
        cout << arr[i][j][k] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }

  return 0;
}
```
#### Output:
![Screenshot (42)o](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/b06b002d-6645-4f0b-88c1-a13a7aeb7f2e)

Kode di atas digunakan untuk berbagai keperluan yang membutuhkan penyimpanan data dalam struktur 3 dimensi.

#### Full code Screenshot:
![Screenshot (42)](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/044aba42-00c7-430e-9649-4cf413775b3d)

#### 3. Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user!
```C++
#include <iostream>
using namespace std;

int main() {
  int n;

  // Input jumlah elemen array
  cout << "Masukkan jumlah elemen array: ";
  cin >> n;

  // Deklarasi array
  int arr[n];

  // Input elemen array
  for (int i = 0; i < n; i++) {
    cout << "Masukkan elemen array[" << i << "] = ";
    cin >> arr[i];
  }

  // Mencari nilai maksimum
  int max = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }

  // Mencari nilai minimum
  int min = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] < min) {
      min = arr[i];
    }
  }

  // Menghitung nilai rata-rata
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }
  float average = (float)sum / n;

  // Menampilkan hasil
  cout << endl;
  cout << "Nilai maksimum: " << max << endl;
  cout << "Nilai minimum: " << min << endl;
  cout << "Nilai rata-rata: " << average << endl;

  return 0;
}

```
#### Output:
![Screenshot (46)o](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/03a9dadc-5d28-49c7-adfa-41707256c735)

Kode di atas digunakan untuk mengetahui nilai maksimum, minimum, dan rata-rata dari data yang diinputkan tanpa repot 
untuk mencari satu persatu dari data tersebut.

#### Full code Screenshot:
![Screenshot (46)](https://github.com/AFaiqatuzzahra/Ini-repo/assets/152428747/b4e9e3aa-c026-488f-a114-7c648dbfaab3)

## Kesimpulan
Kesimpulan laporan modul kali ini adalah, kita dapat mempelajari bahwa array merupakan struktur data penting untuk menyimpan
dan mengolah data. Memahami konsep array dan penggunaannya merupakan langkah awal yang penting dalam mempelajari
struktur data dan algoritma.

## Referensi
[1]S. I. Awad and J. T. Yen, “3D Strain Imaging Using a Rectilinear 2D Array,” Ultrasonic Imaging, vol. 29, no. 4, pp. 220–230, Oct. 2007, doi: https://doi.org/10.1177/016173460702900403.
[‌2]M. R. Abu Sara, M. F. J. Klaib, and M. Hasan, “Hybrid Array List: An Efficient Dynamic Array with Linked List Structure”, IndoJC, vol. 5, no. 3, pp. 47-62, Jan. 2021.
