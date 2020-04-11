#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<queue>
#include<set>
#include<stack>
using namespace std;
typedef long long ll;

struct node{
    char pos;
    node* lchild;
    node* rchild;
};

node* build(int& position, string str) {
    char ch = str[position++];
    if(ch == '#')
        return nullptr;
    node *root = new node();
    root->pos = ch;
    root->lchild = build(position, str);
    root->rchild = build(position, str);
    return root;
}

void inorder(node *head){
    if(!head) return;
    if(head->lchild) inorder(head->lchild);
    cout<<head->pos<<" ";
    if(head->rchild) inorder(head->rchild);
}

int main() {
    string str;
    cin>>str;
    int postition = 0;
    node *head = build(postition, str);
    inorder(head);
    return 0;
}