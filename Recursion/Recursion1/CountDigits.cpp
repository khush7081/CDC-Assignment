  #include<iostream>
  using namespace std;
  int f( int x, int n){
        if( x == 0) return 0;
        int digits = 0;
        int r = x % 10;
        if( r == 0) return f(x/10, n);
        if( n % r == 0) digits = 1 + f(x/10, n);
        else digits = 0 + f(x/10, n);
        return digits;
    }
    
    int evenlyDivides(int n) {
        
        return f(n,n);
        
    }