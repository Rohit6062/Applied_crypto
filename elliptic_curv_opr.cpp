#include"crypto.h"
using namespace std;


bool elliptic_curve::is_valid(ZZ_p x){
    return power(x,(this->prime-1)/2)==1;
}

elp_pnt* elliptic_curve::points_on_curv(ui n){
    if(n%2!=0)n++;
    elp_pnt* output = (elp_pnt*) calloc(sizeof(elp_pnt),n);
    ui cnt;
    cnt=0;
    ZZ x;
    ZZ_p y;
    ZZ_p tmp;
    for(x=0;x<this->prime && cnt!=n;x++){ 
        y = power(to_ZZ_p(x),3)+ (this->a*to_ZZ_p(x)) + this->b;
        if(this->is_valid(y)){
            tmp = power(y,(this->prime+1)/4);
            cout<<"x => "<<x<<" "<<tmp<<endl;
            output[cnt].c1 = to_ZZ_p(x);
            output[cnt].c2 = tmp;
            cnt++;
            output[cnt].c1 = to_ZZ_p(x);
            output[cnt].c2 = -tmp;
            cnt++;
        }
    }
    if(!cnt)return NULL;
    return output;
}

elp_pnt elliptic_curve::ellp_add(elp_pnt a,elp_pnt b){
    elp_pnt output; 
    ZZ_p lambda = (b.c2-a.c2)*inv(b.c1-a.c1);
    output.c1 = power(lambda,2) - a.c1 - b.c1;
    output.c2 = lambda * (a.c1 - output.c1) - a.c2;
    cout<<"lambda "<<lambda<<endl;
    return output;
}

elp_pnt elliptic_curve::ellp_doubling(elp_pnt a){
    elp_pnt output; 
    ZZ_p lambda = ((3 * power(a.c1,2)) + this->a) * inv(2 * a.c2);
    output.c1 = power(lambda,2) - a.c1 - a.c1;
    output.c2 = lambda * (a.c1 - output.c1) - a.c2;
    return output;
}

elp_pnt elliptic_curve::ellp_scalar_mul(ZZ m,elp_pnt P){
    elp_pnt Q = P;
    ZZ tmp = ZZ(1) << (ZZ_log2(to_ZZ_p(m)))-2;
    cout<<"Q:  "<<Q.c1<<" "<<Q.c2<<endl;
    while(tmp>0){
        if((m & tmp)==1)Q=this->ellp_add(P,this->ellp_doubling(Q));
        else Q = this->ellp_doubling(Q);
        cout<<"Q:  "<<Q.c1<<" "<<Q.c2<<endl;
        tmp = tmp >> 1;
    }
    return Q;
}

