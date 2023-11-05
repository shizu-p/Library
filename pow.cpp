#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a) for(int i = 0; i < (a); ++i)

template<typename T> bool chmax(T &a,T b){if(a<b){a=b; return true;} return false;}
template<typename T> bool chmin(T &a,T b){if(a>b){a=b; return true;} return false;}

struct pow_ll{
    ll a,x;
    pow_ll(ll a,ll x):a(a),x(x){}
    ll res = 1;
    ll pow(){
        while(x>0){
            if(x&1) res*=a;
            a*=a;
            x>>=1;
        }
        return res;
    }
};