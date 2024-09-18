#include"crypto.h"
#include"dlp.cpp"
#include"diff_hell.cpp"
#include"el_gamal.cpp"
int main(){
    cryptoAlgo a;
    ZZ p = conv<ZZ>("101");
    ZZ_p::init(p);
    ZZ_p g,h;
    g=2;
    h=100001;
    // a.el_gamal2();

    cout<<a.dlp(p,g,h)<<endl;;
    return 0;
}
