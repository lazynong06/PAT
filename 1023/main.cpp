//这题做了足足50分钟，第一次提交只用17分钟，拿了11分，有三个点没过
//long long int最大能表示1.8*10^19，但是题目要求输入的数不超过20位，如果用long long int就越界了
//改用大数类即可解决此问题
//用map来计算各个数字出现的次数，以判断是否位permutation

#include<iostream>
#include<map>
#include<string>

using namespace std;

struct big{
    long long int b;
    long long int s;
    big(string r){
        int len = r.length();
        if(len<=10){
            b = 0;
            s = 0;
            for (int i = 0; i<=len-1 ; i++){
                s = s * 10 + r[i] - '0';
            }
        }
        else{
            s = 0;
            for (int i = len - 10; i <= len-1; i++){
                s = s * 10 + r[i] - '0';
            }
            b = 0;
            for (int i = 0; i <=len-11; i++){
                b = b * 10 + r[i] - '0';
            }
        }
    }
    big(long long int x,long long int y){
        b = x;
        s = y;
    }
};

big mul(big a){
    long long int y = a.s * 2 % 10000000000;
    long long int x = a.s * 2 / 10000000000+a.b*2;
    return big(x, y);
}

bool compare(big a,big b){
    big n1 = a, n2 = b;
    map<int, int> m1,m2;
    for (int i = 0; i < 10; i++){
        m1[i] = 0;
        m2[i] = 0;
    }
    while(n1.s){
        m1[n1.s % 10]++;
        n1.s /= 10;
    }
    while(n1.b){
        m1[n1.b % 10]++;
        n1.b /= 10;
    }
    while(n2.s){
        m2[n2.s % 10]++;
        n2.s /= 10;
    }
    while(n2.b){
        m2[n2.b % 10]++;
        n2.b /= 10;
    }
    //比较
    for (int i = 0; i < 10; i++){
        if(m1[i]!=m2[i])
            return false;
    }
    return true;
}

int main(){
    string s;
    cin>>s;
    big n1(s);
    big n2 = mul(n1);
    if(compare(n1,n2))
        cout << "Yes\n";
    else
        cout << "No\n";
    if(n2.b>0)
        cout << n2.b;
    cout << n2.s;
    system("PAUSE");
    return 0;
}