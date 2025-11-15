#include<iostream>
using namespace std;
int power(int a, int b){
        if(a == 0 || b == 0) return 1;
        return a * power(a, b-1);
    }
    int reverse(int n){
        int rev = 0;
        while(n > 0){
            rev =rev * 10 + (n % 10);
            n /= 10;
        }
        return rev;
    }
    int reverseExponentiation(int n) {
        int b = reverse(n);
        return power(n, b);
        
    }