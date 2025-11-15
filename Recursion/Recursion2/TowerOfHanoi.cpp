  #include<iostream>
  using namespace std;
  int toh( int n, int a, int b, int c ){
        if( n == 0) return 0;
        int count = 0;
        count += toh(n-1, a, c, b);
        count++;
        count += toh(n-1, b,a,c);
        return count;
    }
    int towerOfHanoi(int n, int from, int to, int aux) {
        return toh(n, from, aux, to);
        
        
    }