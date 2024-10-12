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

typedef gamal_enc_msg elp_pnt;
typedef unsigned int ui;

class cryptoAlgo{
    private:
    ZZ private_key ;//= RandomBnd(ZZ(1000001));
    ZZ prime;
    ZZ_p generator;
    ZZ_p h;
    public:
    cryptoAlgo(ZZ Optimus_prime){
        this->prime = Optimus_prime;
        this->private_key = RandomBnd(Optimus_prime);
        ZZ_p::init(this->prime);
        conv(this->generator,RandomBnd(Optimus_prime));
        this->h = this->createH();
        cout<<"\tPrime\tGenerator\tH\n\t"<<this->prime<<"\t"<<this->generator<<"\t"<<this->h<<endl;
    }

    ZZ dlp(ZZ_p);
    void diff_hell(ZZ a,ZZ b);
    gamal_enc_msg el_gamal_encryption(ZZ_p message);
    ZZ_p el_gamal_decryption(gamal_enc_msg enc); 
    ZZ_p createH();
};

class elliptic_curve{
private:
    ZZ prime;
    ZZ_p a;
    ZZ_p b; 
    ZZ_p A;
    public: 
    elliptic_curve(ZZ Optimus_prime, ZZ_p a,ZZ_p b){
        this->prime = Optimus_prime;
        ZZ_p::init(Optimus_prime);
        this->a = a;
        this->b = b;
    }
    elp_pnt* points_on_curv(ui);
    bool is_valid(ZZ_p x);
    elp_pnt ellp_add(elp_pnt a,elp_pnt b);
    elp_pnt ellp_doubling(elp_pnt a);
};
