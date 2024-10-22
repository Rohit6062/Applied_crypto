#include<iostream>
#include"crypto.h"
int main(){
    ZZ p = conv<ZZ>("11");
    ZZ_p::init(p);
    cryptoAlgo* a = new cryptoAlgo(p);
    gamal_enc_msg h = a->el_gamal_encryption(to_ZZ_p(5));//<<endl;

    elliptic_curve *k = new elliptic_curve(p,to_ZZ_p(1),to_ZZ_p(6));
    elp_pnt* j;
    ui n = 0;
    j = k->points_on_curv(n);
    if(!j)cout<<"points on curv not fount!\n",n=0;
    for(int l=0;l<n;l++){
        cout<<j[l].c1<<endl;
        cout<<j[l].c2<<endl;
        cout<<endl;
    }
    
    return 0;
}
