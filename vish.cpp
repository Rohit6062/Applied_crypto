#include<iostream>
#include"crypto.h"
int main(){
    cryptoAlgo a;
    string str="this is test string";
    ZZ p = conv<ZZ>("1000001");
    ZZ_p::init(p);
    ZZ_p g,h;//,msg;
    g=3;
    h = a.createH(g);
    long l;
    for(int i=0;i<str.size();i++)
        conv(l,a.el_gamal_decryption(a.el_gamal_encryption(p,g,h,to_ZZ_p(ZZ(str[i]))))),
        printf("%c",(char)l);
    cout<<endl;
    return 0;
}
