#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a) for(int i = 0; i < (a); ++i)

template<typename T> bool chmax(T &a,T b){if(a<b){a=b; return true;} return false;}
template<typename T> bool chmin(T &a,T b){if(a>b){a=b; return true;} return false;}

struct edge{
    int to;
    ll cost;
    edge(int to=-1,ll cost=-1):to(to),cost(cost){}
};
using Graph = vector<vector<edge>>;

struct dfs{
    // 参考
    // https://qiita.com/drken/items/a803d4fc4a727e02f7ba#4-3-%E4%BA%8C%E9%83%A8%E3%82%B0%E3%83%A9%E3%83%95%E5%88%A4%E5%AE%9A
    Graph g;
    int n;
    vector<bool> seen;
    vector<int> color,depth,subtree_size;
    
    dfs(const Graph g) : g(g) , n((int)g.size()){
    }

    bool bipartite(int start){
        color.resize(n,-1);
        return bip_dfs(start);
    }
    bool bip_dfs(int v,int cur = 0){
        color[v] = cur;
        for(int i = 0; i < (int)g[v].size(); ++i){
            // vの隣接頂点の色が確定しているか
            if(color[ g[v][i].to ] != -1) {
                if(color[ g[v][i].to ] == cur) return false;
                continue;
            }
            if(!bip_dfs(g[v][i].to,1-cur)) return false;
        }
        return true;
    }

    void depth_subsize_resize(int v){
        depth.resize(n);
        subtree_size.resize(n);
        depth_subsize(v,-1,0);
    }
    void depth_subsize(int v,int p, int d){
        depth[v] = d;
        for(edge e: g[v]){
            if(e.to == p) continue;
            depth_subsize(e.to,v,d+1);
        }
        subtree_size[v] = 1;
        for(edge e : g[v]){
            if(e.to == p) continue;
            subtree_size[v] += subtree_size[e.to];
        }
    }
    void subtree_depth(int v,vector<int> &subt,vector<int> &dep){
        depth_subsize_resize(v);
        subt = subtree_size;
        dep = depth;
    }
};

/*
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;
    Graph g(n);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        g[a].push_back({b,-1});
        g[b].push_back({a,-1});
    }
    
    dfs d(g);
    vector<int> depth,subtree;
    d.subtree_depth(0,subtree,depth);
    for(int i = 0; i < n; ++i){
        cout << i << " depth : " << depth[i] << "  subtree : " << subtree[i] << endl;
    }
}
*/