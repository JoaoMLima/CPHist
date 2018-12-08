#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d\n", &n);
    printf("%d\n", n/2);
    if (n & 1) {printf("3"); n-=3;}
    else {printf("2"); n-=2;}
    while(n) {printf(" 2"); n-=2;} printf("\n");
 	return 0;
}