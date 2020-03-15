#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;

const int maxn = 510;
const int INF = 100000;

int ma[maxn][maxn];
int city[maxn];
int m, n,st,et;
bool vis[maxn];
int dis[maxn];
int weight[maxn];//用于权值计数；
int num[maxn];//用于记录路径条数

void dij(int st) {
    fill(vis, vis + maxn, true);
    fill(weight, weight + maxn, 0);
    fill(dis, dis + maxn, INF);
    fill(num, num + maxn, 0);
    dis[st] = 0;
    num[st] = 1;
    weight[st] = city[st];
    //vis[st] = false;//不能再访问;
    for (int i = 0; i < n; i++) {
        int index = -1;//找到最小节点；
        int min = INF;
        for (int j = 0; j < n; j++) {
            if (vis[j]&&dis[j] < min) {
                min = dis[j];
                index = j;
            }
        }
        if (index == -1)
            return;
        //如果找到最小值了;
        vis[index] = false;
        //进行以该节点为中间节点的更新；
        for (int j = 0; j < n; j++) {
            if (vis[j] && ma[index][j] != INF) {
                if (dis[j] > dis[index] + ma[index][j]) {
                    //发现更短路径；
                    dis[j] = dis[index] + ma[index][j];
                    weight[j] = weight[index] + city[j];
                    num[j] = num[index];
                }
                else if (dis[j] == dis[index] + ma[index][j]) {
                    //如果发现相等路径；
                    if (weight[index] + city[j] > weight[j]) {
                        //如果权值更大；
                        weight[j] = weight[index] + city[j];
                    }
                    num[j] += num[index];
                }
            }
        }
    }
}




int main(){
    int a, b;
    fill(ma[0], ma[0] + maxn * maxn, INF);
    cin >> n >> m >> st >> et;
    for (int i = 0; i < n; i++) {
        //城市节点；
        cin >> city[i];
    }
    for (int i = 0; i < m; i++) {
        //城市路径；
        cin >> a >> b;
        cin >> ma[a][b];
        ma[b][a] = ma[a][b];
        ma[a][a] = ma[b][b] = 0;
    }
    dij(st);
    printf("%d %d", num[et], weight[et]);
    return 0;
}