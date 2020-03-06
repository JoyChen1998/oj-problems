#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define Max 1000005

int N, M;
float num[Max];
pair<int ,float> n1[Max], n2[Max];

int main(){
//  freopen("test.txt", "r", stdin);
    memset(num, 0, sizeof(num));
    memset(n1, 0, sizeof(n1));
    memset(n2, 0, sizeof(n2));
    
    cin>>N;
    for(int i = 0; i < N; i++) {
        cin>>n1[i].first>>n1[i].second;
    }
    cin>>M;
    for(int i = 0; i < M; i++) {
        cin>>n2[i].first>>n2[i].second;
    }
    int number = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            int ex = n1[i].first + n2[j].first;
            float co = n1[i].second * n2[j].second;
            num[ex] += co;
        }
    }
    for(int i = 0; i < Max; i++) if(num[i] != 0) number ++;
    cout<<number;
    for(int i = Max -1; i >= 0; i--){
        if(num[i] != 0){
            cout<<" "<<i<<" ";
            cout<<fixed<<setprecision(1)<<num[i];
        }
    }
    
    return 0;
}