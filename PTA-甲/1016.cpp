
#include<vector>
#include<iostream>
#include<map>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
double price[24];//美元/分钟 
double dayPrice=0.0;
struct record{
	int month,day,hour,min,time;string status;
	bool operator < (const record &other) const{
		return time<other.time;
	}
	record(int mon,int d,int h,int m,int t,string s):month(mon),day(d),hour(h),min(m),time(t),status(s){}
};
double bill(int day,int hour,int min){//到1日0时0分的费用 
	double sum = min*price[hour];
	for(int i=0;i<hour;i++) sum+=(price[i]*60);
	return sum+(day-1)*dayPrice*60;
}
map<string,set<record> > mp; 
int main(void){
	for(int i=0;i<24;i++){
		cin>>price[i];
		price[i]=price[i]/100.00;
		dayPrice+=price[i];
	}
	int N;cin>>N;
	string name,status;int mon,day,hour,min;
	for(int i=0;i<N;i++){
		cin>>name;
		scanf("%d:%d:%d:%d",&mon,&day,&hour,&min);
		cin>>status;
		int time = min+hour*60+day*24*60;
		mp[name].insert(record(mon,day,hour,min,time,status));
	}
	map<string,set<record> >::iterator i;
	for(i = mp.begin();i!=mp.end();i++){
		set<record>::iterator j=(i->second).begin();
		set<record>::iterator jnext=(i->second).begin();
		jnext++; 
		bool output = false;
		double sumBill = 0.0;
		for(;j!=(i->second).end()&&jnext!=(i->second).end();j++,jnext++){
			if(j->status=="on-line"&&jnext->status=="off-line"){
				if(!output){
					printf("%s %02d\n",(i->first).c_str(),j->month);
					output = true;	
				}
				printf("%02d:%02d:%02d ",j->day,j->hour,j->min);
				printf("%02d:%02d:%02d ",jnext->day,jnext->hour,jnext->min);
				double thisBill = bill(jnext->day,jnext->hour,jnext->min) - bill(j->day,j->hour,j->min);
				printf("%d $%.2f\n",jnext->time-j->time,thisBill);
				sumBill += thisBill;
			}
		}
		if(output){
			printf("Total amount: $%.2f\n",sumBill);
		}
	}
	return 0;
}