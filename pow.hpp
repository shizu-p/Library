#include<bits/stdc++.h>
using namespace std;

struct pow_ll{
    long long a,x;
    pow_ll(long long a,long long x):a(a),x(x){}
    long long res = 1;
    long long pow(){
        while(x>0){
            if(x&1) res*=a;
            a*=a;
            x>>=1;
        }
        return res;
    }
};