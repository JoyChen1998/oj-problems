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

#define Max 10001
#define INF 0x3f3f3f3f

vector<string> v;

void split(const string &src, const string &separator, vector<string> &dest) {
    const string &str = src;
    string substring;
    string::size_type start = 0, i;
    dest.clear();
    i = str.find_first_of(separator, start);
    do {
        if (i != string::npos) {
            substring = str.substr(start, i - start);
            dest.push_back(substring);
            start = i + separator.size();
            i = str.find(separator, start);
            if (start == string::npos)
                break;
        }
    } while (i != string::npos);
    substring = str.substr(start);
    dest.push_back(substring);
}

int K, num[Max], neg = 0;

int main(){
    cin>>K;
    for(int i = 0; i < K; i++){
        cin>>num[i];
        if(num[i] < 0) neg++;
    }

    int sum = 0, firsti = 0, lasti = K-1, maxSum = 0, temp = 0;
    for(int i = 0; i < K; i++){
        sum += num[i];
        if(maxSum < sum || (sum == 0 && lasti == K-1)) {
            maxSum = sum;
            temp = firsti;
            lasti = i;
        }
        if(sum <= 0){
            sum = 0;
            firsti = i+1;
        }
    }
    if(neg == K) {
        temp = 0;
        lasti = K-1;
    }
    cout<<maxSum<<" "<<num[temp]<<" "<<num[lasti];
    return 0;
}
