#include<stdio.h>
#include<iostream>
#include<queue>

using namespace std;

struct customer{
    int start;
    int take;
    int finish;
    customer(){
        start = 0;
        finish = -1;
    }
};

int N, M, K, Q;

queue<int> que[21];
customer all[1001];
int ask[1001];
//时间从0开始，到9*60结束
int t = 0;

int isFull(){
    int m = 100000;
    int index = -1;
    for (int i = 0; i < N;i++){
        if(que[i].size()<M&&que[i].size()<m){
            m = que[i].size();
            index = i;
        }
    }
    return index;
}

int finishOne(){   //找一个队列中最先完成的人拿出来
    int first = 100000;
    int index = -1;
    for (int i = 0; i < N; i++){
        if(!que[i].empty()){    //先判断是否非空
            int n = que[i].front();
            if(all[n].start+all[n].take < first){
                first = all[n].start+all[n].take;
                index = i;
            }
        }
    }
    if(index>-1){
        if(all[que[index].front()].start<540)
            all[que[index].front()].finish = first;
        que[index].pop();
        t = first;
        if(que[index].size()>0)
            all[que[index].front()].start = t;
    }
    return index;
}

int pushOne(int pos,int n){
    que[pos].push(n);
}

int main(){
    int no = 0;
    cin >> N >> M >> K >> Q;
    for (int i = 0; i < K;i++){
        cin >> all[i].take;
    }
    for (int i = 0; i < Q;i++){
        cin >> ask[i];
    }
    while(no<K&&t<540){
        while(isFull()>-1){
            all[no].start = t;
            pushOne(isFull(), no);
            no++;
        }
        finishOne();
    }
    int flag = 0;
    do{
        flag = finishOne();
    } while (flag > -1);
    //输出结果
    for (int i = 0; i < Q; i++){
        customer c = all[ask[i]-1]; //-1是因为题目给的下标是从1开始
        if(c.finish>-1){
            printf("%02d:%02d\n",c.finish/60+8,c.finish%60);
        }
        else{
            printf("Sorry\n");
        }
    }
    system("PAUSE");
    return 0;
}