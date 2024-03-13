#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a) for(int i = 0; i < (a); ++i)

template<typename T> bool chmax(T &a,T b){if(a<b){a=b; return true;} return false;}
template<typename T> bool chmin(T &a,T b){if(a>b){a=b; return true;} return false;}

using Graph = vector<vector<int>>;



struct dfs_no_rec{
    int n;
    Graph g;
    
    dfs_no_rec(Graph g) : n((int)g.size()) , g(g) {}

    vector<bool> search(int v){
        vector<bool> seen(n,false);
        stack<int> stk;
        stk.push(v);
        while(!stk.empty()){
            int node = stk.top();
            stk.pop();
            for(int next : g[node]){
                if(seen[next])continue;
                stk.push(next);
            }
        }
    }
};
