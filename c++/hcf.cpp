/*
Problem: Write a program to find HCF of two numbers
         by without using recursion.

Input: The first line contains any 2 positive numbers
         separated by space.

Output: Print the HCF of given two numbers.
*/

#include<iostream>

int gcd(int,int);

int main() {
    int m,n;
    scanf("%d",&m);
    scanf("%d",&n);
    while(m != n) {
        if(m > n) {
            m = m - n;
        } else {
            n = n - m;
        }
    }
    printf("%d", m);
    return 0;
}