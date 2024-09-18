// ZZ cryptoAlgo::dlp(){
//     cout<<"enter value of p\n";
//     cin>>p;
//     p = conv<ZZ>(p);
//     ZZ_p::init(p);
//     cout<<"enter generator: "<<endl;
//     cin>>g;
//     cout<<"enter root : "<<endl;
//     cin>>h;
//     // h = power(g,x);
//     for(x = 0; x < p ; x++){
//         pow = power(g,x);
//         if(pow == h){
//             return x;            
//         }
//     }
//     return ZZ(-1);
// }
//
ZZ cryptoAlgo::dlp(ZZ p,ZZ_p g,ZZ_p h){
    ZZ_p::init(p);
    ZZ_p pow;
    ZZ x;
    x= 0;  
    for(x; x < p ; x++){
        pow = power(g,x);
        if(pow == h)return x;
    }
    return ZZ(-1);
}
