#include"crypto.h"

ZZ_p cryptoAlgo::create_Random_coprime(ZZ x){
    // ZZ_p::init(x+1);
    ZZ tmp = RandomBnd(x);
    while(GCD(x,tmp)!=ZZ(1))tmp=RandomBnd(x);
    ZZ_p output;
    conv(output,tmp);
    return output;
}

bool cryptoAlgo::create_signature(ZZ prime,ZZ_p generator,ZZ m){
    ZZ_p::init(prime); 
    ZZ_p h = createH(generator);
    ZZ random_number = RandomBnd(prime);
    ZZ_p y = this.create_signature(prime-1);
} 
