//完成时间：5/27/2020

// 坑点：所有正数都是紧密的，这时需要输出最大数+1
//用set可以去重且自动排序

#include<stdio.h>
#include<iostream>
#include<set>

using namespace std;

set<int> num;

int main(){
    int N, tmp;
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        scanf("%d", &tmp);
        num.insert(tmp);
    }
    //先将所有小于1的弹出
    set<int>::iterator it = num.begin();
    for (it; it != num.end()&&*it<=0; it++){} //让it递增直至对应的值大于0
    int i = 1;
    int flag = 0;
    for (it; it != num.end(); it++)
    {
        if(*it!=i){
            printf("%d", i);
            flag = 1;
            break;
        }
        i++;
    }
    if(!flag)
        printf("%d",i);
    system("PAUSE");
    return 0;
}