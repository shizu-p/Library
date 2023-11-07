#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a) for(int i = 0; i < (a); ++i)

template<typename T> bool chmax(T &a,T b){if(a<b){a=b; return true;} return false;}
template<typename T> bool chmin(T &a,T b){if(a>b){a=b; return true;} return false;}

vector<int> eratos(int n){
    vector<bool> isprime(n+1,true);
    vector<int> prime;
    for(int i=2;i<n;++i){
        if(!isprime[i]) continue;
        prime.push_back(i);
        for(int j=i*2;j<=n;j+=i) isprime[j] = false;
    }
    return prime;
}
