/*
    Determine the output
*/

#include <iostream>

using namespace std;

void q1() {
    int a = 5, b = 10, c = 15;
    int *arr[] = {&a, &b, &c};
    cout << arr[1];
}

void q2() {
    char arr[20];
    int i;
    for(i = 0; i < 10; i++) {
        *(arr + i) = 65 + i;
    } 
    *(arr + i) = 0;
    cout << arr;
}

void q3() {
    char*ptr;
    char str[] = "abcdefg";
    ptr = str;
    ptr += 5;
    cout << ptr;
}

int main() {
    // q1();
    // q2();
    q3();
    
    return 0;
}