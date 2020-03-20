#include<iostream>

#define Max 100010
using namespace std;

struct Node{
    int t;
    char d;
    bool flag;
}node[Max];
int N, f1, f2;

int main(){
//  freopen("test.txt", "r", stdin);
    for(int i = 0; i < Max; i++) node[i].t = -1;
    scanf("%d%d%d", &f1, &f2, &N);
    int f, t; char d;
    for(int i = 0; i < N; i++){
        scanf("%d %c %d", &f, &d, &t);
        node[f] = {t, d, false};
    }
    for(int i = f1; i != -1; i = node[i].t) node[i].flag = true;
    for(int i = f2; i != -1; i = node[i].t){
        if(node[i].flag ) {
            printf("%05d", i);
            return 0;
        }
    }
    printf("-1");
    return 0;
}