void cryptoAlgo::diff_hell(){
    ZZ a,b;
    ZZ_p A,B;
    cout<<"enter value of p\n";
    cin>>p;
    p = conv<ZZ>(p);
    ZZ_p::init(p);
    cout<<"enter generator: "<<endl;
    cin>>g;
    cout<<"enter alice's secret key: "<<endl;
    cin>> a;
    cout<<"enter bob's secret key: "<<endl;
    cin>> b;
    A = power(g,a);
    B = power(g,b);
    cout << "alice's key : "<<power(B,a)<<endl;
    cout << "bob's key : " << power(A,b)<<endl;
    return;
}
