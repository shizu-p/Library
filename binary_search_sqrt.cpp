#include<bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename T> bool chmax(T &a,T b){if(a<b){a=b; return true;} return false;}
template<typename T> bool chmin(T &a,T b){if(a>b){a=b; return true;} return false;}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double r;
    cin>>r;
    double res=-1.0;

    double lef=0.0,rig=r;
    while(abs(lef-rig)>=0.0001){
        double mid=(lef+rig)/2;
        if(mid*mid>r)rig=mid;
        else if(mid*mid<r)lef=mid;
        else if(mid*mid==r){
            res=mid;
            break;
        }
    }
    if(res==-1.0){
        if(abs(lef*lef-r)<abs(rig*rig-r))res=lef;
        else res=rig;
    }
    cout<<fixed<<setprecision(10);
    cout<<res<<endl;

}
