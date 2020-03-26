//八皇后递归解法
#include<iostream>
using namespace std;
int queen[9]={-1,-1,-1,-1,-1,-1,-1,-1,-1};
int count=0;
bool available(int pointi,int pointj){//判断某个皇后是否与已有皇后冲突
	for(int i=1;i<pointi;i++){
		if(pointj==queen[i])return false;//同一列拒绝
		if((pointi-i)==(pointj-queen[i]))return false;//同一主对角线拒绝
		if((pointi-i)+(pointj-queen[i])==0)return false;//同一副对角线拒绝
	}
	return true;
}
void findSpace(int queenNumber){//在第queenNumber行找能放皇后的位置
	for(int i=1;i<9;i++){//从1~8遍历这一行的八个空位
		if(available(queenNumber,i)){
//如果可以放这个位置就记录下第queenNumber个皇后的位置
			queen[queenNumber]=i;
			if(queenNumber==8){//如果八个皇后都放满了统计一下
				count++;
				return;
			}
			int nextNumber=queenNumber+1;//还有皇后没放递归放下一个皇后
			findSpace(nextNumber);
		}
	}
	queen[--queenNumber]=-1;//如果这一行没有可放的位置说明上一行皇后放的位置不行，要为上一个皇后寻找新的可放位置
	return;
}


int main(){
	findSpace(1);//从（1，1）开始递归好理解
	cout<<count<<endl;
	return 0;
}