#include <iostream>
using namespace std ;
main()
{
    char op;
    float num1, num2;
    cout << "masukkan operator:";
    cin >> op ;
    cout << "masukkan angka 1 & 2";
    cin >>  num1 >> num2;
    switch(op)
    {
    case '+':
        cout << num1 + num2;
        break;
    case '-':
        cout << num1 - num2;
        break;
    default:
        cout << "Error! operator is not correct";
    }
    return 0;
}