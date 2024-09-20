#include"crypto.h"
void cryptoAlgo::diff_hell(ZZ p,ZZ_p g,ZZ a,ZZ b){
    ZZ_p A,B;
    p = conv<ZZ>(p);
    ZZ_p::init(p);
    A = power(g,a);
    B = power(g,b);
    cout << "alice's key : "<<power(B,a)<<endl;
    cout << "bob's key : " << power(A,b)<<endl;
    return;
}
