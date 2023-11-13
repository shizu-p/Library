#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a) for(int i = 0; i < (a); ++i)

template<typename T> bool chmax(T &a,T b){if(a<b){a=b; return true;} return false;}
template<typename T> bool chmin(T &a,T b){if(a>b){a=b; return true;} return false;}

//組み合わせ全列挙
vector<int> a;
int n,k;
void combi_index(int num=0){
    if((int)a.size() == k){
        for(auto s : a){
            cout << s;
        }
        cout << endl;
        return;
    }
    for(int i=num;i<n;++i){
        a.push_back(i);
        combi_index(i+1);
        a.pop_back();
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    n = 5;
    k = 3;
    combi_index();
}