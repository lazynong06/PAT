//无坑点，一次过

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<set>
#include<stdio.h>

using namespace std;

struct Node{
    int no;
    int left;
    int right;
    Node(){
        left = right = -1;
    }
};

int root[10];
Node Nodes[10];
int N;

int translate(char c){
    if(c=='-')
        return -1;
    else
        return c - '0';
}

//用队列进行层序遍历
vector<int> level_order(int r){
    queue<Node> q;
    vector<int> result;
    q.push(Nodes[r]);
    Node tmp;
    while(!q.empty()){
        tmp = q.front();
        result.push_back(tmp.no);
        if(tmp.right>-1)
            q.push(Nodes[tmp.right]);
        if(tmp.left>-1)
            q.push(Nodes[tmp.left]);
        q.pop();
    }
    return result;
}

//题目要求将树左右翻转再中序遍历，但是只需要更改一下遍历的逻辑即可，不用真的反转树
vector<int> in; //全局变量递归过程中可直接访问
void inverted_in_order(int r){
    if(Nodes[r].right>-1)
        inverted_in_order(Nodes[r].right);
    in.push_back(Nodes[r].no);
    if(Nodes[r].left>-1)
        inverted_in_order(Nodes[r].left);
}

int main(){
    fill(root, root + 10, 1);
    cin >> N;
    char x, y;
    for (int i = 0; i < N; i++){
        cin >> x >> y;
        Nodes[i].no = i;
        Nodes[i].left = translate(x);
        Nodes[i].right = translate(y);
        if(translate(x)>-1)
            root[translate(x)] = 0;
        if(translate(y)>-1)
            root[translate(y)] = 0;
    }
    int r = 0;
    //判断根的位置
    for (int i = 0; i < N; i++){
        if(root[i])
            r = i;
    }
    //层序遍历
    vector<int> result = level_order(r);
    for (int i = 0; i < N-1; i++){
        cout << result[i] << ' ';
    }
    cout << result[N - 1]<<endl;

    //逆树中序遍历
    inverted_in_order(r);
    for (int i = 0; i < N-1; i++){
        cout << in[i] << ' ';
    }
    cout << in[N - 1];
    system("PAUSE");
    return 0;
}