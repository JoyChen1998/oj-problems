#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 2501;

bool cmp(char *p, char *q){
    return strcmp(p, q) < 0;
}

int main(){
    vector<char*> db[MAXN];
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i=0, t; i<n; i++){
        char *name = new char[5];
        scanf("%s %d", name, &t);
        for(int j=0, num; j<t; j++){
            scanf("%d", &num);
            db[num].push_back(name);
        }
    }
    for(int i=1; i<=k; i++){
        vector<char*> temp = db[i];
        sort(temp.begin(), temp.end(), cmp);
        printf("%d %d\n", i, temp.size());
        for(int j=0; j<temp.size(); j++){
            printf("%s\n", temp[j]);
        }
    }
    return 0;
}