//16分钟完成，无坑点
//可以不用纠结将ascii转成字符，在输出的时候用printf("%c",x)即可将ascii码x输出成字符

#include<iostream>
#include<string>
#include<stdio.h>

using namespace std;

void d2x(int n,int &a,int &b){
    int x,y;
    x = n % 13;
    y = n / 13;
    if(x<10)
        a = x+'0';
    else
        a = x - 10 + 'A';
    if(y<10){
        b = y + '0';
    }
    else
        b = y + 'A'-10;
}

int main(){
    int n1, n2, n3;
    int a, b;
    cin >> n1 >> n2 >> n3;
    cout << "#";
    d2x(n1, a, b);
    printf("%c%c", b, a);
    d2x(n2, a, b);
    printf("%c%c", b, a);
    d2x(n3, a, b);
    printf("%c%c", b, a);
    system("PAUSE");
    return 0;
}