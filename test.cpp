#include"vish.cpp" 
ZZ pw(ZZ a,ZZ b){
    ZZ output = conv<ZZ>("1");
    while(b>0){
        output=output*a;
        b=b-1;
    }
    return output;
}
int main(){
    ZZ a(10);
    ZZ b(11);
}
