#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct node{
    int num;
    node *next;
};

node *initLink(int n) {
    auto *head = (node *)malloc(sizeof(node));
    head->next = nullptr;
    node *p = head;
    for(int i = 1; i <= n ; i++) {
        auto *newnode = (node *)malloc(sizeof(node));
        newnode->num = i;
        newnode->next = nullptr;
        head->next = newnode;
        head = newnode;
    }
    head->next = p->next;
    return p;
}

void solve(node *head, int k){
    if(head == nullptr) return;
    node *p = head->next;
    node *pre = head;
    int cnt = 0;

    while(p->next != p) {
        cnt++;

        if(cnt % k ==0) {
            node *tmp = p;
            p = p->next;
            pre->next = p;
            cout<<"this turn is "<<tmp->num<<endl;
            free(tmp);
        } else {
            p = p->next;
            pre = pre->next;
        }
    }
}

int main() {
    int n = 5, kth =3 ;
    node *head = initLink(n);
    solve(head, kth);
    return 0;
}
