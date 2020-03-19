#include <cstdio>
#include<cstring>
using namespace std;
int main(){
        char old[85], now[85];
        bool hashTable[127]={false};
        scanf("%s%s", old, now);
        int len1=strlen(old), len2=strlen(now);
        for(int i=0; i<len1; i++){
                int c1=old[i], c2, j;
                for(j=0; j<len2; j++){
                        c2=now[j];
                        if(c1>='a'&&c1<='z') c1-=32;
                        if(c2>='a'&&c2<='z') c2-=32;
                        if(c1==c2)break;
                }
                if(j==len2&&hashTable[c1]==false){
                        printf("%c",c1);
                        hashTable[c1]=true;
                }
        } 
        return 0;
}