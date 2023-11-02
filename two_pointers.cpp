#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a) for(int i = 0; i < (a); ++i)

template<typename T> bool chmax(T &a,T b){if(a<b){a=b; return true;} return false;}
template<typename T> bool chmin(T &a,T b){if(a>b){a=b; return true;} return false;}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i=0;i<n;++i)cin >> a[i];
    
    int sum=0;
    int r=0;
    int res=0;
    //m未満の和の部分列の数を求める
    for(int l=0;l<n;++l) {
        while(r<n && sum+a[r] < m){
            //[l,r) の半開区間
            sum+=a[r];
            ++r;
        }
        res+=r-l;

        //rがlと同じ位置にある時はrを右にずらす sumは0になっているので変更しない
        if(l==r)++r;
        //lが一つ右がズレるのでズレた分をsumから引く
        else sum-=a[l];
    }
    cout << res << endl;
}