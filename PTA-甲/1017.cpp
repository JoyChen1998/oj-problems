#include <bits/stdc++.h>
using namespace std;
const int maxn = 110, INF = 0x3fffffff;
int end_time[maxn]; 
struct cus{
    int arrive_time, process_time;
    cus(int _arr, int _pro) : arrive_time(_arr), process_time(_pro){}
};
vector<cus> customers;
int GetTime(int h, int m, int s){
    return h * 3600 + m * 60 + s;
}
bool cmp(cus a, cus b){
    return a.arrive_time < b.arrive_time;
}
int main(){
    int num_cus, num_win;
    int open_time = GetTime(8, 0, 0), close_time = GetTime(17, 0, 1);
    scanf("%d %d", &num_cus, &num_win);
    for(int i = 0; i < num_cus; ++i){
        int th, tm, ts, tp;
        scanf("%d:%d:%d %d", &th, &tm, &ts, &tp);
        int t_time = GetTime(th, tm, ts);
        if(t_time < close_time){
            customers.push_back(cus(t_time, tp <= 60 ? tp * 60 : 3600));
        }
    }
    fill(end_time, end_time + maxn, open_time);
    sort(customers.begin(), customers.end(), cmp);
    int wait_time = 0;
    for(int i = 0; i < customers.size(); ++i){
        int now = -1, Min = INF;
        for(int j = 0; j < num_win; ++j){
            if(end_time[j] < Min){
                Min = end_time[j];
                now = j;
            }
        }   
        if(end_time[now] <= customers[i].arrive_time){
            end_time[now] = customers[i].arrive_time + customers[i].process_time; 
        }else{
            wait_time += (end_time[now] - customers[i].arrive_time);
            end_time[now] += customers[i].process_time;
        }   
    } 
    if(customers.size() == 0) printf("0.0");    //测试数据中无 
    else printf("%.1f", wait_time / 60.0 / customers.size());
    return 0;
} 