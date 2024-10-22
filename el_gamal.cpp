#include"crypto.h"
// creating h
ZZ_p cryptoAlgo::createH(){
    return power(this->generator,this->private_key);
}

// el gamal decryption
ZZ_p cryptoAlgo::el_gamal_decryption(gamal_enc_msg enc){
    return inv(power(enc.c1,this->private_key)) * enc.c2;
}

// el gamal encryption
gamal_enc_msg cryptoAlgo::el_gamal_encryption(ZZ_p message){
    ZZ y;
    gamal_enc_msg enc;
    ZZ randomNum = RandomBnd(this->prime);

    enc.c1 = power(this->generator,randomNum);
    enc.c2 = power(this->h,randomNum);
    enc.c2 = enc.c2 * message;
    return enc;
}

encrypted_text elliptic_curve::el_gamal_on_elp_curv_encryption(elp_pnt P,elp_pnt message){
    ZZ y = RandomBnd(this->prime); 
    encrypted_text enc;
    this->Q = this->ellp_scalar_mul(this->private_key,P);
    enc.c1 = this->ellp_scalar_mul(y,P);
    enc.c2 = this->ellp_add(message,this->ellp_scalar_mul(y,this->Q)); 
    return enc;
}

elp_pnt elliptic_curve::el_gamal_on_elp_curv_decryption(encrypted_text enc){
    elp_pnt message;
    elp_pnt unk = this->ellp_scalar_mul(this->private_key,enc.c1);
    unk.c2 = -unk.c2;
    return this->ellp_add(enc.c2,unk);
}

