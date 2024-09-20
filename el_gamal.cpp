#include"crypto.h"

// creating h
ZZ_p cryptoAlgo::createH(ZZ_p generator){
    return power(generator,this->private_key);
}

// el gamal decryption
ZZ_p cryptoAlgo::el_gamal_decryption(gamal_enc_msg enc){
    return inv(power(enc.c1,this->private_key)) * enc.c2;
}

// el gamal encryption
gamal_enc_msg cryptoAlgo::el_gamal_encryption(ZZ prime,ZZ_p generator,ZZ_p h, ZZ_p message){
    ZZ_p::init(prime); 
    ZZ y;
    gamal_enc_msg enc;
    ZZ randomNum = RandomBnd(prime);

    enc.c1 = power(generator,randomNum);
    enc.c2 = power(h,randomNum);
    enc.c2 = enc.c2 * message;

    return enc;
}

