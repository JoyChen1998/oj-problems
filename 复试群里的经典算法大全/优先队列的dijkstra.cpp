#include<iostream>
//优先队列的dijkstra
using namespace std;

void dijkstra(int s) {
  priority_queue<DistNode> Q;
  Q.push_back(DistNode{0, s});
  for(int i = 1; i <= n; i++) d[i] = INF;//把d[i]都设置为最大值
  d[s] = 0;
  memset(done, 0, sizeof(done));
  while(!Q.empty()) {
    DistNode x = Q.top(); Q.pop();
    int u = x.u;
    if(done[u]) continue;//如果这个点已经被提出过了，直接抛弃（适用于那种松弛之后重复放入队列的点）
    done[u] = true;
    for(int i = 0; i < Q[u].size(); i++) 
      Edge& e = edges(Q[u][i]);
      if(e.dist + d[u] < d[e.to] && d[u] < INF) {
        d[e.to] = e.dist + d[u];
        p[e.to] = G[u][i];
        Q.push_back(Edge(d[e.to], e.to));//把松弛过后点的d值重新放入队列
      }
    }
  }


int main() {
  


  return 0;
}
