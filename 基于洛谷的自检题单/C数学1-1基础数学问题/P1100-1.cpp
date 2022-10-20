#include <bits/stdc++.h>
#include <limits.h>
using namespace std;


int main(){ 
    unsigned int x;
    short *x1, *x2;
    
    scanf("%u", &x);
    x1 = (short*)&x;
    x2 = (short*)&x + 1;

    swap(*x1, *x2);
    printf("%u\n", x);
    return 0;
}