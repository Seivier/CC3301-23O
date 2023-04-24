#include <stdio.h>
#include<stdlib.h>

 int bits(int n);

 int main(int argc, char*argv[]){
     int test=atoi(argv[1]);
     printf("%x tinen %d bits en 1\n", test, bits(test));
 }

 int bits(int n){
     int mask = 0x1;
     int cnt=0;
     for(int i=0;i<sizeof(n)*8;i++){
        if(n&mask){
            cnt++;
        }
     }
     return cnt;
 }