#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a) for(int i = 0; i < (a); ++i)

template<typename T> bool chmax(T &a,T b){if(a<b){a=b; return true;} return false;}
template<typename T> bool chmin(T &a,T b){if(a>b){a=b; return true;} return false;}

using Graph = vector<vector<int>>;

void dfs(const Graph &g,int v,vector<bool> &seen){
    seen[v] = true;
    for(auto nv : g[v]){
        if(seen[nv]) continue;
        dfs(g,nv,seen);
    }
}

vector<int> depth,subtree;
void t_dfs(const Graph &g,int v,int p,int dep){
    //行きがけに深さをメモする
    depth[v] = dep;
    for(auto nv : g[v]){
        if(nv==p)continue;
        t_dfs(g,nv,v,dep+1);
    }

    //帰りがけにsubtreeを見る
    //自分自身をカウント
    subtree[v]=1;
    for(auto nv : g[v]){
        //親ノードはまだ未確定なのでスルーする
        if(nv==p)continue;
        //隣接しているノードのsubtreeを足す
        subtree[v]+=subtree[nv];
    }
    
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;
    Graph g(n);
    for(int i=0;i<m;++i){
        int a,b;
        cin >> a >> b;
        --a,--b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    depth.resize(n);
    subtree.resize(n);
    t_dfs(g,0,-1,0);
    for(int i=0;i<n;++i){
        cout << i << " subtree_size : " << subtree[i] << endl;
        cout << i << " depth : " << depth[i] << endl;
    }
}