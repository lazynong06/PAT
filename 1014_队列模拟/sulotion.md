## 需要注意的点
- 使用queue时，访问queue之前需要判断queue是否为空
- 每一个顾客A服务完成后，应该让队列中的下一个顾客B开始服务，即把A的结束时间赋给B的开始时间
- 结束时间 = 开始时间+持续时间
- 17:00之后(包括17:00)开始的服务的顾客全部sorry，可以让所有顾客的结束时间都初始化为-1，这样默认都是sorry
- 输出时间格式可以用printf("%02d:%02d")
- 这个题目一次提交就过了，但是本地实现花了挺长时间，主要是思路前期思路不成熟，边实现边做思路调整，效率很低

## 代码
```cpp
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
```

