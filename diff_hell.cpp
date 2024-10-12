#include"crypto.h"

void cryptoAlgo::diff_hell(ZZ a,ZZ b){
    ZZ_p A,B;
    A = power(this->generator,a);
    B = power(this->generator,b);
    cout << "alice's key : "<<power(B,a)<<endl;
    cout << "bob's key   :   " << power(A,b)<<endl;
    return;
}

