//坑点1：输入的数可能不是质数，所以既要判断反转之后的数是否为质数，也要判断原先的数是否为质数
//坑点2：1不是质数！！！

#include<iostream>
#include<queue>
#include<math.h>

using namespace std;

int rev(int N,int D){
    queue<int> tmp;
    int result = 0;
    while(N!=0){
        tmp.push(N % D);
        N = N / D;
    }
    while(!tmp.empty()){
        result = result * D + tmp.front();
        tmp.pop();
    }
    return result;
}

bool isPrime(int X){
    if(X==1)
        return false;
    for (int i = 2; i <= sqrt(X);i++){
        if(X%i==0)
            return false;
    }
    return true;
}

int main(){
    int r = 0;
    int N, D;
    cin >> N;
    queue<string> tmp;
    while(N>0){
        cin >> D;
        r = rev(N, D);
        if(isPrime(r)&&isPrime(N))
            tmp.push("Yes");
        else
            tmp.push("No");
        cin >> N;
    }
    while(tmp.size()>1){
        cout << tmp.front() << endl;
        tmp.pop();
    }
    cout << tmp.front();
    tmp.pop();
    system("PAUSE");
    return 0;
}