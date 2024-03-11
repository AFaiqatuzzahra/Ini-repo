#include <stdio.h>

struct Person {
    char name[50];
    int age;
};

int main() {
    // Mendeklarasikan dan menginisialisasi variabel dari struct Person
    struct Person person1 = {"John", 30};

    // Mengakses dan mencetak nilai variabel dari struct
    printf("Name: %s\n", person1.name);
    printf("Age: %d\n", person1.age);

    return 0;
}

