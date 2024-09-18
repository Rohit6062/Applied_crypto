void cryptoAlgo::el_gamal(){
    cout<<"enter value of p\n";
    cin>>p;
    p = conv<ZZ>(p);
    ZZ_p::init(p);
    cout<<"enter generator: "<<endl;
    cin>>g;
    ZZ x,y;
    ZZ_p m;
    ZZ_p C1,C2;
    cout << "enter secret key(x): "<<endl;
    cin>>x;
    cout<< "enter message: "<<endl;
    cin>>m;
    cout <<"enter some number from group(y): "<<endl;
    cin>>y;
    // encryption
    h = power(g,x);
    // without signature
    C1 = power(g,y);
    C2 = power(h,y);
    C2  = C2* m;  
    //decryption
    C1 = inv(power(C1,x));
    C1 = C2 * C1;
    cout << "recovered message: "<<C1<<endl;
}




















void cryptoAlgo::el_gamal2(){
    cout<<"enter value of p\n";
    cin>>p;
    p = conv<ZZ>(p);
    ZZ_p::init(p);
    cout<<"enter generator: "<<endl;
    cin>>g;
    ZZ x,y;
    string m;
    ZZ_p C1;
    cout << "enter secret key(x): "<<endl;
    cin>>x;
    cout<< "enter message: "<<endl;
    cin>>m;
    int len = m.size();
    ZZ_p C2[len];
    ZZ_p msg[len];
    for(int i=0;i<len;i++)msg[i] = m[i];
    cout <<"enter some number from group(y): "<<endl;
    cin>>y;
    // encryption
    h = power(g,x);
    C1 = power(g,y);
    for(int i=0;i<len;i++)
        C2[i] = power(h,y),
        // C2[i] *(C2[i],ZZ_p(m[i])),  
        C2[i] = C2[i] * msg[i],
        cout<<C2[i]<<endl;
    //decryption
    C1 = inv(power(C1,x));
    ZZ_p tmp ;
    cout << "recovered message: \n";
    for(int i=0;i<len;i++)
        tmp = C1 * C2[i],
        cout<<tmp<<" ";
}
