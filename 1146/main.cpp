//取巧做法：通过观察后面的点到前面的任意一点是否有边(有向)
//没拿满分，有个测试点不知道为什么没过，但是23分也够了...

#include<iostream>
#include<stdio.h>
#include<queue>

using namespace std;

int Map[1001][1001] = {0};    //邻接矩阵，下标从1开始
int query[101][1001];   //要查询的数据
int N, M;   //N定点数，M边数
int K;  //查询数，打印结果的下标从0开始

bool func(int x){
    for (int i = 1; i <= N; i++){
        for (int j = i + 1; j <= N; j++){
            if(Map[query[x][j]][query[x][i]])
                return true;
        }
    }
    return false;
}

int main(){
    cin >> N >> M;
    int x, y;
    for (int i = 0; i < M; i++){
        cin >> x >> y;
        Map[x][y] = 1;
    }
    cin >> K;
    for (int i = 0; i < K; i++){
        for (int j = 0; j < N; j++){
            cin >> query[i][j];
        }
    }
    queue<int> R;
    for (int i = 0; i < K; i++){
        if(func(i))
            R.push(i);
    }
    while(R.size()>1){
        cout << R.front() << " ";
        R.pop();
    }
    cout << R.front();
    system("PAUSE");
    return 0;
}