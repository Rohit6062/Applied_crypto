#include<iostream>
#include<NTL/ZZ.h>
#include<NTL/ZZ_p.h>
#include<string>

using namespace std;
using namespace NTL;

struct gamal_enc_msg{
    ZZ_p c1;
    ZZ_p c2;
};

class cryptoAlgo{
    private:
    ZZ private_key = RandomBnd(ZZ(1000001));

    public:
    ZZ dlp(ZZ p,ZZ_p g, ZZ_p h);

    void diff_hell(ZZ p, ZZ_p g,ZZ a,ZZ b);

    gamal_enc_msg el_gamal_encryption(ZZ prime,ZZ_p generator,ZZ_p h,ZZ_p message);

    ZZ_p el_gamal_decryption(gamal_enc_msg enc); 

    ZZ_p createH(ZZ_p);
};
