//完成时间：5/27/2020

//坑点：
//查找的时候，遇到0就不要查找了，说明它不在table里，不要傻乎乎地找size次
//对于被没有位置插入的元素，查找它的时候要查size+1次，鬼知道为什么要+1

#include<iostream>
#include<stdio.h>

using namespace std;

int T[10001] = {0};

int prime(int raw){
    bool isP = true;
    for (int i = 2; i * i <= raw; i++){
        if(raw%i==0){   //跟0比较不要用!操作符
            isP = false;
            break;
        }
    }
    if(isP)
        return raw;
    else
        return prime(raw + 1);
}

void H(int N,int size){
    int num;
    for (int i = 0; i < N; i++){
        cin >> num;
        int fh = num % size;
        if(T[fh]==0){  //没被占
            T[fh] = num;
        }
        else{   //被占了
            int flag = 0; //flag表示有没有位置
            for (int p = 1; p < size; p++){
                int mh = (fh + p * p) % size;
                if(T[mh]==0){ //加上p*p没被占
                    T[mh] = num;
                    flag = 1;
                    break;
                }
            }
            if(flag==0) //实在没位置了
                cout << num << " cannot be inserted.\n";
        }
    }
}

float S(int M, int size){
    int sum = 0;
    int num;
    for (int i = 0; i < M; i++){
        cin >> num;
        bool flag = false;
        for (int p = 0; p < size; p++){
            int mh = (num + p * p) % size;
            if(T[mh]==0){
                sum += (p+1);
                flag = true;
                break;
            }
            if(T[mh]==num){ //找到了
                sum = sum + p + 1;
                flag = true;
                break;
            }
        }
        if(!flag)
            sum += (size+1);
    }
    return sum * 1.0 / M;
}

int main(){
    int Msize, N, M;
    cin >> Msize >> N >> M;
    Msize = prime(Msize);
    H(N,Msize);
    printf("%.1f", S(M, Msize));
    system("PAUSE");
    return 0;
}