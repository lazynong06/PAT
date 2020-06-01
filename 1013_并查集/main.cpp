//并查集问题

//vscode有毒啊，不知道为什么程序跑不起来了，也不报错

//这题用cin输入最后一个样例会超时，不是算法的问题
//并查集做union时是父亲合并，不是自身合并
//这题也可以用图的遍历来做，只要数遍历的次数即可

#include<iostream>
#include<queue>
#include<set>
#include<stdio.h>

using namespace std;

int Map[1010][1010] = {0};
int f[1010] = {0};
queue<int> query;
int N;

void initF(){
    for (int i = 1; i <= N; i++){
        f[i] = i;
    }
}

void unionF(int a, int b){
    int fa = f[a];
    int fb = f[b];
    if(fa!=fb)
        f[fb] = fa; //父亲不同，则将父亲合并
}

int findF(int a){   //findF是动态的，每次union之后find的结果可能不一样
    int x = a;
    while(f[a]!=a){
        a = f[a];
    }
    //路径压缩
    int tmp;
    while(x!=a){
        tmp = f[x];
        f[x] = a;
        x = f[tmp];
    }
    return a;
}

int cluster(int x){ //x是被删掉的点
    initF();
    for (int i = 1; i <= N; i++){
        for (int j = i + 1; j <= N; j++){
            if(i==x||j==x)
                continue;
            if(Map[i][j])
                unionF(i, j);
        }
    }
    set<int> re;
    for (int i = 1; i <= N; i++){
        if(i==x)
            continue;
        re.insert(findF(i));
    }
    return re.size() - 1;
}

int main(){
    int M, K;
    scanf("%d%d%d",&N,&M,&K);
    int x, y;
    for (int i = 0; i < M; i++){
        scanf("%d%d", &x, &y);
        Map[x][y] = 1;
        Map[y][x] = 1;
    }
    for (int i = 0; i < K; i++){
        scanf("%d", &x);
        query.push(x);
    }
    int tmp;
    while(query.size()>1){
        tmp = query.front();
        printf("%d\n",cluster(tmp));
        query.pop();
    }
    printf("%d",cluster(query.front()));
    system("PAUSE");
    return 0;
}