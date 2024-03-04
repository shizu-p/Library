#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a) for(int i = 0; i < (a); ++i)

template<typename T> bool chmax(T &a,T b){if(a<b){a=b; return true;} return false;}
template<typename T> bool chmin(T &a,T b){if(a>b){a=b; return true;} return false;}

template<typename T> vector<T> pre_sum(vector<T> &vec){
    vector<T> sum((int)vec.size()+1,0);
    for(int i=0;i<(int)vec.size();++i){
        sum[i+1] = sum[i] + vec[i];
    }
    return sum;
}

