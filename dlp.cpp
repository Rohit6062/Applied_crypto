#include"crypto.h"
ZZ cryptoAlgo::dlp(ZZ p,ZZ_p g,ZZ_p h){
    ZZ_p::init(p);
    ZZ_p pow;
    ZZ x;
    x= 0;  
    for(x; x < p ; x++){
        pow = power(g,x);
        if(pow == h)return x;
    }
    return ZZ(-1);
}
