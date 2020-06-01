//这题真的难！所有题里面ac率最低的一道
//总体思路是用二分法进行查找，下界为N2最大位+1，上界为搜索目标tar(+1)
//binarysearch里面if后面要写else if，因为如果x==-1，后面的就不能再跑了！只写if后面还会运行！
//搜索上界可以定为最大值+1，因为如果写成mid = (left+right)/2，最大值+1搜不到，但是最大值能搜到
//储存结果要用LL，但是即使用LL还是会溢出，溢出说明过大了

//还有一种情况，如tar=9，但是N2=8，这样也是impossible，这套代码就会陷入死循环，只是pat测试好像没设这个坑

#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>

typedef long long int LL;

using namespace std;


int getval(char c){
    if(c<='9')
        return c - '0';
    else
        return c - 'a'+10;
}

LL getnum(string s,int rdx){
    LL ret = 0;
    for (int i = 0; i < s.size(); i++){
        ret = ret * rdx + getval(s[i]);
    }
    if(ret<0)
        return -1;
    return ret;
}

LL getlow(string s){
    char low = s[0];
    for (int i = 0; i < s.size(); i++){
        if(s[i]>low)
            low = s[i];
    }
    return getval(low) + 1;
}

LL binarysearch(LL left, LL right, LL tar, string n){
    while(left<right){
        LL mid = (left + right) / 2;
        LL x = getnum(n, mid);
        if(x>tar||x==-1)
            right = mid;
        else if(x<tar)
            left = mid;
        else if(x==tar)
            return mid;
    }
    return -1;
}

int main(){
    string N1, N2;
    int tag, radix;
    cin >> N1 >> N2 >> tag >> radix;
    if(tag==2){
        string tmp = N1;
        N1 = N2;
        N2 = tmp;
    }
    //N2只有一位
    LL tar = getnum(N1, radix);
    LL left = getlow(N2);
    LL right = max(left, getnum(N1,radix))+1;

    //LL result = binarysearch(left, right, tar, N2);
    LL result = binarysearch(left, right, tar, N2);
    if(result>0)
        cout << result;
    else
        cout << "Impossible";
    system("PAUSE");
    return 0;
}