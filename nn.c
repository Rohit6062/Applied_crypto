#include<stdio.h>
#include<stdlib.h>

long log_2(long x){
    long output=0;
    while(x)output++,x=x>>1;
    return output;
}
int main(){
    printf("log_2(100) = %ld\n", log_2(999999999999999999));
    
    return 0;
}
