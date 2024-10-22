#include<iostream>
#include"crypto.h"
int main(){
    ZZ p = conv<ZZ>("11");
    ZZ_p::init(p);
    cryptoAlgo* a = new cryptoAlgo(p);
    gamal_enc_msg h = a->el_gamal_encryption(to_ZZ_p(5));//<<endl;

    elliptic_curve *k = new elliptic_curve(p,to_ZZ_p(1),to_ZZ_p(6));
    elp_pnt* j;
    ui n = 6;
    j = k->points_on_curv(n);
    if(!j)cout<<"points on curv not fount!\n",n=0;
    for(int l=0;l<n;l++){
        cout<<j[l].c1<<endl;
        cout<<j[l].c2<<endl;
        cout<<endl;
    }
    //1, 3 
    encrypted_text tmop = k->el_gamal_on_elp_curv_encryption(j[1],j[3]);  
    cout << "rmop "<<tmop.c1.c1<<" "<<tmop.c1.c2<<endl;
    cout << "rmop "<<tmop.c2.c1<<" "<<tmop.c2.c2<<endl;
    gamal_enc_msg kkkk = k->el_gamal_on_elp_curv_decryption(tmop);
    cout << "rkkkkkkkkk "<<kkkk.c1<<" "<<kkkk.c2<<endl;

    return 0;
}
