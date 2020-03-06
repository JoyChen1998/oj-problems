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


int main(){
    double arr[3][3];
    double sum =1;
    for(int i = 0 ; i < 3 ; i++) {
        double tmp = 0, index = 0;
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
            if(tmp < arr[i][j]) {
                tmp = arr[i][j];
                index = j;
            }
        }
        if(index == 0)  cout<<"W ";
        else if(index == 1) cout<<"T ";
        else if(index == 2) cout<<"L ";
        sum *= tmp;
    }
    sum = 2*(sum*0.65 - 1);
    printf("%.2f\n", sum);
    return 0;

}
