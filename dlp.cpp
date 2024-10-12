#include"crypto.h"
ZZ cryptoAlgo::dlp(ZZ_p k){
    ZZ_p pow;
    ZZ i;
    i= 0;  
    for(i; i < this->prime ; i++){
        pow = power(this->generator,i);
        if(pow == k)return i;
    }
    return ZZ(-1);
}
