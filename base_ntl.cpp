#include"crypto.h"
ui ZZ_log2(ZZ_p z){
    ZZ x = rep(z);
    ui output = 0;
    while(x>0){
        output++;
        x = x >> 1;
    }
    return output;
}
