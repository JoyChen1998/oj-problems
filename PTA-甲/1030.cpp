#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <cmath>
#include <iomanip>
#include <map>
using  namespace std;

const int INF = 0x3f3f3f;
const int maxn = 505;
int pre[maxn], cost[maxn][maxn], path[maxn][maxn], d[maxn], c[maxn];
bool vis[maxn] = {false};

int n,m,st, ed;

void dij(int s) {
    fill(d , d+n, INF);
    fill(c, c+n, INF);
    for(int i = 0; i < n ; i++) pre[i] = i;
    d[s] = 0;
    c[s] = 0;
    // preprocess
    for(int i = 0 ; i < n; i++) {
        int u = -1 , minn = INF;
        for(int j = 0; j < n; j++) {
            if (!vis[j] && minn > d[j]) {
                u = j;
                minn = d[j];
            }
        }
        if(u == -1) return;
        vis[u] = true;
        // choose a short e
        for(int v = 0; v < n; v++) {
            if(!vis[v] && path[u][v] !=INF) {
                if(d[u] + path[u][v] < d[v]) {
                    d[v] = d[u] + path[u][v];
                    c[v] = c[u] + cost[u][v];
                    pre[v] = u;
                } else if(d[u] + path[u][v] == d[v]) {
                    if(cost[u][v] + c[u] < c[v]) {
                        c[v] = cost[u][v] + c[u];
                        pre[v] = u;
                    }
                }
            }
        }
    }

}

void dfs(int v) {
    if(v == st) {
        cout<<v<<" ";
        return;
    }
    dfs(pre[v]);
    cout<<v<<" ";
}

int main(){
    cin>>n>>m>>st>>ed;
    memset(path, INF, sizeof(path));
    memset(cost, INF, sizeof(cost));
    for(int i = 0; i < m; i++) {
        int s,e,v,co;
        cin>>s>>e>>v>>co;
        path[s][e] = path[e][s] = v;
        cost[s][e] = cost[e][s] = co;
    }

    dij(st);
    dfs(ed);
    cout<<d[ed]<<" "<<c[ed]<<endl;
    return 0;
}
